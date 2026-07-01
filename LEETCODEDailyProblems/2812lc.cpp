class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Step 1: multi-source BFS to get safeness factor of each cell
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Step 2: Dijkstra-like, maximize min safeness along path
        vector<vector<int>> best(n, vector<int>(n, -1));
        priority_queue<tuple<int,int,int>> pq; // max-heap on safeness
        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [s, x, y] = pq.top(); pq.pop();
            if (s < best[x][y]) continue; // stale entry
            if (x == n - 1 && y == n - 1) return s;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int ns = min(s, dist[nx][ny]);
                    if (ns > best[nx][ny]) {
                        best[nx][ny] = ns;
                        pq.push({ns, nx, ny});
                    }
                }
            }
        }
        return best[n-1][n-1];
    }
};