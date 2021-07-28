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
int n;
data a[N];
vec<int> ST[5*N];
int cnt = 0;
void build(int id = 1, int l = 1, int r = n)
{
    if(l > r) return;
    if(l == r)
    {
        cnt++;
        ST[id].pb(a[l].y);
        return;
    }
    int mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);
    merge(ST[2*id].begin(), ST[2*id].end(), ST[2*id + 1].begin(), ST[2*id + 1].end(), back_inserter(ST[id]));
}
int get(int u, int v, int val, int type, int id = 1, int l = 1, int r = n)
{
    if(r < u || l > v) return 0;
    if(l >= u && r <= v)
    {
        if(type == 1) return upper_bound(SZ(ST[id]), val) - ST[id].begin();
        else return lower_bound(SZ(ST[id]), val) - ST[id].begin();
    }
    int mid = (l + r) >> 1;
    return get(u, v, val, type, 2*id, l, mid)+ get(u, v, val, type, 2*id + 1, mid + 1, r);
}
int res1[N], res2[N];
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
    build();
    for(int i = 1; i <= n; i++)
    {
        res1[a[i].id] = get(i + 1, n, a[i].y, 1);
    }
    for(int i = 1; i <= n; i++) cout << res1[i] << " \n"[i == n];
    for(int i = 2; i <= n; i++)
    {
        res2[a[i].id] = (i - 1) - get(1, i - 1, a[i].y, 2);
    }
    for(int i = 1; i <= n; i++) cout << res2[i] << " \n"[i == n];
    return 0;
}



