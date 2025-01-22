#include <string.h>

int memo[30][30][31];

bool isScrambleHelper(char *s1, char *s2, int i1, int i2, int len) {
    if (len == 1) return s1[i1] == s2[i2];
    if (memo[i1][i2][len] != -1) return memo[i1][i2][len];
    int freq[26] = {0};
    for (int i = 0; i < len; i++) {
        freq[s1[i1 + i] - 'a']++;
        freq[s2[i2 + i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) return memo[i1][i2][len] = 0;
    }
    for (int i = 1; i < len; i++) {
        if ((isScrambleHelper(s1, s2, i1, i2, i) && isScrambleHelper(s1, s2, i1 + i, i2 + i, len - i)) ||
            (isScrambleHelper(s1, s2, i1, i2 + len - i, i) && isScrambleHelper(s1, s2, i1 + i, i2, len - i))) {
            return memo[i1][i2][len] = 1;
        }
    }
    return memo[i1][i2][len] = 0;
}

bool isScramble(char *s1, char *s2) {
    int len = strlen(s1);
    if (len != strlen(s2)) return false;
    memset(memo, -1, sizeof(memo));
    return isScrambleHelper(s1, s2, 0, 0, len);
}
