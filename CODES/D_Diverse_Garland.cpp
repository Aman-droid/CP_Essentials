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
// int main() {
//     FIO;
//     int T=1;//cin>>T;
//     while (T--){
//         int n,m,x;cin>>n;
//         string s;cin>>s;
//         char st[3]={'R','G','B'};
//         int dp[n][3]; //dp[i][0]==min changes if at ith pos color is 0==>red
//         dp[0][0]= (s[0]=='R')?0:1;
//         dp[0][1]= (s[0]=='G')?0:1;
//         dp[0][2]= (s[0]=='B')?0:1;
//         for(int i=1;i<n;i++){
//             dp[i][0]= (s[i]=='R')? 0:1;
//             dp[i][1]= (s[i]=='G')? 0:1;
//             dp[i][2]= (s[i]=='B')? 0:1;
//             dp[i][0]+=min(dp[i-1][1],dp[i-1][2]);
//             dp[i][1]+=min(dp[i-1][0],dp[i-1][2]);
//             dp[i][2]+=min(dp[i-1][1],dp[i-1][0]);
//         }
//         int pos=-1;
//         if(dp[n-1][0]<dp[n-1][1])pos=0;
//         else pos=1;
//         int y=min(dp[n-1][0],dp[n-1][1]);
//         if(dp[n-1][2]<y)pos=2;
//         ll z=min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
//         cout<<z<<endl;
//         string ans;
//         ans.pb(st[pos]);
//         //watch(pos);
//         for(int i=n-2;i>=0;i--){
//             if(pos==0){
//                 pos= (dp[i][1]<dp[i][2])? 1:2;
//             }
//             else if(pos==1){
//                 pos= (dp[i][0]<dp[i][2])? 0:2;
//             }
//             else{
//                 pos= (dp[i][0]<dp[i][1])? 0:1;
//             }
//             ans.pb(st[pos]);
//         }
//         reverse(ans.begin(),ans.end());
//         cout<<ans<<endl;
//     }
//     return 0;   
// }

int main() {
	int n;cin>>n;
	string s;cin>>s;
	int ans = 0;
	rep(i,0,n-1){
		int j = i;
		while (j < n && s[i] == s[j]) {
			j++;
		}
		string tmp = "RGB";
		tmp.erase(tmp.find(s[i]), 1);
		if (j < n) tmp.erase(tmp.find(s[j]), 1);
		for (int k = i + 1; k < j; k += 2) {
			ans++;
			s[k] = tmp[0];
		}
		i = j-1;
	}
	cout<<ans<<endl<<s<<endl;
	return 0;
}