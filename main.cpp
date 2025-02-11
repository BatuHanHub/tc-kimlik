#include <iostream>
#include <string>

using namespace std;

string tcMi(string tc) {
	unsigned int c = 0, t = 0, ob = 0; // cift-tek ve onbirinci

	// 10562272296
	for(short int i = 1; i < 11; i+=2) {
		c += int(tc[i-1]) - '0'; // '0' -> 48 ASCII
	}

	for(short int i = 0; i < 7; i+=2) {
		t += int(tc[i+1]) - '0';
	}

	for(int i = 0; i < tc.length()-1; i++) {
		ob += int(tc[i]) - '0';
	}

	short int on = ((c*7)-t) % 10; 
	short int onbir = ob%10;

	// cout << to_string(on) << " " << tc[10-1] << endl;
	// cout << to_string(onbir) << " " << tc[11-1] << endl;

	string sonuc = (on == (tc[9] - '0') && onbir == (tc[10] - '0') && tc[0] != '0')? "(+) Ulkeye hos geldin yurtdas!" : "(-) Ulkene geri don bir daha geri gelme!";

	return sonuc;
}

int main() {
	string tcNO;
	short int can = 3;

	while(1) {
		cout << "11 haneli TC kimlik numaranizi yaziniz. Cikmak icin \'q\' tusuna basin." << endl << "tc> ";
		cin >> tcNO;

		if(tcNO.length() == 11) {
			cout << tcMi(tcNO) << endl << endl;
		} else if(tcNO == "q" || tcNO == "Q") {
			cout << "Gorusuruz!" << endl;
			break;
		} else {
			can -= 1;
			string cevap = (can == 0)? "!?> Hadi ama adamimim... Alt tarafi 11 tane tusa basacaksin! Bu kadar zor olmasa gerek :)":
			"HATA!> Sence bu \"" + tcNO + "\" TC kimlik numarasina mi benziyor?";

			cerr << cevap << endl << endl;
			continue;
		}
	}

	return 0;
}