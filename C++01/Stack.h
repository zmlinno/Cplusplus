#pragma once
#include<iostream>

using namespace std;

class Stack
{
public:
    //成员变量
    int *a;
    int top;
    int capacity;

public:
    //成员函数
    void Init(int n =4);
    void Push(int x);
};

class Queue
{
public:
    //成员函数
    void Init(int n);
    void Push(int x);
};