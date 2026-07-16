#include<iostream>
using namespace std;

// Brute Force Method
int Number(vector<int> &arr){
    int n = arr.size();
    int ans=0;
    for (int i = 0; i < 32; i++)
    {
        int cnt=0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1<<i))
            {
                cnt++;
            }
        }
        if (cnt%3==1)
        {
            ans=ans | (1<<i);
        }
    }
    return ans;
}

// Better Method
int Number2(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    for (int i = 1; i < n; i=1+3)
    {
        if (arr[i-1]!=arr[i])
        {
            return arr[i-1];
        }
        
    }
    return arr[n-1];   
}

//Optimal Method(Bucket Method)
int Number3(vector<int> &arr){
    int n = arr.size();
    int ones=0;
    int twos=0;
    for (int i = 0; i <n; i++)
    {
        ones=(ones^arr[i])&(~twos);
        twos=(twos^arr[i])&(~ones);
    }
    return ones;
}
int main(){
    vector<int> arr={5,5,5,6,6,6,4,3,3,4,4,3,2,2,2,1};
    cout<<Number3(arr);
    return 0;
}