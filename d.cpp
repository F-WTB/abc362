#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<ll, int>;
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
int N, M, A[200000], U, V, B;
vector<pr> g[200000];

priority_queue<pr, vector<pr>, greater<pr>> q;

ll d[200000];

int main() {
    cin >> N >> M;
    fill(d, d + N, 1e18);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) {
        cin >> U >> V >> B;
        --U, --V;
        g[U].emplace_back(V, B);
        g[V].emplace_back(U, B);
    }

    q.emplace(A[0], 0);
    d[0] = A[0];

    while (q.size()) {
        auto [w, v] = q.top();
        q.pop();
        if (d[v] < w) continue;
        for (auto [nv, c] : g[v]) {
            ll nw = w + c + A[nv];
            if (nw < d[nv]) {
                d[nv] = nw;
                q.emplace(nw, nv);
            }
        }
    }

    for (int i = 1; i < N; ++i) cout << d[i] << (i < N - 1 ? '\t' : '\n');
}
