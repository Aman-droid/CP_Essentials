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
bool chk(string s, string t){
	int i=0;
	for(int j=0;j<s.size();j++){
		if(t[i] == s[j])i++;
		
        if(i == t.size())
		return true;	
	}
	return false;
}
int main()
{
    string s,t;cin>>s>>t;
    int n=s.length();
    int ans=0;
    rep(i,0,n-1){
        rep(j,i,n-1){
            string s1="";
            if(i>=1)s1+=s.substr(0,i);
            if(j+1<n) s1+=s.substr(j+1,n-(j+1));
            if(chk(s1,t))
                ans=max(ans,j-i+1);
        }
    }
    cout<<ans<<endl;
}