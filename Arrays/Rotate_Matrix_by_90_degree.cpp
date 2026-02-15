#include<iostream>
using namespace std;

//Brute Force Method
vector<vector<int>> Rotate1(vector<vector<int>> &matrix){
    int n=matrix.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j][n-1-i]=matrix[i][j];
        }   
    }
    return temp;
}

//Optimal Method 
vector<vector<int>> Rotate2(vector<vector<int>> &matrix){
    int n=matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }   
    }
    for (int i = 0; i < n; i++)
    {
     reverse(matrix[i].begin(),matrix[i].end());   
    }
    
    return matrix;
}

int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,1,2,3},{5,6,7,8}};
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<endl;

    //Brute Force Method Output
    // vector<vector<int>> res1=Rotate1(matrix);
    // for (auto row : res1) {
    //     for (auto val : row) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    //Optimal Method Output
    vector<vector<int>> res2=Rotate2(matrix);
    for (auto row : res2) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}