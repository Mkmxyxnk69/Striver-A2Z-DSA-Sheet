#include<iostream>
#include <numeric> 
using namespace std;

//Function which is used to find the number of student-------------------------------------------------------------------------------------
int numberOfStudent(vector<int> &arr, int pages1){
    int std=1,page=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (page + arr[i]<=pages1)
        {
            page+=arr[i];
        }
        else{
            std++;
            page=arr[i];
        }
    }
    return std;
}

//Brute Force Method-------------------------------------------------------------------------------------
int minimumPages(vector<int> &arr,int student){
    if (student>arr.size())
    {
        return -1;
    }
    
    int low=*max_element(arr.begin(),arr.end());
    int n=arr.size();
    int high = accumulate(arr.begin(), arr.end(), 0);
    for (int j = low; j <=high; j++)
    {
        int countstd=numberOfStudent(arr,j);
        if (countstd==student)
        {
            return j;
        }
    }
    return -1;
}

//Optimal Method-------------------------------------------------------------------------------------
int minimumPages2(vector<int> &arr,int student){
    if (student>arr.size())
    {
        return -1;
    }
    
    int low=*max_element(arr.begin(),arr.end());
    int n=arr.size();
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans=high;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        int countstd=numberOfStudent(arr,mid);
        if (countstd<=student)
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
    vector<int> arr={10,20,30,40};
    cout<<minimumPages2(arr,2);
    return 0;
}

/*
Brute Force Method-------------------------------------------------------------------------------------
Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[])
Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/

/*
Optimal Method-------------------------------------------------------------------------------------
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/