// source.cpp
#include <iostream>
#include "Payment.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Payment payment;
    payment.Read();
    payment.calculateAccruedAmount();
    payment.calculateWithheldAmount();
    payment.calculateNetAmount();
    payment.calculateYearsWorked();
    payment.Display();
    return 0;
}
