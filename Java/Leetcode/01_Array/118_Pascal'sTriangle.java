package Leetcode;

import java.util.ArrayList;
import java.util.List;

class PascalTri {


    public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> ans = new ArrayList<>();
        if (numRows < 1)
            return ans;
        List<Integer> one = new ArrayList<>();
        one.add(1);
        ans.add(one);

        for (int i = 1; i < numRows; i++) {
            List<Integer> tmp = new ArrayList<>();
            tmp.add(1);
            for (int j = 1; j < i; j++) {
                int sum = ans.get(i - 1).get(j - 1) + ans.get(i - 1).get(j);
                tmp.add(sum);
            }
            tmp.add(1);
            ans.add(tmp);
        }

        return ans;

    }

}
