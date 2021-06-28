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
int k;

int check(ll x,int tag){
	int res=0;
	for(int i=1 ; i<=x; i=i*10){
		if(tag==1){
            res += (x-i+1)*(x-i+2)/2;
        }
		else{ 
            res+=(x-i+1);
        }
	}
	return res;
}

int bins(int l,int r,int tag){
    int res=-1;
	while(l<=r){
		int mid=(l+r+1)/2;
		if(check(mid,tag)<k){
            l=mid+1;
            res=mid;
        }
		else{ 
            r=mid-1;    
	    }
    }
	return res;
}
 
void solve(){
    cin>>k;
    int x=bins(0,2e9,1);
    k-=check(x,1);

    int y=bins(0,x+1,0);
    k-=check(y,0);

    cout<<to_string(y+1)[k-1]<<endl;
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}