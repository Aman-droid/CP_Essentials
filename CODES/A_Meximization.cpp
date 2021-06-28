#include<bits/stdc++.h>
#define ll long long 
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
signed main() {
    //FIO;
    int T=1;cin>>T;
    while (T--){
        int n,m,x;cin>>n;
        vector<int>ans;
        int a[n];
        int cnt[110]={};
        rep(i,0,n-1){
            cin>>x;
            cnt[x]++;
        }
        for(int i=0;i<105;i++){
            if(cnt[i]>0){
                ans.pb(i);
                cnt[i]--;
            }
        }
        int tmp=0;
        for(int i=0;i<105;i++){
            if(cnt[i]>0){
                tmp=cnt[i];
                rep(j,1,tmp){
                    ans.pb(i);
                }
            }
        }
        for(auto it:ans){
            cout<<it<<" ";
        } 
        cout<<endl; 
    }
    return 0;   
}