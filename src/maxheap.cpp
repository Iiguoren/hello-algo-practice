#include <iostream>
#include <vector>
using namespace std;

class Maxheap{
    private:
    vector<int> maxHeap;

    public:

    Maxheap(vector<int> nums) {
    // 将列表元素原封不动添加进堆
        maxHeap = nums;
    // 堆化除叶节点以外的其他所有节点
    for (int i = parent(size() - 1); i >= 0; i--) {
        siftdown(i);
        }
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    int parent(int i){
        return (i-1)/2;
    }
    void swap(int i, int j){
        int tmp = maxHeap[i];
        maxHeap[i] = maxHeap[j];
        maxHeap[j] = tmp;
    }

    int size(){
        return maxHeap.size();
    }

    void siftup(int i){
        while(true){
            int p = parent(i);
            if(p<0 || maxHeap[p]>maxHeap[i])
                break;
            else{
                swap(p, i);
            }
            i = p;
        }
    }

     void push(int num){
        maxHeap.push_back(num);
        siftup(size() - 1);
    }

    void siftdown(int i){
        while(true){
            int l = left(i), r = right(i), m = i;
            if(l<size() && maxHeap[l]>maxHeap[m])
                m = l;
            if(r<size() && maxHeap[r]>maxHeap[m])
                m = r;
            if (m == i)
                break;
            
            swap(i, m);
            i = m;
        }
    }

    void pop(){
        swap(0, size()-1);
        maxHeap.pop_back();
        siftdown(0);
    }

    void print(){
        for(int i = 0; i<size(); i++)
            cout<<maxHeap[i]<<" ";
        cout<<endl;
    }

    

};

int main(){
    vector<int> vec= {5 , 1, 7, 2, 8, 6};
    Maxheap heap = Maxheap(vec);
    heap.print();
}