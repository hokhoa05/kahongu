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
vec<iii> edge;
ll dist[N];
int cha[N];
int main()
{
    fastio();
    ///init();
    cin >> n >> m;
    while(m--)
    {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        edge.pb(iii(w, ii(x, y)));
    }
    for(int i = 1; i <= n; i++)
    { 
        dist[i] = 1e18;
        cha[i] = 0;
    }
    int k;
    for(int i = 1; i <= n; i++)
    {
        k = 0;
        for(auto it : edge)
        {
            ll c = it.fi;
            int a = it.se.fi;
            int b = it.se.se;
            if(dist[b] > dist[a] + c) 
            {
                dist[b] = dist[a] + c;
                cha[b] = a;
                k = b;
            }
        }
    }
    if(!k) cout << "NO";
    else 
    {
        cout << "YES\n";
        vec<int> ans;
        for(int i = 1; i <= n; i++) k = cha[k];
        for(int i = k;; i = cha[i])
        {
            ans.pb(i);
            if(i == k && (int)ans.size() > 1) break;
        }
        for(int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    }
    return 0;
}

