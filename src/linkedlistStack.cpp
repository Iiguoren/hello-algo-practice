#include <iostream>
#include "../include/listnode.h"

class linkedlistStack{
    private:
    listnode *stacktop;
    int stksize;
    
    public:
    linkedlistStack(){
        stacktop = nullptr;
        stksize = 0;
    }
    
    ~linkedlistStack(){}

    int size(){
        return stksize;
    }

    int get(){
        if (stacktop == nullptr){
            std::cout<<"empty"<<std::endl;
        }
        return stacktop->value;
    }

    int pop(){
        int num = get();
        listnode *tmp = stacktop;
        stacktop = stacktop->next;
        delete tmp;
        stksize--;
        return num;
    }

    void push(int num){
        listnode *node = new listnode(num);
        node->next = stacktop;
        stacktop = node;
        stksize++;
    }

    void printstack(){
        listnode *tmp = stacktop;
        while(tmp!=nullptr)
        {
            std::cout<<tmp->value;
            tmp = tmp->next;
        }
        std::cout<<std::endl;
    }
};

int main(){
    linkedlistStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.printstack();

}
