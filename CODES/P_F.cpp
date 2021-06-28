#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int n;cin>>n;
        /*ll x=1;
        vector<int>ans;
        rep(i,1,n){            
            rep(j,1,n){
                int tmp=x;
                x++;
                while(tmp>0){
                    ans.pb(tmp%2);
                    tmp=tmp/2;
                }
                reverse(ans.begin(),ans.end());
                for(auto it:ans)cout<<it;
                cout<<" ";
                ans.clear();
            }
            cout<<endl;
        }*/
        ll cnt=1;
        rep(i,1,n){
            rep(j,1,n){
                ll x=log2(cnt)+1;
                for(ll k=x-1;k>=0;k--) 
                    cout<<(((1<<k)&cnt)?1:0);
                cout<<" "; 
                cnt++;
            }
            cout<<endl;
        }
    }
    return 0;   
}