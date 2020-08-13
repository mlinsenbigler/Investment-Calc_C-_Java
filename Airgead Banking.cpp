//============================================================================
// Name        : Airgead Banking.cpp
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================

#include <string>
#include <iostream>
#include "DataIn.h"
#include "Calc.h"
#include "Reports.h"
#include "InvestmentData.h"

using namespace std;

void startPgm() {
    bool restart = true;

    try {
        do {

            // Prompt user for input and store results
            DataIn userData;
            userData.promptUser();

            // Pass the user input to calculate
            Calculations calculations;
            InvestmentData acctWithNoMonthlyDep = calculations.calcAnnualInv(userData);
            InvestmentData acctWithMonthlyDep = calculations.calcAnnualInv(userData, true);

            ReportGen balAndIntReport;
            balAndIntReport.reportGenerator(acctWithNoMonthlyDep, acctWithMonthlyDep);

            // Prompt the user to continue or exit program
            restart = balAndIntReport.startOverCheck();
        } while (restart);
    }
    catch (runtime_error& except) {
        cout << "An error occurred. Exception: " <<  except.what() << endl;
    }
}

int main() {

    startPgm();

    return 0;
}
