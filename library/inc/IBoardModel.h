#pragma once

#include <cstdint>
#include <memory>

enum class EHeading : std::uint8_t
{
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

enum class ECommand : std::uint8_t
{
    MOVE = 0,
    REPORT = 1,
    LEFT = 2,
    RIGHT = 3
};

// Board model interface
class IBoardModel
{
public:

    virtual ~IBoardModel() noexcept = default;

    virtual bool PlaceRobot( std::uint8_t X_coord, std::uint8_t Y_coord, EHeading heading ) noexcept = 0;

    virtual bool ExecCommand( ECommand command ) noexcept = 0;
};

typedef std::shared_ptr < IBoardModel > SpBoardModel_t;
