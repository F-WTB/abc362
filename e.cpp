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
int N, A[80];

struct st {
    ll d;
    int v, len;
    st() {}
    st(ll d, int v, int len) : d(d), v(v), len(len) {}

    auto operator<=>(const st &) const = default;
};

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    map<st, mint> m;
    for (int i = 0; i < N; ++i) {
        map<st, mint> add;

        for (auto [x, w] : m)
            if (A[i] == x.d + x.v)
                add[st(x.d, A[i], x.len + 1)] += w;

        for (auto [x, w] : add)
            m[x] += w;

        for (int j = 0; j < i; ++j)
            ++m[st(A[i] - A[j], A[i], 2)];
    }

    vector<mint> ans(N);
    ans[0] = N;
    for (auto [x, w] : m) ans[x.len - 1] += w;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << (i < ans.size() - 1 ? '\t' : '\n');
}
