#include "addemployeedialog.hpp"
#include "ui_addemployeedialog.h"

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployeeDialog)
{
    ui->setupUi(this);
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

void AddEmployeeDialog::on_buttonBox_accepted()
{
    mEmployee.setName(ui->txtName->text());
    mEmployee.setAge(ui->spinnerAge->value());
    mEmployee.setSalary(ui->spinnerSalary->value());
    accept();
}

void AddEmployeeDialog::on_buttonBox_rejected()
{
    reject();
}

Employee AddEmployeeDialog::employee() const
{
    return mEmployee;
}
