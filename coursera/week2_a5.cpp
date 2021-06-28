#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll period(ll m) {
    ll a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) 
            return i + 1;
    }
    return 0;
}

ll solve(ll n, ll m) {
    ll rem = n % period(m);
    ll a = 0;
    ll b = 1;

    ll res = rem;

    for (int i = 1; i < rem; i++) {
        res = (a + b) % m;
        a = b;
        b = res;
    }
    return res % m;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) <<endl;
}