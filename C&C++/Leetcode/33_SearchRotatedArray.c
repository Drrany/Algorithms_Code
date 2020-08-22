

int search(int *nums, int numsSize, int target)
{

    int i = 0, j = numsSize - 1;
    int index = -1;
    while (i <= j)
    {

        int mid = (i + j) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[0] <= nums[mid] && target >= nums[0] && target < nums[mid]) //如果0~mid间无旋转且target值位于nums[0]和nums[mid]之间，j减小
            j = mid - 1;

        else if (nums[0] > nums[mid] && target < nums[mid]) //如果0~mid间有旋转且target值小于nums[mid]，表示target位于旋转点~mid之间，j减小
            j = mid - 1;

        else if (nums[0] > nums[mid] && target >= nums[0]) //如果0~mid间有旋转且target值>=nums[0]，表示target位于0~旋转点之间，j减小
            j = mid - 1;

        else
            i = mid + 1;

    }

    return index;
}