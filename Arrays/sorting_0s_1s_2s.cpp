#include<iostream>
using namespace std;

//Better Method----------------------------------------------------------------------------------------
void sorting(vector<int> &arr){
    int n=arr.size();
    int count0=0,count1=0,count2=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==0)
        {
            count0++;
        }
        else if (arr[i]==1)
        {
            count1++;
        }
        else count2++;
        
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i]=0;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        arr[i]=1;
    }
    for (int i = count0 + count1; i < n; i++)
    {
        arr[i]=2;
    }

}

// Optimal Method ----------------------------------------------------------------------------------------
void sorting2(vector<int> &arr){
    int n=arr.size();
    int low=0, mid=0 , high=n-1;
    while (mid<=high)
    {
        if (arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
        
        
    }
    
}

int main(){
    vector<int> arr={1,1,2,2,0,0,1,0,2,0,1};

    //Better Method----------------------------------------------------------------------------------------
    // sorting(arr);
    // cout << "Sorted array: ";
    // for(int x : arr) {
    //     cout << x << " ";
    // }

    //Optimal Method(Dutch National Flag Algorithm)---------------------------------------------------------
    sorting2(arr);
    cout << "Sorted array2: ";
    for(int x : arr) {
        cout << x << " ";
    }
    
    return 0;
}

/*
Optimal Method---------------------------------------------------------------------------------------------
Time Complexity: O(n) The array is traversed only once using the `mid` pointer. Each element is checked at most once, and swaps are done in constant time.
Space Complexity: O(1) Only a few integer pointers (`low`, `mid`, `high`) are used. Sorting is done in-place, requiring no additional space.
*/