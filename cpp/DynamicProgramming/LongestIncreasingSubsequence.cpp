/* Dynamic Programming C/C++ implementation of LIS problem */
#include<iostream>

using namespace std;

int lis(int arr[], int n) {
    int i, j, max = 0;
//    lis = (int *) malloc(sizeof(int) * n);

    int *lis = new int[n];
    for (i = 0; i < n; i++) lis[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    for (i = 0; i < n; i++) cout << lis[i];
    cout << "---------------";
    for (i = 0; i < n; i++) if (max < lis[i]) max = lis[i];
//    free(lis);
    delete lis;
    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length =" << lis(arr, n);
    return 0;
}