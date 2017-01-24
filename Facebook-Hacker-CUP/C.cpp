#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef struct{
	ll ini, fim,soma;
	int lados,rep;
	double prob;
	void constr(int s,int l,int r,int life){
		soma = s;
		lados = l;
		rep = r;
		ini = rep + soma;
		fim = (rep*lados)+soma;
		double aux = (life - fim);
		cout << life << "   " << ini << "  " << fim << "  " << endl;
		prob = aux < 0 ? (aux*-1)/(fim-ini):0;//aux/(fim-ini);
	}
}dados;
typedef vector<dados> vd;

bool ordena(dados a,dados b){return a.prob > b.prob;}

ll fat(ll n){
	ll saida = 1;
	for(int i=1;i<n;i++){
		saida *=i;
	}
	return saida;
}

main(){
	ll life,dados,rep,s,d;
	int n,i,j,k;	
	char lixo,o;
	string str;
	stringstream ss;
	
	cin >> n;
	
	for(k=0;k<n;k++){
		cin >> life >> dados;
		vd v(dados);
		for(i=0;i<dados;i++){
			cin >> str;
			ss.clear();
			ss << str;
			ss >> rep;
			ss >> lixo;
			ss >> d;
			o = ' ';
			ss >> o;
			ss >> s;
			if(o=='-'){
				v[i].constr(-s,d,rep,life);
			}
			else if(o=='+'){
				v[i].constr(s,d,rep,life);
			}
			else{
				v[i].constr(0,d,rep,life);
			}
		}
		sort(v.begin(),v.end(),ordena);
		ll saida = pow(v[0].lados,v[0].rep);
		cout << (fat(v[0].fim-v[0].ini)/fat(life-v[0].fim))/saida << endl;
//		cout << (v[0].prob*saida)/saida << endl;
	}
}
