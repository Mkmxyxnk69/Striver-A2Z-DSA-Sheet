#include<iostream>
#include<vector>
#include<climits> 
using namespace std;

//Brute Force Method------------------------------------------------------------------------------------------------
int Profit1(vector<int> &arr){
    int n = arr.size();
    int maxi=INT_MIN;
    int currProfit=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            currProfit=arr[j]-arr[i];
            maxi = max(maxi, currProfit);
        }
        
    }
    return maxi;
    
}
//Optimal Method------------------------------------------------------------------------------------------------
int Profit2(vector<int> &arr){
    int n = arr.size();
    int currProfit=0;
    int mini=arr[0];
    int maxi=0;
    for (int i = 1; i < n; i++)
    {
        currProfit=arr[i]-mini;
        maxi=max(currProfit,maxi);
        mini=min(mini,arr[i]);
    }
    return maxi;
    
    
    
}
int main(){
    vector<int> arr={7,1,5,3,6,4,9};
    cout<<Profit2(arr)<<endl;
    return 0;
}

/*
Brute Force Method------------------------------------------------------------------------------------------------
Time Complexity: O(n²) Because for each element, we are checking every future element nested loops.
Space Complexity: O(1) No extra space used, only variables for storing max profit.
*/

/*
Optimal Method------------------------------------------------------------------------------------------------
Time Complexity: O(n),This is because we are iterating through the array of prices exactly once. There are no nested loops or recursive calls.
Space Complexity: O(1),Only two variables are used to store the minimum price and maximum profit, regardless of the input size.
*/