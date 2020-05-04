#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
#include <time.h>
#include <cstdlib>
#include "Header.h"

using namespace std;

void cumulativeSum(const vector<double>& input, vector<double>& result) {
	result.push_back(input[0]);
	for (int i = 1; i < input.size(); i++) {
		result.push_back(result[i - 1] + input[i]);
	}
}

void StockPrice(double S0, double T, double sim, double steps, double sigma, double r, vector<double> &S)
{
	//comments can be used when we want to use our self-generated standard normal distribution
	//vector<float> unif1(steps), unif2(steps);
	//vector<float> norm(steps);
	vector<double> bm(steps);
	vector<double> dlnS(steps);
	vector<double> lnS;

	//Uniform(unif1, rand() % 1000000 + 1);
	//Uniform(unif2, rand() % 1000000 + 1);
	//Normal(norm, unif1, unif2);

	vector<double> norm = StdNormal(steps);

	double dt = T / steps;
	double mu = r - 0.5*pow(sigma, 2.0);
	BM(dt, norm, bm);

	for (int i = 0; i < steps; i++) {
		dlnS[i] = mu * dt + sigma * bm[i];
	}
	cumulativeSum(dlnS, lnS);

	for (int i = 0; i < steps; i++) {
		S[i] = exp(log(S0) + lnS[i]);
	}
}