#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
// Big two primes
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define vii vector<ii>
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
void pr(int x) {cout << x;}
void prl(int x) {cout << x << endl;}
// typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;
//bool isPrime(int N){ for(int i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
int cbrt(int x) { int lo = 1, hi = min(2000000ll, x); while (hi - lo > 1) {int mid = (lo + hi) / 2; if (mid * mid * mid < x) {lo = mid;} else hi = mid;} if (hi * hi * hi <= x) return hi; else return lo;}
const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int N = (int)(2 * 1e5 + 10);
/*// bool comp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
// if (p1.fi > p2.first) return true;
// else if (p1.se == p2.se) {
// if (p1.se.fi < p2.se.fi) return true;
// }
// return false;
// }
 
 
class Compare
{
    public: 
    bool operator() (pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
    {
        if (p1.fi > p2.fi) 
            return true;
        else if (p1.fi == p2.fi) {
            if (p1.se.fi < p2.se.fi) 
                return true;
        }   
        return false;
    }
};
 
 
signed main() {
#ifndef ONLINE_JUDGE
// for getting input from input.txt
freopen("input.txt", "r", stdin);
// for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif
 
fio;
//srand(time(NULL));
int T = 1;
cin >> T;
 
while (T--) {
    int n;cin >> n;
    vi a(n, 0);
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({n, {0, (n - 1)}});
    int cnt = 0;
    while (!pq.empty()) {
 
int l = -1 * pq.top().se.fi;
int r = pq.top().se.se;
 
int len = pq.top().fi;
pq.pop();
 
if (l > r) continue;
cnt++;
int mid = (r + l) / 2;
 
// cout << l << " " << r << " " << mid << endl;
a[mid] = cnt;
// cout << l << " " << mid - 1 << endl;
pq.push({mid - l + 1, { (-1 * l) , mid - 1}});
// cout << mid + 1 << " " << r << endl;
pq.push({r - mid + 1, { -1 * (mid + 1), r}});
 
// prl(222);
}
 
for (auto it : a) cout << it << " ";
cout << endl;
}
}
*/ 

