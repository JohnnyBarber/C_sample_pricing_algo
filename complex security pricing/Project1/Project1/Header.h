#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#define M_PI 3.14159265358979323846
using namespace std;

int mod(int a, int b)
{
	int ret = a % b;
	return ret >= 0 ? ret : ret + b;
}

//random number generator
void Uniform(vector<float> &uniform,float start) {
	int a = pow(7.0, 5.0);
	int b = 0.0;
	int m = pow(2.0, 31.0) - 1.0;
	int n = uniform.size();

	vector<int> unif(n + 1);
	unif[0] = start;

	for (int i = 1; i < (n + 1); i++) {
		unif[i] = mod(a*unif[i - 1] + b, m);
	}
	for (int i = 0; i < n; i++) {
		uniform[i] = unif[i + 1] / float(m);
	}
}

void Normal(vector<float> &norm, const vector<float> &unif1, const vector<float> &unif2)
{
	int n = norm.size();
	vector<float> Z1(n), Z2(n);
	for (int i = 0; i < n; i++) {
		Z1[i] = sqrt(-2 * log(unif1[i]))*cos(2 * M_PI*unif2[i]);
		Z2[i] = sqrt(-2 * log(unif1[i]))*sin(2 * M_PI*unif2[i]);
		norm[i] = Z1[i];
	}
}

void BM(float dt, const vector<float> &Z, vector<float> &W) {
	int n = Z.size();
	for (int i = 0; i < n; i++) {
		W[i] = sqrt(dt)*Z[i];
	}
}