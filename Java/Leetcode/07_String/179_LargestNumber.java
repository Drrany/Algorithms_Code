
import java.util.Arrays;
import java.util.Comparator;

class LargestNumber {

    public static String largestNumber(int[] nums) {

        StringBuilder res = new StringBuilder();

        int len = nums.length;
        String[] copynums = new String[len];
        for (int i = 0; i < len; i++)
            copynums[i] = String.valueOf(nums[i]);

        Arrays.sort(copynums, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return -(o1 + o2).compareTo(o2 + o1);
            }
        });

        if (copynums[0].charAt(0) == '0')
            return "0";

        for (String s : copynums) {
            res.append(s);
        }

        return res.toString();

    }

}