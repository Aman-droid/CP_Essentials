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
int main()
{
	FIO;
    int T;cin>>T;
    while(T--)
	{
		int n,k; cin>>n>>k;
		string s; cin>>s;
		int ans = 0;
		for (int i =0;i<k/2;++i){
			int cnt[26] = {};
			for (int j = 0; j + k - 1 < n; j += k){
				int i1 = j + i;
				int i2 = j + (k - 1 - i);
				cnt[s[i1] - 'a']++;
				cnt[s[i2] - 'a']++;
			}
			int req = 2 * (n / k);
			int mx = *max_element(cnt, cnt + 26);
			ans += req - mx;
		}
		if (k & 1){
			int cnt[26] = {};
			for (int i = k / 2; i < n; i += k){
				cnt[s[i] - 'a']++;
			}
			int req = n / k;
			int mx = *max_element(cnt, cnt + 26);
			ans += req - mx;
		}
		cout << ans << '\n';
	}
	return 0;
}