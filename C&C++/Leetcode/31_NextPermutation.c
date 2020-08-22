#include <stdio.h>

void nextPermutation(int *nums, int numsSize)
{
    for (int i = numsSize - 1; i > 0; i--)//从后向前遍历数组
    {
        if (nums[i - 1] < nums[i])//表示存在大于的排列
        {
            int min = nums[i];
            int index = i;
            for (int j = numsSize - 1; j > i; j--)//找到大于且最接近nums[i-1]的值
            {
                if (nums[j] < min && nums[j] > nums[i - 1])
                {
                    min = nums[j];
                    index = j;
                }
            }
            nums[index] = nums[i - 1];//交换这两个值
            nums[i - 1] = min;


            for (int j = numsSize - 1; j > i; j--)//将i-1右边升序排列
            {
                int flag = 0;
                for (int k = i; k < j; k++)
                {
                    if (nums[k] > nums[k + 1])
                    {
                        int tmp = nums[k];
                        nums[k] = nums[k + 1];
                        nums[k + 1] = tmp;
                        flag = 1;
                    }
                }
                if (!flag)
                    break;
            }
            return;
        }
    }

    for (int i = 0; i < numsSize / 2; i++)//如果不存在，交换前后即得到升序排列
    {
        int tmp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }
    return;
}

int main()
{

    int nums[] = {1, 3, 2};
    int numsSize = 3;
    nextPermutation(nums, numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d", nums[i]);
    }
}