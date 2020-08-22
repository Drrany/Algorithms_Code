package Leetcode;

class SearchWord {

    public static void main(String[] args) {
        text t = new text();
        //char[][] board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
        char[][] board = { { 'A' } };
        String word = "A";
        boolean a = t.exist(board, word);
        System.out.println(a);
    }

    boolean[][] flag;//记录走过的路
    int m;//数组行数
    int n;//数组列数
    char[][] board;
    String word;
    int[][] dire = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

    public boolean exist(char[][] board, String word) {

        if (board == null || board[0].length < 1)
            return false;

        m = board.length;
        n = board[0].length;

        this.board = board;
        this.word = word;

        flag = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(i, j, 0))
                    return true;

            }
        }

        return false;

    }

    public boolean dfs(int i, int j, int k) {

        if (k == word.length() - 1)
            return board[i][j] == word.charAt(k);
        if (board[i][j] == word.charAt(k)) {

            flag[i][j] = true;
            for (int l = 0; l < 4; l++) {

                int newi = i + dire[l][0];
                int newj = j + dire[l][1];
                if (isInArea(newi, newj) && !flag[newi][newj]) {
                    if(dfs(newi, newj, k + 1))
                        return true;
                }

            }
            flag[i][j] = false;

        }
        return false;
    }

    public boolean isInArea(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

}
