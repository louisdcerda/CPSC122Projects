#include <iostream>
using namespace std;

#include "8-MyString.h"
#include <cstring>

//Constructor
MyString::MyString(char const* strIn)
{
    int index = 0;

    while(strIn[index] != '\0')
    {
        length = index;
        index++;
    }

    str = new char[length + 1];

    for(int i = 0; i < length + 1; i++)
    {
        str[i] = strIn[i];
    }

    str[index] = '\0';
}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
    delete []str; 
}

void MyString::myDisplay()
{
    cout << str << endl;
}

void MyString::myStrcpy(char const* strIn)
{
    int index = 0;

    while(strIn[index] != '\0')
    {
        length = index;
        index++;
    }

    str = new char[length + 1];

    for(int i = 0; i < length; i++)
        str[i] = strIn[i];

    str[index] = '\0';
}

int MyString::myStrlen()
{
    return length;
    //ask DePalma
}

int MyString::myStringlen(char const* strIn)
{
    int index = 0;

    while(strIn[index] != '\0')
    {
        index++;
    }
    
    return index;
}

bool MyString::isEqual(char const* strIn)
{
    int index = 0;

    while(index < (length + 1))
    {
        if(str[index] != strIn[index])
        {
            return false;
        }

        index++;
    }

    return true;
}

int MyString::find(char const* strIn)
{
    int strInLength = myStringlen(strIn);
    
    if(strInLength > length)
    {
        return -1;
    }
    else if(strInLength == length)
    {
        if(isEqual(strIn))
            return 0;
        else
            return -1;
    }
    else
    {
        for(int i = 0; i < length - strInLength + 1; i++)
        {
            if(isSub(strIn, i))
            {
                return i;
            }
        }
    }
    return -1;
}

void MyString::concat(char const* strIn)
{
    int strInLength = myStringlen(strIn);

    char* temp = new char[length + strInLength + 1];

    for(int i = 0; i < length; i++)
    {
        temp[i] = str[i];
    }
    
    for(int i = 0; i < strInLength; i++)
    {
        temp[length + i] = strIn[i];
    }

    temp[length + strInLength] = '\0';

    str = temp;
}

bool MyString::isSub(char const* strIn, int idx)
{
    int len = 0;
    while(strIn[len] != '\0')
    {
        len++;
    }

    for(int i = 0; i < len; i++)
    {
        if(str[idx + i] != strIn[i])
            return false;
    }

    return true;
}