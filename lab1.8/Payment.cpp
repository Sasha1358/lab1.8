#include "Payment.h"
#include <ctime>
#include <string>
using namespace std;

Payment::Payment() : rate(0, 0), accruedAmount(0, 0), withheldAmount(0, 0) {
    lastName = "";
    firstName = "";
    middleName = "";
    startYear = 0;
    bonusPercentage = 0.0;
    incomeTax = 0.0;
    workedDays = 0;
    workingDaysPerMonth = 0;
    yearsWorked = 0;
}

Payment::Payment(const std::string& lastName, const std::string& firstName, const std::string& middleName, const Money& rate, int startYear, double bonusPercentage, double incomeTax, int workedDays, int workingDaysPerMonth)
    : rate(rate), accruedAmount(0, 0), withheldAmount(0, 0) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->middleName = middleName;
    this->startYear = startYear;
    this->bonusPercentage = bonusPercentage;
    this->incomeTax = incomeTax;
    this->workedDays = workedDays;
    this->workingDaysPerMonth = workingDaysPerMonth;
    yearsWorked = 0;
}

Payment::Payment(const Payment& other)
    : rate(other.rate), accruedAmount(other.accruedAmount), withheldAmount(other.withheldAmount) {
    lastName = other.lastName;
    firstName = other.firstName;
    middleName = other.middleName;
    startYear = other.startYear;
    bonusPercentage = other.bonusPercentage;
    incomeTax = other.incomeTax;
    workedDays = other.workedDays;
    workingDaysPerMonth = other.workingDaysPerMonth;
    yearsWorked = other.yearsWorked;
}

Payment::~Payment() {
    // ����������
}


void Payment::Init(const std::string& lastName, const std::string& firstName, const std::string& middleName,
    const Money& rate, int startYear, double bonusPercentage, double incomeTax,
    int workedDays, int workingDaysPerMonth) {
    this->lastName = lastName;
    this->firstName = firstName;
    this->middleName = middleName;
    this->rate = rate;
    this->startYear = startYear;
    this->bonusPercentage = bonusPercentage;
    this->incomeTax = incomeTax;
    this->workedDays = workedDays;
    this->workingDaysPerMonth = workingDaysPerMonth;
}

std::string Payment::getLastName() const {
    return lastName;
}

void Payment::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

std::string Payment::getFirstName() const {
    return firstName;
}

void Payment::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

std::string Payment::getMiddleName() const {
    return middleName;
}

void Payment::setMiddleName(const std::string& middleName) {
    this->middleName = middleName;
}

Payment::Money Payment::getRate() const {
    return rate;
}

void Payment::setRate(const Money& rate) {
    this->rate = rate;
}

int Payment::getStartYear() const {
    return startYear;
}

void Payment::setStartYear(int startYear) {
    this->startYear = startYear;
}

double Payment::getBonusPercentage() const {
    return bonusPercentage;
}

void Payment::setBonusPercentage(double bonusPercentage) {
    this->bonusPercentage = bonusPercentage;
}

double Payment::getIncomeTax() const {
    return incomeTax;
}

void Payment::setIncomeTax(double incomeTax) {
    this->incomeTax = incomeTax;
}

int Payment::getWorkedDays() const {
    return workedDays;
}

void Payment::setWorkedDays(int workedDays) {
    this->workedDays = workedDays;
}

int Payment::getWorkingDaysPerMonth() const {
    return workingDaysPerMonth;
}

void Payment::setWorkingDaysPerMonth(int workingDaysPerMonth) {
    this->workingDaysPerMonth = workingDaysPerMonth;
}

Payment::Money Payment::getAccruedAmount() const {
    return accruedAmount;
}

Payment::Money Payment::getWithheldAmount() const {
    return withheldAmount;
}

int Payment::getYearsWorked() const {
    return yearsWorked;
}

void Payment::calculateAccruedAmount() {
    Money baseAmount = (rate / workingDaysPerMonth) * workedDays;
    Money bonus = baseAmount * (bonusPercentage / 100.0);
    accruedAmount = baseAmount + bonus;
}

void Payment::calculateWithheldAmount() {
    Money pensionFund = accruedAmount * 0.01;
    Money incomeTaxAmount = (accruedAmount - pensionFund) * (incomeTax / 100.0);
    withheldAmount = pensionFund + incomeTaxAmount;
}

void Payment::calculateNetAmount() {
    Money netAmount = accruedAmount - withheldAmount;
}

void Payment::calculateYearsWorked() {
    time_t currentTime;
    time(&currentTime);
    struct tm timeinfo;
    localtime_s(&timeinfo, &currentTime);

    int currentYearInt = timeinfo.tm_year + 1900;
    yearsWorked = currentYearInt - startYear;
}

void Payment::Read() {
    std::cout << "������ �������: ";
    std::cin >> lastName;
    std::cout << "������ ��'�: ";
    std::cin >> firstName;
    std::cout << "������ �� �������: ";
    std::cin >> middleName;
    std::cout << "������ ������ (������ ������): ";
    int hryvnia, kopiyka;
    std::cin >> hryvnia >> kopiyka;
    rate.Init(hryvnia, kopiyka);
    std::cout << "������ �� ������� ������: ";
    std::cin >> startYear;
    std::cout << "������ ������� ��������: ";
    std::cin >> bonusPercentage;
    std::cout << "������ ������� �� ��������: ";
    std::cin >> incomeTax;
    std::cout << "������ ������� ������������� ���: ";
    std::cin >> workedDays;
    std::cout << "������ ������� ������� ��� � �����: ";
    std::cin >> workingDaysPerMonth;
}

void Payment::Display() const {
    std::cout << "�������: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "������: " << rate.toString() << std::endl;
    std::cout << "г� ������� ������: " << startYear << std::endl;
    std::cout << "³������ ��������: " << bonusPercentage << std::endl;
    std::cout << "������� �� ��������: " << incomeTax << std::endl;
    std::cout << "ʳ������ ������������� ���: " << workedDays << std::endl;
    std::cout << "ʳ������ ������� ��� � �����: " << workingDaysPerMonth << std::endl;
    std::cout << "���������� ����: " << accruedAmount.toString() << std::endl;
    std::cout << "�������� ����: " << withheldAmount.toString() << std::endl;
    std::cout << "���� ������: " << yearsWorked << " ����" << std::endl;
}

Payment::Money::Money() {
    hryvnia = 0;
    kopiyka = 0;}
Payment::Money::Money(long hryvnia, unsigned char kopiyka) : hryvnia(hryvnia), kopiyka(kopiyka) {}
Payment::Money::~Money() {}

long Payment::Money::getHryvnia() const {
    return hryvnia;
}

void Payment::Money::setHryvnia(long hryvnia) {
    this->hryvnia = hryvnia;
}

unsigned char Payment::Money::getKopiyka() const {
    return kopiyka;
}

void Payment::Money::setKopiyka(unsigned char kopiyka) {
    this->kopiyka = kopiyka;
}

void Payment::Money::Init(long hryvnia, unsigned char kopiyka) {
    this->hryvnia = hryvnia;
    this->kopiyka = kopiyka;
}

void Payment::Money::Read() {
    std::cout << "Enter Hryvnia: ";
    std::cin >> hryvnia;
    std::cout << "Enter Kopiyka: ";
    std::cin >> kopiyka;
}

void Payment::Money::Display() const {
    std::cout << hryvnia << "," << (int)kopiyka;
}

std::string Payment::Money::toString() const {
    return std::to_string(hryvnia) + "," + std::to_string(kopiyka);
}


Payment::Money Payment::Money::operator+(const Money& other) const {
    long sumHryvnia = hryvnia + other.hryvnia;
    int sumKopiyka = kopiyka + other.kopiyka;
    sumHryvnia += sumKopiyka / 100;
    sumKopiyka %= 100;
    return Money(sumHryvnia, sumKopiyka);
}

Payment::Money Payment::Money::operator-(const Money& other) const {
    long differenceHryvnia = hryvnia - other.hryvnia;
    int differenceKopiyka = kopiyka - other.kopiyka;
    if (differenceKopiyka < 0) {
        differenceHryvnia -= 1;
        differenceKopiyka += 100;
    }
    return Money(differenceHryvnia, differenceKopiyka);
}

Payment::Money Payment::Money::operator*(double multiplier) const {
    long totalKopiyka = hryvnia * 100 + kopiyka;
    totalKopiyka *= multiplier;
    long newHryvnia = totalKopiyka / 100;
    unsigned char newKopiyka = totalKopiyka % 100;
    return Money(newHryvnia, newKopiyka);
}

Payment::Money Payment::Money::operator/(double divisor) const {
    long totalKopiyka = hryvnia * 100 + kopiyka;
    totalKopiyka /= divisor;
    long newHryvnia = totalKopiyka / 100;
    unsigned char newKopiyka = totalKopiyka % 100;
    return Money(newHryvnia, newKopiyka);
}

bool Payment::Money::operator==(const Money& other) const {
    return hryvnia == other.hryvnia && kopiyka == other.kopiyka;
}

bool Payment::Money::operator!=(const Money& other) const {
    return !(*this == other);
}

bool Payment::Money::operator<(const Money& other) const {
    if (hryvnia != other.hryvnia) {
        return hryvnia < other.hryvnia;
    }
    return kopiyka < other.kopiyka;
}

bool Payment::Money::operator>(const Money& other) const {
    if (hryvnia != other.hryvnia) {
        return hryvnia > other.hryvnia;
    }
    return kopiyka > other.kopiyka;
}

