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

int N, w[200000], c, p[200000];
vector<int> g[200000];

void dfs(int v) {
    bool b = 1;
    for (int nv : g[v]) {
        if (nv == p[v]) continue;
        p[nv] = v;
        dfs(nv);
        if (w[nv] > N / 2) b = 0;
        w[v] += w[nv];
    }
    if (b && N - w[v] <= N / 2) c = v;
}

vector<int> a;
bool b[200000];

void dfs2(int v) {
    a.push_back(v);
    b[v] = 1;
    for (int nv : g[v]) {
        if (nv == p[v]) continue;
        dfs2(nv);
    }
}

void solve() {
    if (N % 2 == 0) a.push_back(c);
    b[c] = 1;

    for (int v : g[c]) {
        if (v == p[c]) continue;
        dfs2(v);
    }
    for (int i = 0; i < N; ++i)
        if (!b[i]) a.push_back(i);

    for (int i = 0; i < N / 2; ++i) cout << a[i] + 1 << ' ' << a[i + N / 2] + 1 << '\n';
}

int main() {
    cin >> N;
    fill(w, w + N, 1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    solve();
}
