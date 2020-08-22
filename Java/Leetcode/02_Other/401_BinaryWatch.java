import java.util.ArrayList;
import java.util.List;

class BinaryWatch {

    public List<String> readBinaryWatch(int num) {

        List<String> ans = new ArrayList<>();

        for (int i = 0; i < 12; i++) {
            int ib = 0;
            for (int j = 0; j < 4; j++) {
                if (((i >> j) & 1) == 1)
                    ib++;
            }
            for (int j = 0; j < 60; j++) {
                int jb = 0;
                for (int k = 0; k < 6; k++) {
                    if (((j >> k) & 1) == 1)
                        jb++;
                }

                if (ib + jb == num) {
                    if (j < 10)
                        ans.add(new String(i + ":0" + j));
                    else ans.add(new String(i + ":" + j));
                }

            }
        }

        return ans;

    }

}