#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template <typename T>
ListD<T>::ListD()
{
 InitializeVars();
}

template<typename T>
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>*; 
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
 length--;
}

template<typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T>*  cur = head->next;

 int i = 0;
 while (i < length)
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

template<typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
    doubleNode<T>* temp = head;
    int pass = 0;

    while (temp->data != pos && temp->next != NULL) 
    {
        pos++;
        temp = temp->next;
    }
    return (pos + 1);
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
  cout << cur->item << endl;
  Insert(cur->item,i);
  cur = cur->next;
 }
}