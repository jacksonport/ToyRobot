message(">>>>>> CurrentListDir: ${CMAKE_CURRENT_LIST_DIR}")

project(RobotTest)

# Local sources of Boost
include_directories(BEFORE /home/sergey/distrib/boost_1_75_0)

message("@@ LIB_PLATFORM_DEPS_DIR: ${LIB_PLATFORM_DEPS_DIR}")

enable_testing()

add_executable(${PROJECT_NAME}
               ToyRobotTest.cpp)

add_test(${PROJECT_NAME} ${PROJECT_NAME})

# Define the libraries this project depends upon
target_link_libraries(${PROJECT_NAME}
                      ToyRobot)

include_directories(AFTER SYSTEM ${INC_PLATFORM_DEPS_DIR})
