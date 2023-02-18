#include <stdio.h>

int main(void)
{
    char magazine[] = {'a', 'a', 'b'};
    char ransomNote[] = {'a', 'a'};

    int letters[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++)
    {
        letters[magazine[i] - 'a']++;
        printf("%d\n", i);
        printf("letters[ %d ]\n", magazine[i] - 'a');
    }
    printf("----------\n");
    for (int i = 0; ransomNote[i] != '\0'; i++)
    {
        if (letters[ransomNote[i] - 'a'] > 0)
        {
            letters[ransomNote[i] - 'a']--;
            printf("%d\n", i);
            printf("letters[ %d ]\n", ransomNote[i] - 'a');
            printf("letters[ransomNote[i] - 'a']-- = [ %d ]\n", letters[ransomNote[i] - 'a']--);
        }
        else
            return 0;
    }

    return 1;
}