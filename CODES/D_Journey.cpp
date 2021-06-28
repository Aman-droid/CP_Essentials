#include<bits/stdc++.h>
#define ll long long 
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

const int mxn=8e5;
const int k=4e5;
int par[mxn];
int R[mxn]; // Rank no of node connected to current par..
int find(int v)  
{
	if(par[v]==v)
		return v;
	else{
		int x=find(par[v]);
		par[v]=x;
		return x;
	}
}

void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)return;
	if(R[a]>R[b]){	//a will be parent 
		par[b]=a;
        cout<<a<<"-->"<<b<<endl;
		R[a]+=R[b];
	}
	else {	  // b will be parent 
		par[a]=b;
        cout<<b<<"-->"<<a<<endl;
		R[b]+=R[a];
	}
} 

int main(){
    FIO;
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        string s;cin>>s;
        rep(i,0,n){
            par[i]=i;
            par[i+k]=i+k;
            R[i+k]=1;
            R[i]=1;
        }
        rep(i,0,n-1){
            if(s[i]=='L'){
                merge(i+1,i+k);
            }
            else{
                merge(i,i+1+k);
            }
        }
        rep(i,0,n){
            ll pr=find(i);
            cout<<pr<<endl;
            cout<<R[pr]<<" ";
        }
        cout<<endl;       
    }
}