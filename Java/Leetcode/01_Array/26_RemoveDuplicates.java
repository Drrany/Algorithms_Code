package Leetcode;


class RemoveDupicates {

    public int removeDuplicates(int[] nums) {

        int slow = 0, fast = 1;
        int len = nums.length;
   
        while (fast < len) {
            if (nums[slow] != nums[fast])
                nums[++slow] = nums[fast++];
            else
                fast++;
        }
        
        return slow+1;

    }

}
