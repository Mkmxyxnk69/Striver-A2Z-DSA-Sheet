#include<iostream>
using namespace std;

//Brute Force Method
int xorNumber(int left,int right){
    int xorr=left;
    for(int i = left+1;i<=right;i++){
        xorr=xorr^i;
    }
    return xorr;
}

//Optimal Method
int xorNum1toN(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    else return n;
}
int xorNumber2(int left,int right){
    int xorRight=xorNum1toN(right);
    int xorLeft=xorNum1toN(left-1);
    int res=xorRight^ (xorLeft);
    return res;
}
int main(){
    cout<<xorNumber2(3,5);
    return 0;
}