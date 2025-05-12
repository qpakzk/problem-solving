import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Triple {

	public int x;
	public int y;
	public int color;
	
	public Triple(int x, int y, int color) {
		this.x = x;
		this.y = y;
		this.color = color;
	}
}

public class Main {

	public static final int DIR = 4;

	public static int n;	
	public static int[][] board;
	
	public static int[] dx = new int[] {1, 0, -1, 0};
	public static int[] dy = new int[] {0, 1, 0, -1};
	
	public static boolean inRange(int x, int y) {
		return 0 <= x && x < n && 0 <= y && y < n;
	}
	
	public static void makeGroups(List<List<Triple>> groups) {
		boolean[][] visited = new boolean[n][n];
		Queue<Triple> queue = new LinkedList<>();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				
				int color = board[i][j];
				queue.add(new Triple(j, i, color));
				List<Triple> group = new ArrayList<>();
				while(!queue.isEmpty()) {
					Triple elem = queue.poll();
					if (visited[elem.y][elem.x]) continue;
					visited[elem.y][elem.x] = true;
					group.add(elem);
					for (int d = 0; d < DIR; d++) {
						int nx = elem.x + dx[d], ny = elem.y + dy[d];
						if (inRange(nx, ny) && !visited[ny][nx] && board[ny][nx] == color) {
							queue.add(new Triple(nx, ny, board[ny][nx]));
						}
					}
				}
				
				if (!group.isEmpty()) {
					groups.add(group);
				}
			}
		}
	}
	
	
	// (그룹 a에 속한 칸의 수 + 그룹 b에 속한 칸의 수) x 그룹 a를 이루고 있는 숫자 값 x 그룹 a와 그룹 b가 서로 맞닿아 있는 변의 수
	public static int calculate(List<List<Triple>> groups, int a, int b) {
		List<Triple> groupA = groups.get(a);
		
		List<Triple> groupB = groups.get(b);
		
		int adjSide = 0;
		for (Triple elemA : groupA) {
			int x = elemA.x, y = elemA.y;
			for (Triple elemB : groupB) {
				for (int d = 0; d < DIR; d++) {
					int nx = x + dx[d], ny = y + dy[d];
					if (inRange(nx, ny) && nx == elemB.x && ny == elemB.y) {
						adjSide += 1;
						break;
					}
				}
			}
		}
		
		return (groupA.size() + groupB.size()) * groupA.get(0).color * groupB.get(0).color * adjSide;
		
	}
	
	public static int calculateScore(List<List<Triple>> groups) {
		int score = 0;
		
		for (int i = 0; i < groups.size() - 1; i++) {
			for (int j = i + 1; j < groups.size(); j++) {
				score += calculate(groups, i, j);
			}
		}
		
		return score;
	}
	
	public static void rotate() {
		int mid = n / 2;
		
		// 십자가 회전
		int[] tmpColors = new int[n];
		for (int i = 0; i < n; i++) {
			tmpColors[i] = board[mid][i];
			board[mid][i] = board[i][mid];
		}
		
		for (int i = 0; i < n; i++) {
			board[n - 1 - i][mid] = tmpColors[i];
		}
		
		// 나머지 회전
		int[] mx = {0, 1, 0, 1};
		int[] my = {0, 0, 1, 1};
		
		for (int t = 0; t < 4; t++) {
			int[][] subBoard = new int[mid][mid];
			for (int i = 0; i < mid; i++) {
				for (int j = 0; j < mid; j++) {
					int x = i;
					int y = j;
					x = Math.abs(mid - 1 - x);
					
					int curX = j + mx[t] * (mid + 1);
					int curY = i + my[t] * (mid + 1);
					subBoard[y][x] = board[curY][curX];
				}
			}
			
			for (int i = 0; i < mid; i++) {
				for (int j = 0; j < mid; j++) {
					int curX = j + mx[t] * (mid + 1);
					int curY = i + my[t] * (mid + 1);
					board[curY][curX] = subBoard[i][j];
				}
			}	
		}
		
	}
	
	private static void start(InputStreamReader inputStreamReader) throws Exception {
		BufferedReader br = new BufferedReader(inputStreamReader);
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		
		board = new int[n][n];
		
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	public static void main(String[] args) throws Exception {

//		start(new FileReader("input.txt"));
		start(new InputStreamReader(System.in));
		
		int t = 3;
		int sum = 0;
		while(true) {
			// 그룹을 구한다.
			
			List<List<Triple>> groups = new ArrayList<>();
			makeGroups(groups);
			
			// 그룹 간 조합에 따라 예술 점수를 구한다.
			sum += calculateScore(groups);
			
			if (t-- <= 0) break;
			
			// 회전한다
			rotate();
		}
		
		System.out.println(sum);
	
	}

}
