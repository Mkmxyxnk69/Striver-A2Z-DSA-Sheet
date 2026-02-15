#include<iostream>
using namespace std;

//Brute Force Method--------------------------------------------------------------------------------------------------------------------------
vector<int> Leader1(vector<int> &arr){
    vector<int> temp;
    int n=arr.size();
    for (int i = 0; i < n; i++)
    {
        bool leader=true;
        for (int  j = i+1; j < n; j++)
        {
            if (arr[j]>arr[i])
            {
                leader=false;
                break;
            }
            
        }
        if (leader==true)
        {
            temp.push_back(arr[i]);
        }
        
        
    }
    
    return temp;
    
}
//Optimal Method--------------------------------------------------------------------------------------------------------------------------
vector<int> Leader2(vector<int> &arr){
    vector<int> temp;
    int n=arr.size();
    int Maxi=INT_MIN;
    for (int i = n-1; i >=0; i--)
    {
        if (arr[i]>Maxi)
        {
            temp.push_back(arr[i]);
        }
        Maxi=max(Maxi,arr[i]);
        
    }
    return temp;
    
}

int main(){
    vector<int> arr={10, 22, 12, 3, 0, 6,7};

    //Brute Force Method output-------------------------------------------------------------------------------------------------------------
    // vector<int> res1=Leader1(arr);
    // for(auto it1 : res1){
    //     cout<<it1<<" ";
    // }

    //Optimal Method Output-----------------------------------------------------------------------------------------------------------------
    vector<int> res2=Leader2(arr);
    for(auto it2 : res2){
        cout<<it2<<" ";
    }
    return 0;
}

/*
Brute Force Method--------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N^2), where N is the size of the input array. This is because we have a nested loop where the outer loop runs N times and the inner loop runs up to N times in the worst case.
Space Complexity: O(1), as we are using only a constant amount of extra space for the answer array, which does not depend on the input size
*/

/*
Optimal Method--------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N), where N is the size of the input array. This is because we traverse the array only once.
Space Complexity: O(1), as we are using only a constant amount of extra space.
*/