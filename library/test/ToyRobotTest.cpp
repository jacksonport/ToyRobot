#define BOOST_TEST_MODULE Robot test

#include <iostream>
#include <boost/test/included/unit_test.hpp>

#include "Board.h"
#include "CinInput.h"

using namespace std;

namespace Robot
{

struct SOrderTraded
{
    int m_orderId;
    int m_tradedPrice;
    uint32_t m_tradedQuantity;

    SOrderTraded( int orderId, int tradedPrice, uint32_t tradedQuantity );
};

SOrderTraded::SOrderTraded( int orderId, int tradedPrice, uint32_t tradedQuantity ) :
m_orderId( orderId ), m_tradedPrice( tradedPrice ), m_tradedQuantity( tradedQuantity )
{
}

struct SBestPriceChanged
{
    string m_instrument;
    int m_bidPrice;
    uint32_t m_bidTotalQuantity;
    int m_askPrice;
    uint32_t m_askTotalQuantity;

    SBestPriceChanged( const string& instrument, int bidPrice, uint32_t bidTotalQuantity,
                       int askPrice, uint32_t askTotalQuantity );
};

SBestPriceChanged::SBestPriceChanged( const string& instrument, int bidPrice, uint32_t bidTotalQuantity,
                   int askPrice, uint32_t askTotalQuantity ) : m_instrument( instrument ), m_bidPrice( bidPrice ),
    m_bidTotalQuantity( bidTotalQuantity ), m_askPrice( askPrice ), m_askTotalQuantity( askTotalQuantity )
{
}

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
