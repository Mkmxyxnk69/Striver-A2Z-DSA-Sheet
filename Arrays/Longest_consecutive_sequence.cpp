#include<iostream>
#include <unordered_set>
using namespace std;

//Brute Force Method--------------------------------------
bool LinearSearch(vector<int> &nums,int x){
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]==x)
        {
            return true;
        }
        
    }
    return false;
}
int longestSequence(vector<int> &nums){
    int n = nums.size();
    int longest=1;
    for (int i = 0; i < n; i++)
    {
        int x=nums[i];
        int count = 1;
        while (LinearSearch(nums,x+1)==true)
        {
            x=x+1;
            count++;
        }
        longest=max(longest,count);
    }
    return longest;
    
}

//Better Method--------------------------------------
int longestSequence2(vector<int> &nums){
    if (nums.empty()) return 0;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int cnt =0;
    int longest=1;
    int lastNum=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i]-1==lastNum)
        {
            cnt++;
            lastNum=nums[i];
        }
        else if (lastNum!=nums[i]-1){
            cnt=1;
            lastNum=nums[i];
        }
        longest=max(longest,cnt);
    }
    return longest;
}

//Optimal Method--------------------------------------
int longestSequence3(vector<int> &nums){
    if (nums.empty()) return 0;
    int longest=1;
    int n = nums.size();
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums[i]);
    }
    for(auto it : st){
        if (st.find(it-1)==st.end())
        {   
            int cnt=1;
            int x=it;
            while (st.find(x+1)!=st.end())
            {
                x=x+1;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> nums={102,4,100,1,2,1,1};
    cout<<longestSequence3(nums);
    return 0;
}

/*
Brute Force Method--------------------------------------
Time Complexity: O(n2), where n is the number of elements in the array. This is because for each element, we may need to perform a linear search through the entire array to find consecutive numbers.
-Space Complexity: O(1), as we are using a constant amount of extra space for variables.
*/

/*
Better Method--------------------------------------
Time Complexity: O(n log n), where n is the number of elements in the array. This is due to the sorting step, which is the most time-consuming operation in this approach.
Space Complexity: O(1), as we are using only a constant amount of extra space.
*/

/*
Optimal Method--------------------------------------
Time Complexity: O(n), where n is the number of elements in the array. This is because we traverse each element once to build the set and then again to find the longest consecutive sequence.
Space Complexity: O(n), as we use a set to store the unique elements of the array, which in the worst case can be equal to the size of the input array.
*/

