#include<bits/stdc++.h>
using namespace std;

using db = long long;

struct pto {
    db x, y;
    pto operator+(const pto& o) const { return {x + o.x, y + o.y}; }
    pto operator-(const pto& o) const { return {x - o.x, y - o.y}; }
    db operator*(const pto& o) const { return x * o.x + y * o.y; } // dot product
    db operator^(const pto& o) const { return x * o.y - y * o.x; } // cross product
};

pto operator*(db k, const pto& p) { return {k * p.x, k * p.y}; }

ostream &operator <<(ostream &os, const pto& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

istream &operator >>(istream &is, pto& p) {
    return is >> p.x >> p.y;
}

int main() {
    int t; cin >> t;
    while(t--) {
        pto p, v; 
        int r;
        cin >> p >> r >> v;
        
        pto L, R; cin >> L >> R;

        // verify 2 * r

        if(R.x - L.x < 2 * r or R.y - L.y < 2 * r) {
            cout << "No\n";
            continue;
        }

        int g = __gcd(abs(v.x), abs(v.y));
        v.x /= g;
        v.y /= g;

        auto intersect = [&](const pto& p, const pto& v, const pto& s, const pto& e) {
            pto d = e - s;

            // p + alpha * v, s + beta * d;
            // alpha >= 0, beta >= 0 and beta <= 1
            if((v ^ d) == 0) {
                pto d1 = s - p, d2 = e - p;

                if((d1 ^ v) == 0 and (d1 * v) >= 0) return true;
                if((d2 ^ v) == 0 and (d2 * v) >= 0) return true;

                return false;
            }
            else {
                db a_num = ((s - p) ^ d), a_den = v ^ d;
                db b_num = (p - s) ^ v, b_den = d ^ v;

                if(a_den < 0) {
                    a_den *= -1;
                    a_num *= -1;
                }
                if(b_den < 0) {
                    b_den *= -1;
                    b_num *= -1;
                }

                if(a_num >= 0 and b_num >= 0 and b_num <= b_den) {
                    return true;
                }
                return false;
            }
        };

        pto s[4], e[4];

        s[0] = {L.x + r, L.y + r}; e[0] = {R.x - r, L.y + r};
        s[1] = {L.x + r, R.y - r}; e[1] = {R.x - r, R.y - r};
        s[2] = {L.x + r, R.y - r}; e[2] = {L.x + r, L.y + r};
        s[3] = {R.x - r, R.y - r}; e[3] = {R.x - r, L.y + r};

        bool cmp = false;
        for(int i = 0; i < 4; i++) {
            if(intersect(p, v, s[i], e[i]))
                cmp = true;
        }

        cout << (cmp ? "Yes\n" : "No\n");
    }


    return 0;
}

