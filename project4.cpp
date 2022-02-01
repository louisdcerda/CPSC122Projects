/* 
Name: louis cerda and Ginn Dugan
Class: CPSC 122 Section 1
Date: 1.21.22
Assignment: Project 4
Description:
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


void fileOpen(fstream&, string name, char mode);
char encrypt(char ch, int key);
char decrypt(char ch, int key);
int keyGen();

int main (int argc, char* argv[])
{

    int value = atoi(argv[1]);9

    case (value)
    {
        case 0: keyGen(argv[2]);  // generate the key
        case 1: encrypt(argv[2]); // encrypt plaintext
        case 2: decrypt(argv[2]); // decrypt ciphertext
    }

    return 0;
}




/*
go case by case depending on what argv[1] is 
so change argv[1]  to an integer
then you go into the case swtich loop
and from there you put the funciton that is going to be sued


in the funcitons you can use argv[3][4] inot naming the files 
*/



int keyGen()
{
    int randomNum = rand() % 25;

    return randomNum;
}


char encrypt(char ch, int key)
{

}


char decrypt(char ch, int key)
{

}



void fileOpen(fstream&, string name, char mode)
{
    string fileType;

    if (mode == 'r')
        fileType = "input";
    if (mode == 'w')
        fileType = "output";

    if (mode == 'r')
        file.open(name, ios::in);  //available thorugh fstream
    if (mode == 'w')
        file.open(name, ios::out);  //available through fstream;

    if (file.fail()) //error condition 
    {
        cout << "Error opening " << fileType << " file" << endl; 
        exit(EXIT_FAILURE);
    }

}