class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& e : invocations) adj[e[0]].push_back(e[1]);

        vector<bool> susp(n, false);
        queue<int> q; q.push(k); susp[k] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) if (!susp[v]) { susp[v] = true; q.push(v); }
        }

        for (auto& e : invocations)
            if (!susp[e[0]] && susp[e[1]]) {
                vector<int> all;
                for (int i = 0; i < n; i++) all.push_back(i);
                return all;
            }

        vector<int> res;
        for (int i = 0; i < n; i++) if (!susp[i]) res.push_back(i);
        return res;
    }
};
