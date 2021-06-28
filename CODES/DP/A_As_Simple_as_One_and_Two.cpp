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

void solve(){
    string s;cin>>s;
    int n=s.length();
    int vis[n]={0};
    int cnt=0;
    vector<int>ans;
    for(int i=0 ; i<=n-3 ; i++){
        if(vis[i]==0 && s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
            if(i-2>=0 && s[i-1]=='w' && s[i-2]=='t'){
                ans.push_back(i+1);
                vis[i]=2;
                vis[i-1]=1;
                vis[i-2]=1;
                vis[i+1]=1;
                vis[i+2]=1;
                cnt++;
            }
            else{
                ans.push_back(i+2);
                vis[i]=1;
                vis[i+1]=2;
                vis[i+2]=1;
            }
        }
    }
    for(int i=0 ; i<=n-3 ; i++){
        if(vis[i]==0 && vis[i+2]==0 && s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
            ans.push_back(i+2);
            vis[i+1]=2;
            vis[i]=1;
            vis[i+2]=1;
        }
    }
    cout<<SZ(ans)<<endl;
    sort(all(ans));
    for(auto it :ans){
        cout<<it<<" ";
    }
    cout<<endl;

}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}