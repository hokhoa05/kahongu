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
int n;
vec<vec<int>> adj(N), Comp(N);
int low[N], num[N], cnt = 0, comp = 0, compID[N];
stack<int> st;
int res[N];
void visit(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
    for (int v : adj[u])
    {
        if (!num[v])
        {
            visit(v);
            low[u] = min(low[v], low[u]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u])
    {
        ++comp;
        int node = 0;
        int v;
        do
        {
            v = st.top();
            st.pop();
            ++node;
            low[v] = num[v] = INT_MAX;
            Comp[comp].pb(v);
            compID[v] = comp;
        } while (v != u);
        if (node > 1)
        {
            for (int v : Comp[comp])
                res[v] = node;
        }
    }
}
int main()
{
    fastio();
    ///init();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[i].pb(x);
        if (i == x)
            res[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (!num[i])
            visit(i);
    for (int i = 1; i <= comp; i++)
    {
        for (int u : Comp[i])
        {
            for (int v : adj[u])
            {
                if (compID[v] != compID[u])
                {
                    if (res[u] == 0)
                        res[u] = res[v] + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    return 0;
}
