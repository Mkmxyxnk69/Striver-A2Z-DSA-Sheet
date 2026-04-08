#include<iostream>
#include<map>
using namespace std;

//Brute Force Method----------------------------------------------------------------------------
int countSubArraySumK1(vector<int> &arr,int num){
    int n = arr.size();
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum=0;
            for (int k= i; k <=j; k++)
            {
                sum+=arr[k];
            }
            if (sum==num)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

//Better Method----------------------------------------------------------------------------
int countSubArraySumK2(vector<int> &arr,int num){
    int n = arr.size();
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            if (sum==num)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

//Optimal Method----------------------------------------------------------------------------
int countSubArraySumK3(vector<int> &arr, int num){
    int n = arr.size();
    map<int,int> mpp;
    mpp[0]=1;
    int count=0,preSum=0;
    for (int i = 0; i < n; i++)
    {
        preSum+=arr[i];
        int remove=preSum-num;
        count+=mpp[remove];
        mpp[preSum]+=1;
    }
    return count;
}
int main(){
    vector<int> arr={1,2,3,-3,1,1,1,4,2,-3};
    int res=countSubArraySumK3(arr,3);
    cout<<res;
    
    return 0;
}

/*
Brute Force Method----------------------------------------------------------------------------
Time Complexity: O(N3), where N = size of the array.We are using three nested loops here. Though all are not running for exactly N times, the time complexity will be approximately O(N3).
Space Complexity: O(1) as we are not using any extra space
*/

/*
Better Method----------------------------------------------------------------------------
Time Complexity: O(n²),We use two nested loops to check all subarrays, where n is the size of the array.
Space Complexity: O(1),Only a few extra variables are used, so constant extra space regardless of input size.
*/

/*
Optimal Method----------------------------------------------------------------------------
Time Complexity: O(n*logn)
Space Complexity: O(N)
*/
