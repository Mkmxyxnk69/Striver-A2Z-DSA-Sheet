#include<iostream>
using namespace std;


class Solution {
    public:
    void printNumber() {
        int num;
        cout<<"Enter the nummber: "<<endl;
        cin >> num;
        cout <<"the number is "<< num;
    }
};

int main(){
    
    Solution obj;
    obj.printNumber();
    
    
    return 0;
}