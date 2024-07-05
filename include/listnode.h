#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// 定义 listnode 结构体
struct listnode{
    int value;
    listnode *next;

    listnode(int num) : value(num), next(nullptr) {};
    ~listnode(){};
};

// 函数声明
void insert(listnode *n0, listnode *p);
void printlistnode(listnode *head);
listnode* find(listnode *n0, int val);

#endif // LISTNODE_H
