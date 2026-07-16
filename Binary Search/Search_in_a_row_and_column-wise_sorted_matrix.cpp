#include<iostream>
using namespace std;
//Brute Force Method-------------------------------------------------------------------------------------------------------------
void search1(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m=mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< m; j++)
        {
            if (mat[i][j]==target)
            {
                cout<<i<<" "<<j<<endl;
            }
            
        }
        
    }

}
//Better Method-------------------------------------------------------------------------------------------------------------
int BS(vector<int> &arr,int target){
    int low=0;
    int high=arr.size()-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if (arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<=target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
vector<int> search2(vector<vector<int>> &matrix,int target){
    int n = matrix.size();
    int m=matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        int index=BS(matrix[i],target);
        if (index!=-1)
        {
            return {i,index};
        }
           
    }
    return {-1,-1};
}

//Optimal Method-------------------------------------------------------------------------------------------------------------
vector<int> search3(vector<vector<int>> &matrix,int target){
    int n = matrix.size();
    int m=matrix[0].size();
    int row=0,col=m-1;
    while (row<n && col>=0)
    {
        if (matrix[row][col]==target)
        {
            return {row,col};
        }
        else if (matrix[row][col]<target){
            row++;
        }
        else{
            col--;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    vector<int> result=search3(matrix,26);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

/*
Brute Force Method-------------------------------------------------------------------------------------------------------------
Time Complexity: O(N X M), where N = given row number, M = given column number in order to traverse the matrix, we are using nested loops running for n and m times respectively.
Space Complexity: O(1) as we are not using any extra space.
*/

/*
Better Method-------------------------------------------------------------------------------------------------------------
Time Complexity: O(N*logM), where N = given row number, M = given column number. We are traversing all rows and it takes O(N) time complexity. And for all rows, we are applying binary search. So, the total time complexity is O(N*logM).
Space Complexity: O(1) as we are not using any extra space.
*/

/*
Optimal Method-------------------------------------------------------------------------------------------------------------
Time Complexity: O(N+M), where N = given row number, M = given column number. We are starting traversal from (0, M-1), and at most, we can end up being in the cell (M-1, 0). So, the total distance can be at most (N+M). So, the time complexity is O(N+M).
Space Complexity: O(1) as we are not using any extra space
*/