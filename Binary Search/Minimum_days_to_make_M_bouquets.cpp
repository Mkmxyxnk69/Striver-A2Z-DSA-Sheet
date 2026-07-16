#include<iostream>
using namespace std;

//Function to calculate for what day it is possible-------------------------------------------------------------------------------------
bool isItPossible(vector<int> &arr, int m, int k,int day){      //m->No.of bouquets
    int count=0;                                                //k->No.of adjacent flowers
    int bouquet=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]<=day)
        {
            count++;
            if (count==k)
            {
                bouquet++;
                count=0;
            }
        }
        else count=0;
    }
    return bouquet>=m;
    
}

//Brute Force Method-------------------------------------------------------------------------------------
int minimumDays1(vector<int> &arr,int m ,int k){
    if (1LL *m*k>arr.size())
    {
        return -1;
    }
    
    int mini_value=*min_element(arr.begin(),arr.end());
    int max_value=*max_element(arr.begin(),arr.end());
    for (int  j=mini_value; j <=max_value; j++)
    {
        if (isItPossible(arr,m,k,j))
        {
            return j;
        }
        
    }
    return -1;
    
}

//Optimal Method-------------------------------------------------------------------------------------
int minimumDays2(vector<int> &arr,int m ,int k){
    if (1LL *m*k>arr.size())
    {
        return -1;
    }
    int res=INT_MAX;
    
    int mini_value=*min_element(arr.begin(),arr.end());
    int max_value=*max_element(arr.begin(),arr.end());
    
    int low=mini_value,high=max_value;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if (isItPossible(arr,m,k,mid))
        {
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
    
    
}
int main(){
    vector<int> arr={7, 7, 7, 7, 13, 11, 12, 7};
    cout<<minimumDays2(arr,4,1);
    return 0;
}

/*
Brute Force Method-------------------------------------------------------------------------------------
Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
Space Complexity : O(1) as we are not using any extra space to solve this problem.
*/

/*
Optimal Method-------------------------------------------------------------------------------------
Time Complexity: O(1) O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
Space Complexity : O(h)O(1) as we are not using any extra space to solve this problem.
*/