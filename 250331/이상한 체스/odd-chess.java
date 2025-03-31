import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

class Pair {
	int x, y;
	
	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Main {
	public static final int INT_MAX = Integer.MAX_VALUE;
	public static final int MAX_N = 8;
	public static final int MAX_M = 8;
	
	public static int n, m;
	public static int minArea = INT_MAX;
	public static int[][] board = new int[MAX_N][MAX_M];
	public static List<Pair> chessPieces = new ArrayList<>();
	public static int[][] pieceDir = new int[MAX_N][MAX_M];
	public static boolean[][] visited = new boolean[MAX_N][MAX_M];
	
	public static int[][] canMove = new int[][] {
		{},
		{1, 0, 0, 0},
		{0, 1, 0, 1},
		{1, 1, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 1, 1}
	};
	
	public static boolean inRange(int x, int y) {
		return 0 <= x && x < n && 0 <= y && y < m;
	}
	
	public static boolean canGo(int x, int y) {
		return inRange(x, y) && board[x][y] != 6;
	}
	
	public static void fill(int startX, int startY, int pieceNum, int faceDir) {
		int[] dx = new int[]{-1, 0, 1, 0};
		int[] dy = new int[]{0, 1, 0, -1};
		
		for (int i = 0; i < 4; i++) {
			if (canMove[pieceNum][i] == 0) {
				continue;
			}
			
			int x = startX, y = startY;
			int moveDir = (i + faceDir) % 4;
			
			while (true) {
				visited[x][y] = true;
				int nx = x + dx[moveDir], ny = y + dy[moveDir];
				if (canGo(nx, ny)) {
					x = nx;
					y = ny;
				}
				else {
					break;
				}
			}
		}
	}
	
	public static int getArea() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
		
		for (int i = 0; i < chessPieces.size(); i++) {
			int x = chessPieces.get(i).x;
			int y = chessPieces.get(i).y;
			
			fill(x, y, board[x][y], pieceDir[x][y]);
		}
		
		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && board[i][j] != 6) {
					area++;
				}
			}
		}
		
		return area;
	}
	
	public static void searchMinArea(int cnt) {
		if (cnt == chessPieces.size()) {
			minArea = Math.min(minArea, getArea());
			return;
		}
		
		int pieceX = chessPieces.get(cnt).x;
		int pieceY = chessPieces.get(cnt).y;
		
		for (int i = 0; i < 4; i++) {
			pieceDir[pieceX][pieceY] = i;
			searchMinArea(cnt + 1);
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
					chessPieces.add(new Pair(i, j));
				}
			}
			
			searchMinArea(0);
		}
		System.out.println(minArea);
		
	}
}