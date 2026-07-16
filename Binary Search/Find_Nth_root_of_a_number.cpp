#include<iostream>
using namespace std;
//Num->number batarah hai kiska root nikal rha hai
//root -> nTh root ka number batarah hai

//Brute Force Method 1
int NthRoot(int num, int root){
    for (int i=1;i<=num;i++){
        int ans=i;
        for(int j=1;j<root;j++){
            ans=ans*i;
        }
        if (ans==num)
        {
            return i;
        }
    }
    return -1;
}

//-----
int multiplication(int n, int root){
    int ans = n;
    for (int  j = 1; j < root; j++)
    {
        ans=ans*n;
    }
    return ans;
    
}
int Nthroot2(int num,int root){
    int low=1,high=num;
    while (low<=high)
    {
        int mid = low+(high-low)/2;
        if (multiplication(mid,root)==num)
        {
            return mid;
        }
        else if (multiplication(mid,root)>=num){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
    

}
int main(){
    cout<<Nthroot2(81,4);
    return 0;
}