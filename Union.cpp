#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

//using set-------------------------------------------------------------------------------------------------
set<int> s1;
void Union1(vector<int> arr1 , vector<int> arr2){
    for (int i = 0; i < arr1.size(); i++)
    {
        s1.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        s1.insert(arr2[i]);
    }
}

//Optimal method--------------------------------------------------------------------------------------------
vector<int> Union2(vector<int> arr1 , vector<int> arr2){
    vector<int> unionArr;
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0;
    int j=0;
    while (i<n1 && j<n2)
    {
        if (arr1[i]<=arr2[j])
        {
            if (unionArr.size()==0 || unionArr.back()!=arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else
        if (unionArr.size()==0 || unionArr.back()!=arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
    }
    while (j<n2)
    {
        if (unionArr.size()==0 || unionArr.back()!=arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
    }
    while (i<n1)
    {
        if (unionArr.size()==0 || unionArr.back()!=arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
    }
    return unionArr;
}

int main(){
    vector<int> arr1={2,5,7,8,9,9,9};
    vector<int> arr2={3,3,6,7,10};
    
    //Method 1 output-------------------------------------------------------------------------------------------------------------------
    // Union(arr1,arr2);
    // for(auto it : s1){
    //     cout<<it<<" ";
    // }

    //Method 2 output -------------------------------------------------------------------------------------------------------------------
    vector<int> a=Union2(arr1,arr2);
    for(auto it : a){
        cout<<it<<" ";
    }
    
    
    
    
    return 0;
}

/*
Using Set-------------------------------------------------------------------------------------------------------------------
Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.

Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} ,O(1) {If Space of union ArrayList is not considered}
*/

/*
Optimal method-------------------------------------------------------------------------------------------------------------------
Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} O(1) {If Space of union ArrayList is not considered}
*/