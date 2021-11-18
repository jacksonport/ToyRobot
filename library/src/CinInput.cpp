
#include <limits>
#include <iostream>
#include <regex>

#include "CinInput.h"
#include "Board.h"

using namespace std;

namespace
{

string cstrRegEx = "(PLACE) ([0-9]*),([0-9]*),(EAST|WEST|SOUTH|NORTH)";
string cstrRegExCmd = "MOVE|LEFT|RIGHT|REPORT";

// Mapping of command strings into enumerations
const string cstrMOVE = "MOVE";
const string cstrLEFT = "LEFT";
const string cstrRIGHT = "RIGHT";
const string cstrREPORT = "REPORT";

typedef map < string, ECommand > MapStringToCmd_t;

MapStringToCmd_t MapToCommandMapping
{
    { cstrMOVE, ECommand::MOVE },
    { cstrLEFT, ECommand::LEFT },
    { cstrRIGHT, ECommand::RIGHT },
    { cstrREPORT, ECommand::REPORT }
};

typedef MapStringToCmd_t::const_iterator CiMapStringToCmd_t;

CiMapStringToCmd_t StrItCmdEnd = MapToCommandMapping.end();

// Convert string command into enumeration
inline bool StringToCmd( const string& Cmd, ECommand* pCmd )
{
    if ( !pCmd )
    {
        return false;
    }

    CiMapStringToCmd_t itFound = MapToCommandMapping.find( Cmd );

    // If found
    if ( StrItCmdEnd != itFound )
    {
        *pCmd = itFound -> second;

        return true;
    }

    return false;
}

};

CinInput::CinInput() : m_spBoardModel( nullptr ), m_rePlacing( cstrRegEx ),
    m_reCommand( cstrRegExCmd )
{
}

bool CinInput::GetInputLine( string* pLine ) noexcept
{
    if ( !pLine )
    {
        return false;
    }

    if ( !m_spBoardModel.get() )
    {
        return false;
    }

    string strInput;

    getline( cin, strInput );

    if ( strInput.empty() )
    {
        return false;
    }

    smatch sm;

    // Check if we have a command
    if ( regex_match( strInput, sm, m_reCommand ) )
    {
        if ( sm.size() != 1 )
        {
            return false;
        }

        ECommand eCmd;

        if ( StringToCmd( sm[ 0 ].str(), &eCmd ) )
        {
            if ( m_spBoardModel -> ExecCommand( eCmd ) )
            {
                if ( ECommand::REPORT == eCmd )
                {
                    if ( !m_spBoardModel -> ExtractResult( pLine ) )
                    {
                        return false;
                    }
                }

                return true;
            }
        }
    }
    else if ( regex_match( strInput, sm, m_rePlacing ) ) // Check if we have a placing
    {
        int iX = abs( atoi( sm[ 2 ].str().c_str() ) );
        int iY = abs( atoi( sm[ 3 ].str().c_str() ) );

        // Check if we exceed maximum possible value for a board dimension
        if ( ( iX > numeric_limits < uint8_t >::max() ) || 
             ( iY > numeric_limits < uint8_t >::max() ) )
        {
            return false;
        }
        
        EHeading eHeading;

        // Extract heading
        if ( StringToHeading( sm[ 4 ].str(), &eHeading ) )
        {
            if ( m_spBoardModel -> PlaceRobot( 
                static_cast < uint8_t > ( iX ), static_cast < uint8_t > ( iY ), eHeading ) )
            {
                return true;
            }
        }
    }
    
    return false;
}

void CinInput::SetBoard( const SpBoardModel_t& spBoard ) noexcept
{
    m_spBoardModel = spBoard;
}
