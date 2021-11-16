#pragma once

#include "IBoardModel.h"

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

    bool PlaceRobot( std::uint8_t X_coord, std::uint8_t Y_coord, EHeading heading ) noexcept override;
    
    bool ExecCommand( ECommand command ) noexcept override;

private:

    // Board size by X/Y
    const std::uint8_t m_XDimension;
    const std::uint8_t m_YDimension;

    SBoardPosition m_stRobotPosition;
};
