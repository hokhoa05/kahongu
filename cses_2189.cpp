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
const int N = int(1e6) + 1;
int t;
complex<ll> s1, s2, p;
ll x, y, x2, y2, x3, y3;
int main()
{
    fastio();
    ///init();
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> x2 >> y2 >> x3 >> y3;
        s1 = {x, y};
        s2 = {x2, y2};
        p = {x3, y3};
        complex<ll> k = (p - s1);
        ll cnt = (conj(k)*(p - s2)).imag();
        if(cnt > 0) cout << "LEFT";
        else if(cnt < 0) cout << "RIGHT";
        else cout << "TOUCH";
        cout << '\n';
    }
    return 0;
}

