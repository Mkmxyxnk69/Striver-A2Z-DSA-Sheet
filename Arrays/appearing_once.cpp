#include<iostream>
#include<map>
using namespace std;

//BetterMethod--------------------------------------------------------------------------------------------
void appearingOnce(vector<int> &arr){
    map<long long ,int>temp;
    for (int i = 0; i < arr.size(); i++)
    {
        temp[arr[i]]++;
    }

    for (auto it = temp.begin(); it != temp.end(); it++)
    {
        if (it->second==1)
        {
            cout<<it->first<<endl;
        }
        
        
    }
}

//OptimalMethod--------------------------------------------------------------------------------------------
int appearingOnce2(vector<int> &arr){
    int xorr=0;
    for (int i = 0; i < arr.size(); i++)
    {
        xorr=xorr^arr[i];
    }
    return xorr;
    
}

int main(){
    vector<int> arr={1,1,2,3,3,4,4};
    //Better Method Output-----------------------------------------------------------------------------------
    appearingOnce(arr);

    //Optimal Method Output----------------------------------------------------------------------------------
    cout<<appearingOnce2(arr);
    return 0;
}

/*
//Better Method----------------------------------------------------------------------------------------------
Time Complexity: O(NlogM). Where N is the size of the array and M is the size of the map
Space Complexity: O(M).  Where M is the size of the map
*/

/*
Optimal Method-------------------------------------------------------------------------------------------------
Time Complexity: O(N). Where N is the size of the array
Space Complexity: O(1). No extra space used
*/