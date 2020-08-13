//============================================================================
// Name        : Reports.h
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#ifndef REPORTS_H_
#define REPORTS_H_

#include <vector>
#include "DataIn.h"
#include "Calc.h"
#include "InvestmentData.h"

using namespace std;

class ReportGen {

public:

    ReportGen();

    void reportGenerator(InvestmentData  &t_dataOne, InvestmentData  &dataTwo);

    bool startOverCheck();

private:

    void printColHeader();

    void annualReport(InvestmentData  &t_data);

};

#endif /* REPORTS_H_ */
