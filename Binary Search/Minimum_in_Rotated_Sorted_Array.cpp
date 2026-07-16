#include<iostream>
using namespace std;
int Minimum(vector<int> &nums){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    
    while(low<=high){
          int mid=low+(high-low)/2;
          if (nums[mid]>nums[high])
          {
            if(nums[low]<ans)
            ans=nums[low];
            low=mid+1;
          }
          else{
            if(nums[mid]<ans){
                ans=nums[mid];
            }
            high=mid-1;
          }
          
    }
    return ans;
    
}
int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    cout<<Minimum(nums);
    return 0;
}