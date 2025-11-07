class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1},{-1,0}};
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) q.emplace(i,j);
                else mat[i][j] = -1;
            }
        }

        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            for (auto d : dir) {
                int nr = r + d[0] , nc = c + d[1];
                if (nr < 0 || nr >= m || nc < 0 ||
                    nc >= n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr,nc);
            }
        }
        return mat;
    }
};
