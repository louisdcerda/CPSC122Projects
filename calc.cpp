#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
    //initialize variables
    InitializeVars();
    //check for valid input
    if(!CheckTokens())
    {
        cout << "Invalid input.  Terminating program." << endl;
        exit(EXIT_FAILURE);
    }
    //create value table
    MakeValueTbl();
    //parse input
    Parse();
    //check for balanced parentheses
    if(!CheckParens())
    {
        cout << "Unbalanced parentheses.  Terminating program." << endl;
        exit(EXIT_FAILURE);
    }
}

Calc::~Calc()
{
    //delete dynamically allocated memory
    delete [] valueTbl;
    delete [] infix;
    delete [] postfix;
}

bool Calc::CheckTokens()
{
    int length = 0;
    for( int i = 0; i < argv[1].length(); i ++)
    {
        if ( argv[1][i] == '(' or argv[1][i] == ')' )
            length++;
        else if (argv[1].isalpha() and argv[1].isupper())
            length++;
        else if (argv[1][i] == '+' or argv[1][i] == '-')
            length++;
        else if (argv[1][i] == '*' or argv[1][i] == '/')
            length ++;
        for ( int k = 0; k < 10; i++)
        {
            if( argv[1][i] == k )
                length ++;
        }
    }

    if (length == argv[1].length())
        return true;
    return false;
}

void Calc::MakeValueTbl()
{
    char* table = new char[26];
    valueIdx = 0;
    for (int i = 0; i < 26; i++)
        table[i] = 0;
}

void Calc::Parse()
{
    
}

bool Calc::CheckParens()
{
    int left = 0;
    int right = 0;
    for ( int i = 0; i < argv[1].length(); i++)
    {
        if ( argv[1][i] == '(')
            left++;
        else if ( argv[1][i] == ')')
            right++;
    }
    if ( left == right)
        return true;
 return false;
}

void Calc::DisplayInFix()
{

}
