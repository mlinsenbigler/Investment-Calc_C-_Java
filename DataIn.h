//============================================================================
// Name        : DataIn.h
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#ifndef DATAIN_H_
#define DATAIN_H_

#include <vector>
#include <windows.h>

using namespace std;

class DataIn {

public:

    DataIn();

    const vector<string> &getMUserPrompts() const;

    double getMInitInvAmt() const;

    void setMInitInvAmt(double t_initialInvestAmt);

    double getMMonthlyDep() const;

    void setMMonthlyDep(double t_monthlyDep);

    double getMAnnualInt() const;

    void setMAnnualInt(double t_annualInt);

    double getMNumYears() const;

    void setMNumYears(double t_numYears);

    void promptUser();

private:

    vector<string> m_userPrompts;

    double m_initInvAmt;
    double m_monthlyDep;
    double m_annualInt;
    double m_numYears;

    void printHeader();

    vector<double> inputCapture();

    bool enterCheck();

};

#endif /* DATAIN_H_ */
