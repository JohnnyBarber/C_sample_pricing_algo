#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
#include <time.h>
#include <cstdlib>
#include "Header.h"

using namespace std;

void cumulativeSum(const vector<float>& input, vector<float>& result) {
	result.push_back(input[0]);
	for (int i = 1; i < input.size(); i++) {
		result.push_back(result[i - 1] + input[i]);
	}
}

void StockPrice(float S0, float T, float sim, float steps, float sigma, float r, vector<float> &S)
{
	vector<float> unif1(steps), unif2(steps);
	vector<float> norm(steps);
	vector<float> bm(steps);
	vector<float> dlnS(steps);
	vector<float> lnS;

	Uniform(unif1, rand() % 1000000 + 1);
	Uniform(unif2, rand() % 1000000 + 1);
	Normal(norm, unif1, unif2);

	float dt = T / steps;
	float mu = r - 0.5*pow(sigma, 2.0);
	BM(dt, norm, bm);

	for (int i = 0; i < steps; i++) {
		dlnS[i] = mu * dt + sigma * bm[i];
	}
	cumulativeSum(dlnS, lnS);

	for (int i = 0; i < steps; i++) {
		S[i] = exp(log(S0) + lnS[i]);
	}
}