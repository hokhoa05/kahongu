/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "test"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b) : 0); }
void init()
{
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
struct Points
{
    ll x, y;
    void read()
    {
        cin >> x >> y;
    }
    Points(ll _x = 0, ll _y = 0)
    {
        x = _x;
        y = _y;
    }
    Points operator-(const Points &b) const
    {
        return (x - b.x, y - b.y);
    }
    ll operator*(const Points &b) const
    {
        return x * b.y - y * b.x;
    }
    ll triangle(const Points &b, const Points &c) const
    {
        return (*this - b) * (*this - c);
    }
};
const int N = int(1e6) + 1;
const ll INF = 1e18;
int main()
{
    fastio();
    init();
    return 0;
}
