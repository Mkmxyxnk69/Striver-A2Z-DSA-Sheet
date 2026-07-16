#include<iostream>
using namespace std;

//Optimal Method---------------------------------------------------------------------------------------
int Searching(vector<int> & nums, int target){
    int n = nums.size();
    int low=0,high=n-1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if (nums[mid]==target)
        {
            return mid;
        }

        if (nums[low]<=nums[mid])
        {
            if (target>=nums[low] && target<nums[mid])
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if (nums[mid]<target && target<=nums[high])
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        
        
    }
    return -1;
    
}
int main(){
    vector<int> nums={3,1};
    cout<<Searching(nums,3);
    return 0;
}

/*
Optimal Method---------------------------------------------------------------------------------------
Time Complexity: O(log N),We eliminate half of the search space in each iteration using binary search.
Space Complexity: O(1),We use only a few variables (low, high, mid) no extra space used.
*/