class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        long long maxCost = 0;
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            maxCost = max(maxCost, (long long)e[2]);
        }

        // Topological Order
        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, c] : graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](long long x) {
            const long long INF = (1LL << 60);
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &[v, w] : graph[u]) {
                    if (w < x) continue;
                    if (v != n - 1 && !online[v]) continue;

                    dist[v] = min(dist[v], dist[u] + (long long)w);
                }
            }

            return dist[n - 1] <= k;
        };

        long long lo = 0, hi = maxCost;
        int ans = -1;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = (int)mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
