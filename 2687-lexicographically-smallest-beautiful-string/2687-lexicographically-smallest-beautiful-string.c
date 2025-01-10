char * smallestBeautifulString(char * s, int k) {
    int n = strlen(s);
    char *ans = malloc((n + 1) * sizeof(char));
    strcpy(ans, s);
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = ans[i] - 'a' + 1; j < k; j++) {
            char c = 'a' + j;
            if ((i < 1 || c != ans[i - 1]) && (i < 2 || c != ans[i - 2])) {
                ans[i] = c;
                for (int l = i + 1; l < n; l++) {
                    for (int m = 0; m < k; m++) {
                        c = 'a' + m;
                        if ((l < 1 || c != ans[l - 1]) && (l < 2 || c != ans[l - 2])) {
                            ans[l] = c;
                            break;
                        }
                    }
                }
                return ans;
            }
        }
    }
    
    return "";
}