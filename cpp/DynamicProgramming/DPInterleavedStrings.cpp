// A Dynamic Programming based program to check whether a string C is
// an interleaving of two other strings A and B.
#include <iostream>
#include <string.h>

using namespace std;

// The main function that returns true if C is
// an interleaving of A and B, otherwise false.
bool isInterleaved(string string1, string string2, string mainString) {
    int s1Size = string1.size(), s2Size = string2.length();

    // Let us create a 2D table to store solutions of
    // subproblems.  C[i][j] will be true if C[0..i+j-1]
    // is an interleaving of A[0..i-1] and B[0..j-1].
    bool Table2D[s1Size + 1][s2Size + 1];

    memset(Table2D, 0, sizeof(Table2D)); // Initialize all values as false.

    if ((s1Size + s2Size) != mainString.length()) return false;
    if (string1.empty() && string1.compare(mainString) == 0) return true;
    if (string2.empty() && string2.compare(mainString) == 0) return true;
    if (string1.empty() && string2.empty() && mainString.empty()) return true;

    // Process all characters of A and B
    for (int i = 0; i <= s1Size; ++i) {
        for (int j = 0; j <= s2Size; ++j) {

            // Current character of mainString matches with current character of string1,
            // but doesn't match with current character of string2
            if (string1[i - 1] == mainString[i + j - 1] && string2[j - 1] != mainString[i + j - 1])
                Table2D[i][j] = Table2D[i - 1][j];

                // Current character of mainSring matches with current character of string2,
                // but doesn't match with current character of string1
            else if (string1[i - 1] != mainString[i + j - 1] && string2[j - 1] == mainString[i + j - 1])
                Table2D[i][j] = Table2D[i][j - 1];

                // Current character of C matches with that of both A and B
            else if (string1[i - 1] == mainString[i + j - 1] && string2[j - 1] == mainString[i + j - 1])
                Table2D[i][j] = (Table2D[i - 1][j] || Table2D[i][j - 1]);
        }
    }

    for (int i = 0; i <= s1Size; ++i) {
        for (int j = 0; j <= s2Size; ++j) {
            cout<<" "<<Table2D[i][j];
        }
        cout<<endl;
    }
    return Table2D[s1Size][s2Size];
}


void test(string A, string B, string C) {
    isInterleaved(A, B, C) ?
    cout << C << " is interleaved of " << A << " and " << B << endl :
    cout << C << " is not interleaved of " << A << " and " << B << endl;
}

int main() {
    test("XXY", "XXZ", "XXZXXXY");
    test("XY", "WZ", "WZXY");
    test("XY", "X", "XXY");
    test("YX", "X", "XXY");
    test("XXY", "XXZ", "XXXXZY");
    test("XXX", "XC", "XXCXX");
    test("", "XC", "XC");
    test("", "", "");

    return 0;
}