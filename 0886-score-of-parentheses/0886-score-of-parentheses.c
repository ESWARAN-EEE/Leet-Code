int scoreOfParentheses(char *s) {
    int stack[50], top = -1, score = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            stack[++top] = score;
            score = 0;
        } else {
            score = stack[top--] + (score > 0 ? 2 * score : 1);
        }
    }
    return score;
}
