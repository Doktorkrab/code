#include <iostream>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

#define int int64_t
const int MAXN = 1e5;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

struct Segment{
    int l, r, x, ind;
};
Segment q[MAXN];
int arr[MAXN];

int32_t main(){

}
