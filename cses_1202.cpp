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
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

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
int n, m;
vec<vec<ii>> adj(N);
const int mod = int(1e9) + 7;
ll dp[N], dist[N], minn[N], maxx[N];
void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e18;
    }
    priq<ii, vec<ii>, greater<ii>> q;
    q.push(ii(0, s));
    dist[s] = 0;
    dp[s] = 1;
    while (!q.empty())
    {
        ll u = q.top().se;
        ll du = q.top().fi;
        q.pop();
        if (du != dist[u])
            continue;
        for (ii it : adj[u])
        {
            ll v = it.se;
            ll uv = it.fi;
            if (dist[v] > dist[u] + uv)
            {
                minn[v] = minn[u] + 1;
                maxx[v] = maxx[u] + 1;
                dp[v] = dp[u] % mod;
                dist[v] = dist[u] + uv;
                q.push(ii(dist[v], v));
            }
            else if (dist[v] == dist[u] + uv)
            {
                maxx[v] = max(maxx[v], maxx[u] + 1);
                minn[v] = min(minn[v], minn[u] + 1);
                dp[v] = (dp[v] + dp[u]) % mod;
            }
        }
    }
}
int main()
{
    fastio();
    ///init();
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        adj[x].pb(ii(w, y));
    }
    dijkstra(1);
    cout << dist[n] << " " << dp[n] << " " << minn[n] << " " << maxx[n];
    return 0;
}
