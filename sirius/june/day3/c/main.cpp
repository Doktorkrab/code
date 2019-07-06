#include <bits/stdc++.h>

using namespace std;

struct Student{
    int cls;
    char word;
    string surname;
    string name;
    int y, m, d;
    bool operator< (const Student& oth) const {
        return tie(cls, word, surname, name, y, m, d) < tie(oth.cls, oth.word, oth.surname, oth.name, oth.y, oth.m, oth.d);
    }
    Student () {}
};

int main(){
    int n;
    cin >> n;
    vector<Student> students(n);
    for (auto& st : students){
        cin >> st.surname >> st.name;
        string tmp;
        cin >> tmp;
        if (tmp.size() == 2){
            st.cls = tmp[0] - '0';
            st.word = tmp[1];
        }
        else{
            st.cls = 10 + (tmp[1] - '0');
            st.word = tmp[2];
        }
        scanf("%d.%d.%d", &st.d, &st.m, &st.y);
    }
    sort(students.begin(), students.end());
    for (auto& st : students){
        cout << st.cls << st.word << ' ' << st.surname << ' ' << st.name << ' ';
        printf("%02d.%02d.%02d\n", st.d, st.m, st.y);
    }
}
