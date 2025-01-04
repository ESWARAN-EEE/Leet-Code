char* convertToBase7(int num) {
    char *res = malloc(32 * sizeof(char));
    int index = 0, isNegative = (num < 0);
    if (!res) return NULL;
    if (num == 0) {
        res[index++] = '0';
        res[index] = '\0';
        return res;
    }
    if (isNegative) num = -num;
    while (num > 0) {
        res[index++] = (num % 7) + '0';
        num /= 7;
    }
    if (isNegative) res[index++] = '-';
    res[index] = '\0';
    for (int l = 0, r = index - 1; l < r; l++, r--) {
        char temp = res[l];
        res[l] = res[r];
        res[r] = temp;
    }
    return res;
}
