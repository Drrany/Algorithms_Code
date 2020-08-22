import java.util.ArrayList;
import java.util.List;

class GrayCode {

    public List<Integer> grayCode(int n) {

        List<Integer> ans = new ArrayList<>();
        ans.add(0);
        if (n < 1)
            return ans;

        for (int i = 1; i <= n; i++) {

            int len = ans.size();
            for (int j = len - 1; j >= 0; j--) {
                int m = ans.get(j);
                if (i == 1)
                    m++;
                else
                    m += 2 << (i - 1);
                ans.add(m);
            }
        }
        return ans;
    }

}