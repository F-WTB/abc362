#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
int N, L[200000], R[200000], ans[200000];

ll a = 0, b = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
        a += L[i];
        b += R[i];
    }

    if (a > 0 || b < 0) {
        cout << "No" << '\n';
        return 0;
    }

    cout << "Yes\n";

    ll r = -a;

    for (int i = 0; i < N; ++i) {
        int t = min((ll)R[i] - L[i], r);
        ans[i] = L[i] + t;
        r -= t;
    }
    for (int i = 0; i < N; ++i) cout << ans[i] << (i < N - 1 ? '\t' : '\n');
}
