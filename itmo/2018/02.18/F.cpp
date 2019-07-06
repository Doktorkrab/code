#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

int n;
int groupToInt(char c){
	string s = "0hdsc";
	for (int i = 0; i < 5; i++)
		if (s[i] == c)
			return i;
	// cerr << c << '\n';
	assert(0); 
}
int getNumber(string s){
	if (s[0] == 'J')
		return 11;
	if (s[0] == 'Q')
		return 12;
	if (s[0] == 'K')
		return 13;
	if (s[0] == 'A')
		return 1;
	return stoi(s);
}
char getGroup(int c){
	string s = "0hdsc";
	return s[c];
}
string getsNumber(int s){
	if (s == 11)
		return "J";
	if (s == 12)
		return "Q";
	if (s == 13)
		return "K";
	if (s == 1)
		return "A";
	return to_string(s);
}
struct Card{
	int price;
	int group;
	friend istream& operator>>(istream& is, Card& c){
		string s;
		is >> s;
		c.group = groupToInt(s.back());
		s.pop_back();
		c.price = getNumber(s);
		return is;
	}
	friend ostream& operator<< (ostream& os, const Card& c){
		os << getsNumber(c.price) << getGroup(c.group);
		return os;
	}
};

Card decks[4];
Card rows[7][13];
int deck_min[5];
int sz[7];
inline void init(){
	memset(sz, 0, sizeof(int) * 7);
	for (int i = 0; i < 5; i++)
		deck_min[i] = 20000;
}

inline void solve(){
	init();
	int cnt = 0;
	for (int i = 0; i < 4; i++){
		cin >> decks[i];
		// cerr << decks[i] << '\n';
		// cerr << decks[i].group << '\n';
		deck_min[decks[i].group] = decks[i].price;
	}
	// cerr << "here\n";
	for (int i = 0; i < 7; i++){
		cin >> sz[i];
		if (sz[i] > 0)
			cnt++;
		for (int j = 0; j < sz[i]; j++){
			cin >> rows[i][j];
			deck_min[rows[i][j].group] = min(deck_min[rows[i][j].group], rows[i][j].price);
		}
	}
	while (1){
		int cnt = 0;
		for (int i = 0; i < 7; i++){
			if (sz[i] != 0)
				cnt++;
		}
		if (cnt == 0)
			break;

		for (int i = 0; i < 7; i++){
			int now = sz[i] - 1;
			if (now < 0)
				continue;
			int found = 0;
			// cerr << rows[i][now] << ' ' << deck_min[rows[i][now].group] << '\n';
			if (deck_min[rows[i][now].group] == rows[i][now].price){
				for (int j = 0; j < 4; j++){
					if (decks[j].group == 0){
						cout << rows[i][now] << ' ';
						decks[j] = rows[i][now];
						sz[i]--;
						found = 1;
						break;
					}
				}
				if (found)
					break;
				assert(0);
			}
			for (int j = 0; j < 4; j++){
				if (decks[j].price + 1 == rows[i][now].price && decks[j].group == rows[i][now].group){
					cout << rows[i][now] << ' ';
					decks[j] = rows[i][now];
					sz[i]--;
					found = 1;
					break;
				}
			}
			if (found)
				break;
		}
	}
	cout << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("F.in", "r", stdin);
		freopen("F.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();

}