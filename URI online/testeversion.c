#include <stdio.h>
#include <stdlib.h>

int main(){
	#ifndef __STDC_VERSION__
		printf("Versão: C89\n");
	#else
		#if (__STDC_VERSION_ == 199409L)
			printf("Versão: C94\n");
		#endif
		#if (__STDC_VERSION_ == 19901L)
			printf("Versão: C99\n");
		#endif
	#endif
return 0;
}