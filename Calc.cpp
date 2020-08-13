//============================================================================
// Name        : Calc.cpp
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#include <vector>
#include <iostream>
#include "Calc.h"
#include "InvestmentData.h"

using namespace std;

const long MAX_AMOUNT = 9999999999999999;

// Default constructor

Calculations::Calculations() {}

InvestmentData Calculations::calcAnnualInv(DataIn& t_userData, bool t_monthlyDep) {

    double openAmt =  t_userData.getMInitInvAmt();
    double depAmt =  t_userData.getMMonthlyDep();
    int intRate =  t_userData.getMAnnualInt();
    int numYears =  t_userData.getMNumYears();
    vector<int> years;
    vector<vector<double>> yearEndBal;

    // object to store data for report

    InvestmentData invDetails;

    try {

        // Return years as array to display

        for (int i = 0; i < numYears; ++i) {
            years.push_back(i + 1);
        }

        if (t_monthlyDep == false) {

            // Calculate without monthly deposit

            yearEndBal = annualBalWithInt(openAmt, 0, intRate, numYears);

        } else {

            // Calculate with monthly deposits

            yearEndBal = annualBalWithInt(openAmt, depAmt, intRate, numYears);
        }

        // Populate Investment object properties

        invDetails.setMYears(years);
        invDetails.setMYearEarnedInt(yearEndBal.at(0));
        invDetails.setMYearEndBal(yearEndBal.at(1));

        return invDetails;
    }

    catch (runtime_error& except) {
        cout << except.what() << endl;
    }
}

//Calculates annual account balance & earned interest

vector<vector<double>> Calculations::annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years) {

    // Local variables

    vector<vector<double>> balPlusInt;
    vector<double> annualIntOnly;
    vector<double> annualBalPlusInt;
    double newBal;
    double yearEndInt;
    double precIntRate = (t_intRate/100.00)/12.00;
    double intTracker = 0;
    double intOnly = 0;

    // Loop over months and calculate annual balance & earned interest

    for (int i = 0; i < (t_years * 12); ++i) {
        yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i+1))) * precIntRate;

        // Allows tracking earned interest back into principle

        intTracker = yearEndInt;

        if (((i+1) % 12) == 0) {
            annualIntOnly.push_back(yearEndInt - intOnly);
            intOnly = yearEndInt;
            newBal = t_openAmount + (t_depositAmount * (i+1)) + yearEndInt;
            annualBalPlusInt.push_back(newBal);
        }
    }

    if (newBal > MAX_AMOUNT ) {
        throw runtime_error("Unable to calculate. Amount too large.");
    }

    // track interest
    balPlusInt.push_back(annualIntOnly);

    // interest + balance
    balPlusInt.push_back(annualBalPlusInt);

    return balPlusInt;
}


