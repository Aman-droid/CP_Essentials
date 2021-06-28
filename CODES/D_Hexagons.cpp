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

#include <bits/stdc++.h>
using namespace std;
ll solve(ll x,ll pos,ll neg)
{
    if(x>0)
        return x*pos;
    else
        return (-x)*neg;
}
int main()
{
    ll T,mn,x,y;
    ll c[7];
    
    cin>>T;
    while(T--)
    {
        cin>>x>>y;
        rep(i,1,6)cin>>c[i];
        mn=2e18;
        mn=min(mn,solve(x,c[6],c[3])+solve(y,c[2],c[5]));
        mn=min(mn,solve(x,c[1],c[4])+solve(y-x,c[2],c[5]));
        mn=min(mn,solve(y,c[1],c[4])+solve(x-y,c[6],c[3]));
        cout<<mn<<endl;
    }
    return 0;
}

