#include<iostream>
using namespace std;

//Optimal Method--------------------------------------------------------------------------------------------------------------------------------
int SearchInsertion(vector<int> &arr,int num){
    int low=0;
    int n=arr.size();
    int high=n-1;
    int ans=n;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if (arr[mid]>=num)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return ans;
}
int main(){
    vector<int> arr={1,3,5,6,7,9};
    cout<<SearchInsertion(arr,8);
    
    return 0;
}

/*
Optimal Method--------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(logN), where N = size of the given array.
Space Complexity: O(1) as we are using no extra space.
*/