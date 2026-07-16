#include<iostream>
using namespace std;

//Function which return no.of days will be required if we are putting x capacity on ship--------------------
int dayRequired(vector<int> &weight,int capacity){
    int load=0,day=1;
    for (int i = 0; i < weight.size(); i++)
    {
        if (weight[i]+load>capacity)
        {
            day++;
            load=weight[i];
        }
        else{
            load+=weight[i];
        }
    }
    return day;
}

//Brute force Method-------------------------------------------------------------------------------------
int minimumCapacity1(vector<int> &weight,int minimumDay){
    int n=weight.size();
    int max=(n*(n+1))/2;
    int mini=*max_element(weight.begin(),weight.end());
    for (int i = mini; i <= max; i++)
    {
        if (dayRequired(weight,i)==minimumDay)
        {
            return i;
        }
    }
    return -1;
}

//Optimal Method-------------------------------------------------------------------------------------
int minimumCapacity2(vector<int> &weight,int minimumDay){
    int n=weight.size();
    int high=(n*(n+1))/2;
    int low=*max_element(weight.begin(),weight.end());
    while (low<=high)
    {
        int mid =low+(high-low)/2;
        if (dayRequired(weight,mid)<=minimumDay)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return low;
    
}
int main(){
    vector<int> weight={3,2,2,4,1,4};
    cout<<minimumCapacity2(weight,3);
    cout<<minimumCapacity1(weight,3);
    return 0;
}

/*
Brute Force Method-------------------------------------------------------------------------------------
Time Complexity: O((sum_weights - max_weight) * N), where N is the number of packages. For each capacity between max weight and total sum, we simulate shipping over N packages.
Space Complexity: O(1), only constant extra space is used.
*/

/*
Optimal Method-------------------------------------------------------------------------------------
Time Complexity: O(N * log(S)), where N is number of packages and S is the search space (sum_weights - max_weight). Each binary search step takes O(N), repeated O(log S) times.
Space Complexity: O(1), constant extra space used.
*/