#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
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
/*int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll m,s;cin>>m>>s;
        if(s==0 || m*9<s){
            cout<<"-1"<<" "<<"-1"<<endl;
            continue;
        }
        ll s1=s,s2=s;
        ll x;
        string a1,a2;
        rep(i,0,m-1){
            x =min(s2,9LL);
            a2+=to_string(x); 
            s2-=x;
        }
        rep(i,0,m-1){
            ll x=0LL+9LL*(m-i-1);
            ll y=1LL+9LL*(m-i-1);
            if(x>=s1 && i!=0 ){
                ll tmp=min(0LL,s1);
                a1+=to_string(tmp);
                s1-=tmp;
            }
            else if(y>=s1 && i==0 ){
                ll tmp=min(1LL,s1);
                a1+=to_string(tmp);
                s1-=tmp;
            }
            else{
                x =s1-(9*(m-1-i));
                //watch(x);
                a1+=to_string(x);
                s1-=x;
            }
        }
        cout<<a1<<" "<<a2<<endl;


    }
    return 0;   
}*/
int main (){
	ll m,s;cin>>m>>s;
    ll s1=s,s2=s;
	if(s<1&&m>1||s>m*9)
	    cout<<-1<<" "<<-1<<endl;
	else {
	    for(ll i=m-1;i>=0;i--){
	        int j=max(0LL,s1-(9LL*i));
	        if(j==0 && i==m-1 && s1>0) j=1;
	        cout<<j;
	        s1-=j;
        }
	    cout<<" ";
	    for(int i=m-1;i>=0;i--){
	        ll j=min(9LL,s2);
	        cout<<j;
	        s2-=j;
        }
	}
	return 0;
}