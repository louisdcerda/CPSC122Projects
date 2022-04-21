#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
}

Calc::~Calc()
{
}

bool Calc::CheckTokens()
{
    string mathOps = argv[1];
    int length = 0;
    for( int i = 0; i < mathOps.len(); i ++)
    {
        if ( mathOps[i] == '(' or mathOps[i] == ')' )
            length++;
        else if (mathOps[i].isalpha() and mathOps[i].isupper())
            length++;
        else if (mathOps[i] == '+' or mathOps[i] == '-')
            length++;
        else if (mathOps[i] == '*' or mathOps[i] == '/')
            length ++;
        for ( int k = 0; k < 10; i++)
        {
            if( mathOps[i] == k )
                length ++;
        }
    }

    if (length == mathOps.len())
        return true;
    return false;
}

void Calc::MakeValueTbl()
{

}

void Calc::Parse()
{
    
}

bool Calc::CheckParens()
{
 return true;
}

void Calc::DisplayInFix()
{}
