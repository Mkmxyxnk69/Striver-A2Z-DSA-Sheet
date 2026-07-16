#include<iostream>
using namespace std;
int TotalSum(vector<int> &arr,int num){
    int sum=0;
    for(int pile:arr){
        sum+=(pile + num - 1) / num;
    }
    return sum;
}

int SmallestDivisor(vector<int>&arr,int threshold){
    if (arr.size() > threshold) return -1;
    int max_value=*max_element(arr.begin(),arr.end());
    int low =1;
    int high=max_value;
    int ans=max_value;

    while (low<=high)
    {
        int mid= low+(high-low)/2;
        if (TotalSum(arr,mid)<=threshold)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return ans;
}
int main(){
    vector<int> arr={21212,10101,12121};
    cout<<SmallestDivisor(arr,1000000);
    return 0;
}

/*
Optimal Method
Time Complexity: O(N × log(M))
jahaan N = arr.size(), M = max(arr[i])

Space Complexity: O(1)
*/