#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    private:
    vector<int> maxHeap;

    public:

    MaxHeap(vector<int> nums) {
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

    int pop(){
        swap(0, size()-1);
        maxHeap.pop_back();
        siftdown(0);
    }

};