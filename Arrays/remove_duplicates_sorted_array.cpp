#include<iostream>
#include<vector>
using namespace std;

//Brute Force Method
void removeDuplicates1(vector<int> &arr){
    vector<int> temp;
    for (int  i = 0; i < arr.size(); i++)
    {
        if (arr[i]==arr[i+1])
        {
            temp.push_back(i);
        }
        
    }
    for (int i = temp.size()-1; i >= 0; --i) {
        int pos = temp[i];
        if (pos >= 0 && pos < (int)arr.size())   // bounds check
        {
        arr.erase(arr.begin() + pos);
        }
    } 
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<arr.size(); 
}
//Optimal Method(function)
int removeDuplicates(vector<int> &arr){
    int i =0;
    for (int j = 1; j< arr.size(); j++)
    {
        if (arr[j]!=arr[i])
        {
            arr[i+1]=arr[j];
            i++;
        }
        
    }
    return i+1;
}
int main(){
    vector<int> arr={1,2,2,2,3,3,3,4,5,5,6,7};
    
    //Brute Force Method------------------------------------------------------------------------
    removeDuplicates1(arr);
    
    //Optimal Method ------------------------------------------------------------------------------------
    int k = removeDuplicates(arr);

    cout << "k = " << k << "\n";
    for (int idx = 0; idx < k; idx++)
        cout << arr[idx] << " ";
    

    return 0;
}

/*
Optimal Method 
Time Complexity: O(N), We traverse the entire original array only once.
Space Complexity: O(1), constant additional space is used to check unique elements
*/