class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int freshFruits = 0;
        queue<pair<int, int>> rottenFruits;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1)
                    freshFruits += 1;
                if(grid[r][c] == 2)
                    rottenFruits.push({r, c});
            }
        }

        int minutes = 0;
        vector<pair<int, int>> directions = { {-1,0},{1,0},{0,-1},{0,1} };
        while(freshFruits > 0 && !rottenFruits.empty()){
           int levelSize = rottenFruits.size();
           for(int i = 0; i < levelSize; i++){
            pair<int, int> coord = rottenFruits.front(); rottenFruits.pop();
            int cr = coord.first, cc = coord.second;
            for(const auto& dir : directions){
                int nr = cr + dir.first, nc = cc + dir.second;
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                    freshFruits -= 1;
                    grid[nr][nc] = 2;
                    rottenFruits.push({nr, nc});
                }
            }
           }
           minutes += 1;
        }

        return (freshFruits == 0) ? minutes : -1;
    }
};