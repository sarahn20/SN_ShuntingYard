#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    this->head = 0;
    this->count = 0;
}

Node* LinkedList::getHead()
{
    return this->head;
}

void LinkedList::display()
{
    for(int i = 0; i < this->count; i++)
    {
        cout << this->get(i) << "\n";
    }
}

string LinkedList::get(int index)
{
    Node* currNode = this->head;
    for(int i = 0; i < index; i++)
    {
        currNode = currNode->getNextNode();
    }
    return currNode->getPayload();
}

void LinkedList::addEnd(string payload)
{
    Node* n = new Node(payload);
    if(!this->head)
    {
        this->head = n;
    }
    else
    {
        //run to the end of the list
        Node* currNode = this->head;
        while(currNode->getNextNode())
        {
            currNode = currNode->getNextNode();
        }
        currNode->setNextNode(n);
    }
    this->count++;
}

string* LinkedList::toStringArray()
{
    int index = 0;
    Node* currNode = this->head;
    string myArr[this->count];
    string* theArray = myArr;
    while(currNode)
    {
        theArray[index] = currNode->getPayload();
        currNode = currNode->getNextNode();
        index++;
    }
    for(int i = 0; i < this->count; i++)
    {
        cout << theArray[i];
        if(i < this->count-1)
        {
            cout << ",";
        }
    }
    return theArray;
}
