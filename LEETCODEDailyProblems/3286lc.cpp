class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // dist[i][j] = maximum health remaining when reaching (i,j)
        vector<vector<int>> dist(m, vector<int>(n, -1));

        priority_queue<vector<int>> pq;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        dist[0][0] = startHealth;
        pq.push({startHealth, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int h = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == m - 1 && c == n - 1)
                return true;

            if (h < dist[r][c])
                continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newHealth = h - grid[nr][nc];

                if (newHealth > 0 && newHealth > dist[nr][nc]) {
                    dist[nr][nc] = newHealth;
                    pq.push({newHealth, nr, nc});
                }
            }
        }

        return false;
    }
};