//============================================================================
// Name        : InvestmentData.cpp
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#include <vector>
#include "InvestmentData.h"

using namespace std;

// Default constructor
InvestmentData::InvestmentData() {}

const vector<int> &InvestmentData::getMYears() const {
    return m_years;
}

void InvestmentData::setMYears(const vector<int> &t_years) {
    m_years = t_years;
}

const vector<double> &InvestmentData::getMYearEndBal() const {
    return m_yearEndBal;
}

void InvestmentData::setMYearEndBal(const vector<double> &t_yearEndBal) {
    m_yearEndBal = t_yearEndBal;
}

const vector<double> &InvestmentData::getMYearEndEarnedInt() const {
    return m_yearEndEarnedInt;
}

void InvestmentData::setMYearEarnedInt(const vector<double> &t_yearEndEarnedInt) {
    m_yearEndEarnedInt = t_yearEndEarnedInt;
}
