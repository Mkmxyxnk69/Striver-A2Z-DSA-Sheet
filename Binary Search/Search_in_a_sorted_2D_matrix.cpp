#include<iostream>
using namespace std;

//Brute Force Method-----------------------------------------------------------------------------------------------
bool search1(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m=mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< m; j++)
        {
            if (mat[i][j]==target)
            {
                return true;
            }
            
        }
        
    }
    return false;
}

//Funcrtion for the binary search in the given array to find out the target is present or not
bool BS(vector<int> &arr,int target){
    int low=0;
    int high=arr.size()-1;
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if (arr[mid]==target)
        {
            return true;
        }
        else if(arr[mid]<=target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}
//Better Method-----------------------------------------------------------------------------------------------
bool search2(vector<vector<int>> &matrix,int target){
    int n = matrix.size();
    int m=matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0]<=target && matrix[i][m-1]>=target)
        {
            return BS(matrix[i],target);
        }
    }
    return false;
}

//Optimal Method-----------------------------------------------------------------------------------------------
bool search3(vector<vector<int>> &matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0,high=(m*n)-1;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        int row=mid/m;
        int col=mid%m;
        if (matrix[row][col]==target)
        {
            return true;
        }
        else if(matrix[row][col]<=target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {10, 11, 12,13}};
    cout<<search3(matrix,11);
                                
    return 0;
}

/*
Brute Force Method-----------------------------------------------------------------------------------------------
Time Complexity: O(n × m), We are traversing the entire matrix with `n` rows and `m` columns. In the worst case, we may end up visiting every cell once if the target is not present. So, the total number of operations is proportional to the number of elements in the matrix.
Space Complexity: O(1),We are not using any additional space. The algorithm uses a constant amount of extra memory regardless of the size of the matrix just loop variables and the target. Therefore, the space complexity is constant.
*/

/*
Better Method-----------------------------------------------------------------------------------------------
Time Complexity: O(n × log m), We go through each of the `n` rows once. For any valid row where the target can exist, we apply binary search which takes O(log m). So overall time = O(n × log m).
Space Complexity: O(1), No extra space is used just a few integer variables for looping and binary search. So space complexity is constant.
*/

/*
Optimal Method-----------------------------------------------------------------------------------------------
Time Complexity: O(log(NxM)), where N = given row number, M = given column number.We are applying binary search on the imaginary 1D array of size NxM.
Space Complexity: O(1) as we are not using any extra space.
*/