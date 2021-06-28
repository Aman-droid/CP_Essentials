#include<bits/stdc++.h>
#define int long long
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
//-------------------soln-----------------------------//

vector <int> mir = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int chk(int x) {
    string s = to_string(x);
    if ((int)s.size() == 1) 
        s = "0" + s;
    string answ = "";

    for (int i = 1; i >= 0; i--) {
        if (mir[s[i] - '0'] == -1) 
            return INF;
        answ += char(mir[s[i] - '0'] + '0');
    }
    return stoi(answ);
}

string prnt(int x) {
    string ans = to_string(x);
    if (x < 10) {
        ans = "0" + ans;
    }
    return ans;
}

signed main() {
    FIO;
    int T;cin >> T;
    while (T--) {
        int h, m, H, M;cin >> h >> m;    
        string s;cin >> s;
        H = (s[0] - '0') * 10 + s[1] - '0';
        M = (s[3] - '0') * 10 + s[4] - '0';        
        while (1) {
            if (M == m) {
                H++;
                M = 0;
            }
            
            if (H == h) {
                H = 0;
            }

            if (chk(M) < h && chk(H) < m) {
                cout <<prnt(H) << ":" <<prnt(M) << '\n';
                break;
            }
            M++;
        }
    }
    return 0;
}
