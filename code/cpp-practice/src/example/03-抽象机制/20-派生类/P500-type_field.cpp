#include <cstdint>
#include <iostream>
#include <list>
#include <string>

struct Employee {
  enum EmplType { kMan, kEmpl };

  EmplType type{kEmpl};
  std::string first_name_;
  std::string family_name;
  char middle_initial{};
  std::int16_t department{};
};

struct Manager : public Employee {
  Manager() { type = kMan; }

  std::list<Employee*> group;  // 管理的人
  std::int16_t level{};
};

void print_employee(const Employee* e) {
  switch (e->type) {
    case Employee::kEmpl:
      std::cout << e->family_name << '\t' << e->department << '\n';
      break;
    case Employee::kMan: {
      std::cout << e->family_name << '\t' << e->department << '\n';
      const Manager* p{static_cast<const Manager*>(e)};
      std::cout << "level" << p->level << '\n';
      break;
    }
  }
}