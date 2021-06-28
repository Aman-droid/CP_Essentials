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
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        vector<int>a[27],b[27];
        int l=0,r=0;
        int n;cin>>n;
        string s1,s2;cin>>s1>>s2;
        vector<pair<char,int>>vec;
        rep(i,0,n-1){
            vec.pb({s1[i],i+1});
        }
        rep(i,0,n-1){
            if(s2[i]=='?'){
                b[26].pb(i+1);
            }
            else{
                b[s2[i]-'a'].pb(i+1);
            }
        }
        int ans=0;
        sort(vec.begin(),vec.end());
        vector<pair<int,int>>res;
        for(int i=n-1;i>=0;i--){
            if(vec[i].ff=='?'){
                ans++;
                rep(x,0,26){
                    if(!b[x].empty()){
                        res.pb({vec[i].ss,b[x].back()});
                        b[x].pop_back();
                        break;  
                    }
                }
            }
            else{
                int p=vec[i].ff-'a';
                if(!b[p].empty()){
                    ans++;
                    res.pb({vec[i].ss,b[p].back()});
                    b[p].pop_back();
                }
                else if(!b[26].empty()){
                    ans++;
                    res.pb({vec[i].ss,b[26].back()});
                    b[26].pop_back();
                }
            }
        }
        cout<<ans<<endl;
        for(auto it:res){
            cout<<it.ff<<" "<<it.ss<<endl;
        }
         
    }
    return 0;   
}