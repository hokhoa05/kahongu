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
const int N = int(1e6) + 1;
int NumNodes, deg[N], NumEdges;
vec<vec<int> > adj(N);
bool vis[N];
vec<int> res;
int cnt = 0, low[N], num[N];
bool te = 0;
stack<int> st;
void visit(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);
    for(int v : adj[u])
    {
        if(!num[v])
        {
            visit(v);
            low[u] = min(low[v], low[u]);
        } else low[u] = min(low[u], num[v]);
    }
    if(low[u] == num[u]) 
    {
        int dem = 0;
        int v;
        do
        {
            v = st.top();
            st.pop();
            ++dem;
            low[v] = num[v] = INT_MAX;
        } while (v != u);
        if(dem > 1)
        { 
            te = 1;
            return;
        }
    }
}
void dfs(int u)
{
    vis[u] = 1;
    for(int v : adj[u]) if(!vis[v]) dfs(v);
    res.pb(u);
}
int main()
{
    fastio();
    ///init();
    cin >> NumNodes >> NumEdges;
    while(NumEdges--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    for(int i = 1; i <= NumNodes; i++) if(!num[i]) visit(i);
    if(te) return cout << "IMPOSSIBLE", 0;
    for(int i = 1; i <= NumNodes; i++) if(!vis[i]) dfs(i);
    for(int i = NumNodes - 1; i >= 0; i--) cout << res[i] << " ";
    return 0;
}

