#include <bits/stdc++.h>
using namespace std;
struct Topic{
    string name;
    vector<string> text;
};
char get_reverse(char a){
    if (a <= 'Z') return a - 'A' + 'a';
    return (a - 'a') + 'A';
}

bool is_letter(char a){
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}
int main() {
    freopen("wiki.in", "r", stdin);
    freopen("wiki.out", "w", stdout);
    int n;
    cin >> n;
    vector<Topic> topics(n);
    unordered_map<string, pair<int, int>> links; // name, short/long, index
    for (int i = 0; i < n; i++){
        cin >> topics[i].name;
        links[topics[i].name] = {0, i};
        topics[i].name[0] = get_reverse(topics[i].name[0]);
        links[topics[i].name] = {0, i};
        topics[i].name[0] = get_reverse(topics[i].name[0]);
        int sim;
        cin >> sim;
        for (int j = 0; j < sim; j++){
            string tmp;
            cin >> tmp;
            links[tmp] = {1, i};
            tmp[0] = get_reverse(tmp[0]);
            links[tmp] = {1, i};
        }
        int line_cnt = 0;
        string tmp;
        cin >> line_cnt;
        topics[i].text.resize(line_cnt);
        getline(cin, tmp);
        for(int j = 0; j < line_cnt; j++){
            getline(cin, tmp);
            topics[i].text[j] = tmp + '\n';
//            cout << topics[i].text[j] << "!!!\n";
        }
    }
    for (int i = 0; i < n; i++){
        cout << topics[i].name << '\n';
        for (const auto& str : topics[i].text){
            string word_now;
            for (char c: str){
                if (!is_letter(c)){
                    if (!links.count(word_now) || links[word_now].second == i){
                        cout << word_now;
                    }
                    else{
                        if (links[word_now].first){
                            cout << "[[" << topics[links[word_now].second].name << '|' << word_now << "]]";
                        }
                        else cout << "[[" << word_now << "]]";
                    }
                    cout << c;
                    word_now.clear();
                }
                else word_now += c;
            }
        }
    }
    return 0;
}