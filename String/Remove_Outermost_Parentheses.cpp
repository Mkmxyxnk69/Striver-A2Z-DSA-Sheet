#include<iostream>
#include<string>
using namespace std;
string validParenthesis(string &str){
    string ans="";
    int level=0;
    int n = str.length();
    for(auto it : str){
        if (it=='(')
        {
            if (level>0)
            {
                ans+=it;
            }
            level++;
        }
        else if(it==')'){
            level--;
            if (level>0)
            {
                /* code */
                ans+=it;
            }
            
        }
        
    }
    return ans;

}
int main(){
    string s = "(()())(())";
    cout<<validParenthesis(s);
    return 0;
}

/*
Time Complexity: O(n), since we are performing a single traversal of the string.
Space Complexity: O(1), since we are using a few variables to track the current state.
*/