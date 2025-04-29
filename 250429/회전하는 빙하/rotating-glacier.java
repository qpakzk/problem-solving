import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Pair {
    int row, col;

    public Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

public class Main {
    public static final int DIR_NUM = 4;
    public static final int MAX_BOARD_SIZE = 64;
    
    public static int n, q;
    public static int boardSize;
    
    public static int[][] board = new int[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    public static int[][] nextBoard = new int[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    public static boolean[][] visited = new boolean[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    
    public static Queue<Pair> queue = new LinkedList<>();

    public static int[] drow = new int[]{0, 1, -1, 0};
    public static int[] dcol = new int[]{1, 0, 0, -1};
    
    public static void initNextBoard() {
    	for(int i = 0; i < boardSize; i++) {
            for(int j = 0; j < boardSize; j++) {
                nextBoard[i][j] = 0;
            }
    	}
    }
    
    public static void renewBoard() {
    	for(int i = 0; i < boardSize; i++) {
            for(int j = 0; j < boardSize; j++) {
                board[i][j] = nextBoard[i][j];
            }
    	}
    }
    
    public static boolean inRange(int row, int col) {
        return 0 <= row && row < boardSize && 0 <= col && col < boardSize;
    }
    
    public static boolean canGo(int row, int col) {
        return inRange(row, col) && !visited[row][col] && board[row][col] > 0;
    }
    
    // 얼음 군집 크기 측정
    public static int bfs() {
        int groupSize = 0;

        while(!queue.isEmpty()) {
            Pair cur = queue.poll();
            groupSize++;
    
            for(int i = 0; i < DIR_NUM; i++) {
                int nextRow = cur.row + drow[i];
                int newCol = cur.col + dcol[i];
    
                if(canGo(nextRow, newCol)) {
                    queue.add(new Pair(nextRow, newCol));
                    visited[nextRow][newCol] = true;
                }
            }
        }
        
        return groupSize;
    }
    
    public static int getTotalAmount() {
        int cnt = 0;
        for(int i = 0; i < boardSize; i++) {
            for(int j = 0; j < boardSize; j++) {
                cnt += board[i][j];
            }
        }
        
        return cnt;
    }
    
    public static int getMaxGroupSize() {
        int maxGroupSize = 0;
        for(int i = 0; i < boardSize; i++) 
            for(int j = 0; j < boardSize; j++)
                if(board[i][j] > 0 && !visited[i][j]) {
                    visited[i][j] = true;
                    queue.add(new Pair(i, j));
                    maxGroupSize = Math.max(maxGroupSize, bfs());
                }
        
        return maxGroupSize;
    }
    
    public static void move(int startRow, int startCol, int halfSize, int moveDir) {
        for(int row = startRow; row < startRow + halfSize; row++)
            for(int col = startCol; col < startCol + halfSize; col++) {
                int nextRow = row + drow[moveDir] * halfSize;
                int nextCol = col + dcol[moveDir] * halfSize;
                
                nextBoard[nextRow][nextCol] = board[row][col]; 
            }
    }
    
    public static void rotate(int level) {
    	// 레벨이 0이면 회전 안한다.
    	if (level == 0) {
    		return;
    	}
    	
    	initNextBoard();
        
        int boxSize = (int) Math.pow(2, level);
        int halfSize = (int) Math.pow(2, level - 1);
        
        // 회전을 진행한다.
        for(int i = 0; i < boardSize; i += boxSize) 
            for(int j = 0; j < boardSize; j += boxSize) {
                move(i, j, halfSize, 0);
                move(i, j + halfSize, halfSize, 1);
                move(i + halfSize, j, halfSize, 2);
                move(i + halfSize, j + halfSize, halfSize, 3);
            }

        renewBoard();
    }
    
    public static int getNeighborCount(int currX, int currY) {
        int cnt = 0;
        for(int i = 0; i < DIR_NUM; i++) {
            int newX = currX + drow[i];
            int newY = currY + dcol[i];
    
            if(inRange(newX, newY) && board[newX][newY] > 0)
                cnt++;
        }
        
        return cnt;
    }
    
    public static void melt() {
    	initNextBoard();
        
        for(int i = 0; i < boardSize; i++)
            for(int j = 0; j < boardSize; j++) {
                int cnt = getNeighborCount(i, j);
                if(board[i][j] > 0 && cnt < 3) {
                    nextBoard[i][j] = board[i][j] - 1;
                } else {
                    nextBoard[i][j] = board[i][j];
                }
            }
        
        renewBoard();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        q = sc.nextInt();
        boardSize = (int) Math.pow(2, n);
        
        for(int i = 0; i < boardSize; i++) {
            for(int j = 0; j < boardSize; j++) {
                board[i][j] = sc.nextInt();
            }
        }
        
        while(q-- > 0) {
            int level = sc.nextInt();
            // 레벨에 따라 회전한다.
            rotate(level);
            // 얼음을 녹인다.
            melt();
        }
        
        System.out.println(getTotalAmount());
        System.out.print(getMaxGroupSize());
        
        sc.close();
    }
}