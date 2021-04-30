/*
Monte Carlo integration efficiency testing
This code compares the standard method of Monte Carlo integral approximation and the Halton method.
To compare the two, this code estimates pi, and counts the time each operation takes in both ticks and seconds.

For my testing, I could not do numbers past about N = 50,000,000 without stack overflow, so it would 

I also have commented out the code to compare in seconds, since it seems to not be useful at all

Changelog:
Date			Editor					Changes
15/04/21		Cameron Willoughby		Creation, implementation of original montecarlo method adapted from on code from https://en.wikipedia.org/wiki/Monte_Carlo_integration
18/04/21		"						Adding multiple time metrics for efficiency testing
28/04/21		"						Adding in include to halton code from https://people.sc.fsu.edu/~jburkardt/cpp_src/halton/halton.html, editing that in

*/

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <ctime>
#include <cmath>
#include <cstring>



#include <halton.hpp>
using namespace std;

double* randseq(int);
double omc(int, double*);
time_t tosec(SYSTEMTIME);


int main() {
srand(time(0)); //setting a 'true' random seed

// Initializing everything I'll need
	int N, ba, bb;
	double opi = 0.0, hpi = 0.0; //The pi we found using the original Monte Carlo and the Halton Sequence method
	int tb, te;       // Ticks Begin and Ticks End (system times in ticks)

	//SYSTEMTIME stb, ste; // SYSTEMTIME Begin and SYSTEMTIME End (system times in SYSTEMTIME)

	double *HSp; //The halton sequences as point pairs (even is x, odd is y)


	cout << "Please enter a number of attempts: " << endl;
	//cin >> N;
	cout << "Please enter base A: " << endl;
	cin >> ba;
	cout << "Please enter base B: " << endl;
	cin >> bb;


	for (N = 10000; N < 20000000; N *= 2.5) {

		double* rands = new double[N];
		rands = randseq(N);
		tb = int(clock()); //capture the bein time in ticks 
		opi = omc(N, rands);
		te = int(clock());//capture the final  time in ticks
		cout << "Pi approx by original MC: " << opi << " using " << N << " iterations took " << te - tb << " ticks" << endl;

		/*
		GetSystemTime(&stb);// capture the being time in SYSTEMTIME
		opi = omc(N, rands);
		GetSystemTime(&ste);// capture the final time in SYSTEMTIME
		time_t ostb = tosec(stb); // convert both times to seconds
		time_t oste = tosec(ste);
		cout << "Pi approx by original MC: " << opi << " using " << N << " iterations took " << oste - ostb << " seconds" << endl;
		*/
		delete[] rands;
		HSp = new double[N * 2];

		int b1[1] = { ba };
		int b2[1] = { bb };

		for (int j = 0; j < N; j += 2) { // compute the halton sequence
			HSp[j] = *halton_base(j, 1, b1);
			HSp[j + 1] = *halton_base(j, 1, b2);
		}


		tb = int(clock()); //capture the bein time in ticks 
		hpi = omc(N, HSp);
		te = int(clock());//capture the final  time in ticks
		cout << "Pi approx by Halton  MC: " << opi << " using " << N << " iterations took " << te - tb << " ticks" << endl;

		/*
		GetSystemTime(&stb);// capture the being time in SYSTEMTIME
		hpi = omc(N, HSp);
		GetSystemTime(&ste);// capture the final time in SYSTEMTIME
		ostb = tosec(stb); // convert both times to seconds
		oste = tosec(ste);
		cout << "Pi approx by Halton MC: " << opi << " using " << N << " iterations took " << oste - ostb << " seconds" << endl;
		*/

		delete[] HSp;
	}//This bracket is to the mass-testing loop
	return 0;
}

double *randseq(int N) {//Function to generate random number points
	double randX, randY, max = (double)RAND_MAX;
	double *rs = new double[N*2];
	for (int i = 0; i < N; i+=2) {
		randX = rand() / max;
		randY = rand() / max;
		rs[i] = randX; //Even values are X
		rs[i + 1] = randY; // Odd values re Y

	}
	return(rs);
}

double omc(int N, double *seq) {//Function for the original monte carlo method
	double pi;
	int inc = 0; // the count of tries 'in circle'

	for (int i = 0; i < N; ++i) {
		if (pow(seq[i], 2) + pow(seq[i+1], 2) < 1) {
			++inc;
		}
	}
	pi = 4.0 * inc / N;
	return(pi);
}

time_t tosec(SYSTEMTIME st) {// converts SYSTEMTIMEs to seconds
	tm T;
	T.tm_sec = st.wSecond;
	T.tm_min = st.wMinute;
	T.tm_hour = st.wHour;
	T.tm_mday = st.wDay;
	T.tm_mon = st.wMonth - 1;
	T.tm_year = st.wYear - 1900;
	T.tm_isdst = -1;
	return(std::mktime(&T));
}
