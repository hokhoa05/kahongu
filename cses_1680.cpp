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
int n, m;
vec<vec<int>> adj(N);
int d[N], cha[N], in[N];
vec<int> ans;
int main()
{
    fastio();
    ///init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        d[i] = -1e9;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        in[y]++;
    }
    queue<int> q;
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (d[v] < d[u] + 1)
            {
                d[v] = d[u] + 1;
                cha[v] = u;
            }
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }
    if (d[n] >= 0)
    {
        int node = n;
        while (node != 1)
        {
            ans.pb(node);
            node = cha[node];
        }
        cout << d[n] + 1 << '\n';
        cout << 1 << " ";
        for (int i = (int)ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}

/*
28
1 26390 15278 11333 48479 68819 69624 61219 80410 45681 27080 96240 18599 35167 45808 20738 49483 38643 2623 35450 15247 26432 6746 34810 83877 12657 16293 100000

17
1 26390 15278 11333 48479 68819 69624 9082 59737 36969 81677 20565 2571 35626 88832 82174 100000  
*/