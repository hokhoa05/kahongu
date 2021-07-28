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
const int N = 5000;
int n, m;
vec<vec<int> > a(N);
int res = INT_MAX;
queue<int> q;
int bfs(int s)
{
    vec<int> dist(n + 1, -1);
    q.push(s);
    dist[s] = 0;
    int ret = INT_MAX;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : a[u])
        {
            if(dist[v] == -1)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
            } 
            else if(dist[v] >= dist[u])
            {
                ret = min(ret, dist[v] + dist[u] + 1);
            }
        }
    }
    return ret;
}
int main()
{
    fastio();
    //init();
    cin >> n >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(int i = 1; i <= n; i++) res = min(res, bfs(i));
    cout << ((res == INT_MAX) ? -1 : res);
    return 0;
}

