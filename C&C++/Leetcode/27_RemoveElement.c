int removeElement(int *nums, int numsSize, int val)
{

    int i = -1, j = -1;
    while (++j < numsSize)
    {
        if (nums[j] != val)
            nums[++i] = nums[j];
    }

    return i + 1;
}