/*
 * We delete the following characters from our two strings to turn them into anagrams of each other:

Remove d and e from cde to get c.
Remove a and b from abc to get c.
We must delete  characters to make both strings anagrams, so we print  on a new line.*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
    int ar[2][26]={0};
    for(int i=0;i<a.length();i++){
        ar[0][(int)a.at(i)-97]++;
    }
    for(int i=0;i<b.length();i++){
        ar[1][(int)b.at(i)-97]++;
    }

    for(int i=0;i<26;i++){
        if(ar[0][i]>ar[1][i])
        {   ar[0][i]=ar[0][i]-ar[1][i];
            ar[1][i]=0;
        }else {
            ar[1][i]=ar[1][i]-ar[0][i];
            ar[0][i]=0;
        }
    }
    int final=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<26;j++){
            if(ar[i][j]!=0)
                final+=ar[i][j];
        }
    }
    return final;
}

int main(){
    //To make cin and cout faster for larger inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cout<<"Enter string 1:";
    getline(cin,a);
    string b;
    cout<<"Enter string 2:";
    getline(cin,b);
    cout << number_needed(a, b) << endl;
    return 0;
}
