//============================================================================
// Name        : DataIn.cpp
// Author      : Michael Linsenbigler
// Description : Airgead Banking Application
//============================================================================


#include <iostream>
#include <vector>
#include <limits>
#include "DataIn.h"

using namespace std;

// Default constructor

DataIn::DataIn() {

    DataIn::m_userPrompts = {
        "Initial Investment Amount:  ",
        "Monthly Deposit:  ",
        "Annual Interest:  ",
        "Number of Years:  "
    };
};

const vector<string> &DataIn::getMUserPrompts() const {
    return m_userPrompts;
}

double DataIn::getMInitInvAmt() const {
    return m_initInvAmt;
}

void DataIn::setMInitInvAmt(double t_initialInvestAmt) {
    m_initInvAmt = t_initialInvestAmt;
}

double DataIn::getMMonthlyDep() const {
    return m_monthlyDep;
}

void DataIn::setMMonthlyDep(double t_monthlyDep) {
    m_monthlyDep = t_monthlyDep;
}

double DataIn::getMAnnualInt() const {
    return m_annualInt;
}

void DataIn::setMAnnualInt(double t_annualInt) {
    m_annualInt = t_annualInt;
}

double DataIn::getMNumYears() const {
    return m_numYears;
}

void DataIn::setMNumYears(double t_numYears) {
    m_numYears = t_numYears;
}

// Print header for user input prompt

void DataIn::printHeader() {
    cout << string(36, '*') << endl;
    cout << string(12, '*') << " Data Input " << string(12, '*') << endl;
}

// Capture user input and set class members

void DataIn::promptUser() {
    vector<double> depositDetails;
    char quitCmd = 'a';

    // loop until user enters 'q'
    while (quitCmd != 'q') {

        try {

            // Clear previous user input

            depositDetails.clear();

            // Display header

            printHeader();

            // Get user input

            depositDetails = inputCapture();
        }

        // Catch invalid arguments

        catch (invalid_argument& except) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << except.what() << endl;
        }

        // Check that depositDetails vector is full and user decides to continue

        if (depositDetails.size() == 4 && enterCheck()) {

            setMInitInvAmt(depositDetails.at(0));
            setMMonthlyDep(depositDetails.at(1));
            setMAnnualInt(depositDetails.at(2));
            setMNumYears(depositDetails.at(3));

            // Exit class and return to main()

            quitCmd = 'q';
        }
    }
}

// Loop over user prompts and store responses

vector<double> DataIn::inputCapture() {

    // Get user input and store in vector

    vector<double> responses;
    vector<string> prompts = getMUserPrompts();

    for (int i = 0; i < prompts.size(); ++i) {
        string prompt = prompts.at(i);
        double userInput;
        cout << prompt;
        cin >> userInput;

        // Check for valid user input

        if (!cin || userInput < 0.01) {
            throw invalid_argument("\n\nAlphabetical characters and amounts less than .01 not allowed. \n\n"
            "Please try again.\n\n");
        }

        // Add user input to vector

        responses.push_back(userInput);
    }
    return responses;
}

bool DataIn::enterCheck() {
	cout << endl;
    cout << "Calculating......" << endl;
    Sleep(3000);
    return cin.get() == '\n';
}
