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
string t1="RGB";
string t2="GBR";
string t3="BRG";

int solve(string s,string t,int n,int k){
    vector<int>c(n,0);
    int tmp=0,res=mod;
    rep(i,0,n-1){
       if(s[i]!=t[i%3])c[i]=1,tmp++;
       if(i>=k)tmp-=c[i-k];
       if(i>=k-1)res=min(res,tmp);
    }
    return res;
}

int main(){
    FIO;
    int T;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int ans=mod;
        ans=min(ans,solve(s,t1,n,k));
        ans=min(ans,solve(s,t2,n,k));
        ans=min(ans,solve(s,t3,n,k));
        cout<<ans<<endl;
    }
}