#include<bits/stdc++.h>


using namespace std;

struct Segment{
    int x1, y1, x2, y2;
};
bool is_on_segment(const Segment& seg, int x, int y){
    if (seg.x1 == seg.x2){
        return seg.x1 == x && seg.y1 <= y && seg.y2 >= y;
    }
    else
        return seg.y1 == y && seg.x1 <= x && x <= seg.x2;
}
int main(){
    freopen("flashmob.in", "r", stdin);
    freopen("flashmob.out", "w", stdout);
    int n;
    cin >> n;
    if (n > 500){
        cout << "0\n";
        return 0;
    }
    vector<Segment> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
        if (arr[i].x1 > arr[i].x2)
            swap(arr[i].x1, arr[i].x2);
        if (arr[i].y1 > arr[i].y2)
            swap(arr[i].y1, arr[i].y2);
    }
    vector<int> is_feed(n);
    vector<pair<int, int>> ans;
    int cnt = 0;
    for (int i = 1; i <= 500; i++){
        for (int j = 1; j <= 500; j++){
            int ind = -1;
            for (int k = 0; k < n; k++){
                if (!is_on_segment(arr[k], i, j))
                    continue;
                if (ind == -1)
                    ind = k;
            }
            // cerr << i << ' ' << j << ' ' << ind + 1 << '\n';
            if (ind == -1 || is_feed[ind])
                continue;
            is_feed[ind] = 1;
            // cerr << ind + 1 << '\n';
            cnt++;
            ans.push_back({i, j});
        }
    }
    if (cnt != n){
        cout << "0\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
}