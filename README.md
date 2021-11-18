# ToyRobot
Implementation for Toy Robot problem. Built and tested on Ubuntu 18.04 LTS 64-bit, gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

Test building requires boost library headers (don't need to build libraries).
If you don't have installed packages with boost headers then you need to unpack your boost headers into some folder and in file library/test/CMakeLists.txt
substitute the line:
include_directories(BEFORE /home/sergey/distrib/boost_1_75_0)
with
include_directories(BEFORE <YOUR_BOOST_PATH>)

After git clone execute in top project folder:
cmake CMakeLists.txt
cmake --build .
make

Running the tests:
cat ./library/test/test_input.txt | ./library/test/RobotTest --log_level=message

