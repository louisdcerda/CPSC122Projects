#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char* argv[])
{
    //testing calc
 Calc* C = new Calc(argv[1]);
 C->DisplayInFix();
 C->~Calc();


 delete C;
 return 0;
}
