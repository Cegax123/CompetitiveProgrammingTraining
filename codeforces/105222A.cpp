#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
	int n; cin >> n;
	vector<int> a(n+1), pos(n+1);
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	
	set<int> L;
	L.insert(1);
	L.insert(n+1);
	
	vector<int> R(n+1);
	R[1] = n;
	
	BIT bit(n+1);
	bit.add(1, 1);
	
	vector<int> b(1, 0);
	
	for(int i = 1; i <= n; i++) {
		b.push_back(bit.sum(1, pos[i]-1));
		
		auto it = L.upper_bound(pos[i]);
		it = prev(it);
		
		int currL = *it;
		
		bit.add(currL, -1);
		L.erase(currL);
		
		int l_st = currL, l_fin = pos[i]-1;
		int r_st = pos[i]+1, r_fin = R[currL];
	
		if(l_st <= l_fin) {
			R[l_st] = l_fin;
			bit.add(l_st, 1);
			L.insert(l_st);
		}
		if(r_st <= r_fin) {
			R[r_st] = r_fin;
			bit.add(r_st, 1);
			L.insert(r_st);
		}
	}
	
	long long ans = 0;
	
	for(int i = 1; i < (int) b.size(); i++) {
		if(b[i] >= b[i-1]) ans += b[i] - b[i-1];	
	}
	
	cout << ans << "\n";
	
	return 0;
}
