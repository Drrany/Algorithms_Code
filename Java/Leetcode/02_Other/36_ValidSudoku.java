import java.util.HashSet;
import java.util.Set;

class VaildSudoku {
    public boolean isValidSudoku(char[][] board) {

        Set<Integer>[] rows = new HashSet[9];
        Set<Integer>[] columns = new HashSet[9];
        Set<Integer>[] boxes = new HashSet[9];

        for (int i = 0; i < 9; i++) {
            rows[i] = new HashSet<Integer>();
            columns[i] = new HashSet<Integer>();
            boxes[i] = new HashSet<Integer>();
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int n = (int) board[i][j];
                    int boxindex = (i / 3) * 3 + j / 3;
                    if (rows[i].contains(n)|| columns[j].contains(n) || boxes[boxindex].contains(n))
                        return false;
                    rows[i].add(n);
                    columns[j].add(n);
                    boxes[boxindex].add(n);
                }
            }
        }

        return true;

    }
}
