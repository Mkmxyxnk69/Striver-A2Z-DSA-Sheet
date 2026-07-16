#include<iostream>
using namespace std;

//Brute Force Method----------------------------------------------------------------------------------------------------------------------
bool isRotational(string &s1,string &s2){
    int n =s1.size();
    string rotated;
    for (int i = 0; i < n; i++)
    {
        rotated=s1.substr(i)+s1.substr(0,i);
        if (rotated==s2)
        {
            return true;
        }
        
    }
    return false;
}

//Optimal Method---------------------------------------------------------------------------------------------------------------------- 
bool isRotational2(string &s1,string &s2){
    string doubledS=s1+s1;
    return doubledS.find(s2) != string::npos;
}
int main(){
    string s1 = "rotation";
    string s2 = "tionrota";
    cout<<isRotational2(s1,s2);

    return 0;
}

/*
Brute Force Method----------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N^2) since generating N rotations and each comparison takes O(N) time.

Space Complexity: O(N) for the space needed to store each rotated string
*/

/*
Optimal Method----------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N), because checking for a substring in s + s is linear in time.

Space Complexity: O(N) for the space needed to store the concatenated string s + s.
*/