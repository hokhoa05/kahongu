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
const int N = int(2e5) + 2;
const int M = 20;
int n, q, par[30][N], depth[N];
bool vis[N];
void dfs(int i)
{
    if(vis[i]) return;
    vis[i] = 1;
    dfs(par[0][i]);
    depth[i] = depth[par[0][i]] + 1;
}
int getpar(int x, int h)
{
    for(int i = 0; i <= 20; i++) if((h >> i)&1) x = par[i][x];
    return ((x) ? x : -1);
}
int main()
{
    fastio();
    ///init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> par[0][i];
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= n; j++) par[i][j] = par[i - 1][par[i - 1][j]];
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int parx = getpar(x, depth[x]);
        if(getpar(x, depth[x] - depth[y]) == y) cout << depth[x] - depth[y] << '\n';
        else if(getpar(parx, depth[parx] - depth[y]) == y) cout << depth[x] + depth[parx] - depth[y] << '\n';
        else cout << "-1\n";
    }
    return 0;
}

