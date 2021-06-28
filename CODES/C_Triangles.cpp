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

vector<pair<int,int>> vp[10];
bool comp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.ff*p1.ff +p2.ss+p2.ss;
}

int main() {
    int T;cin>>T;
    while (T--)
    {
        int n;cin>>n;
        int a[n+1][n+1];
        for(int x=0;x<9;x++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++)
                {
                    vp[a[i][j]].pb({i,j});
                }
            }
        }
        for(int i=0;i<=9;i++)
        {
            if(vp[i].size()<=1)
                cout<<"0"<<" ";
            else if(vp[i].size()==2)
            {
                int ans1=0,ans2=0;
                if(vp[i][0].ff==vp[i][1].ff)
                {
                    ans1=(vp[i][0].ss==vp[i][1].ss)*max(abs(1-vp[i][0].ff),abs(n-vp[i][0].ff));
                }
                else if(vp[i][0].ff==vp[i][1].ff)
                {
                    ans1=(vp[i][0].ss==vp[i][1].ss)*max(abs(1-vp[i][0].ff),abs(n-vp[i][0].ff));
                }
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                    sort(vp[i].begin(),vp[i].end(),comp);
                }              
            }
        }
    }
}

