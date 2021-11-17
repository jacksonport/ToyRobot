#pragma once

#include "IBoardModel.h"

bool HeadingToString( ECommand cmd, std::string* pCmd );
bool StringToHeading( const std::string& Cmd, ECommand* pCmd );

struct SPosition
{
    std::uint8_t m_X;
    std::uint8_t m_Y;
};

struct SBoardPosition : public SPosition
{
    EHeading m_Heading;
};

class CSquareBoard : public IBoardModel
{
public:

    CSquareBoard( std::uint8_t X_dimension = 5, std::uint8_t Y_dimension = 5 );

    // Constructor delegating
    CSquareBoard( const SPosition& position );

    bool PlaceRobot( std::uint8_t X_coord, std::uint8_t Y_coord, EHeading heading ) noexcept override;
    
    bool ExecCommand( ECommand command ) noexcept override;

    bool ExtractResult( std::string* pLine ) noexcept override;

private:

    // Board size by X/Y
    const std::uint8_t m_XDimension;
    const std::uint8_t m_YDimension;

    SBoardPosition m_stRobotPosition;

    std::string m_strLastCommandResult;

    bool m_bPlaced;
};
