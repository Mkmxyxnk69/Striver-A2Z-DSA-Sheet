#include<iostream>
using namespace std;

//Brute Force Method--------------------------------------------------------------------------------------------------------------
double median(vector<int> &arr1, vector<int> &arr2){
    vector<int> arr3;
    int n1=arr1.size();
    int n2=arr2.size();
    int n=n1+n2;
    int i=0,j=0;
    while (i<n1 && j<n2)
    {
        if (arr1[i]<=arr2[j])
        {
            arr3.push_back(arr1[i++]);
        }
        else arr3.push_back(arr2[j++]);
    }
    if (i<n1)
    {
            arr3.push_back(arr1[i++]);
    }
    if (j<n2)
    {
            arr3.push_back(arr2[j++]);
    }
    if (n%2==1)
    {
        return arr3[n/2];
    }
    else{
        return (arr3[n/2]+arr3[(n/2)-1])/2.0;
    }
}

//Better Method--------------------------------------------------------------------------------------------------------------
double median2(vector<int> &arr1, vector<int> &arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int n = n1 + n2;
    int index2=n/2;
    int index1=index2-1;
    int ele1=-1,ele2=-1;
    int i =0, j=0;
    int count =0;
    if (n2==0)
    {
        if (n1%2==1)
        {
            return arr1[n1/2];
        }
        else{
            return (arr1[n1/2]+arr1[(n1/2)-1])/2.0;
        }
    }
    if (n1==0)
    {
        if (n2%2==1)
        {
            return arr2[n2/2];
        }
        else{
            return (arr2[n2/2]+arr2[(n2/2)-1])/2.0;
        }
    }
    
    
    while(i<n1 && j<n2){
        if (arr1[i]<arr2[j])
        {
            if (count==index1)
            {
                ele1=arr1[i];
            }
            if (count==index2)
            {
                ele2=arr2[i];
            }
            count++;
            i++;
        }
        else{
            if (count==index1)
            {
                ele1=arr1[j];
            }
            if (count==index2)
            {
                ele2=arr2[j];
            }
            count++;
            j++;
        } 
    }
    while (i<n1)
    {
        if (count==index1)
        {
            ele1=arr1[i];
        }
        if (count==index2)
        {
            ele2=arr2[i];
        }
        count++;
        i++;
    }
    while (j<n2)
    {
        if (count==index1)
        {
            ele1=arr1[j];
        }
        if (count==index2)
        {
            ele2=arr2[j];
        }
        count++;
        j++;
    }
    if (n%2==1)
    {
        return ele2;
    }
    else{
        return (ele1+ele2)/2.0;
    }

}

//Optimal Method--------------------------------------------------------------------------------------------------------------
double median3(vector<int> &arr1, vector<int> &arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int n = n1+n2;
    if (n1>n2)
    {
        return median3(arr2,arr1);
    }
    int low=0, high=n1;
    int left=(n1+n2+1)/2;
    while (low<=high)
    {
        int mid1 = low+(high-low)/2;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;  
        if(mid1<n1)
        {
            r1=arr1[mid1];
        }
        if (mid1-1>=0)
        {
            l1=arr1[mid1-1];
        }
        if (mid2<n2)
        {
            r2=arr2[mid2];
        }
        if (mid2-1>=0)
        {
            l2=arr2[mid2-1];
        }
        if (l1<=r2 && l2<=r1){
            if (n%2==1)
            {
                return max(l1,l2);
            }
            else{
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
        else if (l1>r2)
        {
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
    return 0;
}

int main(){
    vector<int> arr1={2,4,6};
    vector<int> arr2={1,3,5};
    cout<<median3(arr1,arr2);
    return 0;
}
/*
Brute Force Method--------------------------------------------------------------------------------------------------------------
Time Complexity: O(N1+N2)), every element of both array is visited once.
Space Complexity: O(N1+N2), to store the merged array
*/

/*
Better Method--------------------------------------------------------------------------------------------------------------
Time Complexity: O(N1+N2), every element of both the arrays is visited once.
Space Complexity: O(1), constant extra space is used.
*/

/*
Optimal Method--------------------------------------------------------------------------------------------------------------
Time Complexity: O(log(min(n1,n2))), we are applying binary search on the range [0, min(n1, n2)].
Space Complexity: O(1) , only constant variables are used
*/