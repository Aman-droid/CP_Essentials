#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//

const int N = 305;
int T, n;
string s[N];
 
void solve() {
    cin >> n;
    int col[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    int k = 0;
    rep(i,0,n-1) {
        cin >> s[i];
        rep(j,0,n-1) {
            char c = s[i][j];
            int val = (i + j) % 3;
            if(c == 'X') {
                col[val][0]++;
                k++;
            }
            else if(c == 'O') {
                col[val][1]++;
                k++;
            }
        }
    }

    rep(d,0,2) {
        rep(d2,0,2) {
            if(d == d2) continue;
            if(col[d][0] + col[d2][1] <= k / 3) {
                rep(i,0,n-1) {
                    rep(j,0,n-1) {
                        if((i + j) % 3 == d && s[i][j] == 'X') {
                            s[i][j] = 'O';
                        }else if((i + j) % 3 == d2 && s[i][j] == 'O') {
                            s[i][j] = 'X';
                        }
                    }
                    cout << s[i] << '\n';
                }
                return;
            }
        }
    }
}
 
int main() {
    FIO;
    cin >> T;
    while(T--) {
        solve();
    }
}