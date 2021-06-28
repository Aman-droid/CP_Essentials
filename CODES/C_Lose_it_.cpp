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


int main() {
    //FIO;
    int T=1;//cin>>T;
    while (T--){
        int n;cin>>n;
        int a[n];
        int p[6]={4,8,15,16,23,42};
        rep(i,0,n-1){
            cin>>a[i];
            a[i]=lower_bound(p,p+6,a[i])-p;
        }
        vector<int> cnt(6,0);
        rep(i,0,n-1){
            if(a[i]==0)cnt[a[i]]++;
            else if(cnt[a[i]-1]>0){
                cnt[a[i]-1]--;
                cnt[a[i]]++;
            }
        }
        int ans=n-(6*cnt[5]);
        cout<<ans<<endl;

    }
    return 0;   
}