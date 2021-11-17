
#include <iostream>
#include <regex>

#include "CinInput.h"

using namespace std;

namespace
{

string cstrRegEx = "(PLACE) ([0-9]*),([0-9]*),(EAST|WEST|SOUTH|NORTH)";
string cstrRegExCmd = "MOVE|LEFT|RIGHT|REPORT";

// Mapping of command strings into enumerations
const string cstrMOVE = "MOVE";
const string cstrLEFT = "LEFT";
const string cstrRIGHT = "RIGHT";
const string cstrREPORT = "REPORT";

typedef map < string, ECommand > MapStringToCmd_t;

MapStringToCmd_t MapToCommandMapping
{
    { cstrMOVE, ECommand::MOVE },
    { cstrLEFT, ECommand::LEFT },
    { cstrRIGHT, ECommand::RIGHT },
    { cstrREPORT, ECommand::REPORT }
};

typedef MapStringToCmd_t::const_iterator CiMapStringToCmd_t;

CiMapStringToCmd_t StrItCmdEnd = MapToCommandMapping.end();

bool StringToCmd( const std::string& Cmd, ECommand* pCmd )
{
    if ( !pCmd )
    {
        return false;
    }

    CiMapStringToCmd_t itFound = MapToCommandMapping.find( Cmd );

    // If found
    if ( StrItCmdEnd != itFound )
    {
        *pCmd = itFound -> second;

        return true;
    }

    return false;
}

};

CinInput::CinInput() : m_spBoardModel( nullptr ), m_rePlacing( cstrRegEx ),
    m_reCommand( cstrRegExCmd )
{
}

bool CinInput::GetInputLine( string* pLine ) noexcept
{
    if ( !pLine )
    {
        return false;
    }

    if ( !m_spBoardModel.get() )
    {
        return false;
    }

    string strInput;

    getline( cin, strInput );

    if ( strInput.empty() )
    {
        return false;
    }

    

    smatch sm;

    // Check if we have a command
    if ( regex_match( strInput, sm, m_reCommand ) )
    {
        if ( sm.size() != 1 )
        {
            return false;
        }
        
        ECommand eCmd;

        if ( StringToCmd( sm[ 0 ], &eCmd ) )
        {
            m_spBoardModel -> ExecCommand( eCmd );

            // TODO
        }
        

        
    }
    else if ( regex_match( strInput, sm, m_rePlacing ) ) // Check if we have a placing
    {

        /*
        for ( auto& strng : sm )
        {
            cout << strng << endl;
        }
        */
        
    }
    
    
    // TODO: read line implementation

    

    // TODO: process line implementation
    
    return false;
}

void CinInput::SetBoard( const SpBoardModel_t& spBoard ) noexcept
{
    m_spBoardModel = spBoard;
}
