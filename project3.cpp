/* 
Name: Louis Cerda and Finn Dugan
Class: CPSC 122 Section 1
Date: 1.24.22
Assignment: Project 3
Description: converts command line arguments into integers 
*/

#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

int atoiMy (char* str);

int main(int argc, char* argv[])
{

    ofstream outFile;
    outFile.open(argv[argc-1]);


    int num1 = atoiMy(argv[1]);
    int num2 = atoiMy(argv[2]);
    int sum = num2 * num1;


    outFile << sum;
    outFile.close();




    return 0;
}



/* 
    Description: Transforms a digit string stored as a c-string to an int. 
    Input: c-string containing  digits
    Returns: integer value of the digit string
*/

int atoiMy (char* str)
{
    int value = 0;
    for (int i =0; str[i] != '\0';++i)
    {
        value = value * 10 + str[i] - '0';
    }
    return value;
}