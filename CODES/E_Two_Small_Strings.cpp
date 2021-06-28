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
    //FIO;
    int T=1;//cin>>T;
    while(T--)
    {
	    int n;cin>>n;
	    string s,t;cin>>s>>t;
	    string tmp[6]={"abc","acb","bac","bca","cab","cba"};
	    vector<string>ans;
	    rep(i,0,5){
	    	string b="";
	    	for(int j=0;j<n;j++)b+=tmp[i];
	    	ans.pb(b);
	    	b="";
	    	for(int j=0;j<n;j++)b+=tmp[i][0];
	    	for(int j=0;j<n;j++)b+=tmp[i][1];
	    	for(int j=0;j<n;j++)b+=tmp[i][2];
	    	ans.pb(b);
		}
        int flag=0;
		for(int i=0;i<ans.size();i++){
			int fl=0;
			for(ll j=0;j<(3*n)-1;j++){
				if(s==ans[i].substr(j,2)||t==ans[i].substr(j,2)){
					fl=1;
				}
			}
			if(fl==0){
                flag=1;
				cout<<"YES"<<endl;
				cout<<ans[i]<<endl;
				break;
			}
		}
        if(flag==0)
		    cout<<"NO"<<endl;
	}
}