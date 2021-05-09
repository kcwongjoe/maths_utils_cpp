#include <newton_method.hpp>

namespace MathsUtils
{
	
    NewtonRaphson::NewtonRaphson(std::function<double(double)> function, std::function<double(double)> derivationFunction)
    {
        mFunction = function;
        mDerivationFunction = derivationFunction;
    }

    double NewtonRaphson::Solve()
    {
        return Solve(0);
    }

    double NewtonRaphson::Solve(double initGuess)
    {
        // Calculate error
        double eps;
        if (std::abs(initGuess) < std::numeric_limits<double>::epsilon() )
        {
            eps = std::numeric_limits<double>::epsilon();
        }
        else
        {
            eps = initGuess * 1e-13;
        }

        // Initialize
        double currentGuess = initGuess;
        double previousGuess = initGuess * 2;
        double error = 2 * eps;
        double approximateZero = eps / 2.0;

        int curIteration = 0;
        while (curIteration < mMaximumIteration && error > eps)
        {
            // Calcualte derivation function.
            double dfunc = mDerivationFunction(currentGuess);

            // If derivation function = 0, reset the guess
            if (std::abs(dfunc) <= approximateZero)
            {
                // Reset Guess
                if (previousGuess == currentGuess)
                {
                    if (currentGuess == 0)
                        currentGuess = eps;
                    else
                        currentGuess *= 2;
                }
                else
                {
                    currentGuess = (currentGuess + previousGuess) / 2.0;
                }
            }
            else
            {
                // Process Newton Raphson method

                // Save previous value
                previousGuess = currentGuess;

                // Newton raphson method
                currentGuess -= mFunction(currentGuess) / dfunc;

                // Calculate error
                error = std::abs(currentGuess - previousGuess);

                // Save current iteration
                curIteration++;
            }
        }

        // Throw error if maximum iteration reach
        if (curIteration >= mMaximumIteration &&  throwErrorIfMaximumIterationReach)
            throw "Newton Raphson method reached the max iteration(" + std::to_string(mMaximumIteration) + ") but the guess error (" + std::to_string(error) + ") is > the eps(" + std::to_string(eps) + " )";

        return currentGuess;
    }

    #pragma region Getter and Setter

    void NewtonRaphson::setMaximumIteration(int iteration)
    {
        if (iteration <= 10)
            throw "Maximum iteration must be > 10.";

        mMaximumIteration = iteration;
    }

    int NewtonRaphson::getMaximumIteration()
    {
        return mMaximumIteration;
    }

    #pragma endregion Getter and Setter
}