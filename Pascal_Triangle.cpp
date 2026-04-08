#include<iostream>
using namespace std;
//Problem 1 
// In this type of problem we have to find the number in the pascal triangle when rows and columns is give.
long long nCr(int n, int r){
    int res=1;
    for (int i = 0; i < r; i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
    
}

//Problem 2
//In this we have to print the whole row of the pascal triangle , where row index is given to us
//Brute Force Method
void rows(int n){
    for (int c = 1; c <= n; c++)
    {
        cout<<nCr(n-1,c-1)<<" ";
        
    }
    
}
//Optimal Method
void rows2(int n){
    int ans =1;
    cout<<ans<<" ";
    for (int i = 1; i <  n; i++)
    {
        ans=ans*(n-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
    
}

//Problem 3
//In this we have to print complete pascal triangle of nth row
//Brute Force Method
void Pascal(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int c = 1; c<=i; c++)
        {
            cout<<nCr(i-1,c-1)<<" ";
        }
        cout<<endl;
    }
}

void Pascal2(int n){
    for (int j= 1; j <= n; j++)
    {
    int ans =1;
    cout<<ans<<" ";
    for (int i = 1; i <  j; i++)
    {
        ans=ans*(j-i);
        ans=ans/i;
        cout<<ans<<" ";
    }
    cout<<endl;
    }
    
}
int main(){
    // int r=5;
    // int c=4;
    // cout<<nCr(r-1,c-1);
    // rows(6);
    // cout<<endl;
    // rows2(6);
    Pascal2(6);
    return 0;
}
