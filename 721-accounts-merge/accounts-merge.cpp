
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string,int> emailToAcc;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAcc.find(email) == emailToAcc.end()) {
                    emailToAcc[email] = i;
                } else {
                    ds.unionBySize(i, emailToAcc[email]);
                }
            }
        }

        unordered_map<int, set<string>> merged;
        for (auto &p : emailToAcc) {
            string email = p.first;
            int accIndex = ds.findUPar(p.second);
            merged[accIndex].insert(email);
        }

        vector<vector<string>> result;
        for (auto &p : merged) {
            int idx = p.first;
            vector<string> temp;
            temp.push_back(accounts[idx][0]); 
            temp.insert(temp.end(), p.second.begin(), p.second.end());
            result.push_back(temp);
        }

        return result;
    }
};
