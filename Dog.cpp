#include <iostream>
using namespace std;

struct Dog
{
  static const double licenseFee;
  string name;
  string breed;
  int age;
};
const double Dog::licenseFee = 17.55;

int main()
{
  Dog dog;

  cout << "Name your dog: ";
  cin >> dog.name;

  cout << "What is your dog's breed: ";
  cin >> dog.breed;

  cout << "How old is your new dog: ";
  cin >> dog.age;

  cout << "\n---------------\nDog: " << dog.name << " is a " << dog.breed << "\nThe dog's age is " << dog.age << "\nLicense fee: " << dog.licenseFee << "\n---------------\n"
       << endl;

  return 0;
}
