///KhoaHo///
#include <bits/stdc++.h>
using namespace std;
///define-zone
#define task "test"
#define vec vector
#define priq priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define SZ(a) a.begin(), a.end()
#define SZZ(a, begin, end) a + begin, a + begin + end
#define fi first
#define se second
#define BIT(n) (1 << n)

///typedef-zone
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

///code-mau
template <class val>
inline val gcd(val a, val b) { return (a ? gcd(b % a, a) : b); }
template <class val>
inline val fmul(val a, val b, val m)
{
    if (!b)
        return 0;
    if (!(b - 1))
        return a;
    if (b % 2)
        return (fmul(a, b / 2, m) * 2 + a) % m;
    else
        return (fmul(a, b / 2, m) * 2) % m;
}
template <class val>
inline bool getbit(val pos, val mask) { return ((mask >> pos) & 1); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
void init()
{
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
}
const int N = int(1e6) + 1;
int n, m, p[N];
vec<vec<int>> adj(N), BigAdj(N), Comp(N);
int low[N], num[N], cnt = 0, comp = 0, compID[N];
ll dp[N], val[N];
stack<int> st;
ll res = 0;
ll DP(int u)
{
    if (dp[u])
        return dp[u];
    dp[u] = val[u];
    for (int v : BigAdj[u])
        dp[u] = max(dp[u], DP(v) + val[u]);
    return dp[u];
}
void visit(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : adj[u])
    {
        if (!num[v])
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u])
    {
        ++comp;
        int v;
        do
        {
            v = st.top();
            st.pop();
            val[comp] += p[v];
            compID[v] = comp;
            low[v] = num[v] = INT_MAX;
        } while (v != u);
    }
}
int main()
{
    fastio();
    ///init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        dp[i] = 0;
        val[i] = 0;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    for (int i = 1; i <= n; i++)
        if (!num[i])
            visit(i);
    for (int i = 1; i <= n; i++)
    {
        for (int v : adj[i])
        {
            if (compID[v] != compID[i])
            {
                BigAdj[compID[i]].pb(compID[v]);
            }
        }
    }
    for (int i = 1; i <= comp; i++)
        res = max(res, DP(i));
    cout << res;
    return 0;
}
