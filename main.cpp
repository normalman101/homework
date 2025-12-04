#include <iostream>
#include <string>
#include <vector>
using std::string, std::vector;
using std::cout, std::endl;
// Создать класс для хранения данных о студенте: ФИО, факультет, группа, оценки (кто поставил, когда поставил,
// по какому предмету, что поставил).

#pragma region Классы
class Human {
public:
    Human(const string &name,
          const string &surname,
          const string &patronymic)

        : m_name(name),
          m_surname(surname),
          m_patronymic(patronymic) {
    }

protected:
    string m_name;
    string m_surname;
    string m_patronymic;
};

class Teacher : public Human {
public:
    Teacher(const string &name,
            const string &surname,
            const string &patronymic,
            const string &discipline)

        : Human{name, surname, patronymic},
          m_discipline{discipline} {
    }

private:
    string m_discipline;
};

class Date {
public:
    Date(const string &date) {
        m_day = stoi(date.substr(0, 2));
        m_month = stoi(date.substr(3, 2));
        m_year = stoi(date.substr(6, 4));
    }

private:
    int m_day;
    int m_month;
    int m_year;
};

class Mark {
public:
    Mark(const Teacher &teacher,
         const string &date,
         const string &discipline,
         const unsigned int &mark)

        : m_teacher{teacher},
          m_date{date},
          m_discipline{discipline},
          m_mark{mark} {
    }

private:
    Teacher m_teacher;
    Date m_date;
    string m_discipline;
    unsigned int m_mark;
};

class Student : public Human {
public:
    Student(const string &name,
            const string &surname,
            const string &patronymic,
            const string &faculty,
            const string &group)

        : Human{name, surname, patronymic},
          m_faculty{faculty},
          m_group{group},
          m_marks{{}} {
    }

private:
    string m_faculty;
    string m_group;
    std::vector<Mark> m_marks;
};
#pragma endregion

int main() {
    return 0;
}