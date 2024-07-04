#include <iostream>
#include <vector>
class Mylist{
    private:
        int *arr;
        int arrcapacity=60;
        int arrsize;
        int extendratio=2;

    public:
        Mylist(int* initarr, int initsize):arrsize(initsize), arrcapacity(){
            arrcapacity=initsize>arrcapacity?initsize:arrcapacity;
            arr = new int[arrcapacity];
            std::cout<<"capacity:";
            for(int i=0;i<arrsize;i++)
                arr[i] = initarr[i];
            std::cout<<arrcapacity<<std::endl;
        }

        ~Mylist(){
            delete[] arr;
        }

        int size(){
            return arrsize;
        }

        int capacity(){
            return arrcapacity;
        }
        void printlist(){
            for(int i=0; i<size(); i++)
                std::cout<<arr[i]<<std::endl;
        }

        int get(int index){
            if(index>=arrsize || index<0)
                std::cout<<"索引越界"<<std::endl;
            return -1;
            return arr[index];
        }

        void extendcapacity()
        {
            int newcapacity = arrcapacity*extendratio;
            int *tmp = arr;
            arr = new int[newcapacity];
            for(int i=0;i<arrsize;i++)
                arr[i] = tmp[i];
            delete[] tmp;
            arrcapacity = newcapacity;
            std::cout<<"capacitychange:"<<capacity()<<std::endl;
        }

        void set(int index, int num)
        {
            if(index>= arrsize || index<0)
                std::cout<<"索引越界"<<std::endl;
            if(size() == capacity())
                extendcapacity();
            for(int i=arrsize;i>index;i--){
                arr[i] = arr[i-1];
            }
            arrsize++;
            arr[index] = num;
        }
};


int main(){
    int array[6] = {1,2,3,4,5,6};
    Mylist list(array, 6);
    list.set(3,3);
    list.printlist();
    std::cout<<"capacity:"<<list.capacity()<<std::endl;
}