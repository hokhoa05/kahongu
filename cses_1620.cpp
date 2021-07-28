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
#define N int(2e5) + 1

///typedef-zone
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<int, int> ii;
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
int n;
ll t, a[N], res = 0;
int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    init();
    #endif // ONLINE_JUDGE
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll mid, l = 1, r = 1e18;
    //int mid;
    while(l <= r)
    {
        mid = (l + r)/2;
        ll sum = 0;
        //cout << mid << '\n';
        for(int i = 1; i <= n; i++)
        {
            sum += mid/a[i];
            if(sum >= t) break;
        }
        if(sum >= t)
        {
            r = mid - 1;
            res = mid;
        } else l = mid + 1;
    }
    cout << res;
    return 0;
}



