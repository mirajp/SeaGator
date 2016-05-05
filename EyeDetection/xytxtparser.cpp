#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string line;
	ifstream infile("33.txt");
	ofstream outfile;
	outfile.open("newXYs.csv", ios::out | ios::binary);

	while (getline(infile, line)) {
		if (line.length() > 1) {
			if (line.length() > 26) {
				outfile << line.substr(15, 5) << "," << line.substr(22, 5) << endl;
			}
			else {
				outfile << line.substr(15, 3) << "," << line.substr(20, 3) << endl;
			}
		}
	}

	infile.close();
	outfile.close();
}