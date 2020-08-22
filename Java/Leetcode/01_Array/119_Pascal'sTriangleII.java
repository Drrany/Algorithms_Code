package Leetcode;

import java.util.ArrayList;
import java.util.List;

class PascalTriTwo {

    public List<Integer> getRow(int rowIndex) {

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i <= rowIndex; i++) {

            List<Integer> pre = new ArrayList<>(ans);
            ans.clear();

            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i)
                    ans.add(1);
                else {
                    int sum = pre.get(j - 1) + pre.get(j);
                    ans.add(sum);
                }
            }

        }

        return ans;
    }

}
