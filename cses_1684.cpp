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
int n, m, low[N], num[N], cnt = 0, CompID[N], Comp = 0, CompOpp[N], in[N], res[N];
vec<vec<int>> adj(N), BigAdj(N);
int op(int x)
{
    if (x > n)
        return x - n;
    else
        return x + n;
}
stack<int> st;
void visit(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (int v : adj[u])
    {
        if (!num[v])
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u])
    {
        int v;
        ++Comp;
        do
        {
            v = st.top();
            st.pop();
            low[v] = num[v] = INT_MAX;
            CompID[v] = Comp;
        } while (u != v);
    }
}
int main()
{
    fastio();
    ///init();
    cin >> m >> n;
    while (m--)
    {
        int x, y;
        char c1, c2;
        cin >> c1 >> x >> c2 >> y;
        if (c1 == '-')
            x += n;
        if (c2 == '-')
            y += n;
        adj[op(x)].pb(y);
        adj[op(y)].pb(x);
    }
    for (int i = 1; i <= 2 * n; i++)
        if (!num[i])
            visit(i);
    for (int i = 1; i <= n; i++)
    {
        if (CompID[i] == CompID[i + n])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        else
        {
            CompOpp[CompID[i]] = CompID[i + n];
            CompOpp[CompID[i + n]] = CompID[i];
        }
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int v : adj[i])
        {
            if (CompID[v] != CompID[i])
            {
                in[CompID[i]]++;
                BigAdj[CompID[v]].pb(CompID[i]);
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= Comp; i++)
        if (in[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (!res[u])
        {
            res[u] = 1;
            res[CompOpp[u]] = 2;
        }
        for (int v : BigAdj[u])
        {
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (res[CompID[i]] == 1)
            cout << "+ ";
        else
            cout << "- ";
    return 0;
}
