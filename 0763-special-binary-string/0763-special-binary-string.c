int cmp(const void *a, const void *b) {
    return strcmp(*(char **)b, *(char **)a);
}

char *makeLargestSpecial(char *s) {
    int count = 0, start = 0, len = strlen(s);
    char **substrings = (char **)malloc(len * sizeof(char *));
    int subCount = 0;
    for (int i = 0; i < len; i++) {
        count += (s[i] == '1') ? 1 : -1;
        if (count == 0) {
            char *sub = (char *)malloc(i - start + 2);
            strncpy(sub, s + start + 1, i - start - 1);
            sub[i - start - 1] = '\0';
            sub = makeLargestSpecial(sub);
            substrings[subCount++] = sub;
            start = i + 1;
        }
    }
    qsort(substrings, subCount, sizeof(char *), cmp);
    char *result = (char *)malloc(len + 1);
    result[0] = '\0';
    for (int i = 0; i < subCount; i++) {
        strcat(result, "1");
        strcat(result, substrings[i]);
        strcat(result, "0");
        free(substrings[i]);
    }
    free(substrings);
    return result;
}
