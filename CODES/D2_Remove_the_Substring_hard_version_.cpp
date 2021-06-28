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
	string s,t;cin>>s>>t;
    int n=SZ(s),m=SZ(t);
    int rt[m];
    for(int i=m-1;i>=0;i--){
        int pos=n-1;
        if(i!=m-1)
            pos=rt[i+1]-1;
        while(s[pos]!=t[i])pos--;
        rt[i]=pos;  //storing the rightmost pos. of s[i]
    }
    int pos=0,ans=0;
    rep(i,0,n-1){
        int x=n-1;
        if(pos<m) x =rt[pos]-1;
        ans=max(ans,x-i+1);
        if(pos<m && t[pos]==s[i])pos++;
    }
	cout<<ans<<endl;
	
	return 0;
}