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
int main()
{
    int T;cin>>T;
    while(T--)
    {
        ll n;cin>>n;
        ll a[2*n];
        unordered_map<ll,ll>cnt,tmp;
        ll N=2*n;
        rep(i,0,N-1){
            cin>>a[i];
            tmp[a[i]]++;
        }
        sort(a,a+N,greater<ll>());
        vpll ans;
        int fl=0,cur;
        ll x,k;
        for(ll i=1;i<N;i++){
            cur =a[0]+a[i]; 
            fl=0; 
            ll op=0,j=0;
            x=cur;
            cnt=tmp;
            ans.clear();
            while(op<n)
            {
                if(cnt[a[j]]>0 && cnt[cur-a[j]]>0){
                    op++; 
                    ans.pb({a[j],cur-a[j]});
                    cnt[a[j]]--;
                    if(cnt[cur-a[j]]) 
                        cnt[cur-a[j]]--;
                    else {
                        fl=1;
                        break;
                    }
                    cur=a[j];
                    while(j<2*n&& cnt[a[j]]==0) j++;
                }
                else {
                    fl=1;
                    break;
                }
            }
            if(fl==0) break;
        }
        if(fl==0){
            cout<<"YES"<<endl;
            cout<<x<<endl;
            for(auto it:ans) 
                cout<<it.ff<<" "<<it.ss<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}