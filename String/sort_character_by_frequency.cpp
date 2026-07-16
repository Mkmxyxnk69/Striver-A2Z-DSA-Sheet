#include<iostream>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        string s1="";
        for(int i =0; i < n ; i++){
            mp[s[i]]++;
        }
        vector<pair<char, int>> vec(mp.begin(), mp.end());
    
        // Sort by value in descending order
        sort(vec.begin(), vec.end(), 
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;  // descending by value
                });
        
        for(auto it : vec){
            int n = it.second;
            for(int i = 0 ; i < n ; i++){
                s1+= it.first;
            }
        }
        return s1;
    }
};

int main(){
    
    return 0;
}