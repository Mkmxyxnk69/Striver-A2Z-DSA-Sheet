#include<iostream>
using namespace std;
//My method-------------------------------------------------------------------------------------------------------------------------------
int RotationCount(vector<int> &arr){
    int n=arr.size();
    int low=0,high=n-1;
    int ans = 0;
    while(low<high){
        int mid = low +(high-low)/2;
        if (arr[low]<arr[mid])
        {
            ans=mid-1;
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return ans;
}

//Same code as finding the minimum in an rotated sorted array , and can get the index of that minimu which tell how many times the array is rotated
//Optimal-------------------------------------------------------------------------------------------------------------------------------
int RotationCount2(vector<int> &nums){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    int index=-1;
    
    while(low<=high){
          int mid=low+(high-low)/2;
          if (nums[mid]>nums[high])
          {
            if(nums[low]<ans){
            ans=nums[low];
            index=low;
            }
            low=mid+1;
          }
          else{
            if(nums[mid]<ans){
                ans=nums[mid];
                index=mid;
            }
            high=mid-1;
          }
          
    }
    return index;
    
}
int main(){
    vector<int> arr={3,4,5,6,1,2};
    cout<<RotationCount2(arr);
    return 0;
}

/*
My Method-------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(log n)
Space Complexity: O(1)
*/

/*
Optimal Method------------------------------------------------------------------------------------------------------------------------------- 
Time Complexity: O(log n)
Space Complexity: O(1)
*/