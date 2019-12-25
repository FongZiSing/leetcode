// 使用并查集
class Solution {
#define Set vector<int>
public:
    int find(Set &s, int x) {
        while(x!=s[x]) x=s[x];
        return x;
    }
    
    bool unite(Set &s, int p, int q) {
        p=find(s, p);
        q=find(s, q);
        if(p!=q) {
            s[p] = q;
            return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Set s(edges.size()+1);
        for(int i=0; i<edges.size(); ++i) s[i] = i;
        for(auto &a : edges) {
            if(!unite(s, a[0], a[1]))
                return a;
        }
        return vector<int>();
    }
};