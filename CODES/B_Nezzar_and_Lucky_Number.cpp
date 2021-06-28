#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
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

bool isSubsetSum(vector<ll> &set, ll n, ll sum)
{
    bool subset[n + 1][sum + 1];
    for (ll i = 0; i <= n; i++)
        subset[i][0] = true;
 
    for (ll i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
    return subset[n][sum];
}

signed main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
        ll t;
        ll q,a;cin>>q>>t;
        ll tmp=t*10;
        while(q--){
            cin>>a;
            if(t==1)cout<<"YES"<<endl;
            else if(a>=tmp){
                cout<<"YES"<<endl;
            }
            else{
                set<ll>arr;
                rep(i,1,9){
                    ll y=t*i;
                    if(y>a)break;
                    arr.insert(y);
                }
                ll i=t;
                while(i<=a){
                    arr.insert(i);
                    i=i+10;
                }
                vector<ll>v;
                for(auto it:arr){
                    //cout<<it<<" ";
                    v.pb(it);
                }
                ll n=SZ(v);
                ll sum=a;
                //watch(sum);
                // bool  dp[n+1][sum+1];
                // rep(i,0,n){rep(j,0,sum)dp[i][j]=false;}
                // dp[0][0]=true;
                // rep(i,1,n){
                //     rep(j,0,sum){
                //         dp[i][j]=dp[i-1][j];
                //         ll left = j-v[i-1];
                //         if(left>=0 && dp[i-1][left])dp[i][j]=true;
                //     }
                // }
                bool res=isSubsetSum(v,n,sum);
                if(res==true)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;  
            }
        }

    }
    return 0;   
}