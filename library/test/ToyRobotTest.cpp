#define BOOST_TEST_MODULE Robot test

#include <iostream>
#include <boost/test/included/unit_test.hpp>

#include "Board.h"
#include "CinInput.h"

using namespace std;

namespace Robot
{

// This class sets up the necessary prerequisites for a unit test
class RobotTests
{
public:

    RobotTests();


    // This is the code under test
    CSquareBoard m_objBoard;

    CinInput m_objINput;

};

RobotTests::RobotTests()
{
}

BOOST_FIXTURE_TEST_SUITE( Robot, RobotTests )

BOOST_AUTO_TEST_CASE( TestValidRobotMovements )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestValidRobotMovements\n" );
    

} // BOOST_AUTO_TEST_CASE( TestValidRobotMovements )



BOOST_AUTO_TEST_SUITE_END()

} // namespace Robot
