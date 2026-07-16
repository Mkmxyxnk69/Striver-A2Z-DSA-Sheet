#include<iostream>
#include<set>
using namespace std;

bool findingDistant(string s,int k){
    int n = s.size();
    
    if(set<char> (s.begin(),s.end()).size()==k){
        return true;
    }
    return false;
}

int atMostKDistinct(string s, int k){
    int n = s.size();
    
    set<string> s1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (findingDistant(s.substr(i,j-i+1),k))
            {
                cout<<s.substr(i,j-i+1)<<endl;
                s1.insert(s.substr(i,j-i+1));
                
            }
        }
    }
    return s1.size();
}

int main(){
    string s ="zatpvvsnhx";
    cout<<atMostKDistinct(s,1);
    return 0;
}