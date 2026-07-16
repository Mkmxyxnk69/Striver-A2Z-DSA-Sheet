#include<iostream>
using namespace std;

//Brute Force Method
int NthNumber(vector<int> &arr, int k){
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]<=k)
        {
            k++;
        }
        else{
            break;
        }
    }
    return k;
}
//Optimal Method
int NthNumber2(vector<int> &arr,int k){
    int n = arr.size();
    int high=n-1;
    int low=0;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        int missing=arr[mid]-(mid+1);
        if (missing<k)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    return low+k;

}


int main(){
    vector<int> arr{2,3,4,7,9,11};
    cout<<NthNumber2(arr,5);
    return 0;
}