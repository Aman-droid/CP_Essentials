#include<bits/stdc++.h>
#define ll long long
#define int long long 
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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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
//-------------------soln-----------------------------//

const int mxn=2e5;

void solve(){
    int n,N;cin>>n;
    string s;
    string pr,sf;

    vector<pair<int,char>>ans;

    vector<pair<string,int>> G[n+1];
    rep(i,1,2*n-2){
        cin>>s;
        N=SZ(s);
        G[N].pb({s,i});
    }
    //watch(n);
    string t1,t2,s1,s2;

    t1 = G[1][0].ff;
    t2 = G[1][1].ff;

    // int cntp=0,cnts=0;
    ans.pb({G[1][0].ss,'P'});
    ans.pb({G[1][1].ss,'S'});
    pr = t1;
    sf = t2;
    
    //watch2(t1,t2);
    
    rep(i,2,n-1){
        t1= G[i][0].ff;
        t2= G[i][1].ff;
        // s1 = reverse(all(t2));
        // s2 = reverse(all(t1));
        if(t1.substr(0,i-1) ==pr && t2.substr(1, i-1) == sf){
            ans.pb({G[i][0].ss,'P'});
            ans.pb({G[i][1].ss,'S'});
            pr=t1;
            sf=t2;
        }
        else if(t2.substr(0,i-1) ==pr && t1.substr(1, i-1) == sf){
            ans.pb({G[i][1].ss,'P'});
            ans.pb({G[i][0].ss,'S'});
            pr=t2;
            sf=t1;
        }
    }
    if(SZ(ans)== (2*n-2) ){
        sort(all(ans));
        for(auto it: ans){
            cout<<it.ss;
        }
        cout<<endl;
        return;
    }

    ans.clear();
    t1 = G[1][0].ff;
    t2 = G[1][1].ff;

    // int cntp=0,cnts=0;
    ans.pb({G[1][0].ss,'S'});
    ans.pb({G[1][1].ss,'P'});
    
    pr = t2;
    sf = t1;
    
    //watch2(t1,t2);
    
    rep(i,2,n-1){
        t1= G[i][0].ff;
        t2= G[i][1].ff;
        // s1 = reverse(all(t2));
        // s2 = reverse(all(t1));
        if(t1.substr(0,i-1) ==pr && t2.substr(1, i-1) == sf){
            ans.pb({G[i][0].ss,'P'});
            ans.pb({G[i][1].ss,'S'});
            pr=t1;
            sf=t2;
        }
        else if(t2.substr(0,i-1) ==pr && t1.substr(1, i-1) == sf){
            ans.pb({G[i][1].ss,'P'});
            ans.pb({G[i][0].ss,'S'});
            pr=t2;
            sf=t1;
        }
    }
    sort(all(ans));
    for(auto it: ans){
        cout<<it.ss;
    }
    cout<<endl;
    

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}