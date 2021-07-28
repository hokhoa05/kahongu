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
typedef pair<int, int> ii;
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
const int N = int(2e5) + 1;
int n;
ll x, a[N], s[N], res = 0;
int tknp(int l, int r, ll p)
{
    int mid;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(s[mid] > p) r = mid - 1;
        else if(s[mid] < p) l = mid + 1;
        else return mid;
    }
    return -1;
}
int main()
{
    fastio();
    ///init();
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
    {
        if(tknp(0, i, s[i] - x) != -1) ++res;
    }
    cout << res;
    return 0;
}

