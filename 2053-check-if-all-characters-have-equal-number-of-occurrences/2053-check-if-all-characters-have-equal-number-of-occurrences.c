bool areOccurrencesEqual(char *s) {
    int freq[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    int targetFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            targetFreq = freq[i];
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0 && freq[i] != targetFreq) {
            return false;
        }
    }
    return true;
}
