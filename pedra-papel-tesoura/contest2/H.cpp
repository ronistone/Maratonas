#include <bits/stdc++.h>
using namespace std;

const int N = 1003;

int n, aluno[N][7][13], ans[13];
char day[N];

int main()
{
		scanf("%d", &n);
		getchar();
				
		memset(aluno, 0, sizeof aluno);
		for(int i=0; i<n; i++) {
					for(int k=0; k<6; k++) {
						scanf("%s", day);
						
						int m = strlen(day);
						
						for(int j=0; j<m; j++) 
							aluno[i][k][day[j]-'A']++; 
							
					}
		}
		
		int f=0;
		for(int k=0; k<7; k++) {
			if(f) printf(" ");
			for(int i=0; i<13; i++) ans[i]=0;
			
			for(int i=0; i<n; i++) {
				for(int j=0; j<13; j++) ans[j]+=aluno[i][k][j];
			}
			
			for(int j=0; j<13; j++){
				if(ans[j] == n) { printf("%c", (j+'A'));f=1;}
			}
		}
		puts("");
		
}
