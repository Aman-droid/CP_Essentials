ll power(ll a, ll b)
{      //a^b
       ll res=1;
       a=a%MOD;
       while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
       }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}//modulo inverse

