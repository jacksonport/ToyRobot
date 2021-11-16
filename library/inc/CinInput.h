#pragma once

#include "IInputController.h"

class CinInput : public IInputController
{
public:
    
    CinInput();

    bool GetInputLine( std::string* pLine ) noexcept override;

    void SetBoard( const SpBoardModel_t& spBoard ) noexcept override;

private:

    SpBoardModel_t m_spBoardModel;
};
