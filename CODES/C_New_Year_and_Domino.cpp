#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
string t[505];
int vis[505][505];
int c[505][505];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
unordered_map<int,int>mp;
bool isValid(int x,int y){
    if(x<0 || x>n-1 || y<0 || y>m-1)
        return false;
    if(vis[x][y]==1)
        return false;
    return  true;
}
 
void dfs(int x,int y,int col)
{
    vis[x][y]=1;
    c[x][y]=col;
    for(int i=0;i<4;i++){
        //xn = x + dx[i] ;
        //yn = y + dy[i] ;
        if(isValid(x + dx[i],y + dy[i]) && t[x + dx[i]][y + dy[i]]=='.'){
            dfs(x+dx[i],y + dy[i],col);
        }
    }
}
int main() {
    int T=1;//cin>>T;
    while (T--)
    {
        cin>>n>>m;
        rep(i,0,n-1)cin>>t[i];
        int q;cin>>q;
        int col=1;
        rep(i,0,n-1){
            rep(j,0,m-1){
                if(!vis[i][j] &&t[i][j]=='.'){
                    dfs(i,j,col);
                    col++;
                }
            }
        }
        rep(i,0,n-1){
            rep(j,0,m-1){
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
        while(q--){
            int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
            x1--;y1--;x2--;y2--;
            ll ans=0;
            mp.clear();
            rep(i,x1,x2){
                rep(j,y1,y2){
                    if(c[i][j]!=0){
                        mp[c[i][j]]++;
                    }
                }
            }

            for(auto it:mp){
                cout<<it.ff<<"----> "<<it.ss<<endl;
                if(it.ss>=2){
                    ans+=(it.ss-1);
                }
            }
            cout<<ans<<endl;
        }
    }
}

