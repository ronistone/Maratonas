#include<bits/stdc++.h>
using namespace std;

double e = 2.71828182845905;
double pi = 3.14159265358979;

struct Dino{
	
	string name;
	double ind;
	
	Dino(string n, double i){
		this->name=n;
		this->ind=i;
	}
	Dino(){}
	
	bool operator < (Dino aux) const{
		if(this->ind==aux.ind){
			return this->name < aux.name;
		}
		else return this->ind < aux.ind;
	}
	
};

bool ehvogal(char c){
	if(c=='a' || c=='A') return true;
	if(c=='e' || c=='E') return true;
	if(c=='i'|| c=='I') return true;
	if(c=='o'|| c=='O') return true;
	if(c=='u'|| c=='U') return true;
	return false;
}

double imad(string S, double A, double C, double P){
	int vogal=0, consoante=0;
	
	for(int i=0; i < S.size(); i++){
		if(ehvogal(S[i])) vogal++;
		else consoante++;
	}
	
	double acum = 0.00;
	for(int i=1; i<=S.size(); i++){
		acum+=pow(P, 1/i) * ((i%2==0)?1:(-1));
	}
	acum = fabs(acum);
	
	double acum2 = ceil(sqrt( pow(vogal, e)+pow(consoante, e))) / floor( pi+log(1+A*C) ) ;

	double acum3 = (max(vogal, consoante) + 1)/(min(vogal, consoante)-1);
	
	return acum*acum2*acum3;
}


int main()
{
		int n;
		string nome;
		double P, A, C;
		cin >> n;
		
		Dino vet[n];
		
		for(int i=0; i < n; i++){
			cin >> nome >> A >> C >> P;
			vet[i] = Dino(nome, imad(nome,A,C,P));
		}
		sort(vet, vet+n);
		
		for(int i =0; i < n; i++){
			cout << vet[i].name;
			//cout << " " << vet[i].ind << " ";
			for(int j=0; j<log10(vet[i].ind)+1; j++){
				cout << "!";
			}
			cout << endl;
		}
}
