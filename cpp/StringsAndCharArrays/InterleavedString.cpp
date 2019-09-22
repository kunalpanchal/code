// C/C++ program to check if given string is an interleaving
// of the other two strings
#include<stdio.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

bool isInterleaved(char *A, char *B, char *mainString) {
    while (*mainString != 0) {
        if (*A == *mainString) A++;
        else if (*B == *mainString) B++;
        else return false;
        mainString++;
    }

    // If A or B still have some characters, then length of
    // C  is smaller than sum of lengths of A and B, so
    // return false
    if (*A || *B) return false;
    return true;
}

// Driver program to test above functions
int main() {
    clock_t tStart = clock();
    char *s1 = "XXX";
    char *s2 = "XC";
    char *mainString = "XXCXX";
//    char *mainString = "ACBG";

    (isInterleaved(s1, s2, mainString) == true || isInterleaved(s2, s1, mainString) == true) ?
    printf("%s is interleaved of %s and %s", mainString, s1, s2) :
    printf("%s is not interleaved of %s and %s", mainString, s1, s2);

    double timeTaken=(double) ((clock() - tStart) / CLOCKS_PER_SEC);
    cout << "Time Taken: " << std::fixed << timeTaken<<"s";
    printf("\nTime taken: %fs\n", timeTaken);
    return 0;
}