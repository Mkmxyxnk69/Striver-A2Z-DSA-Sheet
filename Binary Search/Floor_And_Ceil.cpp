#include<iostream>
using namespace std;

//Optimal Method--------------------------------------------------------------------------------------------------------------------------------
int Floor1(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high=n-1;
    int ans = -1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if (arr[mid]<=target)
        {
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    return ans;
}

int Ceil1(vector<int> &arr,int target){
    int n=arr.size();
    int low=0, high=n-1;
    int ans = -1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if (arr[mid]>=target)
        {
            ans=arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return ans;
}
int main(){
    vector<int> arr={10,30,40,50};
    cout<<Floor1(arr,25)<<endl;
    cout<<Ceil1(arr,25);
    return 0;
}

/*
Optimal Method--------------------------------------------------------------------------------------------------------------------------------
Time Complexity:O(logN), where N = size of the given array. We are using the Binary Search algorithm
Space Complexity: O(1). No extra space used
*/