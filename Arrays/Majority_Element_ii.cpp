#include<iostream>
#include<unordered_map>
using namespace std;

//Brute Force Method---------------------------------------------------------------------
void majorityElement1(vector<int> &arr){
    vector<int> ls;
    for (int i = 0; i < arr.size(); i++)
    {
        if (ls.size()==0 || ls[0]!=arr[i])
        {
            int cnt =0;
            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j]==arr[i])
                {
                    cnt++;
                }
            }
            if (cnt>(arr.size()/3))
            {
                ls.push_back(arr[i]);
            }
        }
        if (ls.size()==2)
        {
            break;
        }
    }
    for (int i = 0; i < ls.size(); i++)
    {
        cout<<ls[i]<<endl;
    }
}

//Better Method---------------------------------------------------------------------
void majorityElement2(vector<int> &arr){
    int n = arr.size();
    vector<int> ls;
    int mini = (n/3)+1;
    unordered_map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if (mpp[arr[i]]==mini)
        {
            ls.push_back(arr[i]);
        }
        if (ls.size()==2)
        {
            break;
        }
    }
    for (int i = 0; i < ls.size(); i++)
    {
        cout<<ls[i]<<endl;
    }
}

//Optimal Method---------------------------------------------------------------------
void majorityElement3(vector<int> &arr){
    int n = arr.size();
    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1==0 && arr[i]!=el2)
        {
            cnt1++;
            el1=arr[i];
        }
        else if ( cnt2==0 && arr[i]!=el1){
            cnt2++;
            el2=arr[i];
        }
        else if (el1==arr[i]) cnt1++;
        else if (el2==arr[i]) cnt2++;
        else{
            cnt1--;
            cnt2--;
        } 
    }
    vector<int> ls;
    cnt1=0,cnt2=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==el1)
        {
            cnt1++;
        }
        if (arr[i]==el2)
        {
            cnt2++;
        }  
    }
    int mini = int(n/3)+1;
    if (cnt1>=mini)
    {
        ls.push_back(el1);
    }
    if (cnt2>=mini)
    {
        ls.push_back(el2);
    }
    for (int i = 0; i < ls.size(); i++)
    {
        cout<<ls[i]<<endl;
    }
    
}


int main(){
    vector<int> arr = {11, 33, 33, 33, 33, 11};
    majorityElement3(arr);
    return 0;
}

/*
Brute Force Method---------------------------------------------------------------------
Time Complexity: O(N^2), where N is the size of the array. This is because for each element, we are traversing the entire array to count its occurrences.
Space Complexity: O(1), as we are using a constant amount of space for the result array, which can hold at most 2 elements.
*/

/*
Better Method---------------------------------------------------------------------
Time Complexity: O(N * logN), where N is the size of the given array. For using a map data structure, where insertion in the map takes logN time, and we are doing it for N elements. So, it results in the first term O(N * logN). On using unordered_map instead, the first term will be O(N) for the best and average case, and for the worst case, it will be O(N2).
Space Complexity: O(N) for using a map data structure. A list that stores a maximum of 2 elements is also used, but that space used is so small that it can be considered constant.
*/

/*
Optimal Method---------------------------------------------------------------------
Time Complexity: O(N), where N is the size of the input array. We traverse the array twice: once to find potential candidates and once to validate them.
Space Complexity: O(1), as we are using a constant amount of space for the counters and candidate elements, regardless of the input size.
*/