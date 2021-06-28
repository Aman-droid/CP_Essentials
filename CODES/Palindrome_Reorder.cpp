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

const int mxn=2e5;
deque<char>q;
int cnt[26];

void solve(){
    int n,fl=0,tmp=0,pos;
    string s;cin>>s;
    n=s.length();
    rep(i,0,n-1){
        cnt[s[i]-'A']++;
    }

    //watch(n);
    if(n%2==1){
        tmp=0;
        rep(i,0,25){
            if(cnt[i]%2==1){
                tmp++;
                pos=i;
            }
        }
        if(tmp>1){
            cout<<"NO SOLUTION"<<endl;
        }
        else{
            tmp=cnt[pos];
            while(tmp--){
                (tmp%2==1)?q.pb(char('A'+pos)):q.pf(char('A'+pos));
            }
            rep(i,0,25){
                if(i!=pos){
                    tmp=cnt[i];
                    while(tmp--){
                        (tmp%2==1)?q.pb(char('A'+i)):q.pf(char('A'+i));
                    }       
                }
            }
            for(auto it:q){
                cout<<it;
            }
            cout<<endl;
        }
    }
    else{
        tmp=0;
        rep(i,0,25){
            if(cnt[i]%2==1){
                tmp++;
                pos=i;
            }
        }
        if(tmp>0){
            cout<<"NO SOLUTION"<<endl;
        }
        else{
            rep(i,0,25){
                tmp=cnt[i];
                while(tmp--){
                    (tmp%2==1)?q.pb(char('A'+i)):q.pf(char('A'+i));
                }       
            }
            for(auto it:q){
                cout<<it;
            }
            cout<<endl;
        }
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