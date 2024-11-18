#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        
        string b[n];
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            for(int j = 0; j < m; j++) {
                if(b[i][j] == '.') cnt++;
            }
        }

        if(cnt > 1 or b[0][m-1] != '.') {
            cout << "No\n";
            continue;
        }

        bool cmp = 1;
        vector<vector<int>> sum(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(b[i][j] != 'C') {
                    if(b[i][j] == '.') continue;
                    int ni = i, nj = j;

                    if(b[i][j] == 'R') nj++;
                    else if(b[i][j] == 'L') nj--;
                    else if(b[i][j] == 'U') ni--;
                    else if(b[i][j] == 'D') ni++;

                    if(ni < 0 or ni >= n or nj < 0 or nj >= m or b[ni][nj] != 'C') {
                        cmp = false;
                    }
                }
                else {
                    int cnt = 0;
                    vector<int> t(4, 0);

                    if(i) {
                        if(b[i-1][j] == 'D') t[0]++;
                    }
                    if(i + 1 < n) {
                        if(b[i+1][j] == 'U') t[1]++;
                    }
                    if(j) {
                        if(b[i][j-1] == 'R') t[2]++;
                    }
                    if(j + 1 < m) {
                        if(b[i][j+1] == 'L') t[3]++;
                    }

                    cnt = accumulate(t.begin(), t.end(), 0);

                    if(cnt != 2 or (t[0] == 1 and t[1] == 1) or (t[2] == 1 and t[3] == 1)) {
                        cmp = false;
                    }
                }
            }
        }

        if(cmp) cout << "Yes\n";
        else cout << "No\n";
    }


    return 0;
}

