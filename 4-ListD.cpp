#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template <typename T>
ListD<T>::ListD()
{
 InitializeVars();
}

template <typename T>
void ListD<T>::Insert(T item, int pos)
{
  //new node goes between these two nodes
  doubleNode<T>* insertPtA = FindPosition(pos);  
  doubleNode<T>* insertPtB = insertPtA->next; 

  //create new node and set its values
  doubleNode<T>* tmp = new doubleNode<T>; 
  tmp->prev = insertPtA;
  tmp->item = item;
  tmp->next = insertPtB;

  //set pointers for nodes before and after the insertion point
  insertPtA->next = tmp;
  insertPtB->prev = tmp;

  length++;
}

template<typename T>
void ListD<T>::Delete(int pos)
{
 doubleNode<T>* deletePt = FindPosition(pos);
 doubleNode<T>* deletePtPrev = deletePt->prev;
 doubleNode<T>* deletePtNext = deletePt->next;

 deletePtPrev->next = deletePtNext;
 deletePtNext->prev = deletePtPrev;

 delete deletePt;
 deletePt = NULL;
 deletePtNext = NULL;
  deletePtPrev = NULL;
 length--;
}

template<typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T>*  cur = head->next;

 int i = 1;
 while (i < length + 1)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

template<typename T>
void ListD<T>::PrintBackward()
{
 doubleNode<T>*  cur = tail->prev;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->prev;
  i++;
 }
}

template<typename T>
void ListD<T>::InitializeVars()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
  //Inserting at the tail is a special case.  It can be made much more efficient than
  //this.
  doubleNode<T>* cur = head;
  int i = 0;  //begin at the dummy node
  while (i < pos - 1)
  {
    cur = cur->next;
    i++;
  }
  return cur;
} 

template<typename T>
ListD<T>::~ListD()
{
 doubleNode<T>* cur = head;
 while(cur != NULL)
 {
  doubleNode<T>* temp = cur;
  cur = cur->next;
  delete temp;
 }
}

template<typename T>
ListD<T>::ListD(const ListD<T>* lst)
{
 InitializeVars();
 //returns a pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  //cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template<typename T>
void ListD<T>::Sort()
{   
  //sort the list using insertion sort
  //start at the second node
  doubleNode<T>* cur = head->next;
  while (cur != tail)
  {
    //insert cur->item into the sorted list
    doubleNode<T>* insertPt = head;
    while (insertPt->next->item < cur->item)
    {
      insertPt = insertPt->next;
    }
    //insert cur->item into the sorted list
    doubleNode<T>* tmp = cur->next;
    cur->next = insertPt->next;
    insertPt->next->prev = cur;
    insertPt->next = cur;
    cur->prev = insertPt;
    cur = tmp;
  } 
}
  // doubleNode<T>* cur = head->next;
  // doubleNode<T>* min;
  // doubleNode<T>* minPrev;
  // doubleNode<T>* minNext;
  // doubleNode<T>* temp;
  // doubleNode<T>* tempPrev;
  // doubleNode<T>* tempNext;
  // int i = 0;
  // while (i < length)
  // {
  //   min = cur;
  //   minPrev = cur->prev;
  //   minNext = cur->next;
  //   cur = cur->next;
  //   i++;
  //   while (cur != tail)
  //   {
  //     if (cur->item < min->item)
  //     {
  //       min = cur;
  //       minPrev = cur->prev;
  //       minNext = cur->next;
  //     }
  //     cur = cur->next;
//       }
//       temp = min;
//       tempPrev = minPrev;
//       tempNext = minNext;
//       minPrev->next = minNext;
//       minNext->prev = minPrev;
//       tempPrev->next = temp;
//       temp->prev = tempPrev;
//       temp->next = tempNext;
//       tempNext->prev = temp;
//       cur = temp;
//     }
// }

template<typename T>
int ListD<T>::DeleteAll(T item)
{

  int count = 0;
  doubleNode<T>* cur = head;
  doubleNode<T>* next;
  doubleNode<T>* prev;

  for(int i = 0; i < length; i++)
  {
    next = cur->next;
    prev = cur->prev; 

    if(cur->item == item)
    {
      count++;
      prev->next = cur->next;
      next->prev = cur->prev;
      delete cur;
      length--;
    } 
    cur = next;    
  }
  return count;
}