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

//-------------------soln-------------------------------------------//
map<string,set<string>>mp;
bool chk(string s,string t){
    int cnt=0;
    for(auto it :mp[s]){
        if(SZ(it)>SZ(t)){
            string tmp= it.substr(SZ(it)-SZ(t));
            int fl=0;
            rep(i,0,SZ(t)){
                if(tmp[i]!=t[i]){
                    fl=1;
                    break;
                }
            }
            if(fl==0)cnt++;
        }
    }
    if(cnt>0)return false;
    else return true;
}

void solve(){
    int n,m;cin>>n;
    string s,t;
    while(n--){
        cin>>s>>m;
        while(m--){
            cin>>t;
            mp[s].insert(t);
        }
    }
    cout<<SZ(mp)<<endl;
    //it.ff = string
    for(auto it:mp){
        set<string>ans;
        for(auto j:it.ss){
            if(chk(it.ff,j)){
                ans.insert(j);
            }
        }
        cout<<it.ff<<" ";
        cout<<SZ(ans)<<" ";
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}