#include<iostream>
#include<map>
#include<string>
using namespace std;

//Brutal Method-------------------------------------------------------------------------
void Sum(vector<int> &arr,int num){
    int count=0;
    for (int i = 0; i < arr.size(); i++)
    {
        int dif=num-arr[i];
        for (int  j = i+1; j < arr.size(); j++)
        {
            if (arr[j]==dif)
            {
                count++;
                cout<<"Yes"<<endl;
                cout<<"["<<i<<","<<j<<"]";//Indexes of the two Number
                break;
            }
        }

        
        
    }
    if (count==0)
    {
        cout<<"NO"<<endl;
    }
    
    
}
//Better Method(Find Yes and No)-------------------------------------------------------------------------
string Sum2(vector<int> &arr, int num){
    unordered_map<int,int> mpp;
    for ( int i = 0; i < arr.size(); i++)
    {
        int more = num-arr[i];
        if (mpp.find(more)!=mpp.end())
        {
            return "Yes";
            
        }
        mpp[arr[i]]=i;
        
    }
    return "No";
    

}
//Better Method(Finding the indexes of the two number)-------------------------------------------------------------------------
vector<int> Sum3(vector<int> &arr, int num){
    unordered_map<int,int> mp;
    for ( int i = 0; i < arr.size(); i++)
    {
        int more = num-arr[i];
        if (mp.find(more)!=mp.end())
        {
            
            return {mp[more],i};
        }
        mp[arr[i]]=i;   
    }
    return{1,-1};
}
//Optimal Method-------------------------------------------------------------------------
string Sum4(vector<int> &arr, int num){
    sort(arr.begin(),arr.end());
    int i=0 , j=arr.size()-1;
    while(i<j){
       int sum=arr[i]+arr[j];
       if (sum==num)
       {
        return "Yes";
       }
       else if (sum<num)
       {
        i++;
       }
       else j--;
    }
    return "No";
    

}
int main(){
    vector<int> arr={2,6,5,8,11};

    //Brutal method-------------------------------------------------------------------------
    Sum(arr,14);

    //Better method(Y & N)-------------------------------------------------------------------------
    cout<<Sum2(arr,14)<<endl;;
    
    //better method(indexes)-------------------------------------------------------------------------
    vector<int> res=Sum3(arr,14);
    cout<<res[0]<<" "<<res[1];

    //Optimal method-------------------------------------------------------------------------
    cout<<Sum4(arr,14);
    
     
    return 0;
}


/*
Brutal Method-------------------------------------------------------------------------
Time Complexity: O(N^2) 
Space Complexity: O(1) 
*/

/*
Better Method-------------------------------------------------------------------------
Time Complexity: O(N) because we traverse the array only once, and each lookup or insertion in the hash map takes O(1) on average, where N is the size of the array.
Space Complexity: O(N) since in the worst case we may store all elements of the array in the hash map.
*/

/*
Optimal method-------------------------------------------------------------------------
Time Complexity: O(N log N) due to sorting the array initially, where N is the number of elements. The two-pointer traversal runs in O(N).
Space Complexity: O(N) because we store the array elements along with their original indices in a separate list or vector for sorting, maintaining original positions.
*/