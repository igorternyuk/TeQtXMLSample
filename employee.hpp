#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

class Employee
{
public:
    explicit Employee(int id = 0, const QString &name = "Ivan Ivanov",
                      int age = 30, double salary = 3200.0);
    QString name() const;
    void setName(const QString &name);
    int age() const;
    void setAge(int age);
    double salary() const;
    void setSalary(double salary);
    int id() const;
    void setId(int id);

private:
    int mId;
    QString mName;
    int mAge;
    double mSalary;
};

#endif // EMPLOYEE_H
