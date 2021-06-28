// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long  int
// #define rep(i,a,b)  for(ll i=a;i<=b;i++)
// #define rep2(i,a,b) for(ll i=b;i>=a;i--)
// #define MOD 1000000007
// #define pb push_back
// #define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
// #define ss second
// #define ff first
// #define mod 1000000007
// #define inf (ll)(1e18)
// #define MAXN 10000001
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(), (c).end()

using namespace std;
ll power(ll a, ll b)
{ //a^b
    ll res = 1;
    a = a % mod;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
            b--;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
//-------------------soln-----------------------------//

const int mxn = 2e5;
map<int, int> m1;
map<pair<int, int>, int> m2;
map<pair<int, int>, int>::iterator it;

void solve()
{
    int n;cin >> n;
    string str;
    cin >> str;
    map<string, int> mp[3];
    for (int i = 0; i <= 2; i++){
        for (int j = 0; j <= max(0LL, n - 1 - i); j++){
            mp[i][str.substr(j, i + 1)] = 1;
        }
    }
    int fl = 0;
    string res;

    for (char c1 = 'a'; c1 <= 'z'; c1++){
        string s1="";
        s1 += c1;
        if (mp[0].find(s1) == mp[0].end()){
            res = s1;
            fl = 1;
            break;
        }
    }

    if (!fl)
    {
        for (char c1 = 'a'; c1 <= 'z'; c1++)
        {
            for (char c2 = 'a'; c2 <= 'z'; c2++)
            {
                string s1, s2;
                s1 = c1;
                s2 = c2;
                string s3 = s1 + s2;
                if (mp[1].find(s3) == mp[1].end())
                {
                    fl = 1;
                    res = s3;
                    break;
                }
            }
            if (fl)
                break;
        }
    }
    if (!fl)
    {
        for (char c1 = 'a'; c1 <= 'z'; c1++)
        {
            for (char c2 = 'a'; c2 <= 'z'; c2++)
            {
                for (char c3 = 'a'; c3 <= 'z'; c3++)
                {
                    string s1, s2, s3;
                    s1 = c1;
                    s2 = c2;
                    s3 = c3;
                    string s4 = s1 + s2 + s3;
                    if (mp[2].find(s4) == mp[2].end()){
                        fl = 1;
                        res = s4;
                        break;
                    }
                }
                if (fl)
                    break;
            }
            if (fl)
                break;
        }
    }
    cout << res << endl;
}
signed main()
{
    FIO;
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
