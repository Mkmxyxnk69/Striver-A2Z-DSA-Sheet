#include<iostream>
using namespace std;
//Brutal Method------------------------------------------------------------------------------------------------------------------------------------
int Search(vector<int> &arr,int target){
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==target)
        {
            return i;
            break;
        }
        
    }
    return -1;
    
}

//Optimal Method(Iterative Implementation)------------------------------------------------------------------------------------------------------------
int Search2(vector<int> &arr,int target){
    int n=arr.size();
    int low=0,high=n-1;
    while (low<=high)
    {
        int mid = (high-low)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        else if(target>arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    return -1;
}

//Recursive Method------------------------------------------------------------------------------------------------------------------------------------
int Search3(vector<int> &arr, int low, int high, int target){
    if (low>high)
    {
        return -1;
    }
    int mid = (high+low)/2;
    if (arr[mid]==target)
    {
        return mid;
    }
    else if(arr[mid]<target){
        return Search3(arr,mid+1,high,target);
    }
    else{
        return Search3(arr,low,mid-1,target);
    }
}

int main(){
    vector<int> arr={1,2,5,7,9,10,13,17,19,31};
    cout<<Search3(arr,0,arr.size()-1,20);
    return 0;
}

/*
Optimal Method-----------------------------------------------------------------------------------------------------------------------------------
Time Complexity: In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. 
This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. 
The number of total divisions will be equal to the time complexity. So the overall time complexity is O(logN), where N = size of the given array.

Space Complexity: 0(1), no extra space being used
*/