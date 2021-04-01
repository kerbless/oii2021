/* William - è brutale ma dovrebbe funzionare */
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin); // Makes file stdin
	freopen("output.txt", "w", stdout); // Makes file stdout
	int H0, M0, H1, M1, DH, DM;
	cin >> H0 >> M0;
	cin >> H1 >> M1;
	if (H0 < 0 || H0 > 24 || H1 < 0 || H1 > 24 || M0 < 0 || M0 > 60 || M1 < 0 || M1 > 60 || (H0 == H1 && M0 == M1) ) {
		return 0;
	}
	
	if (H0 < H1) DH = H1 - H0;
	else {
		DH = 24 - (H0 - H1);
	}
	if (M0 < M1) DM = M1 - M0; 
	else {
		DM = 60 - (M0 - M1);
		DH--;
	}
	
	if ((DM + DH*60) > 24*60) {
		return 0;
	}
	
	cout << DH << " " << DM;
	
	return 0;
}