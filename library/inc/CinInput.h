#pragma once

#include <regex>

#include "IInputController.h"

class CinInput : public IInputController
{
public:
    
    CinInput();

    bool GetInputLine( std::string* pLine ) noexcept override;

    void SetBoard( const SpBoardModel_t& spBoard ) noexcept override;

private:

    std::regex m_rePlacing;
    std::regex m_reCommand;

    SpBoardModel_t m_spBoardModel;
};
