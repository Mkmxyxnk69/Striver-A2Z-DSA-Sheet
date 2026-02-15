#include<iostream>
#include<map>
using namespace std;

//Better Method------------------------------------------------------------------------------------------------------
void Maxx(vector<int> &arr){
    map<int,int> mpp;
    int n=arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if (it.second>n/2)
        {
            cout<<it.first<<" is repeating "<<it.second<<" time "<<endl;
        }   
    }
}

//Optimal Method(Moore's Voting Algorithm)---------------------------------------------------------------------------
int Maxx2(vector<int> &arr){
    int count1 =0;
    int el;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count1==0)
        {
            count1=1;
            el=arr[i];
        }
        else if (el==arr[i])
        {
            count1++;
        }
        else count1--;
    }
    int count2=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==el)
        {
            count2++;
        }
    }
    if (count2>arr.size()/2)
    {
        return el;
    }
    return -1;
    
    
    
}
int main(){
    vector<int> arr={2,2,1,1,2,2,3,2,1,1,1,1};
    //Better Method----------------------------------------------------------------------------------------------
    // Maxx(arr);

    //optical Method---------------------------------------------------------------------------------------------
    cout<<Maxx2(arr);
    return 0;
}

/*
Better Method-----------------------------------------------------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

/*
Optimal Method----------------------------------------------------------------------------------------------------
Time Complexity: O(N), where N is the size of the input array. This is because we are iterating through the array once to find the potential majority element and then again to verify it.
Space Complexity: O(1), as we are using only a constant amount of extra space.
*/
