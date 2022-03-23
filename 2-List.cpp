#include <iostream>
using namespace std;

#include "2-List.h"


//Class-related functions
//Constructor
List::List()
{       
 length = 0;
 head = NULL;
}

//Destructor
List::~List()
{

}

//Head-related functions
void List::PutItemH(itemType item)
{
    node* temp = new node; // declaring a new node
    temp->item = item; // temp points to item which = itemIn
    temp->next = head; 
    head = temp;
    // if (length == 0)
    // {
    //     tail = head;
    // }
    temp = NULL;
    length ++;
}

itemType List::GetItemH() const
{
    node* cur = head; // points to head
    cur = cur->next; // head pointer after
    cur = NULL;
    return cur->item; // returns item 
    
}

void List::DeleteItemH()
{
    node* cur = head;
    head = head->next;
    delete cur;
    cur = NULL;
}


//General operations on the class

void List::Print() const
{
    node* cur = head;

    while (cur != NULL && cur->next != NULL)
    {
        cout << cur->item << endl;
        cur = cur->next;
    }
    cout << cur->item << endl;

    cur = NULL;
}

bool List::IsEmpty() const
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}




int List::Find(const itemType target) const
{
    node* cur = head;
    int pass = 0;

    while (cur != NULL && cur->next != NULL) // (!cur->target) // if cur isnt pointing to target
    {
        if (cur->item == target)
            pass++;
        cur = cur->next;
    }

    cur = NULL;
    return pass; // returning the # of times the target is hit
}



int List::GetLength() const
{
    node* cur = head;
    int length = 0;

    while(cur != NULL && cur->next != NULL)
    {
        length ++;
        cur = cur->next;
    }
    length ++;
    cur = cur->next;

    cur = NULL;
    return length;

}


int List::DeleteItem(const itemType target)
{
    int pass = 0;

    while(cur != NULL && cur->next != NULL)
    {
        if(cur->item == target)
        {
            node* 

        }
        cur = cur->next;
    }
    return pass;
}




// finish DeleteItem function and test
// finish getItem test
// finsih constructor
