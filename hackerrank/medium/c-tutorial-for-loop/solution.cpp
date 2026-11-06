#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i = n; i <= m; i++) {
        if (i >= 1 && i <= 9) {
            cout << arr[i] << "\n";
        } else {
            if (i % 2 == 0) {
                cout << "even\n";
            } else {
                cout << "odd\n";
            }
        }
    }
    
    return 0;
}
