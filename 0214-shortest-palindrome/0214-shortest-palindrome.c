char* shortestPalindrome(char *s) {
    int len = strlen(s), end = len - 1;
    while (end >= 0) {
        int i = 0, j = end;
        while (i < j && s[i] == s[j]) i++, j--;
        if (i >= j) break;
        end--;
    }
    int add = len - end - 1;
    char *result = (char*)malloc(len + add + 1);
    for (int i = 0; i < add; i++) result[i] = s[len - i - 1];
    strcpy(result + add, s);
    return result;
}
