#include "list.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}



bool LinkedList::add(int val)
{
   // int size;
    Node * newNode = new Node();
    newNode->next = head;
    newNode->data = val;
    
    if(!head)       //if list is empty
    {
        head = newNode;
        tail = newNode;
 //       size++;
        return true;
    }
    
    head->prev = newNode;
    head = newNode;
//    size++;
    return true;
}

bool LinkedList::remove(int val)
{
    if(head->data == val)
    {
        Node * current = head;
        head = current->next;
        head->prev = NULL;
        current->next = NULL;
        delete current;
    }
    else if(tail->data == val)
    {
        Node * current = tail;
        tail = current->prev;
        tail->next = NULL;
        current->prev = NULL;
        delete current;
    }
    else
    {

        Node * curr = head;
        while(curr->next != NULL)
            
            if(curr->data == val)
            {
                Node * prv = curr->prev;
                prv->next = curr->next;
                Node * nxt = curr->next;
                nxt->prev = curr->prev;
                curr->next = NULL;
                curr->prev = NULL;
                delete curr;
                
                
            }
            else if(curr->data != val)
            {
                curr = curr->next;
            }
    }
    return true;
}

void LinkedList::printAscending() const
{
    Node * curr = tail;
    cout << "Ascending: ";
    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void LinkedList::printDescending() const
{
   
    
    Node * curr = head;
    cout << "Decending: ";
    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
