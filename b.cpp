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
int x[3], y[3];
vector<int> v;
int main() {
    for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];
    for (int i = 0; i < 2; ++i)
        for (int j = i + 1; j < 3; ++j)
            v.push_back((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

    sort(v.begin(), v.end());
    cout << (v[0] + v[1] == v[2] ? "Yes\n" : "No\n");
}
