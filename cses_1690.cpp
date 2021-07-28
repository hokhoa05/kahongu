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
vec<vec<int> > a(25);
int n, m;
const int mod = int(1e9) + 7;
ll dp[(1 << 20)][24];
int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    init();
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        a[y].pb(x);
    }
    dp[1][1] = 1;
    for(int s = 2; s < (1 << n); s++)
    {
        if(((s>>(n-1))&1) && (s!=((1<<n) - 1))) continue;
        for(int i = 1; i <= n; i++)
        {
            if(!((s >> (i - 1))&1)) continue;
            for(int v : a[i])
            {
                if((s >> (v-1))&1)
                {
                    dp[s][i] += dp[s^(1<<(i - 1))][v];
                    dp[s][i] %= mod;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n];
    return 0;
}



