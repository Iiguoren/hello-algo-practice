#include <iostream>

struct listnode{
    int value;
    listnode *next;

    listnode(int num) : value(num), next(nullptr) {};
};

void insert(listnode *n0, listnode *p)
{
    listnode *n1 = n0->next;
    n0->next = p;
    p->next = n1;
}

void printlistnode(listnode *head)
{
    listnode *current = head;
    while(current != nullptr)
    {
        std::cout<<current->value<<"";
        current = current->next;
    }
    std::cout<<std::endl;
}

listnode *find(listnode *n0, int val)
{

     while (n0 != nullptr)
     {
        if(n0->value == val)
            return n0;
        else
            n0 = n0->next;
     }

}

int main()
{
    listnode *n0 = new listnode(0);
    listnode *n1 = new listnode(1);
    listnode *n2 = new listnode(2);
    listnode *n3 = new listnode(3);
    listnode *n4 = new listnode(4);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printlistnode(n0);

    listnode *p = new listnode(0);
    insert(n0, p);

    printlistnode(n0);

    listnode *node = find(n0, 3);
    std::cout<<node->value<<std::endl;
    delete n0;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
}