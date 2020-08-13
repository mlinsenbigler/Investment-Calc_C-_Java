//============================================================================
// Name        : Calc.h
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#ifndef CALC_H_
#define CALC_H_

#include <vector>
#include "DataIn.h"
#include "InvestmentData.h"

using namespace std;

class Calculations {

public:

    Calculations();
    InvestmentData calcAnnualInv(DataIn& data, bool t_monthlyDep = false);

private:

    vector<vector<double>> annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years);
};

#endif /* CALC_H_ */
