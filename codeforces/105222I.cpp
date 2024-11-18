#include<bits/stdc++.h>
using namespace std;

struct pto {
    int x, y;
};

int main() {
    int n, l, h; cin >> n >> l >> h;

    vector<int> poss_x, poss_y;
    poss_x.push_back(0);
    poss_y.push_back(0);

    vector<pair<pto, pto>> rect;

    auto cmp = [&](const pair<pto, pto>& r1, const pair<pto, pto>& r2) {
        if(r2.first.y >= r1.second.y or r2.first.x >= r1.second.x or r2.second.y <= r1.first.y or r2.second.x <= r1.first.x)
            return true;
        return false;
    };

    const int INF = 1e9 + 100;
    pair<int, int> dummy = {INF, INF};

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        pair<int, int> st = dummy;
        for(int stx : poss_x) {
            for(int sty : poss_y) {
                if(stx + x > l or sty + y > h) continue;
                pair<pto, pto> r = {{stx, sty}, {stx + x, sty+y}};

                bool found = true;
                for(auto r2 : rect) {
                    if(!cmp(r2, r)) {
                        found = false;
                        break;
                    }
                }
                if(found) st = min(st, {stx, sty});
            }
        }

        if(st != dummy) {
            rect.push_back({{st.first, st.second}, {st.first + x, st.second + y}});
            poss_x.push_back(st.first + x);
            poss_y.push_back(st.second + y);
            cout << st.first << " " << st.second << "\n";
        }
        else cout << -1 << "\n";
    }


    return 0;
}

