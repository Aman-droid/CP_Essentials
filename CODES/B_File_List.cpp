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
    string s;cin>>s;
    int n= s.size();
    vector<string>ans;
    vector<int>pos;
    string s1,s2;
    int cnt=0,tmp;
    int j=0;
    int fl=0;

    rep(i,0,n-1){
        if(s[i]=='.'){
            pos.push_back(i);
        }
    }
    int N=SZ(pos);
    int a[n]={0};

    if(N==0 || pos[0]>8 || pos[0]<=0 || n-pos[N-1]-1 > 3 ||n-pos[N-1]-1 <= 0){
        cout<<"NO"<<endl;
        return;
    }
    rep(i,1,N-1){
        int x=pos[i]-pos[i-1]-1;
        if( x > 11 || x < 2){
            cout<<"NO"<<endl;
            return;
        }
        else{
            int mid= min(8LL,x-1LL);
            a[pos[i]-mid]=1;
        }
    }
    string res="";

    rep(i,0,n-1){
        if(a[i]==0){
            res+=s[i];
        }
        else{
            ans.push_back(res);
            res="";
            res+=s[i];
        }
    }
    ans.push_back(res);
    cout<<"YES"<<endl;
    for(auto it:ans){
        cout<<it<<endl;
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