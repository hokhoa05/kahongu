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
vec<iii> a;
ll res = 0;
int par[N];
int anc(int u)
{
    if(par[u] == u) return u;
    else return par[u] = anc(par[u]);
}
void join(int p, int q)
{
    par[anc(p)] = anc(q);
}
int cnt = 0;
int main()
{
    fastio();
    ///init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    while(m--)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        a.pb(iii(w, ii(x, y)));
    }
    sort(SZ(a));
    for(int i = 0; i < a.size(); i++)
    {
        int u = a[i].se.fi;
        int v = a[i].se.se;
        if(anc(u) != anc(v))
        {
            join(u, v);
            res += a[i].fi;
            ++cnt;
        }
    }
    if(cnt == n - 1) cout << res;
    else cout << "IMPOSSIBLE";
    return 0;
}

