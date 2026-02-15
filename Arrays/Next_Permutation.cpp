#include<iostream>
using namespace std;

//Optimal Method--------------------------------------------------------------------------------------------------------------------------
vector<int> permutation(vector<int> &arr){
    int n=arr.size();
    int idx=-1;
    for (int i = n-2; i >=0; i--)
    {
        if (arr[i]<arr[i+1])
        {
            idx=i;
            break;
        }
    }
    if (idx==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
   
    
    for (int i = n-1; i >idx; i--)
    {
        if (arr[i]>arr[idx])
        {
            swap(arr[idx],arr[i]);
            break;
        }
        
    }
    reverse(arr.begin()+idx+1,arr.end());
    return arr;
    
    
}
int main(){
    vector<int> arr={1,2,3};
    vector<int> res=permutation(arr);
    for(auto it : res){
        cout<<it<<" ";
    }
    return 0;
}

/*Optimal Method--------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N), we find the breaking point and reverse the subarray in linear time.
Space Complexity: O(1), constant additional space is used
*/