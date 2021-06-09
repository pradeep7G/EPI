#include<bits/stdc++.h>
using namespace std;

/*
    *
    * 
*/

vector<int> generatePrimes(int n)
{
    vector<int> primes;

    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;
    for(int p=2;p<n;p++)
    {
        if(is_prime[p])
        {
            primes.emplace_back(p);
            for(int j=p;j<=n;j+=p)
            {
                is_prime[j]=false;
            }
        }
    }
    return primes;
}
int main()
{
    auto primes=generatePrimes(10);
    for(auto x:primes)cout<<x<<" ";cout<<"\n";
}