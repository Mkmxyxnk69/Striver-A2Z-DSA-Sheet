#include<iostream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int total=0;
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='I'){
                if(s[i+1]=='V' || s[i+1]=='X'){
                    total-=1;
                }
                else{
                    total+=1;
                }
            }
            if(s[i]=='V') total+=5;
            if(s[i]=='X') {
                if(s[i+1]=='L' || s[i+1]=='C'){
                    total-=10;
                }
                else{
                    total+=10;
                }
            }
            if(s[i]=='L') total+=50;
            if(s[i]=='C'){
                if(s[i+1]=='D' || s[i+1]=='M'){
                    total-=100;
                }
                else{
                    total+=100;
                }
            }
            if(s[i]=='D') total+=500;
            if(s[i]=='M') total+=1000;
        }
        return total;
    }
};
int main(){
    
    return 0;
}