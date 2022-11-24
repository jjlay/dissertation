
/*
 * Welford online variance calculator
 *
 * See also
 * Lay, H., Colgin, Z., Reshniak, V., Khaliq, A.Q.M. (2018).
 * "On the implementation of multilevel Monte Carlo simulation
 * of the stochastic volatility and interest rate model using
 * multi-GPU clusters." Monte Carlo Methods and Applications,
 * 24(4), pp. 309-321.
 *
 * JJ Lay
 * Middle Tennessee State University
 * October 2018
 *
 * DATE        AUTHOR  COMMENTS
 * ----------  ------  ---------------
 * 2018-12-16  JJL     Initial version
 *
 */

#pragma once

void welford(long double* pcount, long double* pmean, long double* pM2, long double pNewValue);
long double welfordVariance(long double* pCount, long double* pMean, long double* pM2);

