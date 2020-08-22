package Leetcode;

class RemoveElement {

    public int removeElement(int[] nums, int val) {

        int slow = 0, fast = 0;
        int len = nums.length;

        while (fast < len) {

            if (nums[fast] == val)
                fast++;
            else
                nums[slow++] = nums[fast++];

        }
        
        return slow;

    }

}
