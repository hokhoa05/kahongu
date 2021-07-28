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
typedef pair<ll, int> ii;
typedef pair<ll, ii> iii;

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
int n, m;
vec<iii> edge;
vec<vec<ii> > adj1(N), adj2(N);
vec<ll> dist1(N), dist2(N);
vec<ll> dijkstra(int s, vec<vec<ii> > adj)
{
    vec<ll> dist(n + 1);
    for(int i = 1; i <= n; i++) dist[i] = 1e18;
    priq<ii, vec<ii>, greater<ii> > q;
    dist[s] = 0;
    q.push(ii(0, s));
    while(!q.empty())
    {
        int u = q.top().se;
        ll du = q.top().fi;
        q.pop();
        if(du != dist[u]) continue;
        for(ii it : adj[u])
        {
            ll uv = it.fi;
            int v = it.se;
            if(dist[v] > dist[u] + uv)
            {
                dist[v] = dist[u] + uv;
                q.push(ii(dist[v], v));
            }
        }
    }
    return dist;
}
ll res = 1e18;
int main()
{
    fastio();
    //init();
    cin >> n >> m;
    while(m--)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        edge.pb(iii(w, ii(x, y)));
        adj1[x].pb(ii(w, y));
        adj2[y].pb(ii(w, x));
    }
    dist1 = dijkstra(1, adj1);
    dist2 = dijkstra(n, adj2);
    for(auto it : edge)
    {
        int u = it.se.fi;
        int v = it.se.se;
        ll uv = it.fi;
        //cout << dist2[u] << '\n';
        res = min(res, dist1[u] + dist2[v] + uv/2);
    }
    cout << res;
    return 0;
}

