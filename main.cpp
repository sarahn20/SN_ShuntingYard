#include<iostream>
#include "StringFactory.hpp"
using namespace std;

int main()
{
    string s = "123+42-8*2";
    LinkedList* ll = new LinkedList();
    ll->display();

    StringFactory::split(s,"+-*/");

}
