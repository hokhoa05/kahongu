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

///typedef-zone
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<ll, int> ii;
typedef pair<int, ii> iii;

///code-mau
template<class val> inline val gcd(val a, val b){ return (a ? gcd(b%a, a): b);}
template<class val> inline val fmul(val a, val b, val m){ if (!b) return 0; if (!(b-1)) return a; if (b%2) return (fmul(a, b/2, m)*2+a)%m; else return (fmul(a, b/2, m)*2)%m; }

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
const int N = 5005;
int n, u, v;
ll x;
ii a[N];
int tknp(int l, int r, ll p)
{
    int mid;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(a[mid].fi > p) r = mid - 1;
        else if(a[mid].fi < p) l = mid + 1;
        else
        {
            if(mid != u && mid != v)return mid;
            int lq, rq;
            if(mid == u)
            {
                if(a[u + 1].fi == p && u<n) lq = u + 1;
                else if(a[u - 1].fi == p && u > 0) rq = u - 1;
                while(a[lq].fi == p && lq <= n)
                {
                    if(lq != v) return lq;
                    ++lq;
                }
                while(a[rq].fi == p && rq > 0)
                {
                    if(rq != v) return rq;
                    --rq;
                }
            }
            if(a[v + 1].fi == p && v<n) lq = v + 1;
            else if(a[v - 1].fi == p && v > 0) rq = v - 1;
            while(a[lq].fi == p && lq <= n)
            {
                if(lq != u) return lq;
                ++lq;
            }
            while(a[rq].fi == p && rq > 0)
            {
                if(rq != u) return rq;
                --rq;
            }
            return 0;
        }
    }
    return 0;
}
int main()
{
    fastio();
    ///init();
    cin >> n >> x;
    if(n < 3) 
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    if(n == 3)
    {
        if(a[1].fi + a[2].fi + a[3].fi == x) 
        {
            cout << 1 << " " << 2 << " " << 3;
        } else cout << "IMPOSSIBLE";
        return 0;
    }
    sort(SZZ(a, 1, n));
    //for(int i = 1; i <= n; i++) cout << a[i].se << ' ';
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            ll s = a[i].fi + a[j].fi;
            u = i; v = j;
            int k = tknp(1, n, x - s);
            if(k) 
            {
                cout << a[u].se << " " << a[v].se << " " << a[k].se << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}

