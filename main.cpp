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
    Human()
        : m_name("empty"),
          m_surname("empty"),
          m_patronymic("empty") {
    }

    Human(const string &name,
          const string &surname,
          const string &patronymic)

        : m_name(name),
          m_surname(surname),
          m_patronymic(patronymic) {
    }

    void setName(const string &name) { m_name = name; }
    string getName() const { return m_name; }

    void setSurname(const string &surname) { m_surname = surname; }
    string getSurname() const { return m_surname; }

    void setPatronymic(const string &patronymic) { m_patronymic = patronymic; }
    string getPatronymic() const { return m_patronymic; }

protected:
    string m_name;
    string m_surname;
    string m_patronymic;
};

class Teacher : public Human {
public:
    Teacher()
        : m_discipline{"empty"} {
    }

    Teacher(const string &name,
            const string &surname,
            const string &patronymic,
            const string &discipline)

        : Human{name, surname, patronymic},
          m_discipline{discipline} {
    }

    void setDiscipline(const string &discipline) { m_discipline = discipline; }
    string getDiscipline() const { return m_discipline; }

    void outputInfoIntoConsole() const {
        cout << "Teacher information: " << endl;
        cout << "* " + m_name << endl;
        cout << "* " + m_surname << endl;
        cout << "* " + m_patronymic << endl;
        cout << "* " + m_discipline << endl;
    }

private:
    string m_discipline;
};

class Date {
public:
    Date()
        : m_day{0},
          m_month{0},
          m_year{0} {
    }

    Date(const int& day, const int& month, const int& year) {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    void setDay(const int &day) { m_day = day; }
    int getDay() const { return m_day; }

    void setMonth(const int &month) { m_month = month; }
    int getMonth() const { return m_month; }

    void setYear(const int &year) { m_year = year; }
    int getYear() const { return m_year; }

    void outputInfoIntoConsole() const {
        cout << "Date: " << m_day << "." << m_month << "." << m_year << endl;
    }

private:
    int m_day;
    int m_month;
    int m_year;
};

class Mark {
public:
    Mark()
        : m_discipline{"empty"},
          m_mark{0} {
    }

    Mark(const Teacher &teacher,
         const Date &date,
         const string &discipline,
         const unsigned int &mark)

        : m_teacher{teacher},
          m_date{date},
          m_discipline{discipline},
          m_mark{mark} {
    }

    void setTeacher(const Teacher &teacher) { m_teacher = teacher; }
    Teacher getTeacher() const { return m_teacher; }

    void setDate(const Date &date) { m_date = date; }
    Date getDate() const { return m_date; }

    void setDiscipline(const string &discipline) { m_discipline = discipline; }
    string getDiscipline() const { return m_discipline; }

    void setMark(const unsigned int &mark) { m_mark = mark; }
    unsigned int getMark() const { return m_mark; }

    void outputInfoIntoConsole() const {
        cout << "Mark information:" << endl;
        cout << "* Teacher: " << m_teacher.getName() + " " + m_teacher.getSurname() + " " + m_teacher.getPatronymic() << endl;
        cout << "* Date: " << m_date.getDay() << "." << m_date.getMonth() << "." << m_date.getYear() << endl;
        cout << "* Discipline: " + m_discipline << endl;
        cout << "* Mark: " << m_mark << endl;
    }

private:
    Teacher m_teacher;
    Date m_date;
    string m_discipline;
    unsigned int m_mark;
};

class Student : public Human {
public:
    Student()
        : m_faculty{"empty"},
          m_group{"empty"} {
    }

    Student(const string &name,
            const string &surname,
            const string &patronymic,
            const string &faculty,
            const string &group,
            const vector<Mark> &marks)

        : Human{name, surname, patronymic},
          m_faculty{faculty},
          m_group{group},
          m_marks{marks} {
    }

    void setFaculty(const string &faculty) { m_faculty = faculty; }
    string getFaculty() const { return m_faculty; }

    void setGroup(const string &group) { m_group = group; }
    string getGroup() const { return m_group; }

    void setMarks(const vector<Mark> &marks) { m_marks = marks; }
    vector<Mark> getMarks() const { return m_marks; }

    void outputInfoIntoConsole() const {
        cout << "Student information: " << endl;
        cout << "* Name: " << m_name << endl;
        cout << "* Surname: " << m_surname << endl;
        cout << "* Patronymic: " << m_patronymic << endl;
        cout << "* Faculty: " << m_faculty << endl;
        cout << "* Group: " << m_group << endl;
        cout << "Marks: " << endl;
        for (const Mark& element : m_marks) {
            element.outputInfoIntoConsole();
        }
    }

private:
    string m_faculty;
    string m_group;
    std::vector<Mark> m_marks;
};
#pragma endregion


int main() {
    Teacher teacher{"Petrov", "Petrovich", "Shishkin", "C++ programming"};
    Teacher teacher2{"Anna", "Petrovna", "Kornikovna", "Biology"};
    Date date{4, 12, 2025};
    Date date2{2, 20, 2025};
    vector<Mark> marks;
    Mark mark{teacher, date, teacher.getDiscipline(), 5};
    Mark mark2{teacher2, date2, teacher2.getDiscipline(), 4};
    marks.push_back(mark);
    marks.push_back(mark2);
    Student student{"Oleg", "Olegovich", "Petrovich", "Software development", "SD1", marks};
    student.outputInfoIntoConsole();
}