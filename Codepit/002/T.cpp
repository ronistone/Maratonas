#include <bits/stdc++.h>
using namespace std;

char digit_hex (int x) {
  if (x >= 0 && x < 10)
    return x+'0';
  else if (x < 16) 
    return x-10+'a';
  else
    return '!';
}

string tobin (int x) {
  string aux;
  while (x > 0) {
    char c = x%2+'0';
    aux = c + aux;
    x /= 2;
  }
  return aux;
}

string tohex (int x) {
  string aux;
  while (x > 0) {
    aux = digit_hex(x%16) + aux;
    x /= 16;
  }
  return aux;
}

int main () {
  char str[50];
  string type;
  int x, n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str >> type;

    cout << "Case " << i+1 << ':' << endl;
    if (type == "bin") {
      x = strtol(str, 0, 2);
      cout << x        << " dec" << endl;
      cout << tohex(x) << " hex" << endl;
    } else if (type == "dec") {
      x = strtol(str, 0, 10);
      cout << tohex(x) << " hex" << endl;
      cout << tobin(x) << " bin" << endl;
    } else {
      x = strtol(str, 0, 16);
      cout << x        << " dec" << endl;
      cout << tobin(x) << " bin" << endl;
    } 

    cout << endl;
  }

  return 0;
}