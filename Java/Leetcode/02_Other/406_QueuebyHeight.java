
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class QueuebyHeight {

    
    public int[][] reconstructQueue(int[][] people) {

        int nums = people.length;
        List<int[]> ans = new ArrayList<>();

        Arrays.sort(people, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0]);

        for (int[] is : people) {
            ans.add(is[1], is);
        }

        return ans.toArray(new int[nums][2]);

    }

}