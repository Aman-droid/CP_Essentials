#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
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
#define int long long
int n, ans = 0;
int a[200005];
map<int, int> mp;
 
int32_t main()
{
	FIO;
	cin>>n;
	for(int i=1;i<= n;i++)
	{
		cin >> a[i];
		for(int p = 2; p <= 2e9; p *= 2)
		{
			if(mp.count(p - a[i]))
				ans +=mp[p - a[i]];
		}
		mp[a[i]]++;
	}
	cout << ans;
	return 0;
}
