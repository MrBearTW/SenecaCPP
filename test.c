int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *res = malloc(sizeof(int) * 100);
    int cf = 1;
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] + cf > 9) {
            digits[i] = (digits[i] + cf) % 10;
        } else {
            digits[i] = digits[i] + cf;
            cf = 0;
            break;
        }
    }
    
    if (cf)
        res[0] = 1;
    
    for (int i = cf, j = 0; j < digitsSize; i++, j++)
        res[i] = digits[j];
    
    *returnSize = digitsSize + cf;
    return res;
}