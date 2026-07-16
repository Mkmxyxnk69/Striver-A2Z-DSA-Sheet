#include<iostream>
using namespace std;

//Function which is used to find that the cow can be placed in the given arr--------------------------------
bool canWePlace(vector<int> &arr, int distance, int cow){
    int cowcount=1;
    int last = arr[0];
    for (int i = 1; i <arr.size(); i++)
    {
        if (arr[i]-last>=distance)
        {
            cowcount++;
            last=arr[i];
        }
    }
    if (cowcount>=cow)
    {
        return true;
    }
    return false;
}

//Brute Force Method-------------------------------------------------------------------------------------
int minMaxDistance1(vector<int> &arr,int cow){
    sort(arr.begin(),arr.end());
    int mini=*min_element(arr.begin(),arr.end());
    int max=*max_element(arr.begin(),arr.end());
    for (int j = 1; j<= (max-mini); j++)
    {
        if (canWePlace(arr,j,cow)==true)
        {
            continue;
        }
        else{
            return j-1;
        }
    }
    return -1;
}

//Optimal Method-------------------------------------------------------------------------------------
int minMaxDistance2(vector<int> &arr,int cow){
    sort(arr.begin(),arr.end());
    int low=*min_element(arr.begin(),arr.end());
    int high=*max_element(arr.begin(),arr.end());
    int ans =0;
    while (low<=high){
        int mid=low+(high-low)/2;
        if (canWePlace(arr,mid,cow)==true)
        {
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={0,3,4,7,10,9};
    cout<<minMaxDistance2(arr,4);
    return 0;
}

/*
Brute Force Method-------------------------------------------------------------------------------------
Time Complexity: O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

/*
Optimal Method-------------------------------------------------------------------------------------
Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Space Complexity: O(1) as we are not using any extra space to solve this problem
*/