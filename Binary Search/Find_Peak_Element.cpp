#include<iostream>
using namespace std;

//Brute Force Method---------------------------------------------------------------------------------------
int Peak1(vector<int> & nums){
    int n= nums.size();
    for (int i = 0; i < n; i++)
    {
        if ((i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i]>nums[i+1]))
        {
            return nums[i];
        }
        
    }
  return 0;  
}

// Optimal Method--------------------------------------------------------------------------------------- 
int Peak2(vector<int> &nums){
    int n = nums.size();
    if (n==1)
    {
        return 0;
    }
    
    if (nums[0]>nums[1])
    {
        return 0;
    }
    if (nums[n-1]>nums[n-2])
    {
        return n-1;
    }
    int low = 1;
    int high = n-2;
    while (low<=high)
    {
        int mid = low +(high-low)/2;
        if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
        {
            return mid;
        }
        else if(nums[mid]>nums[mid-1]){
            low=mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums={1,2,1,3,5,6,4};
    cout<<Peak2(nums)<<endl;
    return 0;
}

/*
Brute Force Method---------------------------------------------------------------------------------------
Time Complexity: O(N) 
Space Complexity: O(1)
*/


/*
Optimal Method---------------------------------------------------------------------------------------
Time Complexity: O(log N),We eliminate half of the search space in each iteration using binary search.
Space Complexity: O(1),We use only a few variables (low, high, mid) no extra space used.
*/