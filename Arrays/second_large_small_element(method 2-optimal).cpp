#include<iostream>
using namespace std;

//Optimal Method
int secondLargest(vector<int> &arr){
    int largest=arr[0];
    int slargest=-1;
    for (int  i = 0; i < arr.size(); i++)
    {
        if (arr[i]>largest)
        {
            slargest=largest;
            largest=arr[i];
        }
        else if (arr[i]<largest and arr[i]>slargest)
        {
            slargest=arr[i];
        }
    }
    return slargest;
    
}
int secondSmallest(vector<int> &arr){
    int smallest=arr[0];
    int ssmallest=INT_MAX;
    for (int  i = 0; i < arr.size(); i++)
    {
        if (arr[i]<smallest)
        {
            ssmallest=smallest;
            smallest=arr[i];
        }
        else if (arr[i]!=smallest && arr[i]<ssmallest){
            ssmallest=arr[i];
        }
        
    }
    return ssmallest;
}
int main(){
    vector<int> arr={4,2,2,5,3,4};
    secondLargest(arr);
    secondSmallest(arr);
    return 0;
}