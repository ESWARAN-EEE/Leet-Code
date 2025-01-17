void gen(char *cur, int len, int o, int c, int max, char **res, int *size) {
    if (len == 2 * max) {
        cur[len] = '\0';
        res[(*size)++] = strdup(cur);
        return;
    }
    if (o < max) {
        cur[len] = '(';
        gen(cur, len + 1, o + 1, c, max, res, size);
    }
    if (c < o) {
        cur[len] = ')';
        gen(cur, len + 1, o, c + 1, max, res, size);
    }
}

char **generateParenthesis(int n, int *returnSize) {
    char **res = malloc(10000 * sizeof(char *));
    char *cur = malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;
    gen(cur, 0, 0, 0, n, res, returnSize);
    free(cur);
    return res;
}
