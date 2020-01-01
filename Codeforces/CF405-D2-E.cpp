/*
    Author: Nguyen Tan Bao
    Status: AC
    Idea: More or less like the editorial https://codeforces.com/blog/entry/11186
*/
 
#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x
 
using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, ll> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;
 
const ll MODBASE = 1000000007LL;
const int MAXN = 100010;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;

int n, m;
vector<int> a[MAXN], b[MAXN], unpaired[MAXN];
bool visited[MAXN];
set<II> blocked;

int dfs(int u) {
    visited[u] = true;
    FOR(i,0,SZ(a[u])-1) {
        int v = a[u][i];
        if (blocked.count(II(u, v)) || blocked.count(II(v, u))) continue;
        b[u].emplace_back(v);
        blocked.insert(II(u, v));
    }
    FOR(i,0,SZ(b[u])-1) {
        int v = b[u][i];
        int w = 0;
        if (!visited[v]) w = dfs(v);
        if (w == 0) unpaired[u].push_back(v);
        else cout << u << ' ' << v << ' ' << w << "\n";
    }
    while (SZ(unpaired[u]) >= 2) {
        int v = unpaired[u].back(); unpaired[u].pop_back();
        int w = unpaired[u].back(); unpaired[u].pop_back();
        cout << v << ' ' << u << ' ' << w << "\n";
    }
    if (SZ(unpaired[u])) return unpaired[u].back();
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    FOR(i,1,m) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    if (m % 2) {
        cout << "No solution";
        return 0;
    }
    dfs(1);
    return 0;
}
