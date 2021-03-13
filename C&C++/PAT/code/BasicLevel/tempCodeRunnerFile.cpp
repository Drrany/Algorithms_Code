#include <cstdio>
#include <cstring>
int main()
{
    int memNum;
    scanf("%d", &memNum);
    int score[memNum];
    memset(score, 0, sizeof(score));

    int num, s;
    int maxnum, max = 0;
    while (memNum-- > 0)
    {
        scanf("%d %d", &num, &s);
        score[num - 1] += s;

        if (score[num - 1] > max)
        {
            maxnum = num;
            max = score[num - 1];
        }
    }
    printf("%d %d", maxnum, max);
    return 0;
}