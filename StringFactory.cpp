#include "StringFactory.hpp"
#include <iostream>

using namespace std;

string* StringFactory::split(string s, string delims)
{
    string myDelim = "";
    string myNum = "";
    LinkedList* splitValues = new LinkedList();
    Node* currNode = splitValues->getHead();
    
    int stringSize = s.length();
    for(int i = 0; i < stringSize; i++) //goes through string
    {
        for(int j = 0; j < delims.length(); j++) //goes through delims
        {
            if(s.at(i) == delims.at(j)) //if char is a delim
            {
                myDelim = s.at(i);
                if(myNum != "") //if this is the first delim hit in the list after the nums have been building 
                //up for a while
                {
                    splitValues->addEnd(myNum);
                    myNum = "";
                }
                splitValues->addEnd(myDelim);
                break;
            }
        }
        if(myDelim == "") //if, after going through all delims, none of them match the char, it must be a num
        {
            myNum = myNum + s.at(i); //add the num to the nums
        }
        myDelim = ""; //if there was no delim, clearing it won't hurt it, and if there was, it has already
        //been added to the list and myDelim is safe to be cleared
    }
    splitValues->addEnd(myNum); //adding the last trapped value
    return splitValues->toStringArray();
}
