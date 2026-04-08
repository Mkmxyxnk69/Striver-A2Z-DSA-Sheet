#include<iostream>
#include<set>
using namespace std;

//Brute Force Method---------------------------------------------------------------------------
vector<vector<int>> SumZero1(vector<int> &arr,int target){
    int n =arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k <n; k++)
            {
                for (int l=k+1; l < n; l++)
                {
                    if (arr[i]+arr[j]+arr[k]+arr[l]==target)
                    {
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    
                }
                
            }
            
        }
        
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//Better Force Method---------------------------------------------------------------------------
vector<vector<int>> SumZero2(vector<int> &arr,int target){
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j<n; j++)
        {
            set<int> hashset;
            for (int k = j+1; k<n; k++)
            {
                int fourth=target-(arr[i]+arr[j]+arr[k]);
                if (hashset.find(fourth)!=hashset.end())
                {
                    vector<int> temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
            
        }
        
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
    
}
//Optimal Method---------------------------------------------------------------------------
vector<vector<int>> SumZero3(vector<int> &arr,int target){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        if (i>0 && arr[i]==arr[i-1])
        {
            continue;
        }
        for (int j = i+1; j < n; j++)
        {
            if (j>i+1 && arr[j]==arr[j-1])
            {
                continue;
            }
        
            int k =j+1;
            int l = n-1;
            while(k<l){
                int sum=arr[i]+arr[j]+arr[k]+arr[l];
                if (sum==target)
                {
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    st.push_back(temp);
                    k++;
                    l--;
                    while (k<l && arr[k]==arr[k-1])
                    {
                        k++;
                    }
                    while (k<l && arr[l]==arr[l+1])
                    {
                        l--;
                    }
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
        }
        }
        
    }
    return st;
}

int main(){
    vector<int> arr = {4,3,3,4,4,2,1,2,1,1};
    int target=9;
    vector<vector<int>> res=SumZero3(arr,target);
    for(auto it : res){
        for(auto zero : it){
            cout<<zero<<" ";
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
Time Complexity: O(N3*log(M)), as we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.

Space Complexity: O(2 * no. of the quadruplets)+O(N), as we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).
*/

/*
Optimal Method---------------------------------------------------------------------------
Time Complexity: O(N3), as Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 

Space Complexity: O(no. of quadruplets), as This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/