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
int n, m, dp[N], in[N];
vec<vec<int>> adj(N), adj2(N);
int mod = int(1e9) + 7;
int main()
{
    fastio();
    //init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = in[i] = 0;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        in[y]++;
        adj[x].pb(y);
        adj2[y].pb(x);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);
    dp[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            in[v]--;
            if (!in[v])
                q.push(v);
        }
        for (int v : adj2[u])
        {
            dp[u] = (dp[u] + dp[v]) % mod;
        }
    }
    cout << dp[n] % mod;
    return 0;
}
