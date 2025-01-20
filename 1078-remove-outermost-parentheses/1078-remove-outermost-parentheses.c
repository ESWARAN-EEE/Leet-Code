char * removeOuterParentheses(char * s) {
    char *result = malloc(strlen(s) + 1);
    int count = 0, index = 0;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            if (count > 0) result[index++] = '(';
            count++;
        } else {
            count--;
            if (count > 0) result[index++] = ')';
        }
    }

    result[index] = '\0';
    return result;
}
