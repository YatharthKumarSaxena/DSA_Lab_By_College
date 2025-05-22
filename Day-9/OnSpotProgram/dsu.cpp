#include <iostream>
using namespace std;

class DSU{
    int* par;
    int* rank;
public:
    DSU(int capacity){
        par = new int[capacity];
        rank = new int[capacity];
        for(int i=0;i<capacity;i++){
            rank[i] = 1;
            par[i] = i;
        }
    }
    void unionGroup(int eleA,int eleB);
    int findParent(int ele);
};

void DSU::unionGroup(int eleA,int eleB){
    int parA = findParent(eleA);
    int parB = findParent(eleB);
    if (parA == parB) return;
    if(rank[parA] >= rank[parB]) {
        par[parB] = parA;
        rank[parA]++;
    } else {
        par[parA] = parB;
        rank[parB]++;
    }
}

int DSU::findParent(int ele){
    return par[ele] = ((par[ele]==ele)? ele:findParent(par[ele]));
}