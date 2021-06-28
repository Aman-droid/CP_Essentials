// Function to print the divisors.O(sqrt(n))
vll Divisors(ll n )
{
    vll res;
    for(ll i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
                res.pb(i);
            else
            {
                res.pb(i);
                res.pb(n/i);
            }
        }
    }
    return res;
}
