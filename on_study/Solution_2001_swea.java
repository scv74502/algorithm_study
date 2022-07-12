package swea_2001;
import java.util.Scanner;

public class Solution_2001_swea {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int rpt = sc.nextInt();
		for(int r = 1;r <= rpt; r++)
		{
			int m = sc.nextInt();
			int n = sc.nextInt();
			
			int[][] arr = new int[m][m];
			
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < m; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			
			int ans = 0;
			int temp = 0;
			
			for(int i = 0; i <= m-n; i++) {
				for(int j = 0; j <= m-n; j++) {
					temp = 0;
					for(int row = 0; row < n; row++) {
						for(int col = 0; col < n; col++) {
								temp += arr[i+row][j+col]; 
						}
					}
					if(ans  < temp) {						
						ans = temp;
					}	
				}
			}
			System.out.println("#" + r + " " +ans);
		}
		sc.close();		
	}
}

