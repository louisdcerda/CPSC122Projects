#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

//All tests are separated by function
void TestInsert();
void TestCopyConstructor();

int main()
{
 TestInsert();
 //TestCopyConstructor();
//  PrintBackwards();
//  deleteall();
//  sortysort();
}



void TestInsert()
{

 ListD<int>* lst = new ListD<int>;
 for (int i = 1; i <= 5; i++)
  lst->Insert(i,i);
 lst->PrintForward();

 //test general case insert
 cout << "Passed Insert Test 1 if 1 through 5 appear on subsequent lines" << endl;
 lst->PrintForward();
 cout << endl;

 //test insert at the head
 lst->Insert(0,1);
 cout << "Passed Insert Test 2 if 0 appears in position 1" << endl; 
 lst->PrintForward();
 cout << endl;

 //test insert at the tail 
 lst->Insert(100,7);
 cout << "Passed Insert Test 3 if 100 appears in final position" << endl; 
 lst->PrintForward();
 cout << endl;
 
 //test insert in middle 
 lst->Insert(50,5);
 cout << "Passed Insert Test 4 if 50 appears in middle position" << endl; 
 lst->PrintForward();
 cout << endl;
 delete lst;
}

// void TestCopyConstructor()
// {
//  ListD<int>* lst1 = new ListD<int>;
//  for (int i = 1; i <= 3; i++)
//   lst1->Insert(i,i);

//  ListD<int>* lst2(lst1);
 
//  cout << "Traverse lst1" << endl;
//  lst1->PrintForward();
//  cout << endl;
//  cout << "Traverse lst2" << endl;
//  lst2->PrintForward();

//  //delete lst1;
//  //delete lst2;
// }



// void PrintBackwards()
// {
//  ListD<int>* lst1 = new ListD<int>;
//  for (int i = 1; i <= 3; i++)
//   lst1->Insert(i,i);
 
//  cout << "Traverse lst1 backwards" << endl;
//  lst1->PrintBackward();
//  cout << endl;

//  delete lst1;
// }



// void deleteall()
// {
//  ListD<int>* lst = new ListD<int>;
//  for (int i = 1; i <= 7; i++)
//   lst->Insert(i,i);
// lst->PrintForward();

//  cout << "All nodes containing instances of 3 have been deleted" << endl;
//  lst->DeleteAll(3);
//  cout << endl;
// lst->PrintForward();
//  cout << endl;
//  cout << "All nodes containing instances of 4 have been deleted" << endl;
//  lst->DeleteAll(4);
// lst->PrintForward();

//  delete lst1;
// }



// void sortysort()
// {
//  ListD<int>* lst1 = new ListD<int>;
//  lst1->Insert(100,1);
//  lst1->Insert(27,2);
//  lst1->Insert(98,3);
//  lst1->Insert(99,4);
//  lst1->Insert(1,5);
//  lsst1->PrintForward();
//  cout << "All nodes containing instances of 3 have been deleted" << endl;
//  lst1->Sort();
//  cout << endl;
//  lst->PrintForward();
//  delete lst1;
// }







//  Write PrintBackward.  Compile/test your work. // done
// 2. Write Delete.  Compile/test your work.
// 3. Write the Destructor.  Compile/test your work.
// 4. Write DeleteAll.  Compile/test your work.
// 5. Write Sort. Compile/test your work.
