#include <iostream>

#include "Board.h"
#include "CinInput.h"

using namespace std;

int main()
{
    SpBoardModel_t spBoard = make_shared < CSquareBoard > ();

    CinInput m_objInput;

    m_objInput.SetBoard( spBoard );

    cout << "Input your command for the robot below. For exit - Ctrl-C:" << endl;

    string strLine = "";

    do
    {
        if ( m_objInput.GetInputLine( &strLine ) )
        {
            if ( !strLine.empty() )
            {
                cout << "Output: " << strLine << endl;
                strLine = "";
            }
        }
        
    } while ( true );
    
    return 0;
}
