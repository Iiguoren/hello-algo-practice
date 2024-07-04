#include <iostream>
#include "../include/listnode.h"

class linkedlistqueue{
    private:
    listnode *front;
    listnode *rear;
    int queuesize;
    
    public:
    linkedlistqueue():front(nullptr), rear(nullptr), queuesize(0) {}
    ~linkedlistqueue(){
    while (front != nullptr){
        listnode *tmp = front;
        front = front->next;
        delete tmp;
        }
    }
    int size(){
        return queuesize;
    }

    bool isempty(){
        return (queuesize==0);
    }

    void push(int num){
        listnode *node = new listnode(num);
        if(front == nullptr){
            rear = node;
            front = node;
            }
        else{
        rear->next = node;  
        rear = node;} 
        queuesize++;
    }

    int peek(){
        if (queuesize == 0 )
            return  -1;
        else{
            return front->value;
        }
    }

    int pop(){
        int num = peek();
        listnode *tmp = front;
        front = front->next;
        delete tmp;
        queuesize--;
        return num;
    }

    void printqueue(){
        listnode *tmp = front;
        while(tmp != nullptr)
        {
            std::cout<<tmp->value<<std::endl;
            tmp = tmp->next;
        }
    }
};

int main(){
    linkedlistqueue queue;
    queue.push(0);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.printqueue();
    int num  = queue.pop();
    std::cout<<num<<std::endl;
    queue.printqueue();
}