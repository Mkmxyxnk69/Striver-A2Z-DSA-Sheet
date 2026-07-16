#include<iostream>
using namespace std;

//Method 1
int countBits(int n ){
    int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        int x =i;
        while (x>0)
        {
            x=x&(x-1);
            cnt++;
        }
    }
    return cnt;
}


int main(){
    int n=10;
    int res=countBits(n);
    cout<<res;
    return 0;
}