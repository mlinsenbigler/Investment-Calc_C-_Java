//============================================================================
// Name        : Reports.cpp
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#include <string_view>
#include <iostream>
#include <iomanip>
#include "Reports.h"
#include "Calc.h"

using namespace std;

const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

// Constructor

ReportGen::ReportGen() {}

// Print the report column titles

void ReportGen::printColHeader() {
    cout << string(66, '=') << endl;
    cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST << endl;
    cout << string(66, '-') << endl;
}

// Print the report header

void ReportGen::reportGenerator(InvestmentData  &t_dataOne, InvestmentData  &t_dataTwo) {
    cout << endl << "     Balance and Interest Without Additional Monthly Deposits     \n";
    annualReport(t_dataOne);
    cout <<"     Balance and Interest With Additional Monthly Deposits     \n";
    annualReport(t_dataTwo);
}

// Print the rows of financial info for the report

void ReportGen::annualReport(InvestmentData  &t_data) {

    // Set local vars to producing accurate report
    vector<int> years = t_data.getMYears();
    vector<double> yearEndBal = t_data.getMYearEndBal();
    vector<double> yearEndEarnedInt = t_data.getMYearEndEarnedInt();

    printColHeader();

    // Loop over InvestmentInfo object to fill out report
    for (int i = 0; i < years.size(); ++i) {
        cout << setw(9) << years.at(i) << fixed << setprecision(2);
        cout << setw(15) << "$" << yearEndBal.at(i) << fixed << setprecision(2);
    	cout << setw(16) << "$" << yearEndEarnedInt.at(i) << fixed << setprecision(2) << endl;
    }
    cout << endl << endl;
}

// Prompt user to start over

bool ReportGen::startOverCheck() {
    string text;

    cout << "Press enter to start over (press 'q' to quit)\n";

    getline(cin, text);

    if (text.empty()) {
        return true;
    }
    else {
        return false;
    }
}
