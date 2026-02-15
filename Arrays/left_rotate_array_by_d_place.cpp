#include<iostream>
#include <algorithm> 
#include <vector>
using namespace std;
//Brutal Method----------------------------------------------------------------------------------------
void leftRotateD(vector<int> &arr,int d){

    int d=d%arr.size();
    for (int k= 0; k< d; k++)
    {
        
        int temp=arr[0];
        for (int j = 1; j < arr.size(); j++)
        {
            arr[j-1]=arr[j];
            
        }
        arr[arr.size()-1]=temp;    
    }
    
}
//Better Method----------------------------------------------------------------------------------------
void leftRotateD2(vector<int> &arr, int d) {
    vector<int> temp;
    int D = d % arr.size();
    for (int i = 0; i < D; i++)
        temp.push_back(arr[i]);

    for (int i = D; i < arr.size(); i++)
        arr[i - D] = arr[i];

    for (int i = 0; i < D; i++)
        arr[arr.size() - D + i] = temp[i];
}

//Optimal method----------------------------------------------------------------------------------------
void leftRotateD3(vector<int> &arr, int d) {
    int D = d % arr.size();

    reverse(arr.begin(), arr.begin() + D);   // first D
    reverse(arr.begin() + D, arr.end());    // remaining
    reverse(arr.begin(), arr.end());        // whole array
}

int main(){
    vector<int> arr={1,2,3,4,5,6};
    leftRotateD3(arr,2); 
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}