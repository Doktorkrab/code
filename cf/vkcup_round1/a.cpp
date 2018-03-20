#include <bits/stdc++.h>
#define ld long double
#define pb push_back
//#define f first
//#define s second
#define mk make_pair


using namespace std;

bool cmp(int a, int b)
{
    return a % b == 0;
}

int main()
{

    clock_t gg = clock();
    int a;
    cin >> a;

    int n = 1000000;
    vector<char> prime (n+1, true);
    prime[0] = prime[1] = false;
    for (int i=2; i<=n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
    vector<int> p;
    for(int i = 0; i <= n; i++)
        if(prime[i])
            p.pb(i);
    int maxp;
    int a1 = a;
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a1%i == 0) {
            maxp =i;
            while(a1%i == 0)
                a1/=i;
        }
    }

    if (a1 > 1) maxp = max(a1, maxp);
    int lower = a - maxp + 1;
    int upper = a;
    int ans = a;
    cout << lower << ' ' << upper << '\n';
    for(int i = lower; i<= upper; i++)
    {
        // cout << i << '\n';
        // if (fabs(clock() - gg) / CLOCKS_PER_SEC >= 1) break;
        int maxi = lower_bound(p.begin(), p.end(), i) - p.begin() - 1;
        for(int it = maxi; it >= 0; it--)
        {
            if(i % p[it] == 0)
                ans = min(ans, i - p[it] + 1);
        }
    }
    cout << ans << '\n';
    cout << fabs(gg - clock()) / CLOCKS_PER_SEC << '\n';
    return 0;
}