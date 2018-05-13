#include "addemployeedialog.hpp"
#include "ui_addemployeedialog.h"
#include <QMessageBox>

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
    bool ok;
    auto id = ui->txtID->text().toInt(&ok);
    if(ok)
    {
        mEmployee.setId(id);
        mEmployee.setName(ui->txtName->text());
        mEmployee.setAge(ui->spinnerAge->value());
        mEmployee.setSalary(ui->spinnerSalary->value());
        accept();
    }
    else
    {
        QMessageBox::critical(this, "Error",
                              "The ID must be a numer");
        reject();
    }

}

void AddEmployeeDialog::on_buttonBox_rejected()
{
    reject();
}

Employee AddEmployeeDialog::employee() const
{
    return mEmployee;
}
