#include<iostream>
using namespace std;

//Brute Force Method----------------------------------------------------------------------------------------------------------------------
string reverseString(string &s){
    int n = s.length();
    vector<string> words;
    string word="";
    for(auto it : s){
        if (it!=' ')
        {
            word += it;
        }
        else if (!word.empty()){
            words.push_back(word);
            word="";
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    reverse(words.begin(),words.end());
    string res="";
    for (int i = 0; i < words.size(); i++)
    {
        res+=words[i];
        res+=" ";
    }
    return res;
    
}

//Optimal Method----------------------------------------------------------------------------------------------------------------------
string reverseString2(string &s){
    int n = s.length();
    int i =n-1;

    string res="";
    while(i>=0){
        while (i >= 0 && s[i] == ' ') {
                i--;
            }
        if (i < 0) break;
        int j=i;
        while (i >= 0 && s[i] != ' ') {
                i--;
            }
        string word=s.substr(i+1,j-i);
        if (!res.empty())
        {
            res+=" ";
        }
        res+=word;
    }
    return res;
}

int main(){
    string s = " amazing coding skills ";
    cout<<reverseString2(s);
    return 0;
}

/*
Brute Force Method----------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N),We traverse the string once to collect words (O(N)) and once more to reverse and join them (O(N)). Hence total time is O(N).

Space Complexity: O(N),We store all words in a separate list/array, requiring extra space proportional to the number of characters.
*/

/*
Optimal Method----------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N), We traverse the string once from right to left and construct the result directly without extra passes.

Space Complexity: O(1),Ignoring the output string, no additional data structures proportional to input size are used.
*/