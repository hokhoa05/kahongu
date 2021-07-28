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
struct data
{
    int x, y;
    int id;
    bool operator < (data &u)
    {
        return ((u.x > x) || ((u.x == x)&&(u.y < y)));
    }
};
data a[N], b[N];
bool res1[N], res2[N];
int n;
int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    init();
    #endif // ONLINE_JUDGE
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(SZZ(a, 1, n));
    int maxx = 0, minn = int(1e9);
    //for(int i = 1; i <= n; i++) cout << a[i].x << " " << a[i].y << " " << a[i].id << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(a[i].y <= maxx) res1[a[i].id] = 1;
        maxx = max(a[i].y, maxx);
    }
    for(int i = n; i >= 1; i--)
    {
        if(a[i].y >= minn) res2[a[i].id] = 1;
        minn = min(a[i].y, minn);
    }
    for(int i = 1; i <= n; i++) cout << res2[i] << " ";
    cout << '\n';
    for(int i = 1; i <= n; i++) cout << res1[i] << " ";
    return 0;
}



