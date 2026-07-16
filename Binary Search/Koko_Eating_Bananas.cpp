#include<iostream>
using namespace std;

//Function for calculating total time --------------------------------------------------------------------------------------------------------------
int time(vector<int> &arr,int hourly){          //hourly->no.of banana eaten per hour
    int totalHours = 0;
    for (int pile : arr) {
        // Add hours using ceil
        totalHours += (pile + hourly - 1) / hourly;
    }
    return totalHours;
    
}

//Brute Force Method--------------------------------------------------------------------------------------------------------------------------------
// int Minimum(vector<int> &arr,int h){           //h->total hour given
//     int max_value=*max_element(arr.begin(),arr.end());
//     for (int i = 1; i <=max_value; i++)
//     {
//         int maxTime=time(arr,i);
//         if (maxTime<=h)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

//Optimal method--------------------------------------------------------------------------------------------------------------------------------
int Minimum2(vector<int> &arr,int h){
    int max_value=*max_element(arr.begin(),arr.end());
    int low=1,high=max_value;
    int ans=max_value;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        int maxTime=time(arr,mid);
        if (maxTime<=h)
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
    vector<int> arr={3, 6, 7, 11};
    cout<<Minimum2(arr,9);
    return 0;
}

/*
Brute Force Method--------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(n * max(a[])), since for each possible speed we go through all the piles.
Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
*/

/*
Optimal Method--------------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N*log(max(a[]))), we apply binary search on our search space to reduce it into half at every step.
Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
*/