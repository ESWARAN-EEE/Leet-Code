int myAtoi(char *s) {
    int i = 0, sign = 1, result = 0;
    while (s[i] == ' ') i++;
    if (s[i] == '+' || s[i] == '-') sign = (s[i++] == '-') ? -1 : 1;
    while (s[i] >= '0' && s[i] <= '9') {
        if (result > (2147483647 - (s[i] - '0')) / 10) 
            return sign == 1 ? 2147483647 : -2147483648;
        result = result * 10 + (s[i++] - '0');
    }
    return result * sign;
}
