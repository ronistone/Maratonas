#include <bits/stdc++.h>
using namespace std;


main(){
	int n,i,j,k,l,m,h;
	string e;
	while(cin >> n and n){
		if(n==1){
			for(i=0;i<=9;i++)
				cout << i;
			cout << endl;
		}
		else if(n==2){
			int x = 0;
			for(i=0;i<=9;i++){
				for(j=i;j<=9;j++){
					if(j!=i)
						//cout << i;
						e+=i+'0';
					//cout << j;
					e+=j+'0';
				}
				//x++;
			}
			e+='0';
			//cout << 0 << endl;
		}
		else if(n==3){
			/*for(i=0;i<=9;i++){
				for(j=i;j<=9;j++){
					for(k=j;k<=9;k++){
						//if(j!=k)
							cout << i;
						//if(k!=j)
							cout << j;
						cout << k;
					}
				}
			}
			cout << endl;*/
			e = "000100200300400500600700800901101201301401501601701801902102202302402502602702802903103203303403503603703803904104204304404504604704804905105205305405505605705805906106206306406506606706806907107207307407507607707807908108208308408508608708808909109209309409509609709809911121131141151161171181191221231241251261271281291321331341351361371381391421431441451461471481491521531541551561571581591621631641651661671681691721731741751761771781791821831841851861871881891921931941951961971981992223224225226227228229233234235236237238239243244245246247248249253254255256257258259263264265266267268269273274275276277278279283284285286287288289293294295296297298299333433533633733833934434534634734834935435535635735835936436536636736836937437537637737837938438538638738838939439539639739839944454464474484494554564574584594654664674684694754764774784794854864874884894954964974984995556557558559566567568569576577578579586587588589596597598599666766866967767867968768868969769869977787797887897987998889899900";

		}
		else if(n==4){
			for(i=0;i<=9;i++){
				for(j=0;j<=9;j++){
					for(k=0;k<=9;k++){
						for(l=0;l<=9;l++){
							cout << i << j << k << l;
						}
					}
				}
			}
			cout << endl;
		}
		else if(n==5){
			for(i=0;i<=9;i++){
				for(j=0;j<=9;j++){
					for(k=0;k<=9;k++){
						for(l=0;l<=9;l++){
							for(m=0;m<=9;m++){
								cout << i << j << k << l << m;
							}
						}
					}
				}
			}
			cout << endl;
		}
		else if(n==6){
			for(i=0;i<=9;i++){
				for(j=0;j<=9;j++){
					for(k=0;k<=9;k++){
						for(l=0;l<=9;l++){
							for(m=0;m<=9;m++){
								for(h=0;h<=9;h++){
									cout << i << j << k << l << m << h;
								}
							}
						}
					}
				}
			}
			cout << endl;
		}
	}
	int num[10];
	memset(num,0,sizeof num);
	for(int i=0;i<e.size();i++){
		num[e[i]-'0']++;
	}
	for(int i=0;i<10;i++)
		cout << num[i] << " ";
	cout << endl;
}
