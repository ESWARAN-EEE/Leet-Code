char* reverseParentheses(char* s) {
    int len = strlen(s), stack[2000], top = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == ')') {
            int start = stack[top--];
            for (int left = start + 1, right = i - 1; left < right; left++, right--) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
            }
        } else if (s[i] == '(') stack[++top] = i;
    }
    char* result = (char*)malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) if (s[i] != '(' && s[i] != ')') result[j++] = s[i];
    result[j] = '\0';
    return result;
}
