class Solution {
public:
    vector<int> parent, rankArr;
    vector<int> vertexCount, edgeCount;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rankArr[rx] < rankArr[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rankArr[rx] == rankArr[ry]) rankArr[rx]++;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rankArr.assign(n, 0);
        vertexCount.assign(n, 1);
        edgeCount.assign(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& e : edges) {
            unite(e[0], e[1]);
        }

        // Count vertices and edges per component root
        vector<int> vCount(n, 0), eCount(n, 0);
        for (int i = 0; i < n; i++) {
            vCount[find(i)]++;
        }
        for (auto& e : edges) {
            eCount[find(e[0])]++;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                int v = vCount[i];
                int e = eCount[i];
                // complete graph has v*(v-1)/2 edges
                if (e == v * (v - 1) / 2) result++;
            }
        }
        return result;
    }
};