#include<iostream>
#include<map>
using namespace std;

//Brute Force Method
int numberOfSubArray1(vector<int> &arr, int m){
    int n= arr.size();
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xorr=0;
            for (int k = i; k <= j; k++)
            {
                xorr=xorr^arr[k];
            }
            if (xorr==m)
            {
                count++;
            }   
        }
    }
    return count;
}

//Better Method
int numberOfSubArray2(vector<int> &arr, int m){
    int n= arr.size();
    int count=0;
    for (int i = 0; i < n; i++)
    {
        int xorr=0;
        for (int j = i; j < n; j++)
        {
            xorr=xorr^arr[j];
            if (xorr==m)
            {
                count++;
            }   
        }
    }
    return count;
}

//Optimal Method
int numberOfSubArray3(vector<int> &arr, int m){
    int n= arr.size();
    map<int,int> mpp;
    mpp[0]=1;
    int count=0,xr=0;
    for (int i = 0; i < n; i++)
    {
        xr=xr^arr[i];
        int x = xr^m;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;
}
int main(){
    vector<int> arr={4,2,2,6,4};
    int res=numberOfSubArray3(arr,6);
    cout<<res;
    return 0;
}