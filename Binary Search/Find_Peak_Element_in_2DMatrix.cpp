#include<iostream>
using namespace std;

//Optimal Method-----------------------------------------------------------------------------------------------
int maximum(vector<vector<int>> &arr,int col){
    int n=arr.size();
    int max_value=-1;
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][col]>=max_value)
        {
            index=i;
            max_value=arr[i][col];
        }
    }
    return index;
}
vector<int> PeakEle(vector<vector<int>> &matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0;
    int high=m-1;
    while (low<=high)
    {
        int mid = low +(high - low)/2;
        int ind=maximum(matrix,mid);
        int left=mid-1>=0? matrix[ind][mid-1]: -1;
        int right=mid+1<m? matrix[ind][mid+1]: -1;
        if (matrix[ind][mid]>left && matrix[ind][mid]>right)
        {
            return {ind,mid};
        }
        else if(matrix[ind][mid]<left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {
          {4, 2, 5, 1, 4, 5},
          {2, 9, 3, 2, 3, 2},
          {1, 7, 6, 0, 1, 3},
          {3, 6, 2, 3, 7, 2}
    };
    vector<int> res=PeakEle(mat);
    for (auto it : res)
    {
        cout<<it<<" ";
    }
    
    
    return 0;
}

/*
Optimal Method-----------------------------------------------------------------------------------------------
Time Complexity: O(N * logM), where N is the number of rows in the matrix, M is the number of columns in each row. The complexity arises because binary search is performed on the columns, and for each mid column, a linear search through the rows is executed to find the maximum element.
Space Complexity: O(1) as no additional space is used.
*/