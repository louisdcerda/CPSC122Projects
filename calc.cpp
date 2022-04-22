#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
    inFix = new char[strlen(argvIn) + 1];
    strcpy(inFix, argvIn);
    if(!CheckTokens())
    {
        cout << "Error: Invalid input" << endl;
        exit(EXIT_FAILURE);
    }
    //CheckParens
    if(!CheckParens())
    {
        cout << "Error: Invalid input" << endl;
        exit(EXIT_FAILURE);
    }

    //MakeValueTbl
    MakeValueTbl();
    //Parse
    Parse();
}

Calc::~Calc()
{
    stk->~Stack();
    valueIdx = 0;
    delete [] valueTbl;
    delete [] inFix;
}




bool Calc::CheckTokens()
{
    for(int i = 0; i < strlen(inFix); i++)
    {
        if(inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/' || inFix[i] == '^' || inFix[i] == '(' || inFix[i] == ')')
        {
            continue;
        }
        else if(inFix[i] >= 'A' && inFix[i] <= 'Z')
        {
            continue;
        }
        else if(inFix[i] >= '0' && inFix[i] <= '9')
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

void Calc::MakeValueTbl()
{
    //26 position valueTbl is dyanically allocated and filled with zeroes  
    //valueIdx is set to 0
    valueTbl = new int[26];
    valueIdx = 0;
    for(int i = 0; i < 26; i++)
    {
        valueTbl[i] = 0;
    }

}

void Calc::Parse()
{
    //1. space for inFix expression is dynamically allocated 
    char* inFixCopy = new char[strlen(inFix) + 1];
    strcpy(inFixCopy, inFix);
    //2. inFixCopy is copied to inFix
    strcpy(inFix, inFixCopy);
    //3. inFixCopy is deleted
    delete [] inFixCopy;
    //4. inFix is parsed
    for(int i = 0; i < strlen(inFix); i++)
    {
        if(inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' || inFix[i] == '/' || inFix[i] == '^')
        {
            stk->Push(inFix[i]);
        }
        else if(inFix[i] >= 'A' && inFix[i] <= 'Z')
        {
            stk->Push(inFix[i]);
        }
        else if(inFix[i] >= '0' && inFix[i] <= '9')
        {
            stk->Push(inFix[i]);
        }
        else if(inFix[i] == '(')
        {
            stk->Push(inFix[i]);
        }
        else if(inFix[i] == ')')
        {
            while(stk->Peek() != '(')
            {
                stk->Pop();
            }
            stk->Pop();
        }
    }
    //5. while the stack is not empty, pop the stack and push the popped value to the output stack
    while(!stk->IsEmpty())
    {
        stk->Pop();
    }
}


bool Calc::CheckParens()
{
    int leftParens = 0;
    int rightParens = 0;
    for(int i = 0; i < strlen(inFix); i++)
    {
        if(inFix[i] == '(')
        {
            leftParens++;
        }
        else if(inFix[i] == ')')
        {
            rightParens++;
        }
    }
    if(leftParens == rightParens)
    {
        return true;
    }
    else
    {
        return false;
    }
}



void Calc::DisplayInFix()
{
    cout << inFix << endl;
}
