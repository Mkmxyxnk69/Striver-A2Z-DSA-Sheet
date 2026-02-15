#include<iostream>
using namespace std;

//Brutal method--------------------------------------------------------------------------------------------------------
int missingNumber1(vector<int> &arr){
    int n=arr.size()+1;
    for (int  i = 1; i < n; i++)
    {
        int count=0;
        for (int j= 0; j < n-1; j++)
        {
            if (arr[j]==i)
            {
                count=1;
                break;
            }
        }
    if (count==0)
    {
        return i;
    }   
    }
    return -1;  
}

//Optimal method --------------------------------------------------------------------------------------------------------
int missingNumber2(vector<int> &arr){
    int sum1=0;
    int n=arr.size()+1;
    int total=(n*(n+1)/2);
    for (int i = 0; i < n-1; i++)
    {
        sum1=sum1+arr[i];
    }
    int missingNum=total-sum1;
    return missingNum;
    
}

int main(){
    vector<int> arr={1,2,3,4,5,7};
    cout<<missingNumber1(arr);
    cout<<missingNumber2(arr);
    
    return 0;
}

/*
Optimal Method--------------------------------------------------------------------------------------------------------
Time Complexity: O(N). Single loop is used
Space Complexity: O(3N) where 3 is for the stack, left small array and a right small array
*/