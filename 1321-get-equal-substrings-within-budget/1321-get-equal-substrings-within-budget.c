int equalSubstring(char* s, char* t, int maxCost) {
    int start = 0, end = 0, currentCost = 0, maxLength = 0;

    while (t[end] != '\0') {
        currentCost += abs(s[end] - t[end]);
        while (currentCost > maxCost) {
            currentCost -= abs(s[start] - t[start]);
            start++;
        }
        maxLength = (end - start + 1 > maxLength) ? end - start + 1 : maxLength;
        end++;
    }

    return maxLength;
}
