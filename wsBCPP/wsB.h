// Definition of wsB functions. Last update 05/01/2020 5:44 PM
#ifndef WSB_H //load wsB.h
#define WSB_H
	double CalculateBz(double a1, double a2, double b1, double b2, double R, double Z, double I, double n);
	// CalculateBz = calcuilate the axial magnetic field in given variables.
	double CalculateBr(double a1, double a2, double b1, double b2, double R, double Z, double I, double n);
	// CalculateBr = calcuilate the radial magnetic field in given variables.
	void WSB(double B[], double a1, double a2, double b1, double b2, double R, double Z, double I, double n);
	// CalculateBr = calcuilate the radial magnetic field in given variables.
#endif


/*MIT License

Copyright (c) 2020 Wooseung Lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/