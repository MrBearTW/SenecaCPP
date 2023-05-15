#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/**
 * Determine if the string s starts with the string prefix.
 * * @param s - the string to see if it starts with prefix
 * @param prefix - the prefix to test
 * @returns true if the strings
 */

int startsWith(const char s[], const char prefix[])
{
    char buf[20];
    int i;
    int sz = strlen(prefix);
    for (i = 0; i < sz; i++)
    {
        buf[i] = s[i];
    }
    buf[sz] = '\0';
    return 0 == strcmp(buf, prefix);
}

/**
 * Determine if the string s ends with the string suffix.
 * * @param s - the string to see if it ends with suffix
 * @param suffix - the suffix to test
 * @returns true if the strings ends with the suffix.
 */

int endsWith(const char s[], const char suffix[])
{
    int sz = strlen(s);
    int slen = strlen(suffix);

    return 0 == strcmp(s + slen - sz, suffix);
}

int main(void)
{
    char s1[] = {"upended"};
    char prefix[] = {"up"};
    char suffix[] = {"ed"};
    printf("%s does %s start with %s\n", s1, startsWith(s1, prefix) ? "" : " not", prefix);
    printf("%s does %s end with %s\n", s1, endsWith(s1, suffix) ? "" : " not", suffix);
    return 0;
}
