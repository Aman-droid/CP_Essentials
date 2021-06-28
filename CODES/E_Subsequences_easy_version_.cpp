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
void solve(string s,int n,int k){
    int ans=0;
    queue<string>q;
    set<string>st;
    q.push(s);
    st.insert(s);
    while(!q.empty() && SZ(st)<k){
        string cur=q.front();
        q.pop();
        for(int i=0;i<SZ(cur);i++){
            string c2=cur;
            c2.erase(i,1);
            if(!st.count(c2) && SZ(st)<k){
                q.push(c2);
                st.insert(c2);
                ans+=n-SZ(c2);
            }
        }
    }
    if(SZ(st)<k)cout<<"-1"<<endl;
    else cout<<ans<<endl; 
}

int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        solve(s,n,k);
    }
    return 0;   
}