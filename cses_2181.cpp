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
const int N = int(1e6) + 1;
int n, m;
ll f[(1 << 10)][1001];
const int mod = int(1e9) + 7;
void dp(int x, int y, int mask, int next_mask)
{
    if(x == m) return;
    if(y >= n) f[next_mask][x + 1] = ((f[next_mask][x + 1]%mod) + (f[mask][x]%mod))%mod;
    else 
    {
        if(getbit(y, mask)) dp(x, y + 1, mask, next_mask);
        else   
        {
            dp(x, y + 1, mask, (next_mask|(BIT(y)) ));
            if((y + 1 < n)&&(!getbit(y + 1,mask))) dp(x, y + 2, mask, next_mask);
        }
    }
}
int main()
{
    fastio();
    cin >> n >> m;
    f[0][0] = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < BIT(n); j++) dp(i, 0, j, 0);
    }
    cout << f[0][m];
    return 0;
}

