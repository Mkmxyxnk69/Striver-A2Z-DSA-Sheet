#include<iostream>
using namespace std;
string longestPrefix(vector<string> &s){
    int n = s.size();
    sort(s.begin(),s.end());
    string s1=s[0];
    string s2=s[n-1];
    int minlength=min(s1.length(),s2.length());
    string ans="";
    for (int i = 0; i < minlength; i++)
    {
        if (s1[i]!=s2[i])
        {
            break;
        }
        ans+=s1[i];
    }
    return ans;
}
int main(){
    vector<string> input = {"interview", "internet", "internal", "interval"};
    
    cout<<longestPrefix(input);
    return 0;
}