#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        return (m_number <= 99999 &&
            m_number >= 10000 &&
            m_balance >= 0);
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }

    bool Account::operator ~() const {
        return m_number == 0;
    }

    Account& Account::operator =(int accountNumber) {
        if (~*this) {
            if (accountNumber <= 99999 && accountNumber >= 10000) {
                this->m_number = accountNumber;
            }
            else {
                this->m_number = -1;
                this->m_balance = 0;
            }
        }
        return *this;
    }

    Account& Account::operator =(Account& a) {
        if (~*this && a) {
            this->m_number = a.m_number;
            this->m_balance = a.m_balance;
            a.m_number = 0, a.m_balance = 0;
        }
        return *this;
    }

    Account& Account::operator +=(double amount) {
        if (*this && amount >= 0) {
            this->m_balance += amount;
        }
        return *this;
    }

    Account& Account::operator -=(double amount) {
        if (*this && amount >= 0 && this->m_balance >= amount) {
            this->m_balance -= amount;
        }
        return *this;
    }

    Account& Account::operator <<(Account& a) {
        // both accounts are valid and the account numbers do not match
        if (*this && a && this->m_number != a.m_number) {
            this->m_balance += a.m_balance;
            a.m_balance = 0;
        }
        return *this;
    }

    Account& Account::operator >>(Account& a) {
        // both accounts are valid and the account numbers do not match
        if (*this && a && this->m_number != a.m_number) {
            a.m_balance += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    }

    double operator +(const Account& a1, const Account& a2) {
        double returnAmount = 0;
        if (a1 && a2) {
            returnAmount = a1.m_balance + a2.m_balance;
        }
        return returnAmount;
    }

    double operator +=(double& amount, Account& a) {
        if (a) {
            amount += a.m_balance;
        }
        return amount;
    }

}