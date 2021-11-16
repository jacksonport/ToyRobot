#pragma once

#include <string>

#include "IBoardModel.h"

// Input controller interface
class IInputController
{
public:

    virtual ~IInputController() noexcept = default;
    
    virtual bool GetInputLine( std::string* pLine ) noexcept = 0;

    virtual void SetBoard( const SpBoardModel_t& spBoard ) noexcept = 0;
};
