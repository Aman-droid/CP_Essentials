#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5;

void solve(int T){
    int n,m,tmp;cin>>n>>m;
    int a[n][m];
    int cost=0,ans=0;
    rep(i,0,n-1){
        rep(j,0,m-1){
            cin>>a[i][j];
            a[i][j]--;
        }
    }
    rep(j,0,m-1){
        vector<int>cnt(n,0);
        rep(i,0,n-1){
            if(a[i][j]%m==j){
                int pos=a[i][j]/m;
                if(pos<n){
                    cnt[(i-pos+n)%n]++;
                }
            }
        }
        cost = n-cnt[0];
        for(int i=1;i<n;i++){
            cost=min(cost,n-cnt[i]+i);
        }
        ans+=cost;
        
    }
    cout<<ans<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}