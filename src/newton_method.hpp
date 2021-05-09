#pragma once
#ifndef MATHS_UTILS_NEWTON_H
#define MATHS_UTILS_NEWTON_H

//************Content************
#include <functional>
#include <limits>
#include <math.h>
#include <string>

namespace MathsUtils
{

	class NewtonRaphson
	{
	private:
		std::function<double(double)> mFunction;
		std::function<double(double)> mDerivationFunction;

		int mMaximumIteration = 1000;

	public:
		NewtonRaphson(std::function<double(double)> function, std::function<double(double)> derivationFunction);

		double Solve();
		double Solve(double initGuess);

		void setMaximumIteration(int iteration);
		int getMaximumIteration();

		bool throwErrorIfMaximumIterationReach = true;

	};

}
//*******************************

#endif