#include<iostream>
using namespace std;
bool checkOddEven(int n ){
    return (n&1)==0;
}
int main(){
    int n = 1879;
    if (checkOddEven(n))
    {
        cout<<n<<" is even "<<endl;
    }
    else{
        cout<<n<<" is odd "<<endl;
    }
    return 0;
}