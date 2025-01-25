int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize) {
    int **dp = (int **)malloc((multipliersSize + 1) * sizeof(int *));
    for (int i = 0; i <= multipliersSize; ++i) {
        dp[i] = (int *)calloc((multipliersSize + 1), sizeof(int));
    }

    for (int m = multipliersSize - 1; m >= 0; --m) {
        for (int left = m; left >= 0; --left) {
            int right = numsSize - 1 - (m - left);
            int chooseLeft = nums[left] * multipliers[m] + dp[m + 1][left + 1];
            int chooseRight = nums[right] * multipliers[m] + dp[m + 1][left];
            dp[m][left] = chooseLeft > chooseRight ? chooseLeft : chooseRight;
        }
    }

    int result = dp[0][0];
    for (int i = 0; i <= multipliersSize; ++i) {
        free(dp[i]);
    }
    free(dp);
    return result;
}
