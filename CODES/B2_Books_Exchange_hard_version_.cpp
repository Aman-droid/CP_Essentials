#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
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
int main()
{
    int T;cin>>T;
	while(T--) {
		int n;cin>>n;
		vector<int> par(n+1);
		for (int i=1;i<=n;i++)cin >> par[i];
		vector<int> vis(n+1,0);
		vector<int> ans(n+1);
		rep(i,1,n) {
			if (vis[i]==0) {
				vector<int> tmp;
				while (vis[i]==0) {     //maintain a vis array to calc. ans of i ,par[i],par[par[i]]
					tmp.pb(i);          //in a single loop
					vis[i] = 1;
					i = par[i];
				}
				for (auto it : tmp)      //all element of the vector tmp will form an cycle
                    ans[it] = SZ(tmp);
			}
		}
		rep(i,1,n)cout<<ans[i]<<" ";
		cout << endl;
	}
	
	return 0;
}

