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
bool vis[N], inst[N];
int n, m;
vec<vec<int> > adj(N);
stack<int> st;
vec<int> ans;
bool dfs(int u)
{
    vis[u] = 1;
    inst[u] = 1;
    st.push(u);
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            if(dfs(v)) return true;
        }
        if(inst[v]) 
        {
            st.push(v);
            return true;
        }
    }
    st.pop();
    inst[u] = 0;
    return false;
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
        adj[x].pb(y);
    }
    for(int i = 1; i <= n; i++) inst[i] = vis[i] = 0;
    bool te = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i))
            {
                te = 1; 
                break;
            }
        }
    }
    if(!te) 
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int cnt = st.top();
    while(!st.empty())
    {
        ans.pb(st.top());
        st.pop();
        if(ans.back() == cnt && (int)ans.size() > 1)
        {
            reverse(SZ(ans));
            cout << (int)ans.size() << '\n';
            for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << ' ';
            return 0;
        }
    }
    return 0;
}

