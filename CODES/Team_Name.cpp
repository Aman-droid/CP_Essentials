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
    int T=1;cin>>T;
    while (T--){
        int n,m,x,p,q;cin>>n;
        vector<string>v[26];
        string s,tmp;
        rep(i,0,n-1){
            cin>>s;
            tmp=s.substr(1);
            v[s[0]-'a'].pb(tmp);
        }
        int ans=0;
        set<string>st;
        rep(i,0,24){
            if(v[i].size()==0)continue;
            m=v[i].size();
            for(auto it:v[i]){
                st.insert(it);
            }
            rep(j,i+1,25){
                if(v[j].size()==0)continue;
                p=0;  //equal
                q=0;
                for(auto it:v[j]){
                    if(st.find(it)!=st.end())p++;
                    else q++;
                }
                ans+=(m-p)*q;
            }
            st.clear();
        }
        ans=ans*2;
        cout<<ans<<endl;    
    }
    return 0;   
}