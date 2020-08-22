

int removeDuplicates(int *nums, int numsSize)
{

    if (numsSize <= 1)
        return numsSize;
    int i = 0, j = 0;
    while (++j < numsSize)
    {
        if (nums[i] != nums[j])
            nums[++i] = nums[j];
    }

    return i + 1;
}