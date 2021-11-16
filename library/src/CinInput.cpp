
#include "CinInput.h"

using namespace std;

CinInput::CinInput() : m_spBoardModel( nullptr )
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
