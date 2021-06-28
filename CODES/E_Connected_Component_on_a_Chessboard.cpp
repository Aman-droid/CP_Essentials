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
using namespace std;

int main() 
{	
	int T;cin >> T;
	while(T--){
		int b,w;cin >> b >> w;
		vector<pii> ans;
        int fl=0;
		if (b < w) {swap(w, b);fl=1;}
        int x=2,y=2;
        while(w>0){
            if((x+y)%2==0)w--,ans.pb({x,y});
            else b--,ans.pb({x,y});
            y++;
        }
        int x1 = 1, y1 = 2;
		while (b > 0 && y1 <= y) {
			ans.pb({x1, y1});
			b--;
			y1 += 2;
		}
		x1=3,y1= 2;
		while (b > 0 && y1 <= y) {
			ans.pb({x1,y1});b--;
			y1 += 2;
		}
		if (b > 0) {
			ans.pb({2, 1});b--;
		}
		if (b > 0) {
			ans.pb({2, y});
			b--;
		}
		if (b > 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for (pii it : ans) cout<<it.ff<< " " <<it.ss + fl<<endl;
		}
	}
}
	

