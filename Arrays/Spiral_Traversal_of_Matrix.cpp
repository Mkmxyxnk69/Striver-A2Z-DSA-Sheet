#include<iostream>
using namespace std;
//Optimal Method
vector<int> Spiral(vector<vector<int>> &matrix){
    int n = matrix.size();     //n->rows
    int m = matrix[0].size();  //m->columns
    int top=0,bottom=n-1,left=0,right=m-1;
    vector<int> ans;
    while(top<=bottom && left<=right){
    for (int i = left; i <= right; i++)
    {
        ans.push_back(matrix[top][i]);
    }
    top++;
    for (int i = top; i <= bottom; i++)
    {
        ans.push_back(matrix[i][right]);
    }
    right--;
    if (top<=bottom){
    for (int i = right; i >= left; i--)
    {
        ans.push_back(matrix[bottom][i]);
    }
    bottom--;
    }
    if (left<=right)
    {
        
        for (int i = bottom; i >= top; i--)
        {
            ans.push_back(matrix[i][left]);
        }
        left++;
    }
    
}
return ans;
    
    
}
int main(){
    vector<vector<int>> matrix = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    vector<int> result = Spiral(matrix);

    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}

/*
Optimal Method
Time Complexity: O(m × n),Because we visit each element of the matrix exactly once, where `m` is the number of rows and `n` is the number of columns.
Space Complexity: O(1)We use only a few integer variables to keep track of boundaries (top, bottom, left, right). The `result` vector is part of the output, so it's not counted as extra space.
*/