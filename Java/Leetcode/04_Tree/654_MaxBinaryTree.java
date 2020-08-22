
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class MaxBinaryTree {

    public static TreeNode constructMaximumBinaryTree(int[] nums) {

        return reCur(nums, 0, nums.length - 1);

    }

    public static TreeNode reCur(int[] nums, int left, int right) {

        if (left < 0 || right >= nums.length || left > right)
            return null;

        int max = nums[left];
        int index = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        TreeNode p = new TreeNode(max);
        p.left = reCur(nums, left, index - 1);
        p.right = reCur(nums, index + 1, right);

        return p;
    }

}