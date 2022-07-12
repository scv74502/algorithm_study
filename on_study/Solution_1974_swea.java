package swea_1974;

import java.util.Scanner;
import java.util.HashSet;


public class Solution_1974_swea {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		HashSet<Integer> chkset = new HashSet<Integer>();
		int rpt = sc.nextInt();
		for(int r = 1;r <= rpt; r++)
		{
			int[][] sdoku = new int[9][9];
			
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j < 9; j++) {
					sdoku[i][j] = sc.nextInt();
				}
			}
			
			int ans = 1;
			
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j < 9; j++) {
					chkset.add(sdoku[i][j]);
				}
				//System.out.println(chkset);
				//System.out.println(chkset.size());
				if(chkset.size() != 9) {
					ans = 0;
					break;
				}
				chkset.clear();
			}
			//System.out.println("vert : "+ans);
			
			// if still number fits sdoku condition, check vertical line
			if(ans == 1) {
				for(int i = 0; i < 9; i++) {
					for(int j = 0; j < 9; j++) {
						chkset.add(sdoku[j][i]);
					}
					
					//System.out.println(chkset.size());
					if(chkset.size() != 9) {
						ans = 0;
						break;
					}
					chkset.clear();
				}
			}
			//System.out.println("horz : "+ans);
			
			// if still number fits sdoku condition, check 3*3 block
			if(ans == 1) {
				for(int i = 0; i <= 6; i+=3) {
					for(int j = 0; j <= 6; j+=3) {
						int row = i + 3;
						int col = j + 3;
									
						for(int c = 0; c < 3; c++) {
							for(int d = 0; d < 3; d++) {
								//System.out.println("i+c : "+(i+c)+", j+d : "+(j+d));
								//System.out.println(sdoku[i+c][j+d]);
								chkset.add(sdoku[i+c][j+d]);
							}								
						}
						
						if(chkset.size() != 9) {
							//System.out.println("horz check size : "+chkset.size());
							ans = 0;
							//System.out.println("horz chkset : "+chkset);
							break;
						}	
						chkset.clear();					
					}
					
				}
			}
			//System.out.println("cube : "+ans);
			System.out.println("#"+r+" "+ans);
		}
		sc.close();		
	}
}
