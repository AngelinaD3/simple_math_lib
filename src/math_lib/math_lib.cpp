#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;        
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }

    int GCD(int a, int b)
    {
		if (b == 0) return a;
		return GCD(b, a % b);
	}


    std::vector<double> solveQuadraticEquation(double a, double b, double c)
    {
        std::vector<double> roots;

        if (a == 0)
        {
            throw std::invalid_argument("Coefficient 'a' cannot be zero in a quadratic equation.");
        }

        double D = b * b - 4 * a * c; 

        if (D > 0) 
        {
            double sqrtD = sqrt(D);
            roots.push_back((-b + sqrtD) / (2 * a)); 
            roots.push_back((-b - sqrtD) / (2 * a)); 
        }
        else if (D == 0) 
        {
            roots.push_back(-b / (2 * a)); 
        }
        

        return roots;
    }
}

