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
const int mxn=2e5;

void solve(){
    int n,k,a,b;cin>>k>>a>>b;
    string s;cin>>s;
    n=s.size();
    if(a*k> n || b*k<n){
        cout<<"No solution"<<endl;
        return;
    }
    int x,rem;
    x=n/k;
    rem=n%k;
    int j=0,tmp;

    rep(i,0,k-1){
        if(rem>0){
            tmp=x+1;
        }
        else{
            tmp=x;
        }
        while(tmp>0 && j<n){
            cout<<s[j];
            j++;
            tmp--;
        }
        rem--;
        cout<<endl;
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