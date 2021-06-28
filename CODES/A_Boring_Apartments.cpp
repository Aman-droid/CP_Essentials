#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;
vector<int>v;
unordered_map<int,int>mp;
int tmp,sum=0;

void solve(){
    int x;cin>>x;    
    int ans=0;
    int i=1;

    cout<<mp[x]<<endl;

}
signed main() {
    FIO;
    int T=1;cin>>T;
    v.push_back(-1);
    sum=0;
    rep(i,1,9){
        tmp=0;
        int pw=1;
        rep(j,0,3){
            tmp+=i*pw;
            pw=pw*10;
            sum+=j+1;
            mp[tmp]=sum;
            v.push_back(tmp);
        }
    }
    
    while (T--){
       solve();
    }
    return 0;   
}