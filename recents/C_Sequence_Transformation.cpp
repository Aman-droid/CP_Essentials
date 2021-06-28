#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;

void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<"1"<<endl;
    }
    else if(n==2){
        cout<<"1 2"<<endl;
    }
    else if(n==3){
        cout<<"1 1 3"<<endl;
    }
    else{

        int a[n+10]={0};

        map<int,int>mp;
        vector<int>res;
        
        int x=1;
        while(x<=n){
            x=x*2;
        }
        
        while(x>=2){
            for(int i=x;i<=n;i=i+x){
                if(a[i]==0){
                    mp[x]++;
                    a[i]=x;
                }
            }
            x=x/2;
        }
        
        if(n%2==0){
            rep(i,1,n/2){
                res.push_back(1);
            }
            x=2;
            while(x<n){
                int tmp= mp[x];
                while(tmp--){
                    res.push_back(x);
                }
                x=x*2;
            }
        }
        else{
            rep(i,1,n/2 + 1){
                res.push_back(1);
            }
            x=2;
            while(x<=n){
                int tmp= mp[x];
                while(tmp--){
                    res.push_back(x);
                }
                x=x*2;
            }
        }
        // cout<<SZ(res)<<endl;
        for(auto it: res){
            cout<<it<<" ";
        }
        cout<<endl;
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