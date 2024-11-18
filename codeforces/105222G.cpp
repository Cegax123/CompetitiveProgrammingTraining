#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int E = 4;
const int L = 30;

int trie[N * L][E];
int go_first[N * L], go_second[N * L];
int trie_first[N * L][2], trie_second[N * L][2];
int idx[N * L];
int nodes = 1;
int nodes_first = 1, nodes_second = 1;

void insert(int pos, 

void insert(int x, int y, int id) {
    int pos = 0;

    for(int i = L-1; i >= 0; i--) {
        int bx = (x >> i) & 1;
        int by = (y >> i) & 1;

        int nxt = 2 * bx + by;

        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }
        pos = trie[pos][nxt];

        if(go_first[pos] == 0) {
            go_first[pos] = nodes_first++;

        }
        
        idx[pos] = id;
    }
}

// try to be greater or equal than x
int check_first(int pos, int st, int a, int b) {
    for(int i = st; i >= 0; i--) {
        // greater
        if(((b>>i)&1) == 0) {
            int bx = 1 ^ ((a>>i)&1);
            int nxt1 = 2 * bx + 0;
            int nxt2 = 2 * bx + 1;

            if(trie[pos][nxt1]) return idx[trie[pos][nxt1]];
            if(trie[pos][nxt2]) return idx[trie[pos][nxt2]];
        }
        // equal
        int bx = ((b>>i)&1) ^ ((a>>i)&1);

        
    }
    return idx[pos];
}

int query(int a, int b) {
    int pos = 0;

    for(int i = L-1; i >= 0; i--) {
        int t = (b>>i)&1;

        // make first = 1, second = 0; (second is less than b)
        if(t == 1) {
            int bx = 1 ^ ((a>>i)&1), by = 0 ^ ((a>>i)&1);
            if(trie[pos][2 * bx + by]) {
                int res = check_first(trie[pos][2 * bx][by], i-1, a, b);
                if(res != -1) return res;
            }
        }
        // make first = 1, second = 0; (first is greater than b)
        else {
            int bx = 1 ^ ((a>>i)&1), by = 0 ^ ((a>>i)&1);
            if(trie[pos][2 * bx + by]) {
                int res = check_second(trie[pos][2 * bx][by], i-1);
                if(res != -1) return res;
            }
        }

        // continue n_bx = n_by = t;
        int bx, by;
        bx = by = t ^ ((a>>i)&1);
        if(trie[pos][2 * bx + by] == 0) return -1;
        pos = trie[pos][2 * bx + by];
    }
    return idx[pos];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(int i = 0; i < n; i++)  cin >> x[i];

    for(int i = 0; i + 1 < n; i++) {
        insert(x[i], x[i+1], i+1);
        insert(x[i+1], x[i], i+1);
    }

    while(q--) {
        int a, b; cin >> a >> b;

    }

    return 0;
}

