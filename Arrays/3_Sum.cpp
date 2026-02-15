#include<iostream>
#include <set>
using namespace std;

//Brute Force Method---------------------------------------------------------------------------
vector<vector<int>> SumZero(vector<int> &arr){
    int n=arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (arr[i]+arr[j]+arr[k]==0)
                {
                   vector<int> temp={arr[i],arr[j],arr[k]};
                   sort(temp.begin(),temp.end());
                   st.insert(temp);
                }
            }
            
        }
        
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Better Method---------------------------------------------------------------------------
vector<vector<int>> SumZero2(vector<int> &arr){
    int n=arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i+1; j < n; j++)
        {
            int third=-(arr[i]+arr[j]);
            if (hashset.find(third)!=hashset.end())
            {
                vector<int> temp={arr[i],arr[j],third};
                sort(arr.begin(),arr.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
            
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Optimal Method---------------------------------------------------------------------------
vector<vector<int>> SumZero3(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i>0 && arr[i]==arr[i-1])
        {
            continue;
        }
        int j = i + 1,k=n-1;
        while (j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if (sum<0)
            {
                j++;
            }
            else if (sum>0)
            {
                k--;
            }
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j<k && arr[j]==arr[j-1])
                {
                    j++;
                }
                while (j<k && arr[k]==arr[k+1])
                {
                    k--;
                }   
            }   
        }   
    }
    return ans;
}
int main(){
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res=SumZero3(arr);
    for(auto &it : res){
        for(auto &num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
Brute Force Method---------------------------------------------------------------------------
Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.
*/

/*
Better Method---------------------------------------------------------------------------
Time Complexity: O(N2 * log(no. of unique triplets)),
as we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
*/

/*
Optimal Method---------------------------------------------------------------------------
Time Complexity: O(NlogN)+O(N2), as The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/