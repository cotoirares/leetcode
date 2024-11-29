#include <iostream>
using namespace std;

// Arbore Binar cu Linked List

struct nod{
    int val;
    nod *fiu_st, *fiu_dr, *parinte;
};

void adaugare_in_ab(int val, nod *rad){
    if(val <= rad->val){
        if(rad->fiu_st != nullptr)
            adaugare_in_ab(val, rad->fiu_st);
        else{
            nod *nou = new nod;
            nou->val = val;
            nou->parinte = rad;
            rad->fiu_st = nou;
        }
    }
    else{
        if(rad->fiu_dr != nullptr)
            adaugare_in_ab(val, rad->fiu_dr);
        else{
            nod *nou = new nod;
            nou->val = val;
            nou->parinte = rad;
            rad->fiu_dr = nou;
        }
    }
}

void afisare_preordine(nod *rad){
    if(rad != nullptr){
        cout << rad->val << ' ';
        afisare_preordine(rad->fiu_st);
        afisare_preordine(rad->fiu_dr);
    }
}

int main(){

    nod *rad = new nod;

    int n, x;
    cin >> n >> x;
    rad->val = x;
    for(int i = 2; i <= n; ++i){
        cin >> x;
        adaugare_in_ab(x, rad);
    }

    afisare_preordine(rad);


    return 0;
}
