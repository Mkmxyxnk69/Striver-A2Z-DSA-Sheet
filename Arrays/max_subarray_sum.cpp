#include<iostream>
using namespace std;

//Brute Force Method--------------------------------------------------------------------------
int maxSum1(vector<int> &arr){
    int n=arr.size();
    int maximum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum=0;
            for (int k = i; k < j; k++)
            {
                sum+=arr[k];
            }
            maximum=max(sum,maximum);
            
        }
        
    }
    return maximum;
    
}

//Better Method-------------------------------------------------------------------------------- 
int maxSum2(vector<int> &arr){
    int n=arr.size();
    int maximum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            maximum=max(sum,maximum);
            
        }
        
    }
    return maximum;
}

//Optimal Method(Kadane's Algorithm)------------------------------------------------------------
int maxSum3(vector<int> &arr){
    int n=arr.size();
    int maximum=INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];

        if (sum>maximum)
        {
            maximum=sum;
        }
        
        if (sum<0)
        {
            sum=0;
        }
    }
    if (maximum<0)
    {
        maximum=0;
    }
    
    return maximum;
    
    
}
/*
Extended version of the same problem bss ismae yeh hai ki agar 
max sum array agar minus mae hai toh empty araay nahi dena jaise pehele problem mae derhe the
*/ 
//Optimal Method(Problem 2)------------------------------------------------------------
int maxSum4(vector<int> &arr){
    int n=arr.size();
    int maximum=INT_MIN;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];

        if (sum>maximum)
        {
            maximum=sum;
        }
        
        if (sum<0)
        {
            sum=0;
        }
    }
    return maximum;
    
    
}
int main(){
    vector<int> arr={-3,-2,-4,-5};
    cout<<maxSum4(arr);
    
    return 0;
}

/*
Brute Force Method---------------------------------------------------------------------------
Time Complexity: O(N^3), where N is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the sum of the subarray.
Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.
*/

/*
Better Method----------------------------------------------------------------------------------
Time Complexity: O(N^2), where N is the size of the array. This is because we have two nested loops: one for the starting index and one for the ending index of the subarray.
Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size
*/

/*Optimal Method(Kadane's Algorithm)------------------------------------------------------------
Time Complexity: O(n), where n is the number of elements in the array. We traverse the array only once.
Space Complexity: O(1). We use a constant amount of space for variables.
*/