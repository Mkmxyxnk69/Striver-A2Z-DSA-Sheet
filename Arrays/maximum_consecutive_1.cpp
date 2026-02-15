#include<iostream>
using namespace std;

int maximum(vector<int> &arr){
    int maxCount=0;
    int count=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==1)
        {
            count++;
        }
        else if (arr[i]!=1){
            count=0;
        }
        if(count>=maxCount){
        maxCount=count;
        } 
    }
    return maxCount;
    
}
int main(){
    vector<int> arr={1,0,1,1,1,0,0,1,1,0};
    cout<<maximum(arr);
    return 0;
}

// Time Complexity: O(N), since we scan the array once.
// Space Complexity: O(1), as only constant extra variables are used.