char* intToRoman(int num) {
    const char *sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static char roman[20];
    roman[0] = '\0';
    for (int i = 0; i < 13; i++) {
        while (num >= val[i]) {
            strcat(roman, sym[i]);
            num -= val[i];
        }
    }
    return roman;
}
