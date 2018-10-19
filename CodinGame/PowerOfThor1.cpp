#include <bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
 
typedef pair<int,int> ii;
 
double norm(ii i){
	return sqrt(i.first*i.first + i.second*i.second);
}
 
 
 ii next(ii i, ii f){
		ii v = make_pair( f.first-i.first, f.second-i.second );
		double no = norm(v);
		ii ans = make_pair( (v.first>0?ceil(((double)v.first)/no):floor(((double)v.first)/no)),
							(v.second>0?ceil(((double)v.second)/no):floor(((double)v.second)/no))) ;
		return ans;
 }
 
 string d[3][3] = {
		
		"NW", "N", "NE",
		"W", "--", "E",
		"SW", "S" , "SE"
		
 };
 
int main()
{
	
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    ii i = make_pair(initialTX, initialTY);
    ii f = make_pair(lightX,lightY);
	ii n;
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();


		n = next(i,f);
		cerr << "(" << n.first << ", " << n.second << ")" << endl;
		cout << d[n.second+1][n.first+1] << endl;

		i.first += n.first;
		i.second += n.second;

    }
}
