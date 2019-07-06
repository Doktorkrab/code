#include <bits/stdc++.h>

using namespace std;


int main(){
	string s;
	cin >> s;
	for (int l = s.size(); l >= 1; l--){
		for (int i = 0; i + l <= s.size(); i++){
			for (int j = i + 1; j + l <= s.size(); j++){
				if (i == j)
					continue;
				int a = 0;
				for (int k = i; k < i + l; k++){
					a += s[k] - '0'; 
				}
				int b = 0;
				for (int k = j; k < j + l; k++)
					b += s[k] - '0';
				if (a == b){
					cout << i + 1 << ' ' << i + l << ' ' << j + 1 << ' ' << j + l << '\n';
					return 0;
				}
			}
		}
	}
	cout << "-1\n";
}