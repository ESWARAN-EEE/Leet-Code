int wiggleMaxLength(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;
    int up = 1, down = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }
    
    return numsSize == 1 ? 1 : (up > down ? up : down);
}
