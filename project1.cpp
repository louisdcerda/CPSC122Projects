/* 
Name: louis cerda
Class: CPSC 122 Section 1
Date: 1.21.22
Assignment: Project 1
Description: ask the user for how many prime numbers they would like to see and in how many columns
*/

#include <iostream>
using namespace std;

bool isPrime (int prime);
void display ( int totalPrimes, int cols);
void errorChecking (int errorNum);

int main(int argc, char* argv[])
{
    int numbers = atoi(argv[1]);
    int columns = atoi(argv[2]);

    if (numbers < 1)
        errorChecking(1);
    if (columns < 1)
        errorChecking(2);
    display(numbers, columns);


    return 0;
}

/*
    Description: Determines whether input integer is prime
    Input: integer whose primality is to be judged
    Returns: true if num is prime, false otherwise
*/ 

bool isPrime (int prime)
{
    for (int i = 2; i < prime; i ++)
    {
        if ( prime % i == 0)
            return false;
    }
    return true;
}

/*
    Description:  over all necessary candidatLoopse primes, invoking isPrime on each, 
	displaying in column fashion those that are prime
    input: integer totalPrimes, indicating the number of primes to display; integer 
	cols, indicating over how many columns the primes are to be displayed
*/

void display ( int totalPrimes, int cols )
{
    int ct = 0;
    int value = 2;
    while (ct < totalPrimes)
    {
        if (isPrime(value) == true)
        {
            cout << value << '\t';
            ct++;
        }
        value++;
        if (ct % cols == 0)
            cout << endl;
        
    }
}

/*
    Description: error checks using a switch case to display the appropirate message
    input: the ineger errorNum, which is used in the switch case
*/

void errorChecking (int errorNum)
{
    switch (errorNum)
    {
        case 1: cout << "Numbers displayed must be >= 1" << endl; exit(0);
        case 2: cout << "Number of columns must be >= 1" << endl; exit(0);
    }
}