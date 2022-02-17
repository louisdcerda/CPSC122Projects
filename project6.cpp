/*
Name: Finn Dugan and Louis Cerda
Class: CPSC 122 Section 1
Date: 2.15.22
Assignment: Project 6
Description: Encrypts a text file using the transformation cipher 
*/

#include <iostream>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

void fileOpen(fstream&, string, char);
void fileControl(string keyFile, string fileIn, string fileOut, int mode);
void keyGen(string);
char transform(char, int encDec[26][2]);
void mysterySort(int(&matrix)[26][2]);

/*
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/

void keyGen(string keyFileName)
{
    int key[26];
    bool validate[26] = {false};
    int pos = 0;

    fstream keyFile;
    fileOpen(keyFile, keyFileName, 'w');

    while(pos < 26)
    {
        while(true)
        {
            int k = rand() % 26;
            if(validate[k] == false)
            {
                key[pos] = k;
                validate[k] = true;
                pos++;
                break;
            }
        }
    }

    for(int i = 0; i < 26; i++)
    {
        keyFile << i << ' ' << key[i] << endl;
    }
}

/*
Description: function opens a file
Input: file stream object reference, name of the file, mode of open
Output: input file name is opened. 
*/

void fileOpen(fstream& file, string name, char mode)
//void fileOpen(fstream& file, char name[], char mode)
{
    string fileType;

    if(mode == 'r')
        fileType = "input";
    if(mode == 'w')
        fileType = "output";

    if(mode == 'r')
        file.open(name, ios::in);  //available thorugh fstream
    if(mode == 'w')
        file.open(name, ios::out);  //available through fstream;

    if(file.fail()) //error condition 
    {
        cout << "Error opening " << fileType << " file" << endl; 
        exit(EXIT_FAILURE);
    }
}

/*
Description: Processes files, invokes function to encrypt/decrypt characters
1. Reads key file. Constructs  arrays for encryption and decryption.  The decryption array is sorted as explained above.  Use the function, MysterySort, described below to do the sorting.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to be encrypted/decrypted and a reference to  the encrypt or decrypt array, depending on the mode.
5.  Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/

void fileControl(string keyFileName, string fileInName, string fileOutName, int mode)
{
    fstream keyFile, fileIn, fileOut;
    fileOpen(keyFile, keyFileName, 'r');

    int encDec[26][2];
    string input = "";
    for(int i = 0; i < 26; i++)
        {
            keyFile >> encDec[i][0];
            keyFile.get();
            keyFile >> encDec[i][1];
            getline(keyFile, input);
        }

    if(mode == 1)
    {
        fileOpen(fileIn, fileInName, 'r');
        fileOpen(fileOut, fileOutName, 'w');

        while(fileIn.peek() != EOF)
        {
            getline(fileIn, input);
            
            for(int i = 0; i < input.length(); i++)
            {
                fileOut << transform(input[i], encDec);
            }
            
            fileOut << endl;
        }
    }

    if(mode == 2)
    {
        int matrix[26][2];

        fileOpen(fileIn, fileInName, 'w');
        fileOpen(fileOut, fileOutName, 'r');

        for(int i = 0; i < 26; i++)
        {
            int num = 1;

            for(int j = 0; j < 2; j++)
            {
                matrix[i][j] = encDec[i][num];
                num--;
            }
        }

        mysterySort(matrix);

        while(fileOut.peek() != EOF)
        {
            getline(fileOut, input);

            for(int i = 0; i < input.length(); i++)
            {
                fileIn << transform(input[i], matrix);
            }

            fileIn << endl;
        }
    }

    fileOut.close();
    fileIn.close();
}

int main(int argc, char* argv[])
{
    int mode = atoi(argv[1]);

    if(mode == 0)
    {
        keyGen(argv[2]);
    }
    if(mode == 1 || mode == 2)
    {
        fileControl(argv[2], argv[3], argv[4], mode);
    }
    return 0;
}

/*
Description: Algorithm to sort the key array. Invoked within keyGen
Input: 26 position 2-D array, K, of integers with columns 0 and 1
Output: an array k’, where col 0 is the sorted version of col 1.   The original column 1 is taken along for the ride.  See the sorting instructions above. 
*/

void mysterySort(int(&matrix)[26][2])
{
    for(int i = 0; i < 26; i++)
    {
        bool swap = false;
        for(int j = 0; j < 25 - i; j++)
        {
            if(matrix[j][0] > matrix[j + 1][0])
            {
                int num0 = matrix[j][0];
                int num1 = matrix[j][1];

                matrix[j][0] = matrix[j+1][0];
                matrix[j][1] = matrix[j+1][1];
                matrix[j+1][0] = num0;
                matrix[j+1][1] = num1;
                swap = true;
            }
        }
        if(!swap)
        {
            break;
        }
    }
}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/

char transform(char ch, int encDec[26][2])
{
    if(ch == ' ')
        return ' ';

    if(islower(ch))
        ch -=32;

    ch -= 65;

    return encDec[ch][1] + 65;
}