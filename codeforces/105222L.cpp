#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> sp, so;
    for(int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        if(c and d) {
            if(a < b) sp.push_back({a, i+1});
            else so.push_back({b, i+1});
        }
        else if(c) {
            sp.push_back({a, i+1});
        }
        else if(d) {
            so.push_back({b, i+1});
        }
    }

    sort(sp.begin(), sp.end());
    sort(so.begin(), so.end());

    cout << sp.size() << " ";
    for(auto x : sp) cout << x.second << " ";
    cout << "\n";
    cout << so.size() << " ";
    for(auto x : so) cout << x.second << " ";
    cout << "\n";

    return 0;
}

