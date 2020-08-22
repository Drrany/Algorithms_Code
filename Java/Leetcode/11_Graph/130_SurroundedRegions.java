


class SurroundedRegions {
    public void solve(char[][] board) {

        if (board == null || board.length < 1)
            return;

        int rows = board.length;
        int columns = board[0].length;

        for (int i = 0; i < rows; i++) {
            reCur(board, i, 0, rows, columns);
            reCur(board, i, columns - 1, rows, columns);
        }

        for (int i = 1; i < columns - 1; i++) {
            reCur(board, 0, i, rows, columns);
            reCur(board, rows - 1, i, rows, columns);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }

    }

    public static void reCur(char[][] board, int i, int j, int rows, int columns) {

        if (i < 0 || j < 0 || i >= rows || j >= columns || board[i][j] == 'X' || board[i][j] == '#')
            return;

        board[i][j] = '#';
        reCur(board, i + 1, j, rows, columns);
        reCur(board, i - 1, j, rows, columns);
        reCur(board, i, j + 1, rows, columns);
        reCur(board, i, j - 1, rows, columns);
    }
}
