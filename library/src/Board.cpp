
#include <map>
#include <sstream>

#include "Board.h"

using namespace std;

namespace
{

// Mapping of actions strings into enumerations
const string cstrNORTH = "NORTH";
const string cstrEAST = "EAST";
const string cstrSOUTH = "SOUTH";
const string cstrWEST = "WEST";

typedef map < EHeading, string > MapHeadingToString_t;
typedef map < string, EHeading > MapStringToHeading_t;

MapHeadingToString_t MapCmdMapping
{
    { EHeading::NORTH, cstrNORTH },
    { EHeading::EAST, cstrEAST },
    { EHeading::SOUTH, cstrSOUTH },
    { EHeading::WEST, cstrWEST }
};

MapStringToHeading_t MapToCmdMapping
{
    { cstrNORTH, EHeading::NORTH },
    { cstrEAST, EHeading::EAST },
    { cstrSOUTH, EHeading::SOUTH },
    { cstrWEST, EHeading::WEST }
};

typedef MapHeadingToString_t::const_iterator CiMapHeadingToString_t;
typedef MapStringToHeading_t::const_iterator CiMapStringToHeading_t;

CiMapHeadingToString_t CmdItEnd = MapCmdMapping.end();
CiMapStringToHeading_t StrItEnd = MapToCmdMapping.end();

};

bool HeadingToString( EHeading cmd, std::string* pCmd )
{
    if ( !pCmd )
    {
        return false;
    }
    
    CiMapHeadingToString_t itFound = MapCmdMapping.find( cmd );

    // If found
    if ( CmdItEnd != itFound )
    {
        *pCmd = itFound -> second;

        return true;
    }

    return false;
}

bool StringToHeading( const std::string& Cmd, EHeading* pCmd )
{
    if ( !pCmd )
    {
        return false;
    }

    CiMapStringToHeading_t itFound = MapToCmdMapping.find( Cmd );

    // If found
    if ( StrItEnd != itFound )
    {
        *pCmd = itFound -> second;

        return true;
    }

    return false;
}

CSquareBoard::CSquareBoard( uint8_t X_dimension, uint8_t Y_dimension ) :
    m_XDimension( X_dimension ), m_YDimension( Y_dimension ),
    m_stRobotPosition{ 0, 0, EHeading::NORTH }, m_strLastCommandResult( "" ),
m_bPlaced( false )
{
}

CSquareBoard::CSquareBoard( const SPosition& position ) : CSquareBoard( position.m_X, position.m_Y )
{
}

bool CSquareBoard::PlaceRobot( uint8_t X_coord, uint8_t Y_coord, EHeading heading ) noexcept
{
    if ( ( X_coord >= m_XDimension ) || ( Y_coord >= m_YDimension ) )
    {
        m_bPlaced = false;

        return false;
    }

    m_stRobotPosition.m_X = X_coord;
    m_stRobotPosition.m_Y = Y_coord;
    m_stRobotPosition.m_Heading = heading;

    m_bPlaced = true;
    
    return true;
}

bool CSquareBoard::ExecCommand( ECommand command ) noexcept
{
    // Check if robot was placed
    if ( !m_bPlaced )
    {
        return false;
    }
    
    m_strLastCommandResult = "";

    switch ( command )
    {
        case ECommand::MOVE:
        {
            // Move if we can
            switch ( m_stRobotPosition.m_Heading )
            {
                case EHeading::NORTH:
                {
                    // Check the border condition
                    if ( m_stRobotPosition.m_Y < m_YDimension - 1 )
                    {
                        ++( m_stRobotPosition.m_Y );

                        return true;
                    }
                    
                    break;
                }

                case EHeading::EAST:
                {
                    if ( m_stRobotPosition.m_X < m_XDimension - 1 )
                    {
                        ++( m_stRobotPosition.m_X );

                        return true;
                    }
                    
                    break;
                }

                case EHeading::SOUTH:
                {
                    if ( m_stRobotPosition.m_Y )
                    {
                        --( m_stRobotPosition.m_Y );

                        return true;
                    }
                    
                    break;
                }

                case EHeading::WEST:
                {
                    if ( m_stRobotPosition.m_X )
                    {
                        --( m_stRobotPosition.m_X );

                        return true;
                    }

                    break;
                }
            }
            
            break;

        } // case ECommand::MOVE:

        case ECommand::REPORT:
        {
            ostringstream strmOutput;

            strmOutput << m_stRobotPosition.m_X << ',' << m_stRobotPosition.m_Y << ',';

            if ( HeadingToString( m_stRobotPosition.m_Heading, &m_strLastCommandResult ) )
            {
                strmOutput << m_strLastCommandResult;

                m_strLastCommandResult = strmOutput.str();

                return true;
            }

            break;
        }

        case ECommand::LEFT:
        {
            switch ( m_stRobotPosition.m_Heading )
            {
                case EHeading::NORTH:
                {
                    m_stRobotPosition.m_Heading = EHeading::WEST;
                    break;
                }

                case EHeading::EAST:
                {
                    m_stRobotPosition.m_Heading = EHeading::NORTH;
                    break;
                }

                case EHeading::SOUTH:
                {
                    m_stRobotPosition.m_Heading = EHeading::EAST;
                    break;
                }

                case EHeading::WEST:
                {
                    m_stRobotPosition.m_Heading = EHeading::SOUTH;
                    break;
                }
            }

            return true;
            
            break;
        }

        case ECommand::RIGHT:
        {
            switch ( m_stRobotPosition.m_Heading )
            {
                case EHeading::NORTH:
                {
                    m_stRobotPosition.m_Heading = EHeading::EAST;
                    break;
                }

                case EHeading::EAST:
                {
                    m_stRobotPosition.m_Heading = EHeading::SOUTH;
                    break;
                }

                case EHeading::SOUTH:
                {
                    m_stRobotPosition.m_Heading = EHeading::WEST;
                    break;
                }

                case EHeading::WEST:
                {
                    m_stRobotPosition.m_Heading = EHeading::NORTH;
                    break;
                }
            }

            return true;

            break;
        }

        // Unsupported command
        default:
        {
            return false;
        }

    } // switch ( command )

    return false;

} // bool CSquareBoard::ExecCommand( ECommand command ) noexcept

bool CSquareBoard::ExtractResult( string* pLine ) noexcept
{
    if ( !pLine || m_strLastCommandResult.empty() )
    {
        return false;
    }
    
    *pLine = m_strLastCommandResult;

    return true;
}
