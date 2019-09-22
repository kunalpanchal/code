#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "enter n";
    cin >> n;
    int count = 1, ele = n, incr = 0;
    for (int i = 0; i < n * 2; i++) {
        if (i < n) {
            for (int j = 0; j <= i && j < n; j++) {
                cout << count << " ";
                count++;
            }
        } else {
            ele--;
            incr++;
            for (int j = ele, k = 0; j >= 0; j--, k += 2) {
                count--;
                cout << count + (-n + incr + k) << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}