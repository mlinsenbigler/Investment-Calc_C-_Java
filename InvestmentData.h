//============================================================================
// Name        : InvestmentData.h
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#ifndef INVESTMENTDATA_H_
#define INVESTMENTDATA_H_

#include <vector>

using namespace std;

class InvestmentData {

public:

    InvestmentData();

    const vector<int> &getMYears() const;

    void setMYears(const vector<int> &t_years);

    const vector<double> &getMYearEndBal() const;

    void setMYearEndBal(const vector<double> &t_yearEndBal);

    const vector<double> &getMYearEndEarnedInt() const;

    void setMYearEarnedInt(const vector<double> &t_yearEndEarnedInt);

private:

    vector<int> m_years;

    vector<double> m_yearEndBal;

    vector<double> m_yearEndEarnedInt;

};

#endif /* INVESTMENTDATA_H_ */
