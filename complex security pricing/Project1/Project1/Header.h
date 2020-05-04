#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include <chrono>
#define M_PI 3.14159265358979323846
using namespace std;

//followings are self generated standard normal distribution
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

//generate a standard normal distribution
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


//to be more efficient and accurate, we use <random> to generate standard normal distribution
vector<double> StdNormal(int n) {
	vector<double> output;
	//double mean = 0;
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	normal_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < n; i++) {
		output.push_back(distribution(generator));
		//mean += output[i];
	}

	//cout << "bm mean : " << mean / n << endl;

	return output;
}

//generate brownian motion
void BM(double dt, const vector<double> &Z, vector<double> &W) {
	int n = Z.size();
	for (int i = 0; i < n; i++) {
		W[i] = sqrt(dt)*Z[i];
	}
}
