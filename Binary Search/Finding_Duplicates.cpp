#include<iostream>
using namespace std;

//Optimal Method---------------------------------------------------------------------------------------
int First1(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high =n-1;
    int first=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==target)
        {
            first=mid;
            high=mid-1;
        }
        else if (arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}
int Last1(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high =n-1;
    int last=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==target)
        {
            last=mid;
            low=mid+1;
        }
        else if (arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return last;
}

int  Occurance3(vector<int> &arr,int target){
    int firstt=First1(arr,target);
    int lastt=Last1(arr,target);
    return (lastt-firstt+1);
}

int main(){
    vector<int> arr={1,2,3,3,3,3,3,5,6,8};
    cout<<Occurance3(arr,5);
    return 0;
}

/*
Optimal Method---------------------------------------------------------------------------------------
Time Complexity:O(logN), where N = size of the given array. We are using the Binary Search algorithm.
Space Complexity: O(1). No extra space used.
*/