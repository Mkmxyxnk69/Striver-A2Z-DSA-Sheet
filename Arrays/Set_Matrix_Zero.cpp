#include<iostream>
using namespace std;

//Better Method
void SetMatrixZero1(vector<vector<int>> &matrix){
    int m=matrix.size(); //rows
    int n=matrix[0].size(); //columns
    vector<int> rows(m,0);
    vector<int> columns(n,0);
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if (matrix[i][j]==0) //i->rows , j->columns
            {
                rows[i]=-1;
                columns[j]=-1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if (rows[i]==-1 || columns[j]==-1)
            {
                matrix[i][j]=0;
            }
            
        }
    }
    
}

//Optimal Method
void SetMatrixZero2(vector<vector<int>> &matrix){
    int m=matrix.size(); //rows
    int n=matrix[0].size(); //columns
    // vector<int> rows(m,0); --> matrix[0][..]
    // vector<int> columns(n,0); --> matrix[..][0]
    int col0=1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if (matrix[i][j]==0) //i->rows , j->columns
            {
                matrix[i][0]=0;
                if (j!=0)
                {
                    matrix[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j]!=0)
            {
                if (matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }   
            }   
        }
    }
    if (matrix[0][0]==0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j]=0;
        }
    }
    if (col0==0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0]=0;
        }   
    }
}


int main(){
    vector<vector<int>> matrix={{1,0,1},{1,1,1},{0,1,1}};
    SetMatrixZero2(matrix);
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Better Method
Time Complexity: O(m × n),We make two passes over the matrix.First pass to identify rows and columns to be zeroed (O(m × n)).Second pass to update the matrix using the markers (O(m × n)).Total time is proportional to the number of cells in the matrix, so O(m × n).
Space Complexity: O(m + n),We store two extra arrays one for m rows and one for n columns. No other extra space is used besides these arrays.
*/

/*
Optimal Method
Time Complexity: O(m × n),We iterate over the entire matrix a constant number of times (first pass for markers, second pass for zeroing, final pass for first row/col), where m = number of rows and n = number of columns.
Space Complexity: O(1),No extra space is used apart from a few boolean flags; all marker information is stored within the first row and column of the matrix itself.
*/