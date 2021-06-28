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
        int x,y;cin>>x>>y;
        string s;cin>>s;
        int n=s.length();
        int u=0,r=0,d=0,l=0;
        rep(i,0,n-1){
            if(s[i]=='R')r++;
            if(s[i]=='L')l++;
            if(s[i]=='U')u++;
            if(s[i]=='D')r++;
        }
        //watch2(x,y);
        int fl=0;
        if(x>=0 && r < x)fl=1;
        if(x<=0 && (l < abs(x)))fl=1;
        if(y>=0 && (u < y))fl=1;
        if(y<=0 && (d < abs(y)))fl=1;
        
        if(fl==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;   
}