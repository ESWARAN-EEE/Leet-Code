int numberOfArrays(char *s, int k) {
    int n = strlen(s);
    int MOD = 1000000007;
    int dp[n + 1];
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 0;
        if (s[i] == '0') continue;
        long num = 0;
        for (int j = i; j < n; j++) {
            num = num * 10 + (s[j] - '0');
            if (num > k) break;
            dp[i] = (dp[i] + dp[j + 1]) % MOD;
        }
    }

    return dp[0];
}
