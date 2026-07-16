#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        string subString;
        int sign=1;
        int cnt=0;
        for(int i =0; i <n ; i++){
            if(s[i]==' ') cnt++;
            else break;
        }
        s=s.substr(cnt);
        n=s.size();
        long long ans = 0;
        for(int i = 0 ; i < n ; i++ ){
            if(i==0 && s[i]=='-') {
                sign = -1;
                continue;
            }
            if(i==0 && s[i]=='+') {
                sign = +1;
                continue;
            }

            if(s[i]>='0' && s[i]<='9'){
                int digit=s[i]-'0';
                if(ans>INT_MAX/10){
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                ans=ans*10+digit;
            }
            else{break;}
        }
        ans= ans*sign;
        if(ans>=INT_MAX) return INT_MAX;
        if(ans<=INT_MIN) return INT_MIN;
        return ans;
    }
};

int main(){
    
    return 0;
}