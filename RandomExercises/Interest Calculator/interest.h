#include <iostream>
using namespace std;


void getValuesFromUser(double &balance, short &months, float &interestRate, double &monthlyDeposit){
    cout << "Insert starting balance: ";
    cin >> balance;
    
    cout << "Insert number of months: ";
    cin >> months;
    
    cout << "Insert interest rate (0.01 equals 1%): ";
    cin >> interestRate;

    cout << "Insert monthly deposit rate: ";
    cin >> monthlyDeposit;
}