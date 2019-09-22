#include <iostream>

using namespace std;

int main() {
//    char s1[100], s2[100];
    string s1, s2;
    int i, j;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
//    for(i=0; s1[i]!='\0'; ++i);  /* i contains length of string s1. */
//    for(j=0; s2[j]!='\0'; ++j, ++i)
//    {
//        s1[i]=s2[j];
//    }
//    s1[i]='\0';
    for (j = 0; j < s2.size(); ++j)
        s1 += s2[j];

    cout << "After concatenation: " << s1;
    return 0;
}