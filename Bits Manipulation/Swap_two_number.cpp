#include<iostream>
using namespace std;
void swapping(int a,int b){
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a is "<<a<<endl;
    cout<<"b is "<<b<<endl;
}
int main(){
    int a =5;
    int b =6;
    swapping(a,b);
    return 0;
}