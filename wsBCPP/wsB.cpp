#include "wsB.h"
#ifndef CMATH
#define CMATH
#include <cmath>
#endif

const double pi = 3.14159265359;
const double mu0 = 4 * pi * 1.0e-7;
const int a_divide = 200;
const int th_divide = 180;

double CalculateBz(double a1, double a2, double b1, double b2, double R, double Z, double I, double n)
{
	double Bz = 0;
	double da = (a2 - a1) / a_divide;
	double dth = pi / th_divide;
	double dI = n * I / ((a2 - a1) * (b2 - b1));
	double z1 = Z - b1;
	double z2 = Z - b2;
	double z12 = pow(z1, 2);
	double z22 = pow(z2, 2);
	double cos_th[th_divide];
	double R2 = pow(R, 2);

	for (int j = 0; j < th_divide; j++)
	{
		cos_th[j] = cos(j * dth + dth / 2);
	}

	for(int i = 0; i < a_divide; i++)
	{
		double a_i = a1 + i * da + da/2;
		double a_i2 = pow(a_i, 2);
		
		for (int j = 0; j < th_divide; j++)
		{
			// cos_th for wsB code reduced function call v1 and 2
			//double th_i = j * dth + dth /2;
			//double cos_th = cos(th_i);

			// Original wsB code brute force writedown
			//Bz += (a_i * (a_i - R * cos(th_i)) / (pow(a_i, 2) - 2 * R * a_i * cos(th_i) + pow(R, 2)))
			//	* ((z1 / sqrt(pow(a_i, 2) - 2 * R * a_i * cos(th_i) + pow(R, 2) + pow(z1, 2)))
			//		- (z2 / sqrt(pow(a_i, 2) - 2 * R * a_i * cos(th_i) + pow(R, 2) + pow(z2, 2))));

			// wsB code reduced function call v1
			//Bz += (a_i * (a_i - R * cos_th) / (a_i2 - 2 * R * a_i * cos_th + R2))
			//	* ((z1 / sqrt(a_i2 - 2 * R * a_i * cos_th + R2 + z12))
			//		- (z2 / sqrt(a_i2 - 2 * R * a_i * cos_th + R2 + z22)));

			// wsB code reduced function call v2
			//double ai2_2Raicosth_R2 = a_i2 - 2 * R * a_i * cos_th + R2;
			//Bz += (a_i * (a_i - R * cos_th) / (ai2_2Raicosth_R2))
			//	* ((z1 / sqrt(ai2_2Raicosth_R2 + z12)) - (z2 / sqrt(ai2_2Raicosth_R2 + z22)));

			// wsB code reduced function call v3
			double ai2_2Raicosth_R2 = a_i2 - 2 * R * a_i * cos_th[j] + R2;
			Bz += (a_i * (a_i - R * cos_th[j]) / (ai2_2Raicosth_R2))
				* ((z1 / sqrt(ai2_2Raicosth_R2 + z12)) - (z2 / sqrt(ai2_2Raicosth_R2 + z22)));


		}
	}
	Bz *= 2 * (mu0 / 4 / pi * dI * dth * da);
	return Bz;
}
double CalculateBr(double a1, double a2, double b1, double b2, double R, double Z, double I, double n)
{
	double Br = 0;
	double da = (a2 - a1) / a_divide;
	double dth = pi / th_divide;
	double dI = n * I / ((a2 - a1) * (b2 - b1));
	double z1 = Z - b1;
	double z2 = Z - b2;
	double z12 = pow(z1, 2);
	double z22 = pow(z2, 2);
	double cos_th[th_divide];
	double R2 = pow(R, 2);

	for (int j = 0; j < th_divide; j++)
	{
		cos_th[j] = cos(j * dth + dth / 2);
	}

	for (int i = 0; i < a_divide; i++)
	{
		double a_i = a1 + i * da + da / 2;
		double a_i2 = pow(a_i, 2);
		
		for (int j = 0; j < th_divide; j++)
		{
			//double th_i = j * dth + dth /2;
			//double cos_th = cos(th_i);
			double ai2_2Raicosth_R2 = a_i2 - 2 * R * a_i * cos_th[j] + R2;
			Br += (a_i* cos_th[j])
				* ((1 / sqrt(ai2_2Raicosth_R2 + z22))
					- (1 / sqrt(ai2_2Raicosth_R2 + z12)));
		}
	}
	Br *= 2 * (mu0 / 4 / pi * dI * dth * da);
	return Br;
}

void WSB(double B[], double a1, double a2, double b1, double b2, double R, double Z, double I, double n)
{
	double da = (a2 - a1) / a_divide;
	double dth = pi / th_divide;
	double dI = n * I / ((a2 - a1) * (b2 - b1));
	double z1 = Z - b1;
	double z2 = Z - b2;
	double z12 = pow(z1, 2);
	double z22 = pow(z2, 2);
	double cos_th[th_divide];
	double R2 = pow(R, 2);

	for (int j = 0; j < th_divide; j++)
	{
		cos_th[j] = cos(j * dth + dth / 2);
	}

	for (int i = 0; i < a_divide; i++)
	{
		double a_i = a1 + i * da + da / 2;
		double a_i2 = pow(a_i, 2);

		for (int j = 0; j < th_divide; j++)
		{
			//double ai2_2Raicosth_R2 = a_i2 - 2 * R * a_i * cos_th[j] + R2;
			//B[0] += (a_i * (a_i - R * cos_th[j]) / (ai2_2Raicosth_R2))
			//	* ((z1 / sqrt(ai2_2Raicosth_R2 + z12)) - (z2 / sqrt(ai2_2Raicosth_R2 + z22)));
			//B[1] += (a_i * cos_th[j])
			//	* ((1 / sqrt(ai2_2Raicosth_R2 + z22))- (1 / sqrt(ai2_2Raicosth_R2 + z12)));
			// 와 씨 이걸 못이긴다고?

			double ai2_2Raicosth_R2 = a_i2 - 2 * R * a_i * cos_th[j] + R2;
			double sqt_Z12 = sqrt(ai2_2Raicosth_R2 + z12);
			double sqt_Z22 = sqrt(ai2_2Raicosth_R2 + z22);
			B[0] += (a_i * (a_i - R * cos_th[j]) / (ai2_2Raicosth_R2))
				* ((z1 / sqt_Z12) - (z2 / sqt_Z22));
			B[1] += (a_i * cos_th[j])
				* (1/sqt_Z22 - 1/ sqt_Z12);

		}
	}
	B[0] *= 2 * (mu0 / 4 / pi * dI * dth * da);
	B[1] *= 2 * (mu0 / 4 / pi * dI * dth * da);
	return ;
}

/*
MIT License

Copyright(c) 2020 Wooseung Lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/