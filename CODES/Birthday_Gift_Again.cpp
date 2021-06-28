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
const int mxn =2e5;
int cnt[mxn];

int main(){
    FIO;
	int T;cin>>T;
	while(T--){
	    string s;cin>>s;
	    int n = s.length();
	    for(int i=1;i<=n;i++){
	        cnt[i] = cnt[i-1] + s[i-1] - '0';
	    }
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        int x = 1;
	        while(true){
	            int j = i + x*x + x;
	            if(j > n) break;
	            int tmp = cnt[j] - cnt[i];
	            if(tmp == x) ans++;
	            x++;
	        }
	    }
	    cout<<ans<<endl;
	}
}