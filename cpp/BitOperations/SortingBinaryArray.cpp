#include<iostream>

using namespace std;

//This is done using single pass
void modify(int ar[], int length) {
    int i = 0, j = length - 1;
    while (i != j) {
        if (ar[i] == 0) i++;
        if (ar[j] == 1) j--;
        (ar[i] == 1 && ar[j] == 0) ? ar[i++] = 0, ar[j--] = 1 : NULL;
    }
}

int main() {
    int ar[10];
    cout << "Enter a Binary array " << endl;
    for (int i = 0; i < 10; i++) cin >> ar[i];
    modify(ar, 10);
    for (int i = 0; i < 10; i++) cout << ar[i];
    return 0;
}
