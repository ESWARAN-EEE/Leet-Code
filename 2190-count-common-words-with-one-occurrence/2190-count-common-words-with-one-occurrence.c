typedef struct {
    char word[101];
    int count1;
    int count2;
} WordEntry;
int countWords(char **words1, int words1Size, char **words2, int words2Size) {
    WordEntry map[2000] = {0};
    int mapSize = 0, result = 0;
    void updateCount(char *word, int isWords1) {
        for (int i = 0; i < mapSize; i++) {
            if (strcmp(map[i].word, word) == 0) {
                if (isWords1) map[i].count1++;
                else map[i].count2++;
                return;
            }
        }
        strcpy(map[mapSize].word, word);
        if (isWords1) map[mapSize].count1 = 1;
        else map[mapSize].count2 = 1;
        mapSize++;
    }
    for (int i = 0; i < words1Size; i++) updateCount(words1[i], 1);
    for (int i = 0; i < words2Size; i++) updateCount(words2[i], 0);
    for (int i = 0; i < mapSize; i++) {
        if (map[i].count1 == 1 && map[i].count2 == 1) result++;
    }
    return result;
}
