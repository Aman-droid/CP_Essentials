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
int sum,lim;
// int lowbit(int x){
// 	for(int i=0;i<40;i++){
// 		if(x&(1LL<<i))
// 			return (1LL<<i);
// 	}
//     return 0;
// }

void solve(){
    cin>>sum>>lim;
	vector<pair<int, int>> v;
	rep(i,1,lim){
		v.pb({(i&(-i)), i});
	}
    sort(all(v));
    reverse(all(v));

	vector<int> ans;

	for(auto it:v){
		if(sum>=it.first){
			sum-=it.first;
			ans.push_back(it.second);
		}
	}
	if(sum>0){
		cout<<"-1"<<endl;
		return;
	}

	cout<<SZ(ans)<<endl;
	for(auto it:ans)
		cout<<it<<" ";
    cout<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}