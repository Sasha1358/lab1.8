#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.8/Payment.h" // Підключаємо заголовний файл класу Payment
#include "../lab1.8/Payment.cpp" // Підключаємо визначення методів класу Payment

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest17
{
    TEST_CLASS(UnitTest17)
    {
    public:

        TEST_METHOD(TestInit)
        {
            // Arrange
            Payment::Money money(100, 50); // Створюємо об'єкт класу Payment::Money з параметрами
            Payment payment;
            std::string lastName = "Doe";
            int startYear = 2020; // Наприклад, встановлюємо рік початку роботи

            // Act
            payment.Init(lastName, "John", "Smith", money, startYear, 5.0, 15.0, 20, 22);

            // Assert
            Assert::AreEqual(lastName, payment.getLastName());
            Assert::AreEqual(startYear, payment.getStartYear());
        }
    };
}
