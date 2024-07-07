
/*Problem link: https://cses.fi/problemset/task/1628/ */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

void subsetSum(int n, vector<int> &a, int ind, int sum, vector<int> &half) {
    if (ind == n) {
        half.push_back(sum);
        return;
    }
    subsetSum(n, a, ind + 1, sum + a[ind], half);
    subsetSum(n, a, ind + 1, sum, half);
}

int32_t main() {

    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int id = n / 2;
    vector<int> left, right;
    subsetSum(id, arr, 0, 0, left);
    subsetSum(n, arr, id, 0, right);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int cnt = 0;
    for (auto i: left) {
        auto low_iterator = lower_bound(right.begin(), right.end(), x - i);
        auto high_iterator = upper_bound(right.begin(), right.end(), x - i);
        int start_index = low_iterator - right.begin();
        int end_index = high_iterator - right.begin();
        cnt += (end_index - start_index);
    }
    cout << cnt << endl;


    return 0;
}
