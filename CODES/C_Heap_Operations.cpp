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
priority_queue<int, vector<int>, greater<int> >q;

void solve(){
    int n,x,tmp;cin>>n;
    string s;
    vector<pair<string,int>>res;

    while(n--){
        cin>>s;

        if(s[0] =='i')
        {
            cin>>x;
            q.push(x);
            res.push_back({s,x});
            
        }

        else if(s[0]=='r'){
            if(q.empty()){
                res.pb({"insert",1});
                res.pb({"removeMin",1});
            }
            else{
                res.pb({s,1});
                tmp=q.top();
                q.pop();
            }   
        }
        else{
            cin>>x;
            if(q.empty()){
                res.pb({"insert",x});
                q.push(x);
                res.pb({"getMin",x});
            }
            else{
                while(!q.empty() && q.top()<x){
                    res.pb({"removeMin",1});
                    q.pop();
                }
                if(q.top()==x){
                    res.pb({"getMin",x});
                }
                else{
                    res.pb({"insert",x});
                    q.push(x);
                    res.pb({"getMin",x});
                }
            } 
        }
    }
    cout<<SZ(res)<<endl;
    for(auto it :res){
        if(it.ff[0]=='r'){
            cout<<it.ff<<endl;
        }
        else{
            cout<<it.ff<<" "<<it.ss<<endl;
        }
    }
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}