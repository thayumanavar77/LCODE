class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> fg(n);
        vector<vector<int>> rg(n);

        for (auto u : connections) {
            fg[u[0]].push_back(u[1]);
            rg[u[1]].push_back(u[0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        int res = 0;

        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            visited[v] = true;

            for (int u : fg[v]) {
                if (!visited[u]) {
                    res++;
                    q.push(u);
                }
            }
            for (int u : rg[v]) {
                if (!visited[u]) q.push(u);
            }
        }
        return res;
    }
};
