import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {
	public static int n, m, t; // 6, 7
	public static int[][] board;
	public static List<Integer> machine = new ArrayList<>();
	public static final int MACHINE = -1;
	public static final int DIR = 4;
	
	public static final int[] dx = {1, 0, -1, 0};
	public static final int[] dy = {0, -1, 0, 1};
	
	public static boolean inRange(int x, int y) {
		return x >= 0 && x < m && y >= 0 && y < n && board[y][x] != MACHINE;
	}
	
	public static void spreadDust(int [][] newBoard) {
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) {
        		if (board[i][j] != MACHINE) {
        			int cur = board[i][j];
	        		
	        		int cnt = 0;
	        		for (int d = 0; d < DIR; d++) {
	        			int nx = j + dx[d], ny = i + dy[d];
	        			if (inRange(nx, ny)) {
	        				cur += board[ny][nx] / 5;
	        				cnt++;
	        			}
	        		}
	        		
	        		cur -= (board[i][j] / 5) * cnt;
	        		newBoard[i][j] = cur;
        		} else {
        			newBoard[i][j] = board[i][j];
        		}
        	}
        }
	}
	
	public static void cleanUp(int [][] newBoard) {
		int x = 0;
		int y = machine.get(0);
		int priv = newBoard[y][x];
		for (int i = 0; i < DIR; i++) {
			while (true) {
				int nx = x + dx[i], ny = y + dy[i];
				if (inRange(nx, ny)) {
					int cur = newBoard[ny][nx];
					if (priv == MACHINE) {
						newBoard[ny][nx] = 0;
					} else {
						
						newBoard[ny][nx] = priv;
					}
					
					x = nx;
					y = ny;
					priv = cur;
				} else {
					break;
				}
			}
		}
		
		x = 0;
		y = machine.get(1);
		priv = newBoard[y][x];
		for (int i = 0; i < DIR; i++) {
			int d = Math.abs(i - DIR) % DIR;
			while (true) {
				int nx = x + dx[d], ny = y + dy[d];
				if (inRange(nx, ny)) {
					int cur = newBoard[ny][nx];
					if (priv == MACHINE) {
						newBoard[ny][nx] = 0;
					} else {
						newBoard[ny][nx] = priv;
					}
					
					x = nx;
					y = ny;
					priv = cur;
				} else {
					break;
				}
			}
		}
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        m = sc.nextInt();
        t = sc.nextInt();
        
        board = new int[n][m];
        
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < m; j++) { 		
        		board[i][j] = sc.nextInt();
        		
        		if (board[i][j] == MACHINE) {
        			machine.add(i);
        		}
        	}
        }
        
        while(t-- > 0) {
    		int[][] newBoard = new int[n][m];
    		spreadDust(newBoard);
    		cleanUp(newBoard);
    		
    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < m; j++) {
    				board[i][j] = newBoard[i][j];
    			}
    		}
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == MACHINE) continue;
				sum += board[i][j];
			}
		}
        System.out.println(sum);
        sc.close();
    }
}