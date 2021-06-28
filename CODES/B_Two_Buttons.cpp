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
const int mxn=4e4;
int main() {
    //FIO;
	int n,x;cin>>n>>x; 
	vector<int >dis(mxn,-1);
	dis[n] = 0;
	queue<int> q; 
    q.push(n);
	while (!q.empty()) {
		int cur = q.front(); 
        q.pop();
		int nxt = cur-1;
		if (nxt >= 0 && dis[nxt] == -1) {
			dis[nxt] = dis[cur]+1;
			q.push(nxt);
		}
		nxt = cur*2;
		if (nxt < mxn && dis[nxt] == -1) {
			dis[nxt] = dis[cur]+1;
			q.push(nxt);
		}
	}
    cout<<dis[x]<<endl;
    return 0;
}
 