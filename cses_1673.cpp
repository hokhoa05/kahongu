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
#define N 5001

///typedef-zone
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<ll, int> ii;
typedef pair<long long, long long> pll;
typedef pair<int, ii> iii;

///code-mau
template<class val> inline val gcd(val a, val b){ return (a ? gcd(b%a, a): b);}

void init()
{
      freopen(task".inp","r",stdin);
      freopen(task".out","w",stdout);
}

void fastio()
{
      ios_base::sync_with_stdio(NULL);
      cin.tie(NULL);
      cout.tie(NULL);
}
int n, m;
vec<vec<int> > adj1(N), adj2(N);
ll dist[N], w[N];
int x[N], y[N];
bool vis1[N], vis2[N];
void dfs1(int u)
{
      vis1[u] = 1;
      for(int v : adj1[u]) if(!vis1[v]) dfs1(v);
}
void dfs2(int u)
{
      vis2[u] = 1;
      for(int v : adj2[u]) if(!vis2[v]) dfs2(v);
}
int main()
{
      fastio();
      ///init();
      cin >> n >> m;
      for(int i = 1; i <= n; i++)
      {
            vis1[i] = vis2[i] = 0;
      }
      for(int i = 1; i <= m; i++)
      {
            cin >> x[i] >> y[i] >> w[i];
            w[i] = -w[i];
            adj1[x[i]].pb(y[i]);
            adj2[y[i]].pb(x[i]);
      }
      for(int i = 1; i <= n; i++) dist[i] = 1e18;
      dfs1(1); dfs2(n);
      dist[1] = 0;
      for(int i = 1; i <= n; i++)
      {
            for(int j = 1; j <= m; j++)
            {
                  if(dist[y[j]] > dist[x[j]] + w[j])
                  {
                        dist[y[j]] = dist[x[j]] + w[j];
                        if(i == n && vis1[y[j]] && vis2[y[j]])
                        {
                              cout << "-1";
                              return 0;
                        }
                  }
            }
      }
      cout << -dist[n];
      return 0;
}


