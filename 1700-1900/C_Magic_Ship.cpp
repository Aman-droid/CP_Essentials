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

const int mxn=1e6+5;
int xx[mxn],yy[mxn];
string s;
int n;

bool chk (int k,int x1,int y1,int x2,int y2){
    int x3,y3;
    x3 =(k/n)*xx[n] + xx[k%n] + x1;
    y3 =(k/n)*yy[n] + yy[k%n] + y1;
    int dis = abs(x2-x3)+ abs(y2-y3);
    return dis<=k;
}
void bin(int x1,int y1,int x2,int y2){
    int low,high; 
    int ans=-1;
    low = 0;
    high = INF;
    while(low<=high){
        int mid=(high+low)/2;
        if(chk(mid,x1,y1,x2,y2)==true){
            high=mid-1;
            ans=mid;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}

void solve(){  
    int x1,y1,x2,y2;  
    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    cin>>s;
    xx[0]=0;
    yy[0]=0;
    for(int i=0;i<n;i++){
        xx[i+1]=xx[i];
        yy[i+1]=yy[i];
        if(s[i] =='R')
            xx[i+1]++;
        else if(s[i] =='L')
            xx[i+1]--;
        else if(s[i] =='U')
            yy[i+1]++;
        else if(s[i] =='D')
            yy[i+1]--;
    }
    bin(x1,y1,x2,y2);

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}