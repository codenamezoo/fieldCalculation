#include <iostream> 
#include <cmath>
//#include <time.h>
#include "wsB.h"
#include <ctime>
#define CLOCKS_PER_SEC ((clock_t)1000) 

int main(int argc, char** argv)
{
	double a1 = 1;
	double a2 = 2;
	double b1 = -2;
	double b2 = 4;
	double R = 1;
	double Z = 3;
	double I = 5000;
	double n = 300;
//	double Bz = 0;
//	double Br = 0;
	double B[2] = { 0,0 };
	clock_t Tstart, Tend;
	Tstart = clock();
	//for (int i = 0; i < 100; i++)
	//{
		//		Bz = CalculateBz(a1, a2, b1, b2, R, Z, I, n);
		//		Br = CalculateBr(a1, a2, b1, b2, R, Z, I, n);
	//}
	//std::cout << "Bz=" << Bz << "\n";
	//std::cout << "Br=" << Br << "\n";
	for (int i = 0; i < 100; i++)
	{
		WSB(B, a1, a2, b1, b2, R, Z, I, n);
	}

	std::cout << "Bz=" << B[0] << "\n";
	std::cout << "Br=" << B[1] << "\n";
	Tend = clock();

	// Calculating total time taken by the program. 
//	double time_taken = ((double) Tend - (double) Tstart);
	double time_taken = ((double)Tend - (double)Tstart);
	std::cout << "Time taken by 100 iteration is : " << time_taken << " ms " << "\n";
	return 0;
}
