

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class SortArrayToBST {


    public static TreeNode sortedArrayToBST(int[] nums) {
        return reCur(nums, 0, nums.length - 1);
    }

    public static TreeNode reCur(int[] nums, int i, int j) {

        if (i > j)
            return null;
        int mid = (i + j + 1) / 2;
        TreeNode p = new TreeNode(nums[mid]);
        p.left = reCur(nums, i, mid - 1);
        p.right = reCur(nums, mid + 1, j);
        return p;
    }

}
