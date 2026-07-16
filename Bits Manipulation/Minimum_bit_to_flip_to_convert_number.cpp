#include<iostream>
using namespace std;

int minimumBit(int start,int goal){
    int num=start^goal;
    int cnt=0;
    while(num>0){
        num=num&(num-1);
        cnt++;
    }
    return cnt;
}
int main(){
    int ans=minimumBit(10,7);
    cout<<ans;
    return 0;
}