#include <iostream>

void insert(int *nums, int size, int num, int index)
{
    for(int i = size-1; i>index; i--)
    {
        nums[i] = nums[i-1];
    }
    nums[index] = num;
}

int main()
{
    int arr[5]={1,2,3,4};
    insert(arr, 5, 3, 3);
    for(int i=0;i<5;i++)
        std::cout<<arr[i]<<std::endl;
    return 0;
}