#include <iostream>
#include <vector>
using namespace std;



//Brute Force Method--------------------------------------------------------------------------------------------
int counter=0;
void sort(vector<int> &arr, int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
            counter=0;
        }
        else if (arr[i]==arr[i+1])
        {
            counter=1;
        }
    }
    
    sort(arr, n - 1);
}

int main() {
    cout << "hello" << endl;
    int n;
    cin >> n;
    
    vector<int> arr(n);          // give it size n
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];           // now arr[i] is valid
    }
    
    // Brute Force Method ---------------------------------------------------------------------
    sort(arr, n);
    
    if (n >= 2) {
        cout << "second largest element in the array " << arr[n - 2] << endl;
        cout << "second smallest element in the array " << arr[1] << endl;
    }
    
    if (counter==1)
    {
        cout<<"-1"<<endl;
    }
    return 0;
}
