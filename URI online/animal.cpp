#include <iostream>
#include <cstring>
using namespace std;
struct dados
{
	char a1[20]= "vertebrado", a2[20]= "invertebrado";
	char b1[20]= "ave", b2[20]= "mamifero", b3[20]= "inseto", b4[20]= "anelideo";
	char c1[20]= "carnivoro", c2[20]= "onivoro", c3[20]= "herbivoro", c4[20]= "hematofago";
};
int main(){
	char a[20],b[20],c[20];
	struct dados d;

	cin >> a;
	cin.clear();
	cin >> b;
	cin.clear();
	cin >> c;
	cin.clear();
	if(!strcmp(a,d.a1)){							//Vertebrado
		if(!strcmp(b,d.b1)){						//vertebrado-ave
			if(!strcmp(c,d.c1)){					//vertebrado-ave-carnivoro
				cout << "aguia\n";
			}
			else if(!strcmp(c,d.c2)){				//vertebrado-ave-onivoro
				cout << "pomba\n";
			}
		}
		else if(!strcmp(b,d.b2)){					//vertebrado-mamifero
			if(!strcmp(c,d.c2)){					//vertebrado-mamifero-onivoro
				cout << "homem\n";
			}
			else if(!strcmp(c,d.c3)){				//vertebrado-mamifero-herbivoto
				cout << "vaca\n";
			}
		}
	}

	else if(!strcmp(a,d.a2)){						//invertebrado
		if(!strcmp(b,d.b3)){						//invertebrado-inseto
			if(!strcmp(c,d.c4)){					//invertebrado-inseto-hematofago
				cout << "pulga\n";
			}
			else if(!strcmp(c,d.c3)){				//invertebrado-inseto-hervivoro
				cout << "lagarta\n";
			}
		}
		else if(!strcmp(b,d.b4)){					//invertebrado-anelideo
			if(!strcmp(c,d.c4)){					//invertebrado-anelideo-hematofago
				cout << "sanguessuga\n";
			}
			else if(!strcmp(c,d.c2)){				//invertebrado-anelideo-onivoro
				cout << "minhoca\n";
			}
		}

	}

return 0;
}