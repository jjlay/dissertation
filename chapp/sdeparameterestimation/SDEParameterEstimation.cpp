#include <iostream>
#include <random>


int main(int argc, char*argv[])
{
	std::cout << "Starting..." << std::endl;

	//
	// Manual variables
	//
	
	double mu = 2.3;
	double sigma = 1.6;

	double X0 = 0.0;

	double T = 1.0;
	int steps = 1000;
	int sims = 100000;

	
	//
	// Calculated variables
	//
	
	double dt = T / static_cast<double>(steps);
	double sqrtdt = sqrt(dt);
	
	double dW = 0.0;

	// See:
	// http://www.cplusplus.com/reference/random/normal_distribution/
	
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0.0, 1.0);

	auto X = new double*[sims];

	for (auto i = 0; i < sims; i++) {
		X[i] = new double[steps];
		X[i][0] = X0;
	}

	double dX = 0.0;

	
	//
	// Perform simulation
	//

	for (auto i = 0; i < sims; i++)
		for (auto s = 1; s < steps; s++)
		{
			dW = distribution(generator) * sqrtdt;
			dX = mu * dt + sigma * dW;
			X[i][s] = X[i][s - 1] + dX;
		}

	//
	// Try to estimate mu and sigma
	//

	// See:
	// http://www.maths.lth.se/matstat/kurser/fms161mas229/Slides/L9/Lecture9.pdf
	
	double muhat = 0.0;
	double diff = 0.0;

	for (auto i = 0; i < sims; i++) {
		diff = 0.0;
		
		for (auto s = 1; s < steps; s++)
			diff += X[i][s] - X[i][s - 1];

		diff = diff / T;

		muhat += diff;
	}

	muhat = muhat / static_cast<double>(sims);
	
	std::cout << "Estimated mu = " << muhat
		<< ", Actual mu = " << mu << std::endl;

	double sigmahat = 0.0;

	for (auto i = 0; i < sims; i++)
	{
		diff = 0.0;

		for (auto s = 1; s < steps; s++)
		{
			double temp = X[i][s] - X[i][s - 1] - muhat * dt;
			temp = temp * temp;
			diff += temp;
		}

		sigmahat += sqrt(diff / (dt * static_cast<double>(steps - 1)));
	}

	sigmahat = sigmahat / static_cast<double>(sims);

	std::cout << "Estimated sigma = " << sigmahat
		<< ", Actual sigma = " << sigma << std::endl;
	
	return 0;
}