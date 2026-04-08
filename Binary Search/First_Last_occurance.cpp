#include<iostream>
using namespace std;

//My Method---------------------------------------------------------------------------------------
vector<int> Occurance1(vector<int> &arr, int target){
    vector<int> temp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==target)
        {
            temp.push_back(i);
        }
    }
    return temp;
    
}

//Brute Force Method---------------------------------------------------------------------------------------
vector<int> Occurance2(vector<int> &arr, int target){
    int first=-1,last=-1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==target)
        {
            if (first==-1)
            {
                first=i;
            }
            last=i;
            
        }
    }
    return {first , last};
    
}

//Optimal Method---------------------------------------------------------------------------------------
int First1(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high =n-1;
    int first=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==target)
        {
            first=mid;
            high=mid-1;
        }
        else if (arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}
int Last1(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high =n-1;
    int last=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==target)
        {
            last=mid;
            low=mid+1;
        }
        else if (arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return last;
}

pair<int,int> Occurance3(vector<int> &arr,int target){
    int firstttt=First1(arr,target);
    int lastttt=Last1(arr,target);
    return {firstttt,lastttt};
}
int main(){
    vector<int> arr={10,20,30,40,40,40,40,50,60};

    //Output for My Method---------------------------------------------------------------------------------------
    vector<int> res=Occurance1(arr,50);
    cout<<res[0]<<endl;
    cout<<res[res.size()-1]<<endl;

    //Brute Force Method---------------------------------------------------------------------------------------
    vector<int> r =Occurance2(arr,40);
    cout<<r[0]<<endl<<r[1]<<endl;

    //Optimal Method---------------------------------------------------------------------------------------
    pair<int,int> r1= Occurance3(arr,70);
    cout<<r1.first<<endl<<r1.second<<endl;
    return 0;
}

/*
Brute Force Method---------------------------------------------------------------------------------------
Time Complexity: O(N), where N is the size of the array. This is because we are traversing the array once to find the last occurrence of the target element.
Space Complexity: O(1), as we are using a constant amount of space for the result variable and the loop index. We are not using any additional data structures that grow with the input size
*/

/*
Optimal Method---------------------------------------------------------------------------------------
Time Complexity:O(logN), where N = size of the given array. We are using the Binary Search algorithm.
Space Complexity: O(1). No extra space used.
*/
