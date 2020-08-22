

class SortArray {

    // 排序算法复习 912

    // 1. 交换排序
    // 1.1 冒泡排序
    public int[] bubbleSort(int[] nums) {

        for (int i = nums.length - 1; i >= 0; i--) {
            boolean flag = false;
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    flag = true;
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
            if (!flag)
                break;
        }

        return nums;

    }

    // 1.2 快速排序
    public int[] quickSort(int[] nums) {
        reCur(nums, 0, nums.length - 1);
        return nums;
    }

    public static void reCur(int[] nums, int left, int right) {

        if (left < right) {
            int mid = sort(nums, left, right);
            reCur(nums, left, mid - 1);
            reCur(nums, mid + 1, right);
        }
        return;

    }

    public static int sort(int[] nums, int left, int right) {

        int tmp = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= tmp)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= tmp)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = tmp;
        return left;

    }

    // 2.插入排序
    // 2.1 简单插入排序
    public int[] insertSort(int[] nums) {

        int len = nums.length;
        for (int i = 1; i < len; i++) {

            int tmp = nums[i];
            int j = i;

            while (j >= 1 && tmp < nums[j - 1]) {
                nums[j] = nums[--j];
            }
            nums[j] = tmp;
        }

        return nums;

    }

    // 2.2 希尔排序
    public int[] shellSort(int[] nums) {
        for (int i = nums.length / 2; i > 0; i /= 2) {
            kSort(nums, i);
        }
        return nums;
    }

    public static void kSort(int[] nums, int k) {

        for (int i = k; i < nums.length; i += k) {

            int tmp = nums[i];
            int j = i;

            while (j >= k && tmp < nums[j - k]) {
                nums[j] = nums[j - k];
                j -= k;
            }
            nums[j] = tmp;
        }

    }

    // 3. 选择排序
    // 3.1 简单选择排序
    public int[] selectSort(int[] nums) {

        int len = nums.length;
        for (int i = 0; i < len; i++) {

            int min = nums[i];
            int index = i;
            for (int j = i + 1; j < len; j++) {

                if (nums[j] < min) {
                    min = nums[j];
                    index = j;
                }

            }
            if (index != i) {
                nums[index] = nums[i];
                nums[i] = min;
            }
        }

        return nums;

    }

    // 3.2 堆排序
    public static int[] heapSort(int[] nums) {

        int len = nums.length;
        for (int i = len / 2 - 1; i >= 0; i--) {// 从最下层的非叶子结点开始调整成堆
            heapAdjust(nums, i, len);
        }

        for (int i = len - 1; i >= 0; i--) {
            int tmp = nums[i];// 将堆顶（即最大值）移到数组最后
            nums[i] = nums[0];
            nums[0] = tmp;
            heapAdjust(nums, 0, i);
        }

        return nums;
    }

    public static void heapAdjust(int[] nums, int root, int len) {// 将以a[root]为根结点的子树构成堆，堆中每个根结点的值都比其孩子结点的值大

        for (int i = 2 * root + 1; i < len; i = 2 * i + 1) {

            if (i + 1 < len)
                i = nums[i] > nums[i + 1] ? i : i + 1;
            if (nums[i] < nums[root])
                break;

            int tmp = nums[root];
            nums[root] = nums[i];
            nums[i] = tmp;

            root = i;
        }

    }

    // 4. 归并排序
    // 4.1 2-路归并
    public static int[] mergeSort(int[] nums) {
        int[] sample = new int[nums.length];
        merge(nums, sample, 0, nums.length);
        return nums;
    }

    public static void merge(int[] nums, int[] sample, int left, int right) {
        if (left >= right - 1)
            return;
        else {
            int mid = (left + right) / 2;
            merge(nums, sample, left, mid);
            merge(nums, sample, mid, right);
            mSort(nums, sample, left, mid, right);
        }
        return;
    }

    public static void mSort(int[] nums, int[] sample, int left, int mid, int right) {

        System.arraycopy(nums, left, sample, left, right - left);
        int i = left, j = mid, k = left;
        for (; i < mid && j < right;)
            nums[k++] = sample[i] > sample[j] ? sample[j++] : sample[i++];

        while (i < mid)
            nums[k++] = sample[i++];

        while (j < right)
            nums[k++] = sample[j++];
        return;
    }


}