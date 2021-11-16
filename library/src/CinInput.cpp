
#include <iostream>

#include "CinInput.h"

using namespace std;

namespace
{

string cstrRegEx = "(PLACE) ([0-9]*),([0-9]*),(EAST|WEST|SOUTH|NORTH)";
string cstrRegExCmd = "MOVE|LEFT|RIGHT|REPORT";

};

CinInput::CinInput() : m_spBoardModel( nullptr ), m_rePlacing( cstrRegEx ),
    m_reCommand( cstrRegExCmd )
{
}

bool CinInput::GetInputLine( string* pLine ) noexcept
{
    // TODO: read line implementation

    if ( !m_spBoardModel.get() )
    {
        return false;
    }

    // TODO: process line implementation
    
    return false;
}

void CinInput::SetBoard( const SpBoardModel_t& spBoard ) noexcept
{
    m_spBoardModel = spBoard;
}
