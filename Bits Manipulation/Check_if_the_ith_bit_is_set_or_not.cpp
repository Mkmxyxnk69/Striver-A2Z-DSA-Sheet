#include<iostream>
using namespace std;

bool isSetOrNot(int n,int bitIndex){
    return (n&(1<<bitIndex))!=0;
}
int main(){
    int n=500;
    int bitIndex=3;
    if (isSetOrNot(n,bitIndex))
    {
        cout<<"It is set 1"<<endl;
    }
    else{
        cout<<"It is set 0"<<endl;
    }
    
    return 0;
}