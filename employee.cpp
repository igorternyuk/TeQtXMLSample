#include "employee.hpp"

Employee::Employee(int id, const QString &name, int age, double salary):
    mId(id), mName(name), mAge(age), mSalary(salary)
{}

QString Employee::name() const
{
    return mName;
}

void Employee::setName(const QString &name)
{
    mName = name;
}

int Employee::age() const
{
    return mAge;
}

void Employee::setAge(int age)
{
    mAge = age;
}

double Employee::salary() const
{
    return mSalary;
}

void Employee::setSalary(double salary)
{
    mSalary = salary;
}

int Employee::id() const
{
    return mId;
}

void Employee::setId(int id)
{
    mId = id;
}
