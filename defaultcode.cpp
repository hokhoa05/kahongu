#include <bits/stdc++.h>
using namespace std;
/// define-zone
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

/// typedef-zone
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef double db;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

/// code-mau
template <class val>
inline val gcd(val a, val b) { return (a ? gcd(b % a, a) : b); }
template <class val>
inline val fmul(val a, val b, val m)
{
    if (!b)
        return 0;
    if (!(b - 1))
        return a;
    if (b % 2)
        return (fmul(a, b / 2, m) * 2 + a) % m;
    else
        return (fmul(a, b / 2, m) * 2) % m;
}
template <class val>
inline bool getBit(val pos, val mask) { return ((mask >> pos) & 1); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
void init()
{
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
}
const int N = int(1e6) + 1;
int main()
{
    fastio();
    init();
    return 0;
}
struct P
{
    int x, y;
    void read()
    {
        cin >> x >> y;
    }
    P operator-(const P &b) const
    {
        return {x - b.x, y - b.y};
    }
    void operator-=(const P &b)
    {
        x -= b.x;
        y -= b.y;
    }
    ll operator*(const P &b) const
    {
        return (ll)x * b.y - (ll)y * b.x;
    }
    ll triangle(const P &b, const P &c) const
    {
        return (b - *this) * (c - *this);
    }
    bool operator<(const P &b) const
    {
        return make_pair(x, y) < make_pair(b.x, b.y);
    }
    ll Dist(const P &b) const
    {
        return (ll)(x - b.x) * (x - b.x) + (ll)(y - b.y) * (y - b.y);
    }
};
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡠⠤⢒⡲⠭⠭⠝⠋⣉⣙⣛⣉⡩⣍⣓⠒⠒⠲⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠖⢋⠵⠒⠚⣋⣀⠤⠖⠊⠉⠁⠀⠀⠀⠀⠀⠈⠉⠋⠙⠒⠲⢭⡓⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⠤⠤⠤⡤⢤⣀⣴⢫⠼⠓⢁⣀⡤⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⡀⡀⠈⠑⢦⣱⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⡠⡮⠿⣍⠭⡿⠚⠛⠛⢿⡃⠀⡠⠋⠀⠀⠀⠀⡰⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠰⡄⠘⣌⠢⡀⠀⠙⢿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠸⡔⣇⠤⢴⡄⢹⠀⠀⠀⠀⠘⣿⠀⠀⠀⠀⠀⢰⠃⡸⠀⠀⠀⠀⢸⡀⡇⠀⠀⠀⠀⠀⠀⢱⠀⡘⣆⠙⢦⠀⠀⠙⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢠⣁⠿⣄⣠⣃⣼⠀⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⡟⠀⡇⠀⢠⠀⢀⣸⡇⢣⠀⠀⠀⠀⠀⠀⠀⣇⢇⢻⣧⡄⣷⡀⠀⠉⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣦⣽⣀⣀⣀⣀⣇⠀⠀⠀⢀⣾⠃⠀⠀⠀⠀⢰⡇⣠⡧⠖⢺⠁⠀⠸⡇⢸⠀⢠⠀⠀⠀⠀⠀⢸⢼⡽⡿⣾⣾⣧⠀⠀⠘⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⢳⡈⠁⠀⠈⠙⣄⠀⣠⣾⠇⠀⠀⠀⠀⠀⣾⣟⣽⡇⠀⢸⠀⠀⠀⣿⡀⣇⢸⡀⠀⠀⠀⠀⢸⣸⡇⡇⠈⢿⡿⡆⣟⢒⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠉⠓⣶⣶⣶⣿⡍⠓⡿⠀⠀⠀⠀⠠⠊⣿⣿⡇⡇⠀⠸⡆⠀⠀⣯⢧⠸⡀⣧⠀⠀⠀⠀⢸⣿⢿⡇⠀⠈⢻⣷⠘⢆⠙⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣿⠋⣾⣿⢻⢦⡏⠀⠀⠀⠀⠀⠀⣿⡿⠀⢷⢠⣀⣇⣀⣄⣹⠘⣤⣳⣸⣔⣄⣆⣤⣼⠾⠿⠻⠷⢶⣌⣿⡄⢈⠇⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⡇⢀⣿⡏⣏⣧⡇⠀⠀⠀⠀⠀⠀⣿⢁⣴⠿⠛⢛⣙⣛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠈⢡⣄⣹⣿⣷⣄⠙⣿⣧⢸⠰⣻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣸⠃⡗⣸⣿⢧⠘⣿⡇⠀⠀⠀⠀⠀⠀⣷⡟⠁⢀⡈⣻⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⡄⠸⣇⠵⠞⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣿⢸⣷⡏⢸⡝⠲⣿⡇⠀⠀⠀⠀⠀⠀⣿⠀⠀⢸⣿⣿⣿⣿⠛⢿⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⡙⠛⠁⣽⠃⠀⠻⣄⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠘⡿⢻⠃⢸⡟⠳⠛⣧⠀⠀⠀⠀⠀⠀⡟⠀⠀⠸⣿⡙⠛⠋⢀⡟⠀⠀⠀⠀⠀⠀⠀⠄⠀⠈⠛⠿⠟⠋⢀⢀⠀⠘⣆⢸⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡇⡿⡆⢸⠹⣄⠀⢿⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠉⡛⡚⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⡱⢣⢏⣞⡆⢹⣼⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣼⣸⠁⣷⢸⡆⢹⣷⣼⡄⠀⠀⠀⠀⠀⣿⠀⢠⢎⠞⡼⡱⠱⠁⠀⠀⠀⠀⣀⣠⣤⣤⣤⣄⡀⠀⠀⠀⠁⠋⠘⠀⠀⢸⣿⡿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢠⣿⡇⠀⣿⡆⣧⢸⣿⣿⣇⠀⠀⠀⠀⠀⣿⠀⠀⠋⠘⠈⠁⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⢿⠁⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⡇⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣼⣿⠀⢠⣿⣧⢸⡄⣿⣿⣿⡄⠀⠀⠀⠀⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⡿⠯⠋⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⢓⡇⠸⡇⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢰⣿⠇⠀⢸⣿⠻⠀⢷⣿⣿⣿⣇⠀⠀⠀⠀⢸⣧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⠁⢨⡇⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣸⣿⠀⠀⡾⡁⠀⠀⣸⣿⣿⣿⣿⡄⠀⠀⠀⠈⣿⣿⣿⣶⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣴⣶⣿⣿⣿⣿⣿⡟⠀⣿⡇⠀⢻⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣿⡿⣆⢰⠇⠀⠀⠀⣿⣿⣿⣿⣿⣷⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⡻⠧⠥⣄⣀⡀⣎⢿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⡇⢸⢹⠇⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢿⢷⠈⡿⡀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⢹⣿⣿⡿⠛⠻⣧⣧⣤⡄⠀⠠⢽⣇⡈⣹⣿⠻⣿⣿⣿⣿⣿⣿⣿⣿⡇⣾⢸⠀⠀⣸⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠘⣾⣶⢧⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠘⣿⣿⣀⡠⠞⣿⠽⢯⣬⣷⣚⠛⢿⣏⣥⡾⠳⣽⣿⣿⣿⣿⣿⣿⣿⢳⣿⣾⠀⠀⡏⡇⠀⠀⠀⠀⠀⠀⠀
*/