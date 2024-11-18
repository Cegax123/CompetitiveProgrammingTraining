#include<bits/stdc++.h>
using namespace std;

vector<int> curr;
vector<vector<int>> poss;

void gen(int pos=0, int sum=0, int last=1) {
    if(sum == 6) {
        vector<int> scurr = curr;
        sort(scurr.begin(), scurr.end());
        
        poss.push_back(scurr);
        return;
    }

    for(int i = last; i <= 5; i++) {
        if(sum + i <= 6) {
            curr.push_back(i);
            gen(pos+1, sum+i, i);
            curr.pop_back();
        }
        if(i != 1 and sum + 1 <= 6) {
            curr.push_back(100+i);
            gen(pos+1, sum+1, i);
            curr.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    gen();

    sort(poss.begin(), poss.end(), [&](const auto& v1, const auto& v2) {
        return v1.size() < v2.size() or (v1.size() == v2.size() and v1 < v2);
    });
    poss.erase(unique(poss.begin(), poss.end()), poss.end());

    vector<int> M;
    for(auto v : poss) {
        int mask = 0;
        for(int x : v) {
            if(x >= 100) x -= 100;

            mask |= (1 << x);
        }
        
        M.push_back(mask);
    }

    int t; cin >> t;
    while(t--) {
        int a[6];
        int mask = 0;
        for(int i = 1; i <= 5; i++) {
            cin >> a[i];
            if(a[i]) mask |= (1 << i);
        }

        long long ans = 0;

        for(int i = 0; i < (int) poss.size(); i++) {
            if((M[i] & mask) != M[i]) continue;
            const auto& v = poss[i];

            vector<int> cnt(6, 0);

            for(int x : v) {
                if(x < 100) cnt[x]++;
                else cnt[x-100]++;
            }

            int mn = 1e9+100;

            for(int i = 1; i <= 5; i++) {
                if(cnt[i] == 0) continue;
                //assert(a[i] >= 0);
                mn = min(mn, a[i] / cnt[i]);
            }

            ans += mn;

            for(int i = 1; i <= 5; i++) {
                a[i] -= mn * cnt[i];
                if(a[i] == 0 and ((mask>>i)&1)) mask ^= (1 << i);
            }

            if(mask == 0) break;
        }
        cout << ans << "\n";
    }

    return 0;
}
