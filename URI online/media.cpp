#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	float n[5],media=0,f=0;
	int i;

	for(i=0;i<4;i++)
		cin >> n[i];

	media += (n[0] * 2);
	media += (n[1] * 3);
	media += (n[2] * 4);
	media += n[3];
	media /= 10;
	if(media >= 7)
		printf("Media: %.1f\nAluno aprovado.\n", media);
	else if(media<5)
		printf("Media: %.1f\nAluno reprovado.\n", media);
	else if((media>=5) && (media<7)){
		cin >> n[5];
		f = media + n[5];
		f = f / 2;
		printf("Media: %.1f\nAluno em exame.\n", media);
		if(f >= 5)
			printf("Nota do exame: %.1f\nAluno aprovado.\nMedia final: %.1f\n", n[5], f);
		else
			printf("Nota do exame: %.1f\nAluno reprovado.\nMedia final: %.1f\n", n[5], f);
	}

	return 0;
}
