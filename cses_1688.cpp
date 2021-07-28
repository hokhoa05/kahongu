///KhoaHo///
#include<bits/stdc++.h>
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
template<class val> inline val gcd(val a, val b){ return (a ? gcd(b%a, a): b);}
template<class val> inline val fmul(val a, val b, val m){ if (!b) return 0; if (!(b-1)) return a; if (b%2) return (fmul(a, b/2, m)*2+a)%m; else return (fmul(a, b/2, m)*2)%m; }
template<class val> inline bool getbit(val pos, val mask) {return ((mask >> pos)&1);}
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
void init()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
const int N = int(2e5) + 1;
int NumNode, par[N][20], Queries, depth[N];
vec<vec<int> > adj(N);
void dfs(int u, int p = -1)
{
    for(int v : adj[u]) 
    {
        if(p != v)
        {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}
int lca(int u, int v)
{
    if(depth[u] < depth[v]) return lca(v, u);
    for(int i = 19; i >= 0; i--)
    {
        if(depth[par[u][i]] >= depth[v]) 
        {
            u = par[u][i];
        }
    }
    if(u == v) return v;
    for(int i = 19; i >= 0; i--)
    {
        if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
int main()
{
    fastio();
    ///init();
    cin >> NumNode >> Queries;
    for(int i = 2; i <= NumNode; i++)
    {
        cin >> par[i][0];
        adj[i].pb(par[i][0]);
        adj[par[i][0]].pb(i);
    }
    for(int i = 1; i < 20; i++)
    {
        for(int u = 1; u <= NumNode; u++) par[u][i] = par[par[u][i - 1]][i - 1];
    }
    depth[1] = 0;
    depth[0] = -1;
    dfs(1);
    while(Queries--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
    return 0;
}

