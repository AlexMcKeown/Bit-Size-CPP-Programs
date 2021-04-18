#include <iostream>

class Staff
{
private:
    int staffNum;
    std::string lName;
    std::string fName;
    double salary;
    int sales;
    std::string staffClass;

    double bonus;
    const static double bonusPerSale[3][5];

public:
    static void displayBonusTable()
    {
        std::string str;
        std::cout << "| Sales | Class A | Class B | Class C |" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                str += " | " + std::to_string(bonusPerSale[i][j]) + " | ";
                if (j == 4)
                {
                    std::cout << str << std::endl;
                    str = "";
                }
            }
        }
    }

    void computeBonus()
    {
        for (int i = 0; i < 3; i++)
        {
            if (sales >= bonusPerSale[i][0] || sales <= bonusPerSale[i][1])
            {
                if (staffClass == "Class A")
                {
                    bonus = salary * bonusPerSale[i][2];
                }
                else if (staffClass == "Class B")
                {
                    bonus = salary * bonusPerSale[i][3];
                }
                else
                {
                    bonus = salary * bonusPerSale[i][4];
                }
            }
        }
    }

    void setFields(int sNum, std::string lastN, std::string firstN, double income, int sale, std::string sClass)
    {
        staffNum = sNum;
        lName = lastN;
        fName = firstN;
        salary = income;
        sales = sale;
        staffClass = sClass;
        computeBonus();
    }

    void display()
    {
        std::cout << "Staff Number: " << staffNum << "\nLast name: " << lName << "\nFirst name: " << fName << "\nSalary: $" << salary << "\nSales: " << sales << "\nStaff Class: " << staffClass << "\nBonus: $" << bonus << std::endl;
    }
};

const double Staff::bonusPerSale[3][5] = {{0.0, 20.0, 0.003, 0.02, 0.005},
                                          {21.0, 50.0, 0.05, 0.035, 0.015},
                                          {51.0, 51.0, 0.075, 0.055, 0.04}};
int main()
{
    Staff aStaff;
    aStaff.setFields(123, "McKeown", "Alex", 1000, 21, "Class A");
    aStaff.display();
    return 0;
}