
project (ToyRobot)

set(HEADER_LIST
    inc/Board.h
    inc/CinInput.h
    inc/IBoardModel.h
    inc/IInputController.h
    )

set(SOURCE_LIST
    src/Board.cpp
    src/CinInput.cpp
    )

add_library(${PROJECT_NAME}
            STATIC
            ${HEADER_LIST}
            ${SOURCE_LIST})

include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/inc)

export(TARGETS ${PROJECT_NAME} FILE "${PROJECT_NAME}Config.cmake")

add_executable("ToyConsole" src/ToyConsole.cpp)

target_link_libraries("ToyConsole" ${PROJECT_NAME})

# Always build the target test
add_subdirectory(test)
