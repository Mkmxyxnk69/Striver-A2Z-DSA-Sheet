#include<iostream>
using namespace std;

//Optimal Method----------------------------------------------------
int SquareRoot(int n){
    int low =1;
    int high=n;
    int ans=0;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if (mid*mid<=n)
        {
            ans=mid;
            low=mid+1;
        }
        else {
            high=mid-1;
        }
        
    }
    return ans;
    
}
int main(){
    cout<<SquareRoot(25);
    return 0;
}

/*
Optimal Method----------------------------------------------------
Time Complexity: O(log(N)), we apply binary search on our search space to reduce it into half at every step.
Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
*/