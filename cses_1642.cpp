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
typedef pair<ll, ii> iii;

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
const int N = 1006;
ll b[N], x;
int n;
map<ll, ii> m;
int main()
{
    fastio();
    ///init();
    cin >> n >> x;
    int cnt = 0;
    for(int i = 1; i <= n; i++) cin >> b[i];
    if(n == 4)
    {
        if(b[1] + b[2] + b[3] + b[4] == x)
        {
            cout << "1 2 3 4";
        } else cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i = n; i >= 1; i--)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            if(m.find(x - b[i] - b[j]) != m.end())
            {
                cout << i << " " << j << " " << m[x - b[i] - b[j]].fi << " " <<  m[x - b[i] - b[j]].se << '\n';
                return 0;
            }
        }
        for(int j = i - 1; j >= 1; j--)
        {
            m[b[i] + b[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}

