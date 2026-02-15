#include<iostream>
using namespace std;

//Finding the largest element in the array---------------------------------------------------------------------

//Brute Force Method
int sortArr1(vector<int> arr){
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}

//OPTIMAL METHOD
int sortArr2(vector<int> arr){
    int largest=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]>largest)
        {
            largest=arr[i];
        }  
    }
    return largest;
    
}
int main(){
    vector<int> arr={4 , 5 ,43, 6, 88, 56};
    cout<<sortArr2(arr);
    return 0;
}

// Brute Force Method-------------------------------------------------------------------------------------------------
// Time Complexity: O(N log N), where N is the size of the array, as we are sorting the array.

// Space Complexity: O(1), as we are using a constant

//OPTIMAL METHOD--------------------------------------------------------------------------------------------------
// Time Complexity: O(N), where N is the size of the array, as we are sorting the array.

// Space Complexity: O(1), as we are using a constant