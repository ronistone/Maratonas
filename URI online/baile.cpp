// exercício: Baile de Formatura
// dificuldade: médio
// tema: programação dinâmica
// complexidade: O( B*G )
// solução: podemos modelar sub-problemas partindo do problema principal,
//          apenas diminuindo o número de garotos ou garotas.
//          Para saber o resultado para [B, G], temos duas opções:
//          1. escolhemos um garoto e fazemos ele dançar com uma garota
//             que ainda não dançou. Logo, partimos para o sub-problema
//             [B-1, G-1], e multiplicamos esse resultado por G, pois ele
//             poderia ter escolhido qualquer uma das G garotas.
//          2. escolhemos um garoto e fazemos ele dançar com uma garota
//             que já dançou com alguém. Logo, partimos para o sub-problema
//             [B-1, G], e multiplicamos esse resultado por 
//             (total_garotas-G), pois ele poderia ter escolhido qualquer
//             uma das garotas que já dançaram.

#include <stdio.h>
#include <string.h>
#define SIZE 1010
typedef long long int lli;
const lli MOD = 1000000007;

lli dp[SIZE][SIZE], G;
lli funcao(lli b, lli g);

int main() {
	lli b;
	
	while(scanf("%lld %lld", &b, &G) && b) {
		for(int i=1; i<=b; i++) {
			memset(dp[i], -1, sizeof(lli)*(G+1));
		}
		
		printf("%lld\n", funcao(b, G));
	}
}

lli funcao(lli b, lli g) {
	if(!b) {
		return (g ? 0 : 1);
	} else if(dp[b][g] != -1) {
		return dp[b][g];
	}
	
	lli ans = 0;
	ans += funcao(b-1, g)*(G-g);
	ans += (g > 0 ? funcao(b-1, g-1)*g : 0);
	
	return dp[b][g] = ans%MOD;
}
