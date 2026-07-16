#include<iostream>
using namespace std;

//Optimal Method---------------------------------------------------------------------------------------
bool Searching(vector<int> & nums, int target){
    int n = nums.size();
    int low=0,high=n-1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if (nums[mid]==target)
        {
            return true ;
        }
        if (nums[low]==nums[mid] && nums[mid]==nums[high])
        {
           low=low+1;
           high=high-1;
           continue;
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
    return false;
    
}
int main(){
    vector<int> nums={5,5,1,2,3,4,5,5,5};
    cout<<Searching(nums,5);
    return 0;
}