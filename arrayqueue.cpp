#include <iostream>

class arrayqueue{
    private:
    int *nums;
    int queuesize;
    int quecapacity;
    public:
    arrayqueue(int capacity){
        nums = new int[capacity];
        quecapacity = capacity;
        queuesize = 0;
    }

    ~arrayqueue(){
        delete[] nums;
    }

    int size(){
        return queuesize;
    }

    int capacity(){
        return quecapacity;
    }
    bool isempty(){
        return queuesize==0;
    }

    void update(){
        int *tmp =nums;
        nums = new int[quecapacity*2];
        for(int i=0; i<quecapacity; i++)
            nums[i] = tmp[i];
        quecapacity = quecapacity * 2;
        delete tmp;
        std::cout<<"capacityupdate"<<quecapacity<<std::endl;
    }

    void push(int num){
        if (quecapacity == queuesize)
            update();
        else{
            nums[queuesize] = num;
            queuesize++;
            } 
    }
    int peek(){
        if(isempty()==0)
            return nums[0];
        else
        {
            std::cout<<"empty"<<std::endl;
            return -1;
        }
    }

    void pop(){
        int num = peek();
        for(int i=0;i<queuesize;i++)
        {
            nums[i] = nums[i+1];
        }
        queuesize--;
    }

    void printqueue(){
        for(int i=0; i<queuesize; i++)
            std::cout<<nums[i];
        std::cout<<std::endl;
    }
};

int main(){
    arrayqueue queue(4);
    std::cout<<"capacity:"<<queue.capacity()<<std::endl;
    queue.push(0);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout<<"capacity:"<<queue.capacity()<<std::endl;
    queue.printqueue();
    queue.push(4);
    queue.pop();
    queue.printqueue();
}