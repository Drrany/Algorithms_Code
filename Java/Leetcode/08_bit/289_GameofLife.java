
class GameofLife {

    public static void gameOfLife(int[][] board) {

        int rows = board.length;
        int columns = board[0].length;

        int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int livecount = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && y >= 0 && x < rows && y < columns)
                        livecount += board[x][y] & 1;
                }
                if (board[i][j] == 1) {
                    if (livecount == 2 || livecount == 3)
                        board[i][j] |= 2;
                } else {
                    if (livecount == 3)
                        board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                board[i][j] >>= 1;
            }
        }

    }

}