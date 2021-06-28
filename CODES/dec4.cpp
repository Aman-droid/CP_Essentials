#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
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

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int n;
vector<string>a;
bool isValid(int x,int y)
{
    if(x>=n || x<0 || y<0 || y>=n)
        return false;
    else
        return true;
    
}
int solve(int x,int y)
{
    int cnt=0;
    rep(i,0,3){
        if(isValid(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]]=='X')
            cnt++;
    }
    return cnt;
}
int main() {
    int T;cin>>T;
    while (T--)
    {
        a.clear();
        rep(i,0,n-1)
        {
            string t;cin>>t;
            a.pb(t);
        }
         rep(i,0,n-1){
            rep(j,0,n-1){
               cout<<a[i][j];
            }
            cout<<endl;
        }
        rep(i,0,n-1){
            rep(j,0,n-1){
               if(solve(i,j)==4)
                    a[i][j]='O'; 
            }
        }
        rep(i,0,n-1){
            rep(j,0,n-1){
               if(solve(i,j)==3)
                    a[i][j]='O'; 
            }
        }
        rep(i,0,n-1){
            rep(j,0,n-1){
               if(solve(i,j)==2)
                    a[i][j]='O'; 
            }
        }
        rep(i,0,n-1){
            rep(j,0,n-1){
               cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}

