import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {
	public static final int MAX_N = 8, MAX_M = 8;
	
	public static int n, m;
	public static int[][] board = new int[MAX_N][MAX_M];
	public static boolean[][] visited = new boolean[MAX_N][MAX_M];
	public static int[][] horseDir = new int[MAX_N][MAX_M];
	public static List<Pair> horses = new ArrayList<>();
	
	public static int minEmptyGrid = Integer.MAX_VALUE;
	
	public static final int[][] canMove = new int[][] {
		{},
		{1, 0, 0, 0},
		{0, 1, 0, 1},
		{1, 1, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 1, 1}
	};
	
	public static void fill(int curX, int curY) {		
		int horseNum = board[curX][curY];
		int curDir = horseDir[curX][curY];
		
		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};
		
		for (int i = 0; i < 4; i++) {
			if (canMove[horseNum][i] == 0) {
				continue;
			}
			
			int x = curX, y = curY;
			int moveDir = (i + curDir) % 4;
			
			while (true) {
				visited[x][y] = true;
				int nx = x + dx[moveDir];
				int ny = y + dy[moveDir];
				
				if (0 > nx || nx > n || 0 > ny || ny > m 
						|| board[nx][ny] == 6) {
					break;
				}
				
				x = nx;
				y = ny;
			}
		}
	}
	
	public static int getEmptyGrid() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
		
		for (Pair horse : horses) {
			fill(horse.x, horse.y);
		}
		
		int emptyGrid = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && board[i][j] != 6) {
					emptyGrid += 1;
				}
			}
		}
		
		return emptyGrid;
	}
	
	public static void searchMinEmptyGrid(int count) {
		if (count == horses.size()) {
			minEmptyGrid = Math.min(minEmptyGrid, getEmptyGrid());
			return;
		}
		
		int x = horses.get(count).x;
		int y = horses.get(count).y;
		
		for (int i = 0; i < 4; i++) {
			horseDir[x][y] = i;
			searchMinEmptyGrid(count + 1);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = sc.nextInt();
				if (1 <= board[i][j] && board[i][j] <= 5) {
					horses.add(new Pair(i, j));
				}
			}
			
			searchMinEmptyGrid(0);
		}
		
		System.out.println(minEmptyGrid);
		sc.close();
	}
	
	static class Pair {
		int x, y;
		
		public Pair(int row, int col) {
			this.x = row;
			this.y = col;
		}
	}
}
