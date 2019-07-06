#include <cstdio>
#include <algorithm> 
#include <iostream> 
using namespace std; 
const int MAXC = 1001000; 
int miny[MAXC]; 
int maxy[MAXC]; 
int sum[MAXC + 1]; 
void edge(int x1, int x2, int y2) 
{ 
    for (int j = min(x1,x2); j < max(x1,x2); j++){
        miny[j] = min(miny[j], y2);
        maxy[j] = max(maxy[j], y2); 
    } 
} 
int main() 
{ 
    int n, k; 
    scanf("%d%d", &n, &k); 
    int x1, y1; 
    int x0, y0; 
    scanf("%d%d", &y1, &x1); 
    x0 = x1, y0 = y1; 
    for (int i = 0; i < MAXC; i++) 
        maxy[i] = -1, miny[i] = MAXC; 
    for (int i = 1; i < n; i++) { 
        int x2, y2; 
        scanf("%d%d", &y2, &x2); 
        edge(x1, x2, y2); 
        x1 = x2, y1 = y2; 
    } 
    edge(x1, x0, y0); 
    long long cur = 0; 
    for (int j = 0; j < MAXC; j++) { 
        if (miny[j] > maxy[j]) 
            continue;
        cerr << miny[j] << ' ' << maxy[j] << '\n';
        int lpos = miny[j] + k - j % k; 
        int rpos = maxy[j] + k - j % k; 
        sum[k - lpos % k]--; 
        sum[k - (rpos + k - 1) % k]++; 
        lpos = (lpos / k); rpos = (rpos + k - 1) / k; 
        cur += max(0, rpos - lpos);
    }
    for (int i = 0; i < MAXC; i++){
     sum[i+1] += sum[i];
    }
    cerr << cur << '\n'; 
    cout << cur + *min_element(sum, sum + MAXC) << endl;
    return 0; 
}
