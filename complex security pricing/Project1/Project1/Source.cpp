#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <numeric>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include "Header.h"
#include "StockPricePath.h"
#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
	double S0 = 25, K = 28, T = 1, sim = pow(10.0, 4.0), steps = 252, sigma = 0.4, r = 0.02;

	vector<double> S(steps);
	vector<double> C(sim);
	double trading_30;
	double avg = 0.0;

	for (int i = 0; i < sim; i++) {
		StockPrice(S0, T, sim, steps, sigma, r, S);
		trading_30 = 0.0;
		avg += S[S.size() - 1];
		for (int j = 0; j < 30; j++) {
			trading_30 += S[S.size() - 1 - j];
		}
		if (K < trading_30 / 30) {
			C[i] = (trading_30 / 30 - K);
		}
		else {
			C[i] = 0;
		}
	}

	double total = 0;
	for (int i = 0; i < sim; i++) {
		total += C[i];
	}
	cout << endl << "Put option price: " << total / sim * exp(-r * T) << endl;
	cout << "avg stock price at T: " << avg / sim << endl;

	/* can have a glance at one of the stock price paths

	ofstream myfile("stock.csv");
	for (auto x : S) {
		myfile << x << endl;
	}
	myfile.close();
	*/

	cout << endl;
	system("pause");
	return 0;
}