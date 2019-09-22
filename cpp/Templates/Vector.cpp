#include <vector>
#include<iostream>

using namespace std;

int main() {
    int size;
    vector<int> a;
    cout << "Enter the size of array";
    cin >> size;
    vector<int> b(size);

    for (int i = 0; i < size; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < size; i++) {
        cout << b[i];
    }

    return 0;
}