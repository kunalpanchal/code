#include<iostream>

using namespace std;

/* DynamicProgramming  Maximum Sum Increasing Subsequence */

int maxSum(int arr[], int n) {
    int i, j, maximum = 0;
    int tempArr[n];

    for (i = 0; i < n; i++) tempArr[i] = arr[i];

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && (tempArr[i] < tempArr[j] + arr[i]))
                tempArr[i] = tempArr[j] + arr[i];

    for (i = 0; i < n; i++)
        if (maximum < tempArr[i])
            maximum = tempArr[i];

    return maximum;
}

int main() {

//    int a[] = {1, 101, 2, 3, 100, 4, 5};
//    int size = sizeof(a)/sizeof(a[0]);
//    cout<<"Max Sum is = "<<maxSum(a,size);

    int testCase2[] = {3, 4, 5, 10};
    int size = sizeof(testCase2) / sizeof(testCase2[0]);
    cout << "Max Sum is = " << maxSum(testCase2, size);
    return 0;
}