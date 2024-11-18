#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(m));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];

    string s; cin >> s;
    vector<int> last(m, -1);

    vector<ll> f(1 << m, 0);

    for(int i = n-1; i >= 0; i--) {
        int x = s[i] - 'a';
        vector<pair<int, int>> p;

        for(int j = 0; j < m; j++) {
            if(last[j] != -1)
                p.push_back({last[j], j});
        }
        sort(p.begin(), p.end());

        int mask = 0;
        for(auto e : p) {
            int l = e.second;
            f[mask] += a[x][l];
            f[mask | (1 << x)] -= a[x][l];
            f[mask | (1 << l)] -= a[x][l];
            f[mask | (1 << x) | (1 << l)] += a[x][l];

            if(x == l) break;
            mask |= (1 << l);
        }

        last[x] = i;
    }

    vector<ll> dp(1 << m, 0);

    for(int i = 0; i < (1 << m); i++)
        dp[i] = f[i];

    for(int i = 0; i < m; i++)
        for(int mask = 0; mask < (1 << m); mask++)
            if(mask & (1 << i))
                dp[mask] += dp[mask^(1 << i)];

    for(int i = 0; i < (1 << m); i++)
        cout << dp[i] << " ";

    return 0;
}
