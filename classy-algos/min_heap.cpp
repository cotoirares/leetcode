#include <iostream>
using namespace std;

// Min Heap

/*
 *
 */

int heap[100001], heapSize, a[100001], n;

void push_up(int nod){
    if(nod == 1)
        return ;
    int tata = nod / 2;
    if(heap[tata] > heap[nod]){
        swap(heap[tata], heap[nod]);
        push_up(tata);
    }
}

void push_down(int nod){
    int fiu1 = 2 * nod;
    int fiu2 = 2 * nod + 1;
    if(fiu1 <= heapSize && fiu2 > heapSize){
        if(heap[fiu1] < heap[nod]){
            swap(heap[fiu1], heap[nod]);
            push_down(fiu1);
        }
    }
    else if(fiu1 <= heapSize && fiu2 <= heapSize){
        if(heap[fiu1] < heap[fiu2] && heap[fiu1] < heap[nod]){
            swap(heap[nod], heap[fiu1]);
            push_down(fiu1);
        }
        else if(heap[fiu2] <= heap[fiu1] && heap[fiu2] < heap[nod]){
            swap(heap[nod], heap[fiu2]);
            push_down(fiu2);
        }
    }
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i){
        heap[++heapSize] = a[i];
        push_up(heapSize);
    }

    for(int i = 1; i <= n; ++i){
        cout << heap[1] << ' ';
        swap(heap[1], heap[heapSize]);
        heapSize--;
        push_down(1);
    }


    return 0;
}
