#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> num;
int c1[10], c2[7];

const int roman[] = {1, 5, 10, 50, 100, 500, 1000};
const int len = 20;

int dp[len];

int calc(ll n) {
    vector<int> digs;
    ll tmp = n;
    while(tmp) {
        digs.push_back(tmp % 10);
        tmp /= 10;
    }
    reverse(digs.begin(), digs.end());
    bool cmp = true;
    for(int i = 0; i < (int) digs.size(); i++) {
        if(digs[i] != num[i]) cmp = false;
    }

    if(cmp) {
        if(dp[digs.size()] != -1) return dp[digs.size()];
    }

    int ans = 1e9 + 100;
    for(int i = 0; i < 10; i++) {
        if(n >= i and (n - i) % 10 == 0) {
            ans = min(ans, c1[i] + calc((n-i)/10));
        }
    }

    for(int i = 0; i < 7; i++) {
        if(n >= roman[i] and (n - roman[i]) % 10 == 0) {
            ans = min(ans, c2[i] + calc((n-roman[i])/10));
        }
    }

    if(cmp) {
        dp[digs.size()] = ans;
    }

    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        long long tmp = n;
        num.clear();
        while(n) {
            num.push_back(n % 10);
            n /= 10;
        }
        reverse(num.begin(), num.end());
        n = tmp;

        for(int i = 0; i < 10; i++) cin >> c1[i];
        for(int i = 0; i < 7; i++) cin >> c2[i];

        memset(dp, -1, sizeof(dp));
        dp[0] = 0;

        cout << calc(n) << "\n";
    }


    return 0;
}
