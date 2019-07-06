#include <iostream>

#define ll long long

using namespace std;

int main() {
    ll hv, dv, tv, hb, db, tb, hp, tp;
    cin>>hv>>dv>>tv>>hb>>db>>tb>>hp>>tp;
    for (int i = 0; i < 1e8; ++i) {
        if(i%tv==0){
            hb-=dv;
        }
        if(hb<=0){
            cout<<"WIN";
            return 0;
        }
        if(i%tb==0){
            hv-=db;
        }
        if(hv<=0){
            cout<<"FAIL";
            return 0;
        }
        if(i%tp==0){
            hv+=hp;
        }
    }
    return 1;
}