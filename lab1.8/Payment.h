// Payment.h
#pragma once
#include <iostream>
#include <string>

class Payment {
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;
    int startYear;
    double bonusPercentage;
    double incomeTax;
    int workedDays;
    int workingDaysPerMonth;
    int yearsWorked;
public: 
    class Money {
    private:
        long hryvnia;
        unsigned char kopiyka;

    public:
        
        Money();  // конструктор за умовчанням
        Money(long hryvnia = 0, unsigned char kopiyka = 0); // конструктор з параметрами

        ~Money();  // деструктор

        // Accessor methods
        long getHryvnia() const;
        void setHryvnia(long hryvnia);
        unsigned char getKopiyka() const;
        void setKopiyka(unsigned char kopiyka);

        // Initialization method
        void Init(long hryvnia, unsigned char kopiyka);
        void Read();
        void Display() const;

        // Conversion to string method
        std::string toString() const;

        // Operator overloading
        Money operator+(const Money& other) const;
        Money operator-(const Money& other) const;
        Money operator*(double multiplier) const;
        Money operator/(double divisor) const;
        bool operator==(const Money& other) const;
        bool operator!=(const Money& other) const;
        bool operator<(const Money& other) const;
        bool operator>(const Money& other) const;
    }; 

    Money rate;  
    Money accruedAmount;
    Money withheldAmount;

    Payment();  // конструктор за умовчанням
    Payment(const std::string& lastName, const std::string& firstName, const std::string& middleName, const Money& rate, int startYear, double bonusPercentage, double incomeTax, int workedDays, int workingDaysPerMonth);  // конструктор з параметрами
    Payment(const Payment& other);  // конструктор копіювання
    ~Payment();  // деструктор


    void Init(const std::string& lastName, const std::string& firstName, const std::string& middleName,
        const Money& rate, int startYear, double bonusPercentage, double incomeTax,
        int workedDays, int workingDaysPerMonth);

    // Accessor methods
    std::string getLastName() const;
    void setLastName(const std::string& lastName);
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);
    std::string getMiddleName() const;
    void setMiddleName(const std::string& middleName);
    Money getRate() const;
    void setRate(const Money& rate);
    int getStartYear() const;
    void setStartYear(int startYear);
    double getBonusPercentage() const;
    void setBonusPercentage(double bonusPercentage);
    double getIncomeTax() const;
    void setIncomeTax(double incomeTax);
    int getWorkedDays() const;
    void setWorkedDays(int workedDays);
    int getWorkingDaysPerMonth() const;
    void setWorkingDaysPerMonth(int workingDaysPerMonth);
    Money getAccruedAmount() const;
    Money getWithheldAmount() const;
    int getYearsWorked() const;

    // Calculation methods
    void calculateAccruedAmount();
    void calculateWithheldAmount();
    void calculateNetAmount();
    void calculateYearsWorked();

    // Input and output methods
    void Read();
    void Display() const;
};
