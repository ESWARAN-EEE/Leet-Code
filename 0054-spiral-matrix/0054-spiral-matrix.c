int* spiralOrder(int** matrix, int ms, int* mcs, int* rs) {
    int top = 0, bottom = ms - 1;
    int left = 0, right = *mcs - 1;
    int* result = (int*)malloc(ms * (*mcs) * sizeof(int));
    *rs = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) result[(*rs)++] = matrix[top][i];
        top++;
        for (int i = top; i <= bottom; i++) result[(*rs)++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) result[(*rs)++] = matrix[bottom][i];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) result[(*rs)++] = matrix[i][left];
            left++;
        }
    }

    return result;
}
