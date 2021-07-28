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
const int N = int(2e5) + 1;
int n, a[N], k;
ll res = 0;
bool check(ll mid)
{
    int cnt = 0;
    ll sum = 0;
    //cout << mid << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > mid) return false;
        if(sum + a[i] > mid)
        {
            sum = 0;
            ++cnt;
        }
        sum += a[i];
    }
    if(sum > 0) ++cnt;
    return (cnt <= k);
}
void tknp(ll l, ll r)
{
    ll mid;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(check(mid))
        {
            r = mid - 1;
            res = mid;
        } else l = mid + 1;
    }
}
int main()
{
    fastio();
    ///init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    tknp(0, 1e18);
    cout << res;
    return 0;
}

