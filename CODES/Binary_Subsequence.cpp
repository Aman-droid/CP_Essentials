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
    FIO;
    int T=1;cin>>T;
    while (T--){
        int m,x=0,y=0,k=0;
        int n;cin>>n;
        string s;cin>>s;
        int a[n],p[n],q[n];
        p[0]=(s[0]=='0')?1:0;
        q[n-1]=(s[n-1]=='1')?1:0;
        rep(i,0,n-1){
            if(s[i]=='0')x++;
            else y++;
        }
        rep(i,1,n-1){
            k=(s[i]=='0')?1:0;
            p[i]=k+p[i-1];
        }
        for(int i=n-2;i>=0;i--){
            k=(s[i]=='1')?1:0;
            q[i]=k+q[i+1];
        }
        int ans=0;
        rep(i,0,n-1){
            if(s[i]=='0'){
                ans=max(ans,p[i]+q[i]);
            }
        }
        int tmp=max(x,y);
        //watch(tmp);
        tmp=n-tmp;
        ans=n-ans;
        ans=min(ans,tmp);
        cout<<ans<<endl;
    }
    return 0;   
}