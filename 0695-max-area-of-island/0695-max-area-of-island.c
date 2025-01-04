int dfs(int** grid, int gridSize, int gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    int area = 1;
    area += dfs(grid, gridSize, gridColSize, i - 1, j);
    area += dfs(grid, gridSize, gridColSize, i + 1, j);
    area += dfs(grid, gridSize, gridColSize, i, j - 1);
    area += dfs(grid, gridSize, gridColSize, i, j + 1);
    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int maxarea = 0, gridColSizeValue = *gridColSize;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSizeValue; j++) {
            if (grid[i][j] == 1) {
                int area = dfs(grid, gridSize, gridColSizeValue, i, j);
                if (area > maxarea) maxarea = area;
            }
        }
    }
    return maxarea;
}