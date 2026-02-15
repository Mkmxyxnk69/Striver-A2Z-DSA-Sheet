#include<iostream>
using namespace std;

// Brute force--------------------------------------------------------------------------------
void zeroEnd1(vector<int> &arr){
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]!=0)
        {
            temp.push_back(arr[i]);
        }
        
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i]=temp[i];
    }
    for (int i = temp.size(); i < arr.size(); i++)
    {
        arr[i]=0;
    }
    
    
    
}
// Optimal Method--------------------------------------------------------------------------------
void zeroEnd2(vector<int> &arr){
   int j=-1;
   for (int i = 0; i < arr.size(); i++)
   {
    if (arr[i]==0)
    {
        j=i;
        break;
    }
   }
   for (int i = j+1; i < arr.size(); i++)
   {
    if (arr[i]!=0)
    {
        swap(arr[i],arr[j]);
        j++;
    }
    
   }
   
    
    
}
int main(){
    vector<int> arr={1,2,0,3,0,0,4,0,5,6};
    zeroEnd2(arr); 
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

/*
Brute force--------------------------------------------------------------------------------
Time Complexity: O(N), we can move all zeroes to end in linear time.
Space Complexity: O(N), additional space used for temporary array.
*/

/*
Optical Approach--------------------------------------------------------------------------------
Time Complexity: O(N), we can move all zeroes to end in linear time.
Space Complexity: O(1), constant additional space is used.
*/