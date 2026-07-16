#include<iostream>
using namespace std;

int setRightMost(int n){
    return n | (n+1);
}
int main(){
    int n = 2;
    int result = setRightMost(n);

    // Print output
    cout << "Number after setting rightmost unset bit: " << result << endl; // Output: 11
    return 0;
}