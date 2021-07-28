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
bool cha[N];
vec<int> res;
int n;
int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    init();
    #endif // ONLINE_JUDGE
    cin >> n;
    bool te = false;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for(int i = 1; !te; i = (i + 2)%n)
    {
        if(!cha[i])
        {
            int k = i;
            while(cha[(k + 1)%n]) ++k;
            cha[(k + 1)%n] = 1;
            if(k + 1 == n) res.pb(n);
            else res.pb((k + 1)%n);
        }
        if((int)res.size() == n) te = 1;
    }
    for(int i = 0; i < (int)res.size(); i++) cout << res[i] << ' ';
    return 0;
}



