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
//-------------------soln-----------------------------//

const int mxn=2e5;
bool comp(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
    if(a.first.first != b.first.first){
        return a.first.first <b.first.first;
    }
    else{
        return a.first.second < b.first.second;
    }       
}

void solve(){
    int n,W,H,wi,hi;cin>>n>>W>>H;
    // cout<<" n   "<< n<<endl;
    int ans =0;
    vector<pair<pair<int,int>,int>>v;
    rep(i,1,n){
        cin>>wi>>hi;
        if(wi<=W || hi<=H )continue;
        else{
            v.push_back({{wi,hi},i});
        }
    }
    int N=v.size();
    if(N==0){
        cout<<"0"<<endl;
        return;
    }

    vector<int>cnt(N+1,1);
    vector<int>par(N+1,-1);

    sort(all(v),comp);
    int mx=-1,pos=-1;
    rep(i,0,N-1){
        rep(j,0,i-1){
            if(v[i].ff.ff > v[j].ff.ff && v[i].ff.ss > v[j].ff.ss && cnt[j]+1 > cnt[i]){
                cnt[i]=cnt[j]+1;
                par[i]=j;
            }
        }    
    }
    // rep(i,0,N-1){
    //     cout<<v[i].ff.ff<<"  "<<v[i].ff.ss <<"  "<<v[i].ss<<" --->"<<cnt[i]<<endl;
    // }

    rep(i,0,N-1){
        if(cnt[i]> mx){
            pos=i;
            mx=cnt[i];
        }
    }

    int tmp=1;
    cout<<mx<<endl;
    vector<int>res;
    while(1){
        res.pb(v[pos].ss);
        if(par[pos]==-1){
            break;
        }
        else{
            pos=par[pos];
        }
    }
    reverse(all(res));
    for(auto it :res){
        cout<<it<<" ";
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