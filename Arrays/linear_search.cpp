#include<iostream>
using namespace std;
void search(vector<int> &arr, int num){
    int count=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==num){
            cout<<i<<endl;
            count=1;
            break;
        }
    }
    if (count==0)
    {
        cout<<"-1"<<endl;
    }
    
}
int main(){
    vector<int> arr={1,2,0,2,3,4,0,5,6};
    search(arr,1); 
    
    return 0;
}