#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

ListD::ListD()
{
 InitializeVars();
}

ListD::ListD(ListD* lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

void ListD::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

//how would you do this?
ListD::~ListD()
{
    doubleNode* cur = head;
    while(cur != NULL)
    {
        doubleNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

// doubleNode* ListD::FindPosition(int pos)
// {
//  //Inserting at the tail is a special case.  It can be made much more efficient than
//  //this.
//  doubleNode* cur = head;
//  int i = 0;  //begin at the dummy node
//  if ( pos > 0)
//  {
//     while (i < pos - 1)
//     {
//     cur = cur->next;
//     i++;
//     }
//  return cur;
// } 

doubleNode* ListD::FindPosition(int pos)
{
    Node* temp = head;
    int pass = 0;

    while (temp->data != pos && temp->next != NULL) 
    {
        pos++;
        temp = temp->next;
    }
    return (pos + 1);
} 

  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

void ListD::Delete(int pos)
{
 doubleNode* deletePt = FindPosition(pos);
 doubleNode* deletePtPrev = deletePt->prev;
 doubleNode* deletePtNext = deletePt->next;

 deletePtPrev->next = deletePtNext;
 deletePtNext->prev = deletePtPrev;

 delete deletePt;
 length--;
}

int ListD::DeleteAll(itemType item)
{
    doubleNode* cur = head->next;
    int count = 0;
    while (cur != tail)
    {
        if (cur->item == item)
        {
            doubleNode* temp = cur;
            cur = cur->next;
            delete temp;
            count++;
            length --;
        }
        else
        {
            cur = cur->next;
        }
    }
    return count;
}

void ListD::PrintForward()
{
    doubleNode* cur = head->next;
    int i = 0;
    while (i < length)
    {
        cout << cur->item << endl;
        cur = cur->next;
        i++;
    }
}

void ListD::Sort()
/*
   pre:  ListD exists
   post: Nodes in the list are in ascending order.  The algorithm used
         to put nodes in order is selection sort. Use the functions
	 found here: .../C-Search-Sort/1-selectionSort.cpp 
   */
{
    doubleNode* cur = head->next;
    doubleNode* min;
    doubleNode* minPrev;
    doubleNode* minNext;
    doubleNode* temp;
    doubleNode* tempPrev;
    doubleNode* tempNext;
    int i = 0;
    while (i < length)
    {
        min = cur;
        minPrev = cur->prev;
        minNext = cur->next;
        cur = cur->next;
        i++;
        while (cur != tail)
        {
            if (cur->item < min->item)
            {
                min = cur;
                minPrev = cur->prev;
                minNext = cur->next;
            }
            cur = cur->next;
        }
        temp = min;
        tempPrev = minPrev;
        tempNext = minNext;
        minPrev->next = minNext;
        minNext->prev = minPrev;
        tempPrev->next = temp;
        temp->prev = tempPrev;
        temp->next = tempNext;
        tempNext->prev = temp;
        cur = temp;
    }
}



// deleteall needs fixing 