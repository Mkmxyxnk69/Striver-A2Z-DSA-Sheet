#include<iostream>
using namespace std;

//Brute Force Method---------------------------------------------------------------------------------------------------------------------
void Rearrange1(vector<int> &arr){
    vector<int> positive;
    vector<int> negative;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]<0)
        {
            negative.push_back(arr[i]);
        }
        else{
            positive.push_back(arr[i]);
        }
    }
    for (int i = 0; i <arr.size()/2 ; i++)
    {
        arr[2*i]=positive[i];
        arr[2*i+1]=negative[i];
    }
    
    
}

//Optimal Method---------------------------------------------------------------------------------------------------------------------
vector<int> Rearrange2(vector<int> &arr){
    vector<int> temp(arr.size(), 0);
    int pos=0;
    int neg=1;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]>=0)
        {
            temp[pos]=arr[i];
            pos=pos+2;
        }
        else{
            temp[neg]=arr[i];
            neg=neg+2;
        }
        
    }
    return temp;
    
    
    
}

//Variety 2  qyestion jbbb positive number!=negative number------------------------------------------------------------------------------------
void Rearrange3(vector<int> &arr){
    vector<int> positive;
    vector<int> negative;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]<0)
        {
            negative.push_back(arr[i]);
        }
        else{
            positive.push_back(arr[i]);
        }
    }
    if(positive.size()>negative.size()){
    for (int i = 0; i <negative.size() ; i++)
    {
        arr[2*i]=positive[i];
        arr[2*i+1]=negative[i];
    }
    for (int j = negative.size(); j < positive.size(); j++)
    {
        arr[j*2]=positive[j];
    }
}
    else{
        for (int i = 0; i <positive.size() ; i++)
    {
        arr[2*i]=positive[i];
        arr[2*i+1]=negative[i];
    }
    for (int j = positive.size(); j < negative.size(); j++)
    {
        arr[j*2]=negative[j];
    }

    }
    
    
}
int main(){
    vector<int> arr{1, 2,-9,-4, -5,7,8,-7,-8,};

    // vector<int> res=Rearrange2(arr);
    // for (auto it : res)
    // {
    //     cout<<it<<" "; 
    // }

    Rearrange3(arr);
    for (auto itt : arr)
    {
        cout<<itt<<" "; 
    }

    
    
    
    return 0;
}

/*
Brute Force Method---------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
Space Complexity: O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
*/

/*
Optimal Method--------------------------------------------------------------------------------------------------------------------------
Time Complexity: O(N) { O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A}.
Space Complexity: O(N) { Extra Space used to store the rearranged elements separately in an array, where N = size of array A}.
*/