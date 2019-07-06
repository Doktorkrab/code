#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <random>
#define int long long

using namespace std;

mt19937 rnd(228228 + 179);

struct go
{
	int l, r;
};

struct sob
{
	int x, y;
};

struct gg
{
	int on, th;
};

bool cmp(const sob& a, const sob& b)
{
	if (a.x < b.x) return true;
	if (a.x > b.x) return false;
	return a.y < b.y;
}

signed main()
{
	int n, q;
	cin >> n >> q;
	vector<go> a(q);
	for (go& i : a)
		cin >> i.l >> i.r;
	vector<sob> s;
	for (go i : a)
	{
		s.push_back({ i.l, 0 });
		s.push_back({ i.r, 1 });
	}
	sort(s.begin(), s.end(), cmp);
	int cnt = 0;
	vector<int> num(n + 1, 0);
	int j = 0;
	for (int i = 0; i <= n; i++)
	{
		while (j < s.size() && s[j].x == i && s[j].y == 0)
		{
			cnt++;
			j++;
		}
		num[i] = cnt;
		while (j < s.size() && s[j].x == i && s[j].y == 1)
		{
			cnt--;
			j++;
		}
	}
	vector<gg> arr(n + 1, { 0, 0 });
	for (int i = 1; i <= n; i++)
	{
		arr[i].on += arr[i - 1].on;
		arr[i].th += arr[i - 1].th;
		if (num[i] == 1)
			arr[i].on++;
		else if (num[i] == 2)
			arr[i].th++;
	}
	int gt = 0;
	for (int i = 0; i <= n; i++)
		if (num[i])
			gt++;
	int ans = 0;
	for (int i = 0; i < q; i++)
	{
		for (int j = i + 1; j < q; j++)
		{
			int nw = arr[a[i].r].on - arr[a[i].l - 1].on + arr[a[j].r].on - arr[a[j].l - 1].on;
			int l = max(a[i].l, a[j].l), r = min(a[i].r, a[j].r);
			if (l <= r)
			{
				nw += arr[r].th - arr[l - 1].th;
			}
			ans = max(ans, gt - nw);
		}
	}
	cout << ans << '\n';
}