bool dfs(char **board, int n, int *bcs, int r, int c, char *word, int idx) {
    if (idx == strlen(word)) return true;
    if (r < 0 || r >= n || c < 0 || c >= bcs[0] || board[r][c] != word[idx]) return false;
    char temp = board[r][c];
    board[r][c] = '#';
    bool found = dfs(board, n, bcs, r + 1, c, word, idx + 1) ||
                 dfs(board, n, bcs, r - 1, c, word, idx + 1) ||
                 dfs(board, n, bcs, r, c + 1, word, idx + 1) ||
                 dfs(board, n, bcs, r, c - 1, word, idx + 1);
    board[r][c] = temp;
    return found;
}

bool exist(char **board, int n, int *bcs, char *word) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < bcs[0]; c++) {
            if (dfs(board, n, bcs, r, c, word, 0)) return true;
        }
    }
    return false;
}
