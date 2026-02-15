#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr={1,2,3,5,7,6};
    
    int count=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]<arr[i+1])
        {
            count=1;
        }
        else if (arr[i]>arr[i+1]){
            count=0;
            break;
        }
        
    }
    if (count==1)
    {
        cout<<"True"<<endl;
    }
    if (count==0)
    {
        cout<<"false";
    }
    
    
    
    return 0;
}