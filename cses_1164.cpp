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
    int val, type, id;
    bool operator < (data &u)
    {
        return ((val < u.val)||((val == u.val)&&(type < u.type)));
    }
};
int n, res[2*N];
data a[2*N];
stack<int> st;
int maxx = 0;
int main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    init();
    #endif // ONLINE_JUDGE
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[++cnt] = {x, 0, i};
        a[++cnt] = {y, 1, i};
    }
    sort(SZZ(a, 1, cnt));
    int tmp = 0;
    for(int i = 1; i <= cnt; i++)
    {
        if(a[i].type == 0)
        {
            ++tmp;
            if(st.empty())
            {
                res[a[i].id] = tmp;
            } else
            {
                res[a[i].id] = st.top();
                st.pop();
            }
            maxx = max(res[a[i].id], maxx);
        }
        else
        {
            --tmp;
            st.push(res[a[i].id]);
        }
    }
    cout << maxx << '\n';
    for(int i = 1; i <= n; i++) cout << res[i] << ' ';
    return 0;
}



