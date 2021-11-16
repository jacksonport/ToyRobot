
#include "Board.h"

using namespace std;

CSquareBoard::CSquareBoard( uint8_t X_dimension, uint8_t Y_dimension ) :
    m_XDimension( X_dimension ), m_YDimension( Y_dimension ),
    m_stRobotPosition{ 0, 0, EHeading::NORTH }, m_strLastCommandResult( "" )
{
}

CSquareBoard::CSquareBoard( const SPosition& position ) : CSquareBoard( position.m_X, position.m_Y )
{
}

bool CSquareBoard::PlaceRobot( uint8_t X_coord, uint8_t Y_coord, EHeading heading ) noexcept
{

    return false;
}

bool CSquareBoard::ExecCommand( ECommand command ) noexcept
{
    m_strLastCommandResult = "";

    // TODO

    return false;
}

bool CSquareBoard::ExtractResult( string* pLine ) noexcept
{
    if ( !pLine || m_strLastCommandResult.empty() )
    {
        return false;
    }
    
    *pLine = m_strLastCommandResult;

    return true;
}
