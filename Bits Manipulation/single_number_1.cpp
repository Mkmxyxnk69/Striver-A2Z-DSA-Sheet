#include<iostream>
using namespace std;

//Brute Force Method
//(loop)

//Better Method
//(hash map\)

//Optimal Method
int singleNumber(vector<int> &arr){
    int n = arr.size();
    int xorr=arr[0];
    for (int i = 1; i < n; i++)
    {
        xorr=xorr^arr[i];
    }
    return xorr;
    
}
int main(){
    vector<int> arr={1,2,2,1,2,4,1,2,1};
    cout<<singleNumber(arr);
    return 0;
}