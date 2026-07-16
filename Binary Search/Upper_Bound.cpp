#include<iostream>
using namespace std;

// Optimal Method---------------------------------------------------------------------------------------------------------------------------
int UpperBound(vector<int>&arr,int target){
    int low=0, high=arr.size()-1;
    int ans = arr.size();
    while(low<=high){
        int mid = low + (high-low)/2;
        if (arr[mid]>target)
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
    vector<int> arr={2,2,3,4,5,5,5,7,8,9,10};
    cout<<UpperBound(arr,5);
    return 0;
}

/*
Optimal Method--------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(logn), used for typical binary search
Space Complexity: O(1), no extra space used
*/
