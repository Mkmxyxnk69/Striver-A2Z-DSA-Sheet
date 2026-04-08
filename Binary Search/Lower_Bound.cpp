#include<iostream>
using namespace std;

//Brute Force Method--------------------------------------------------------------------------------------------------------------------------------
// int LowerBound1(vector<int> &arr, int x){
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i]>=x)
//         {
//             return i;
//         }
//     }
//     return arr.size();
    
// }

//Optimal Method------------------------------------------------------------------------------------------------------------------------------------
int LowerBound2(vector<int> &arr,int x){
    int low=0;
    int high=arr.size()-1;
    int ans=arr.size();
    while (low<=high)
    {
        int mid =  low + (high - low)/2;
        if (arr[mid]>=x)
        {
            ans = mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={2,2,3,4,5,7,8,9,10,25,47};
    cout<<LowerBound2(arr,67);
    return 0;
}

/*
Brute Force Method--------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N), where N = size of the given array.
Space Complexity: O(1), no extra space used
*/

/*
Optimal Method------------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(logn), used for typical binary search
Space Complexity: O(1), no extra space used
*/