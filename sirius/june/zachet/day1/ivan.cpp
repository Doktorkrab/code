#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
#define int ull
int x;
int b, m;
unsigned long long mm;
vector<int> power;
vector<int> prefix;
vector<int> prefix2;

int hash1(int i, int j)
{
    return (unsigned long long)(prefix[j] - 1LL * prefix[i] * power[j - i]+ mm) % m;
}

int hash2(int i, int j)
{
    return (unsigned long long)(prefix2[j] - 1LL * prefix2[i] * power[j - i] + mm) % m;
}

bool pal(int i, int j)
{
    if (hash1(i, j) == hash2(x - j + 1, x - i + 1))
        return true;
    return false;
}

signed main()
{
    b = 29;
    m = 150000001;
    mm = m * m;
    string s;
    cin >> s;
    x = s.size();
    prefix.resize(x + 1, 0);
    prefix2.resize(x + 1, 0);
    power.resize(x + 1, 1);
    for (int i = 0; i < x; ++i)
        power[i + 1] = power[i] * b % m;
    for (int i = 0; i < x; ++i)
        prefix[i + 1] = (prefix[i] * b + s[i] - 'a' + 1 + mm) % m;
    for (int i = 0; i < x; ++i)

        prefix2[i + 1] = (prefix2[i] * b + s[x - i - 1] - 'a' + 1 + mm) % m;
    vector<int> odd(x);
    for (int i = 1; i < x + 1; ++i)
    {
        int l = 0;
        int r = min(i, x - i + 1);
        int mid;
        while (l + 1 < r)
        {
            mid = (l + r) / 2;
            if (pal(i - mid, i + mid))
                l = mid;
            else
                r = mid;
        }
        odd[i - 1] = (l * 2) + 1;
    }
    for (int i = 0; i < odd.size(); ++i)
        cout << odd[i] << " ";
    return 0;
}
