#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &num, int target){
    int i = 0;
    int j = num.size() - 1;
    while(i <= j){
        int m = (i+j)/2;
        if(num[m]>target)
            j = m - 1;
        else if(num[m]<target)
            i = m + 1;
        else{
            return m; 
        }+
    }
    return -1;  
}


int main(){
    vector<int> nums = {1,4,8,9,11,24,66,75};
    int index = binarySearch(nums, 26);
    cout<<index<<endl;

}