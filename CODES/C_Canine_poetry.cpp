#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
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
unordered_map<int,int>mp;
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        mp.clear();
        string s;cin>>s;
        int n=s.length();
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        int ans=0;
        if(s[0]==s[1]){
            ans++;
            mp[1]++;
        }
        //watch(ans);
        rep(i,2,n-1){
            if(s[i]==s[i-1] && mp.count(i-1)==0){
                ans++;
                //cout<<i<<" "<<i-1<<" "<<ans<<endl;
                mp[i]++;
            }
            else if(s[i]==s[i-2] && mp.count(i-2)==0){
                ans++;
                //cout<<i<<" "<<i-2<<" "<<ans<<endl;
                mp[i]++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;   
}