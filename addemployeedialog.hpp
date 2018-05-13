#ifndef ADDEMPLOYEEDIALOG_HPP
#define ADDEMPLOYEEDIALOG_HPP

#include <QDialog>
#include "employee.hpp"

namespace Ui
{
    class AddEmployeeDialog;
}

class AddEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployeeDialog(QWidget *parent = nullptr);
    ~AddEmployeeDialog();
    Employee employee() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddEmployeeDialog *ui;
    Employee mEmployee;
};

#endif // ADDEMPLOYEEDIALOG_HPP
