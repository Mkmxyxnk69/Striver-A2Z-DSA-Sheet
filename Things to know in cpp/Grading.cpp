#include<iostream>
using namespace std;

class Solution {
    int marks;
public:
    void set_marks(int a){
        marks=a;
    }
    void studentGrade(int marks) {
        if (marks>=90)
        {
            cout<<"GRADE A"<<endl;
        }
        else if (marks<90 && marks>=70)
        {
            cout<<"GRADE B"<<endl;
        }
        else if (marks<70 && marks>=50)
        {
            cout<<"GRADE C"<<endl;
        }
        else if (marks<50 && marks>=35)
        {
            cout<<"GRADE D"<<endl;
        }
        else{
            cout<<"FAIL"<<endl;
        }
        
        
    }
};

int main(){
    int x;
    cout<<"Enter the marks: "<<endl;
    cin>>x;

    Solution obj;
    obj.set_marks(x);
    obj.studentGrade(x);
    return 0;
}