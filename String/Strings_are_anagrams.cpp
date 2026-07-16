#include<iostream>
#include<map>
using namespace std;

//Brute Force Method 1-------------------------------------------------------------------------------------------------------
bool Anagram(string &s1,string &s2){
    map<char,int> mpp1;
    map<char,int> mpp2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        mpp1[s1[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        mpp2[s1[i]]++;
    }
    for (int i = 0; i <n; i++)
    {
        if (mpp1[s1[i]]!=mpp2[s1[i]])
        {
            return false;
        }
        
    }
    return true;
}

//Brute Force Method 2-------------------------------------------------------------------------------------------------------
bool Anagram2(string &s1,string &s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int n1 = s1.size();
    int n2=s2.size();
    if (n1!=n2)
    {
        return false;
    }
    for (int i = 0; i < n1; i++)
    {
        if (s1[i]!=s2[i])
        {
            return false;
        }
        
    }
    return true;
    
}

//Optimal Method-------------------------------------------------------------------------------------------------------
bool Anagram3(string &s1,string &s2){
    int frequency[26]={0};
    int n1=s1.length();
    int n2=s2.length();
    if (n1!=n2){
        return false;
    }
    for (int i = 0; i < n1; i++)
    {
        frequency[s1[i]-'a']++;
        frequency[s2[i]-'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (frequency[i]!=0)
        {
            return false;
        }
    }
    return true;
}
int main(){
    string s1="abcde";
    string s2="bcdea";
    cout<<Anagram3(s1,s2);
    return 0;
}
/*
Brute Force Method 1-------------------------------------------------------------------------------------------------------
Time Complexity: O(N log N)
Space Complexity: O(1)
*/

/*
Better Force Method 2-------------------------------------------------------------------------------------------------------
Time Complexity: O(N log N), where N is the length of the strings. This is due to the sorting step performed on both strings.

Space Complexity: O(1), as the sorting is done in-place and no extra space proportional to input size is used (excluding the input strings themselves).
*/

/*
Optimal Method-------------------------------------------------------------------------------------------------------
Time Complexity: O(N), where N is the length of the strings. Each string is traversed once, and the frequency array is checked in constant time (26 iterations).

Space Complexity: O(1), as a fixed-size array of 26 elements is used regardless of the input size
*/