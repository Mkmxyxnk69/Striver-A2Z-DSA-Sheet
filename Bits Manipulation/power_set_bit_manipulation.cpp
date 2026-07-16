#include<iostream>
using namespace std;

vector<vector<int>> getPowerSet(vector<int> &arr){
    int n = arr.size();
    int subsets = 1<<n;
    vector<vector<int>> ans;
    for (int i = 0; i < subsets; i++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++)
        {
            if (i & (1<<j))
            {
                subset.push_back(arr[j]);
            }
            
        }
        ans.push_back(subset);
    }
    return ans;  
}



int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> subsets = getPowerSet(arr);
    cout << "Subsets: " << endl;
    for (auto subset : subsets) {
        cout << "[ ";
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0; 
}

/*
Time Complexity: O(N x 2N) where N is the number of elements in the input array. Iterating through all possible numbers from 0 to 2N-1 where N is the number of elements in the input array requires O(2N) iterations.For each iteration, we perform O(N) operations to construct the corresponding subset by interpreting the bits of the number.

Space Complexity: O(N x 2N) where N is the number of elements in the input array. We store all subsets in a list. Since there are 2N subsets in the power set, each subset can have at most N elements.
*/