#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
const int mxn=2e5;

int n,m;
vector<int> cnt;
int diff;
 
void func() {
    for (int i = 1; i <= n; i++){
        cnt[i]--;
        if (cnt[i] == 0)
            diff--;
    }
}

void solve(){
    cin >>n>>m;
    cnt.assign(n+1, 0);
    
    diff = 0;
    rep(i,1,m){
        int x;cin >> x;
        if(cnt[x]++ == 0)diff++;
 
        if (diff == n) {
            func();
            cout<<"1";
        } 
        else {
            cout<<"0";
        }
    } 
    cout <<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
 
