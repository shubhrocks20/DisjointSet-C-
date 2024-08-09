#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultimateParentU = findUltimateParent(u);
        int ultimateParentV = findUltimateParent(v);
        if(ultimateParentU == ultimateParentV) return;

        if(rank[ultimateParentU] > rank[ultimateParentV]){
            // Lesser rank get attached to bigger rank so rank doesnot get affected
            parent[ultimateParentV] = ultimateParentU;
        }
        else if(rank[ultimateParentU] < rank[ultimateParentV]){
            // Lesser rank get attached to bigger rank so rank doesnot get affected
            parent[ultimateParentU] = ultimateParentV;
        }
        else{
            parent[ultimateParentU] = ultimateParentV;
            rank[ultimateParentV]++;
        }
    }
    void unionBySize(int u, int v){
        int upu = findUltimateParent(u);
        int upv = findUltimateParent(v);
        if(upu == upv) return;

        if(size[upu] > size[upv]){
            parent[upv] = upu;
            size[upu] += size[upv];
        }
        else{
            parent[upu] = upv;
            size[upv] += size[upu];
        }
    }
};
int main()
{
    DisjointSet d1(7);
    d1.unionBySize(1,2);
    d1.unionBySize(2,3);
    d1.unionBySize(4,5);
    d1.unionBySize(6,7);
    d1.unionBySize(5,6);

    if(d1.findUltimateParent(3) == d1.findUltimateParent(7)){
        cout<<"Same Component"<<endl;
    }
    else{
        cout<<"Not same component"<<endl;
    }

    d1.unionBySize(3,7);
    if(d1.findUltimateParent(3) == d1.findUltimateParent(7)){
        cout<<"Same Component"<<endl;
    }
    else{
        cout<<"Not same component"<<endl;
    }


    return 0;
}