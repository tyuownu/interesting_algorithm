/*************************************************************************
    > File Name: test.cpp
    > Author: 
    > Mail: 
    > Created Time: 2015年09月22日 星期二 23时04分21秒
 ************************************************************************/

#include<iostream>
#include "avltree.h"
using namespace std;

static void PrintElement(const int &data)
{
    cout<<data<<" ";
}

int main()
{
    avltree<int> root;
    root.Insert(3);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(2);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(1);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(4);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(5);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(6);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(7);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(16);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(15);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(14);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(13);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(12);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(11);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(10);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(8);
    root.PreOrder(PrintElement);cout<<endl;
    root.Insert(9);
    root.PreOrder(PrintElement);cout<<endl;
    return 0;
}

