#include <iostream>
#include <map>

using namespace std;
int main() {

    //To make cin and cout faster for larger inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<char, int> m;
    int arr[] = {'a', 'b', 'c', 'b', 'e', 'c', 'e', 'e'}, len = 8;
    for (int k = 0; k < len; k++) m[arr[k]] += 1;

    for (map<char, int>::iterator i = m.begin(); i != m.end(); i++)
        if (i->second % 2 == 0)
            cout << i->first << " " << i->second << "\n";
    return 0;
}
