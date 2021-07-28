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
int n, m, deg[N], del[N];
vec<vec<ii>> adj(N);
int st[N];
bool vis[N];
void dfs(int u)
{
    vis[u] = 1;
    for (ii v : adj[u])
        if (!vis[v.fi])
            dfs(v.fi);
}
int main()
{
    fastio();
    //init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        deg[i] = 0, vis[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        del[i] = 0;
        int x, y;
        cin >> x >> y;
        adj[x].pb(ii(y, i));
        adj[y].pb(ii(x, i));
        deg[x]++;
        deg[y]++;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && deg[i] > 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    int even = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] % 2 == 0)
            ++even;
        //cout << deg[i] << " \n"[i == n];
    }
    if (even != n)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int top = 0;
    st[++top] = 1;
    while (top > 0)
    {
        bool check = 0;
        int u = st[top];
        while (!adj[u].empty())
        {
            int v = adj[u].back().fi;
            int edge = adj[u].back().se;
            adj[u].pop_back();
            if (!del[edge])
            {
                del[edge] = 1;
                st[++top] = v;
                check = 1;
                break;
            }
        }
        if (!check)
        {
            cout << u << ' ';
            --top;
        }
    }
    return 0;
}
