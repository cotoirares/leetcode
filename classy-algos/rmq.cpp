#include <iostream>
using namespace std;

// RMQ

/*
 *
 */

#define inf 1000000000

int rmq[100001], a[100001], n;

void ConstructieRMQ(int nod, int st, int dr){
    if(st == dr){
        rmq[nod] = a[st];
        return ;
    }
    int mij = (st + dr) / 2;
    ConstructieRMQ(2 * nod, st, mij);
    ConstructieRMQ(2 * nod + 1, mij + 1, dr);
    rmq[nod] = min(rmq[2 * nod], rmq[2 * nod + 1]);
}

int Query(int nod, int st, int dr, int stt, int drt){
    if(st >= stt && dr <= drt)
        return rmq[nod];
    if(stt > dr || drt < st)
        return inf;
    int mij = (st + dr) / 2;
    int min1 = Query(2 * nod, st, mij, stt, drt);
    int min2 = Query(2 * nod + 1, mij + 1, dr, stt, drt);
    return min(min1, min2);
}

int main(){

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    ConstructieRMQ(1, 1, n);
    cout << Query(1, 1, n, 3, 5);
    return 0;
}
