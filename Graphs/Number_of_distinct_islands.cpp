/*
Performing dfs on every connected componenets os 1 considering each as a island and storing its shape in a vector of pairs.
Then storing all the islands in a set of vectors of pairs to remove duplicates shapes.

Shape is stored as taking one point as base and finding difference of all other points with that base point. It will be same for same shapes.
*/

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int base_i, int base_j, vector<pair<int, int>> &island)
    {
        if (i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        island.push_back({i - base_i, j - base_j});
        dfs(grid, i + 1, j, base_i, base_j, island);
        dfs(grid, i - 1, j, base_i, base_j, island);
        dfs(grid, i, j + 1, base_i, base_j, island);
        dfs(grid, i, j - 1, base_i, base_j, island);
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        set<vector<pair<int, int>>> islands;
        vector<pair<int, int>> island;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, i, j, island);
                    islands.insert(island);
                    island.clear();
                }
            }
        }
        return islands.size();
    }
};
