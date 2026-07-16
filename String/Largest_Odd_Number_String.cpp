#include<iostream>
using namespace std;
string largestOdd(string &s){
    int n=s.size();
    int index=n-1;
    for (int  i = n-1; i >=0; i--)
    {
        int digit=s[i]-'0';
        int check=digit%2;
        if (check==1)
        {
            break;
        }
        index--;
    }
    int j=0;
    while (j <= index && s[j] == '0') j++;

    return s.substr(j,index-j+1);
}
int main(){
    string s = "4206";
    cout<<largestOdd(s);
    return 0;
}