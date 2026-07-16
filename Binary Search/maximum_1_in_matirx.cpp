#include<iostream>
using namespace std;

//Brute Force Method-------------------------------------------------------------------------------------------------------------------
int maximum1(vector<vector<int>> &matrix){
    int n=matrix.size();            //n->No of rows
    int m = matrix[0].size();      //m->no of columns
    int maximum=INT_MIN;
    int index=-1;
    for (int i = 0; i <n; i++)
    {
        int count=0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j]==1)
            {
                count++;
            }
        }
        if (count>maximum)
        {
            maximum=count;
            index=i;
        }
        
    }
    return index;
}
//Function for lower bound-------------------------------------------------------------------------------------------------------------------
int LowerBound(vector<int> &arr,int x){
    int low=0;
    int high=arr.size()-1;
    int ans=arr.size();
    while (low<=high)
    {
        int mid =  low + (high - low)/2;
        if (arr[mid]>=x)
        {
            ans = mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
//Optimal Method-------------------------------------------------------------------------------------------------------------------
int maximum2(vector<vector<int>> &matrix){
    int n=matrix.size();            //n->No of rows
    int m = matrix[0].size();      //m->no of columns
    int maximum=INT_MIN;
    int index=-1;
    for (int i = 0; i <n; i++)
    {
        int count=m-LowerBound(matrix[i],1);
        if (count>maximum)
        {
            maximum=count;
            index=i;
        }
        
    }
    return index;
}
int main(){
    vector<vector<int>> matrix={{0,0,0,1},{0,0,1,1},{0,1,1,1},{0,1,1,1}};
    cout<<maximum2(matrix);
    return 0;
}

/*
Brute Force Method-------------------------------------------------------------------------------------------------------------------
Time Complexity:O(n X m), where n = given row number, m = given column number. We are using nested loops running for n and m times respectively.
Space Complexity: O(1). No extra space used
*/

/*
Optimal Method-------------------------------------------------------------------------------------------------------------------
Time Complexity:O(n X logm), where n = given row number, m = given column number. We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.
Space Complexity: O(1), no extra space is used.
*/