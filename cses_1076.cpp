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
const int N = int(2e5) + 5;
int n, a[N], k;
ll sum = 0;
map<int, int> m, m1;
int bit[N];
void add(int x, int val){
	for (; x < N; x += x & -x) bit[x] += val;
}
int get(int x, int sum = 0)
{
	for (; x > 0; x -= x & -x) sum += bit[x]; return sum;
}
int main()
{
    fastio();
    //init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        m[a[i]] = 0;
    }
    int cnt = 1;
    for(auto &i : m)
    {
        i.se = cnt++;
        m1[i.se] = i.fi;
    }
    int median = k/2 + (k & 1);
    for(int i = 1; i <= n; i++)
    {
        add(m[a[i]], 1);
        if(i > k) add(m[a[i - k]], -1);
        if(i >= k)
        {
            int mid, l = 1, r = N;
            int ans = -1;
            while(l <= r) 
            {
                mid = (l + r) >> 1;
                if(get(mid) >= median && get(mid - 1) < median)
                {
                    ans = mid;
                    break;
                } else if(get(mid) < median) l = mid + 1;
                else r = mid - 1;
            }
            cout << m1[ans] << ' ';
        }
    }
    return 0;
}

