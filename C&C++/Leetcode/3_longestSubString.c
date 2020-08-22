#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{

    int start = 0, end = 0, max = 0;

    int map[128] = {0};
    map[s[0]] = 1;

    while (s[end] != 0)
    {
        end++;
        max = (end - start) > max ? (end - start) : max;
        while(map[s[end]]){
            map[s[start]] = 0;
            start++;
        }
        map[s[end]] = 1;
    }

    return max;
}

int main()
{
    char c[] = "abcdefgh";
    int b = lengthOfLongestSubstring(c);
    printf("%d", b);
    return 0;
}