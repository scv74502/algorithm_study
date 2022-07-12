package swea_1961;

import java.util.Scanner;

public class Solution_1961_swea {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int rpt = sc.nextInt();
		for(int r = 1;r <= rpt; r++)
		{
			int m = sc.nextInt();
			
			String rot90 = "";
			String rot180 = "";
			String rot270 = "";
			
			int[][] arr = new int[m][m];
			
			for(int i = 0; i < m; i++) {
				for(int j = 0; j < m; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			
			
			// 90 rotate value string
			for(int i = 0;i < m; i++) {
				for(int j = m-1; j >= 0; j--) {
					rot90 += Integer.toString(arr[j][i]);
				}
			}
			
			// 270 rotate value string
			for(int i = m-1;i >= 0; i--) {
				for(int j = 0; j < m; j++) {
					rot270 += Integer.toString(arr[j][i]);
				}
			}
			
			// 180 rotate value string
			for(int i = m-1;i >= 0; i--) {
				for(int j = m-1; j >= 0; j--) {
					rot180 += Integer.toString(arr[i][j]);
				}
			}
//			System.out.println(rot90);
//			System.out.println(rot180);
//			System.out.println(rot270);
			
			System.out.println("#"+r);
			for(int i = 0; i < m;i++) {
				for(int j = 0; j < m;j++) {
					System.out.print(rot90.charAt(i * m + j));
				}
				System.out.print(" ");
				
				for(int j = 0; j < m;j++) {
					System.out.print(rot180.charAt(i * m + j));
				}
				System.out.print(" ");
				
				for(int j = 0; j < m;j++) {
					System.out.print(rot270.charAt(i * m + j));
				}
				System.out.println();
			}
			
		}
		sc.close();		
	}
}
