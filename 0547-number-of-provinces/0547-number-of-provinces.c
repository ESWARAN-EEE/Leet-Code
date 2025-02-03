void dfs(int** isConnected, int isConnectedSize, int* visited, int node) {
    visited[node] = 1;
    for (int i = 0; i < isConnectedSize; i++) {
        if (isConnected[node][i] && !visited[i]) {
            dfs(isConnected, isConnectedSize, visited, i);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int* visited = (int*)calloc(isConnectedSize, sizeof(int));
    int provinces = 0;

    for (int i = 0; i < isConnectedSize; i++) {
        if (!visited[i]) {
            dfs(isConnected, isConnectedSize, visited, i);
            provinces++;
        }
    }

    free(visited);
    return provinces;
}
