/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: N/A 
Description: Program illustrates using class MyString 
*/

#include "8-MyString.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
    MyString str1(argv[1]);
    MyString* str2 = new MyString(argv[1]);

//Test of myDisplay
    cout << "***************************************" << endl;
    cout << "*****Test 1 myDisplay*****" << endl;
    cout << "Static test" << endl;
    cout << "Output should be the command line input" << endl;
    str1.myDisplay();
    cout << endl;
    cout << "*****Test 2  myDisplay*****" << endl;
    cout << "Dynamic test" << endl;
    cout << "Output should be the command line input" << endl;
    str2->myDisplay();
    cout << endl;
    cout << "***************************************" << endl;
//End Test of myDisplay

//Test of myStrcpy
    // cout << "***************************************" << endl;
    // cout << "*****Test 1 myStrcpy*****" << endl;
    // cout << "Static test" << endl;
    // cout << "Output should be the command line input" << endl;
    // str1.myDisplay();
    // str1.myStrcpy("Static test successful");
    // str1.myDisplay();
    // cout << endl;
    // cout << "*****Test 2  myStrcpy*****" << endl;
    // cout << "Dynamic test" << endl;
    // cout << "Output will be a sucess or failure of test" << endl;
    // str2 -> myDisplay();
    // str2 -> myStrcpy("Dynamic test successful");
    // str2 -> myDisplay();
    // cout << endl;
    // cout << "***************************************" << endl;
//End Test of myStrcpy

//Test of myStrlen
    // cout << "***************************************" << endl;
    // cout << "*****Test 1 myStrlen*****" << endl;
    // cout << "Static test" << endl;
    // cout << "Output should be the length of string" << endl;
    // str1.myDisplay();
    // cout << "The length of string 1 is: " << str1.myStrlen();
    // str1.myDisplay();
    // cout << endl;
    // cout << "*****Test 2  myStrlen*****" << endl;
    // cout << "Dynamic test" << endl;
    // cout << "Output will be the length of string" << endl;
    // str2 -> myDisplay();
    // cout << "The length of string 2 is: " << str2 -> myStrlen();
    // cout << endl;
    // cout << "***************************************" << endl;
//End Test of myStrlen

//Test of isEqual 
    // cout << "***************************************" << endl;
    // cout << "*****Test 1 isEqual*****" << endl;
    // cout << "Static test" << endl;
    // cout << "Output should be success or failure of isEqual function" << endl;
    // str1.myDisplay();
    // if(str1.isEqual(argv[1]))
    //     cout << "Both strings are equal.";
    // else 
    //     cout << "Static test unsuccessful. ";
    // cout << endl;
    // cout << "*****Test 2  isEqual*****" << endl;
    // cout << "Dynamic test" << endl;
    // cout << "Output should be success or failure of isEqual function" << endl;
    // if(str2 -> isEqual(argv[1]))
    //     cout << "Both strings are equal.";
    // else 
    //     cout << "Dynamic test unsuccessful. ";
    // cout << endl;
    // str2->myDisplay();
    // cout << endl;
    // cout << "***************************************" << endl;
//End test of isEqual

//Test of find
    // cout << "***************************************" << endl;
    // cout << "*****Test 1 find*****" << endl;
    // cout << "Static test" << endl;
    // cout << "Output is the index of the first occurance of h of the command line input";
    // str1.myDisplay();
    // if(str1.find("h") > -1)
    //     cout << "The starting index of the substring is at: " << str1.find("h");
    // else   
    //     cout << "There was no substring found";
    // cout << endl;
    // cout << "*****Test 2  myStrlen*****" << endl;
    // cout << "Dynamic test" << endl;
    // cout << "Output will be a sucess or failure of test" << endl;
    // str2 -> myDisplay();
    // cout << "The length of string 2 is: " << str2 -> find("h");
    // cout << endl;
    // cout << "***************************************" << endl;
//End Test of find

//Test of concat
    // cout << "***************************************" << endl;
    // cout << "*****Test 1 concat*****" << endl;
    // cout << "Static test" << endl;
    // cout << "Output should be the commad line input" << endl;
    // str1.myDisplay();
    // str1.concat(", Static Test sucessful");
    // cout << endl;
    // str1.myDisplay();
    // cout << endl;
    // cout << "*****Test 2  concat*****" << endl;
    // cout << "Dynamic test" << endl;
    // cout << "Output will be a sucess or failure of test" << endl;
    // str2 -> myDisplay();
    // str2 -> concat(", Dynamic test successful");
    // str2 -> myDisplay();
    // cout << endl;
    // cout << "***************************************" << endl;
//End Test of concat

delete str2;
return 0;  
}