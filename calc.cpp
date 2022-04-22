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

    //check for valid input
    for(int i = 0; i < strlen(argvIn); i++)
    {
        if(argvIn[i] == '+' || argvIn[i] == '-' || argvIn[i] == '*' || argvIn[i] == '/' || argvIn[i] == '(' || argvIn[i] == ')')
        {
            continue;
        }
        else if(argvIn[i] >= 'A' && argvIn[i] <= 'Z')
        {
            continue;
        }
        else if(argvIn[i] >= '0' && argvIn[i] <= '9')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}



    // int length = 0;
    // for( int i = 0; i < argv[1].length(); i ++)
    // {
    //     if ( argv[1][i] == '(' or argv[1][i] == ')' )
    //         length++;
    //     else if (argv[1].isalpha() and argv[1].isupper())
    //         length++;
    //     else if (argv[1][i] == '+' or argv[1][i] == '-')
    //         length++;
    //     else if (argv[1][i] == '*' or argv[1][i] == '/')
    //         length ++;
    //     for ( int k = 0; k < 10; i++)
    //     {
    //         if( argv[1][i] == k )
    //             length ++;
    //     }
    // }

    // if (length == argv[1].length())
    //     return true;
    // return false;


}

void Calc::MakeValueTbl()
{
    valueTbl = new int[26];
    for(int i = 0; i < 26; i++)
    {
        valueTbl[i] = 0;
    }
    valueIdx = 0;
}

//     char* table = new char[26];
//     valueIdx = 0;
//     for (int i = 0; i < 26; i++)
//         table[i] = 0;
// }

void Calc::Parse()
{
    char inFix = new char[argv[1].length()];
    char postFix = new char[argv[1].length()];
    int i = 0;
    int j = 0;
    while(i < argv[1].length())
    {
        if(argv[1][i] == '(')
        {
            inFix[j] = argv[1][i];
            j++;
        }
        else if(argv[1][i] == ')')
        {
            inFix[j] = argv[1][i];
            j++;
        }
        else if(argv[1][i] == '+' or argv[1][i] == '-' or argv[1][i] == '*' or argv[1][i] == '/')
        {
            inFix[j] = argv[1][i];
            j++;
        }
        else if(argv[1][i] == 'A' or argv[1][i] == 'B' or argv[1][i] == 'C' or argv[1][i] == 'D' or argv[1][i] == 'E' or argv[1][i] == 'F' or argv[1][i] == 'G' or argv[1][i] == 'H' or argv[1][i] == 'I' or argv[1][i] == 'J' or argv[1][i] == 'K' or argv[1][i] == 'L' or argv[1][i] == 'M' or argv[1][i] == 'N' or argv[1][i] == 'O' or argv[1][i] == 'P' or argv[1][i] == 'Q' or argv[1][i] == 'R' or argv[1][i] == 'S' or argv[1][i] == 'T' or argv[1][i] == 'U' or argv[1][i] == 'V' or argv[1][i] == 'W' or argv[1][i] == 'X' or argv[1][i] == 'Y' or argv[1][i] == 'Z')
            inFix[j] = argv[1][i];
            j++;
        else if(argv[1][i] == '0' or argv[1][i] == '1' or argv[1][i] == '2' or argv[1][i] == '3' or argv[1][i] == '4' or argv[1][i] == '5' or argv[1][i] == '6' or argv[1][i] == '7' or argv[1][i] == '8' or argv[1][i] == '9')
        {
            inFix[j] = argv[1][i];
            j++;
        }
        else
        {
            cout << "Invalid input.  Terminating program." << endl;
            exit(EXIT_FAILURE);
        }
        i++;

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
    cout << "Infix: " << infix << endl;
}
