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
    SpBoardModel_t m_spBoard;

    CinInput m_objInput;
};

RobotTests::RobotTests()
{
    m_spBoard = make_shared < CSquareBoard > ();

    m_objInput.SetBoard( m_spBoard );
}

BOOST_FIXTURE_TEST_SUITE( Robot, RobotTests )

BOOST_AUTO_TEST_CASE( TestValidRobotMovements )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestValidRobotMovements" );
    
    int iCount = 0;

    string strLine = "";

    while ( m_objInput.GetInputLine( &strLine ) )
    {
        ++iCount;

        if ( !strLine.empty() )
        {
            BOOST_CHECK_EQUAL( strLine, "0,1,NORTH" );
        }
    }

    BOOST_CHECK_EQUAL( iCount, 3 );

} // BOOST_AUTO_TEST_CASE( TestValidRobotMovements )

BOOST_AUTO_TEST_CASE( TestValidRobotMovements_2 )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestValidRobotMovements_2" );
    
    int iCount = 0;

    string strLine = "";

    while ( m_objInput.GetInputLine( &strLine ) )
    {
        ++iCount;

        if ( !strLine.empty() )
        {
            BOOST_CHECK_EQUAL( strLine, "0,0,WEST" );
        }
    }

    BOOST_CHECK_EQUAL( iCount, 3 );

} // BOOST_AUTO_TEST_CASE( TestValidRobotMovements_2 )

BOOST_AUTO_TEST_CASE( TestValidRobotMovements_3 )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestValidRobotMovements_3" );
    
    int iCount = 0;

    string strLine = "";

    while ( m_objInput.GetInputLine( &strLine ) )
    {
        ++iCount;

        if ( !strLine.empty() )
        {
            BOOST_CHECK_EQUAL( strLine, "3,3,NORTH" );
        }
    }

    BOOST_CHECK_EQUAL( iCount, 6 );

} // BOOST_AUTO_TEST_CASE( TestValidRobotMovements_3 )


BOOST_AUTO_TEST_CASE( TestRobotMovementsHitNorthBorder )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestRobotMovementsHitNorthBorder" );
    
    int iCount = 0;

    string strLine = "";

    while ( m_objInput.GetInputLine( &strLine ) )
    {
        ++iCount;

        if ( !strLine.empty() )
        {
            BOOST_CHECK_EQUAL( strLine, "0,4,NORTH" );
        }
    }

    BOOST_CHECK_EQUAL( iCount, 6 );

} // BOOST_AUTO_TEST_CASE( TestRobotMovementsHitNorthBorder )

BOOST_AUTO_TEST_CASE( TestRobotMovementsHitEastBorder )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestRobotMovementsHitEastBorder" );
    
    int iCount = 0;

    string strLine = "";

    while ( m_objInput.GetInputLine( &strLine ) )
    {
        ++iCount;

        if ( !strLine.empty() )
        {
            BOOST_CHECK_EQUAL( strLine, "4,0,EAST" );
        }
    }

    BOOST_CHECK_EQUAL( iCount, 7 );

} // BOOST_AUTO_TEST_CASE( TestRobotMovementsHitEastBorder )

BOOST_AUTO_TEST_CASE( TestRobotNotFallingOverNorthBorder )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestRobotNotFallingOverNorthBorder" );
    
    int iCount = 0;

    string strLine = "";

    while ( m_objInput.GetInputLine( &strLine ) )
    {
        ++iCount;
    }

    BOOST_CHECK_EQUAL( iCount, 5 );

    BOOST_REQUIRE( m_objInput.GetInputLine( &strLine ) );

    if ( !strLine.empty() )
    {
        BOOST_CHECK_EQUAL( strLine, "0,4,NORTH" );
    }

} // BOOST_AUTO_TEST_CASE( TestRobotNotFallingOverNorthBorder )

BOOST_AUTO_TEST_CASE( TestRobotNotFallingOverWestBorder )
{
    cout << endl;
    BOOST_TEST_MESSAGE( "TestRobotNotFallingOverWestBorder" );

    int iCount = 0;

    string strLine = "";

    while ( m_objInput.GetInputLine( &strLine ) )
    {
        ++iCount;
    }

    BOOST_CHECK_EQUAL( iCount, 3 );

    BOOST_REQUIRE( m_objInput.GetInputLine( &strLine ) );

    if ( !strLine.empty() )
    {
        BOOST_CHECK_EQUAL( strLine, "0,0,WEST" );
    }

} // BOOST_AUTO_TEST_CASE( TestRobotNotFallingOverWestBorder )

BOOST_AUTO_TEST_SUITE_END()

} // namespace Robot
