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

string S, T;
int N, Q;
vector<int> sa;

bool g(string &T, int k) {
    for (int i = 0; i < T.size() && k + i < N; ++i) {
        if (T[i] == S[k + i]) continue;
        return T[i] < S[k + i];
    }
    return T.size() <= N - k;
}

int f(string &T) {
    int ok = N, ng = -1;
    while (abs(ok - ng) > 1) {
        int m = (ok + ng) / 2;
        (g(T, sa[m]) ? ok : ng) = m;
    }
    return ok;
}

int main() {
    cin >> S >> Q;
    N = S.size();
    sa = suffix_array(S);
    for (int _ = 0; _ < Q; ++_) {
        cin >> T;
        int a = f(T);
        T += '~';
        int b = f(T);
        cout << b - a << '\n';
    }
}
