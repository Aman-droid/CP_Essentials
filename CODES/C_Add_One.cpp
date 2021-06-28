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
//-------------------soln-----------------------------//

const int mxn=2e5;

void solve(){
    int n,m,x;cin>>n>>m;
    int N=n,tmp;
    
    int cnt1[15]={};
    int cnt2[15]={};

    while(N>0){
        x=N%10;
        cnt1[x]++;
        N=N/10;
    }
    // rep(i,0,9)cout<<cnt1[i]<<" ";
    // cout<<endl;

    rep(i,1,m){
        rep(i,0,9){
            if(i==9){
                if(cnt1[i]>0){
                    tmp=cnt1[i];
                    cnt1[i]=0;
                    cnt2[0]+=tmp;
                    cnt2[1]+=tmp;
                }
            }
            else{
                if(cnt1[i]>0){
                    tmp=cnt1[i];
                    cnt1[i]=0;
                    cnt2[i+1]+=tmp;
                }
            }
        }
        // rep(i,0,9)cout<<cnt1[i]<<" ";
        //     cout<<endl;
        rep(i,0,9){
            cnt1[i]=cnt2[i];
            cnt2[i]=0;
        }

    }

    int ans=0;
    rep(i,0,9){
        ans=(ans+cnt1[i])%mod;
    }
    ans=ans%mod;
    cout<<ans<<endl;
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}