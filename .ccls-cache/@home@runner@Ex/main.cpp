// Etienne Mudjindji
// Thien Nguyen

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Income {
private:
  string name;
  double salary;

public:
  Income(string n, double s) {
    name = n;
    salary = s;
  }

  void setName(string n) { name = n; }

  void setSalary(double s) { salary = s; }

  string getName() { return name; }

  double getSalary() { return salary; }
};

class Expenses {
private:
  string name;
  double amountpaid;

public:
  Expenses(string n, double a) {
    name = n;
    amountpaid = a;
  }

  void setName(string n) { name = n; }

  void setAmountPaid(double a) { amountpaid = a; }

  string getName() { return name; }

  double getAmountPaid() { return amountpaid; }
};

class Person {
private:
  vector<Income> incomes;
  vector<Expenses> expenses;
  string name;
  double IncomeTotal;
  double ExpenseTotal;

public:
  void setName(string n) { name = n; }

  void addIncome(Income i) { incomes.push_back(i); }

  void addExpense(Expenses e) { expenses.push_back(e); }

  string getName() { return name; }

  double getIncomeTotal() {
    for (int i = 0; i < incomes.size(); i++) {
      IncomeTotal += incomes[i].getSalary();
    }
    return IncomeTotal;
  }

  double getExpenseTotal() {
    for (int i = 0; i < expenses.size(); i++) {
      ExpenseTotal += expenses[i].getAmountPaid();
    }
    return ExpenseTotal;
  }

  double getLeftOver() { return getIncomeTotal() - getExpenseTotal(); }
};

int main() {
  Person p1, p2;
  int incomesPerMonth1, incomesPerMonth2;
  int expensesPerMonth1, expensesPerMonth2;

  // Input for Person 1
  cout << "Enter name for Person 1: ";
  string name1;
  cin >> name1;
  p1.setName(name1);

  cout << "How many incomes does " << name1 << " get a month? ";
  cin >> incomesPerMonth1;

  for (int i = 0; i < incomesPerMonth1; i++) {
    string name;
    double salary;

    cout << "Enter name of the income: ";
    cin >> name;

    cout << "Enter amount of the income: ";
    cin >> salary;

    Income userIncome(name, salary);
    p1.addIncome(userIncome);
  }

  cout << "How many expenses does " << name1 << " have a month? ";
  cin >> expensesPerMonth1;

  for (int i = 0; i < expensesPerMonth1; i++) {
    string name;
    double amountPaid;

    cout << "Enter name of the expense: ";
    cin >> name;

    cout << "Enter amount of the expense: ";
    cin >> amountPaid;

    Expenses userExpense(name, amountPaid);
    p1.addExpense(userExpense);
  }

  // Input for Person 2
  cout << "Enter name for Person 2: ";
  string name2;
  cin >> name2;
  p2.setName(name2);

  cout << "How many incomes does " << name2 << " get a month? ";
  cin >> incomesPerMonth2;

  for (int i = 0; i < incomesPerMonth2; i++) {
    string name;
    double salary;

    cout << "Enter name of the income: ";
    cin >> name;

    cout << "Enter amount of the income: ";
    cin >> salary;

    Income userIncome(name, salary);
    p2.addIncome(userIncome);
  }

  cout << "How many expenses does " << name2 << " have a month? ";
  cin >> expensesPerMonth2;

  for (int i = 0; i < expensesPerMonth2; i++) {
    string name;
    double amountPaid;

    cout << "Enter name of the expense: ";
    cin >> name;

    cout << "Enter amount of the expense: ";
    cin >> amountPaid;

    Expenses userExpense(name, amountPaid);
    p2.addExpense(userExpense);
  }

  // Output formatting
  cout << "\n";
  cout << "Name\t\tIncome\t\tExpenses\t\tLeftover" << endl;
  cout << "------------------------------------------------------" << endl;
  cout << name1 << "\t\t" << p1.getIncomeTotal() << "\t\t"
       << p1.getExpenseTotal() << "\t\t" << p1.getLeftOver() << endl;
  cout << name2 << "\t\t" << p2.getIncomeTotal() << "\t\t"
       << p2.getExpenseTotal() << "\t\t" << p2.getLeftOver() << endl;

  return 0;
}