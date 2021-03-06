#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{

    stk = new Stack();

    for (int i = strlen(argvIn); i >= 0; i--)
    {
        stk->Push(argvIn[i - 1]);
    }


    
    if(!CheckTokens())
    {
        cout << "Error: Invalid input" << endl;
        exit(EXIT_FAILURE);
    }

    MakeValueTbl();
    Parse();


    //CheckParens
    if(!CheckParens())
    {
        cout << "Error: Invalid input" << endl;
        exit(EXIT_FAILURE);
    }
}

Calc::~Calc()
{
    delete stk;
    valueIdx = 0;
    delete valueTbl;
    delete inFix;
}

bool Calc::CheckTokens()
{
    Stack* temp = new Stack();
    while (stk->Peek() != 0)
    {
        temp->Push(stk->Peek());
        stk->Pop();
    }

    while(temp->IsEmpty() != true)
    {
        if(temp->Peek() < 40 || temp->Peek() > 90 || temp->Peek() == 44 || temp->Peek() == 46 || temp->Peek() == 63 || temp->Peek() == 64)
            return false;
        stk->Push(temp->Peek());
        temp->Pop();
        }
    return true;   
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

void Calc::Parse()
{
    int len = stk->GetLength();
    inFix = new char[len + 1];
    char* temp = new char[len + 1];
    int index = 0;
    int index1 = 0;
    int index2 = 0;

    for (int i = 0; stk->Peek() != 0; i++)
    {
        inFix[i] = char(stk->Peek());
        stk->Pop();
    }

    while (index < len)
    {
        if ((int(inFix[index]) >= 48) && (int(inFix[index]) <= 57))
        {
            index1 = FindLast(index);

            string cat = " ";

            while (index <= index1)
            {
                cat.push_back(inFix[index]);
                index++;
            }

            valueTbl[valueIdx] = stoi(cat);
            temp[index2] = char(valueIdx + 65);
            index2++;
            valueIdx++;
        }
        else
        {
            temp[index2] = inFix[index];
            index2++;
            index++;
        }

        for  (int i = 0; i < index2; i++)
        {
            inFix[i] = temp[i];
        }
        inFix[index2 - 1] = '\0';
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
 return true;
}

void Calc::DisplayInFix()
{
     for (int i = 0; inFix[i] != '\0'; i++)
    {
        cout << inFix[i];
    }
    cout << endl;
}


int Calc::FindLast(int index)
{
    while ((int(inFix[index]) >= 48) && (int(inFix[index]) <= 57))
    {
        index++;
    }
    return index - 1;
}