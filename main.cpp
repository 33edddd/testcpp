#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> nums(m);
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    long long n;
    cin >> n;

    long long x = 1;
    int count = 0;
    int i = 0;

    while (x <= n) {
        if (i < m && nums[i] <= x) {
            x += nums[i];
            i++;
        }
        else {
            x *= 2;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}