#include <vector>
#include <climits>
#include <string>
#include <iostream>
using namespace std;

class ArrayBineryTree{
    private:
        vector<int> tree;
    public:
    ArrayBineryTree(vector<int> arr){
        tree = arr;
    }

    size(){
        return tree.size();
    }

    int val(int i){
        if(i<0||i>=tree.size()) //不加=会使size号节点为负的最大值出现
            return INT_MAX;
        return tree[i];
    }

    int left_index(int i){
        return 2*i+1;
    }
    int right_index(int i){
        return 2*i+2;
    }

    int parent(int i){
        return(i-1)/2;
    }

    vector<int> preorder(){
        vector<int> vec;
        dbs(0, "pre", vec);
        return vec;
    }

    vector<int> inorder(){
        vector<int> vec;
        dbs(0, "in", vec);
        return vec;
    }

    vector<int> postorder(){
        vector<int> vec;
        dbs(0, "post", vec);
        return vec;
    }

private:
    void dbs(int i, string order, vector<int> &vec){
        if(val(i) == INT_MAX)
            return;
        if(order == "pre")
            vec.push_back(val(i));
        dbs(left_index(i), order, vec);
        if(order == "in")
            vec.push_back(val(i));
        dbs(right_index(i), order, vec);
        if(order == "post")
            vec.push_back(val(i));
    }       
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,INT_MAX,INT_MAX};
    
    ArrayBineryTree tree = ArrayBineryTree(arr);
    cout<<tree.size()<<endl;
    vector<int> vec;
    vec = tree.preorder();
    cout<<"preorder:"<<endl;
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
    vec = tree.inorder();
        cout<<"inorder:"<<endl;
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
    vec = tree.postorder();
        cout<<"inorder:"<<endl;
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}