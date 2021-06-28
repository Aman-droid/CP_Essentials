#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

vector<vector<int>>v,v1,v2;
bool comp(vector<int>& a,vector<int>& b){
    if(a[0]!=b[0])return a[0]<b[0];   
    else if(a[1]!=b[1])return a[1]<b[1];   
    else return a[2]<b[2];   
}

void solve(int T){
    int n,x,y,z;cin>>n;
    
    rep(i,1,n){
        cin>>x>>y>>z;
        v.pb({x,y,z,i});
    }

    sort(all(v),comp);
    //watch(n);

    for(int i=0;i<n;i++){
        if(i<n-1){
            if(v[i][0] == v[i+1][0] && v[i][1] == v[i+1][1]){
                cout<<v[i][3]<<" "<<v[i+1][3]<<endl;
                i++;
            }
            else{
                v1.pb({v[i][0],v[i][1],v[i][2],v[i][3]});
            }
        }
        else{
            v1.pb({v[i][0],v[i][1],v[i][2],v[i][3]});
        }
    }

    int n1=SZ(v1);
    for(int i=0;i<n1;i++){
        if(i<n1-1){
            if(v1[i][0] == v1[i+1][0] && i<n1-1){
                cout<<v1[i][3]<<" "<<v1[i+1][3]<<endl;
                i++;
            }
            else {
                v2.pb({v1[i][0],v1[i][1],v1[i][2],v1[i][3]});
            }
        }
        else {
            v2.pb({v1[i][0],v1[i][1],v1[i][2],v1[i][3]});
        }

    }

    int n2=SZ(v2);
    for(int i=0;i<n2;i+=2){
        cout<<v2[i][3]<<" "<<v2[i+1][3]<<endl;
    }
}

signed main() {
    //FIO;
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}