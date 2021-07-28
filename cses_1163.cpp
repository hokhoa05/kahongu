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
int n, p, x;
multiset<int> ans;
set<int> lights;
int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    init();
    #endif // ONLINE_JUDGE
    cin >> x >> n;
    lights.insert(0);
    lights.insert(x);
    ans.insert(x);
    while(n--)
    {
        cin >> p;
        auto it = lights.upper_bound(p);
        auto it2 = it;
        --it2;
        ans.erase(ans.find(*it - *it2));
        ans.insert(p - *it2);
        ans.insert(*it - p);
        lights.insert(p);
        auto res = ans.end();
        --res;
        cout << *res << ' ';
    }
    return 0;
}



