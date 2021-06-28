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

void solve(){
    int n;cin>>n;ll A[n];
	rep(i,0,n-1) cin>>A[i];
	stack< pair<int,int>>s;

	s.push({0,1});//ind lvl
	vector<string>v(n);
	
    v[0]='1';
    
	rep(i,1,n-1){
		if(A[i]==1){
			s.push({i,s.top().ss+1});
			v[i]  = v[i-1];
			v[i] += '.';
			v[i] += '1';
		}
		else if(A[i]-A[i-1]==1){
			s.push({i,s.top().ss});
			v[i] = v[i-1].substr(0,v[i-1].size()-1);
			string st = to_string(A[i]);
			v[i] += st;
		}
		else{
			int fl=1;
			while(fl){
				ll ind = s.top().ff;
				ll cnt = s.top().ss;

				if(A[ind]+1 != A[i]){
					while(!s.empty() && s.top().ss == cnt) s.pop();
				}
				else{
					fl=0;
					s.push({i,cnt});
					v[i] = v[ind].substr(0,v[ind].size()-1);
					string st = to_string(A[i]);
					v[i] += st;
				}
			}
		}
	}
	rep(i,0,n-1) cout<<v[i]<<"\n";
}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}

