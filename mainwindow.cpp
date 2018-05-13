#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "addemployeedialog.hpp"
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDebug>

enum
{
    ID,
    NAME,
    AGE,
    SALARY
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TeQtXMLSample");
    QStringList titles { "Id", "Name", "Age", "Salary" };
    ui->tableWidget->setColumnCount(titles.size());
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    ui->tableWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
    ui->tableWidget->addAction(ui->actionRemove);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addEmployee(Employee employee)
{
    auto id = employee.id();
    const int rowCount = ui->tableWidget->rowCount();
    bool isIdOK = true;
    for(int row = 0; row < rowCount; ++row)
    {
        auto currId = ui->tableWidget->item(row, ID)->text().toInt();
        if(currId == id)
        {
            QMessageBox::critical(this, "Error",
                                  "The employee with Id you typed already exists!");
           isIdOK = false;
           break;
        }
    }

    if(isIdOK)
    {
        ui->tableWidget->insertRow(rowCount);
        ui->tableWidget->setItem(rowCount, ID, new QTableWidgetItem(
                                     QString::number(employee.id())));
        ui->tableWidget->setItem(rowCount, NAME, new QTableWidgetItem(
                                     employee.name()));
        ui->tableWidget->setItem(rowCount, AGE, new QTableWidgetItem(
                                     QString::number(employee.age())));
        ui->tableWidget->setItem(rowCount, SALARY, new QTableWidgetItem(
                                     QString::number(employee.salary())));
    }
}


void MainWindow::on_actionOpen_triggered()
{
    auto dir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)
            .value(0, QDir::homePath());
    auto fileName = QFileDialog::getOpenFileName(this, "Open file...", dir,
                         "XML files (*.xml);;All files (*.*)");

    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QDomDocument doc;
    doc.setContent(&file);
    file.close();
    auto root = doc.firstChild().toElement(); //<Employees></Employees>
    auto it = root.firstChild().toElement(); // First child <Employee></Employee>
    while(!it.isNull())
    {
        auto id = it.attribute("Id").toInt(); //Check int parsing
        auto name = it.firstChild().toElement().text();
        auto age = it.firstChild().nextSiblingElement("Age").text().toInt();
        auto salary = it.firstChild().nextSiblingElement("Salary").text().toDouble();
        addEmployee(Employee(id, name, age, salary));
        it = it.nextSibling().toElement();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    auto dir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)
            .value(0, QDir::homePath());

    auto fileName = QFileDialog::getSaveFileName(this, "Save file...", dir,
                         "XML files (*.xml);;All files (*.*)");

    QDomDocument doc;
    auto root = doc.createElement("Employees");
    doc.appendChild(root);
    const int rowCount = ui->tableWidget->rowCount();
    for(int row = 0; row < rowCount; ++row)
    {
        auto id = ui->tableWidget->item(row, ID)->text().toInt();
        auto name = ui->tableWidget->item(row, NAME)->text();
        auto age = ui->tableWidget->item(row, AGE)->text().toInt();
        auto salary = ui->tableWidget->item(row, SALARY)->text().toDouble();
        Employee employee(id, name, age, salary);
        auto elementEmployee = doc.createElement("Employee");
        elementEmployee.setAttribute("Id", employee.id());
        auto elementName = doc.createElement("Name");
        elementName.appendChild(doc.createTextNode(employee.name()));
        auto elementAge = doc.createElement("Age");
        elementAge.appendChild(doc.createTextNode(QString::number(employee.age())));
        auto elementSalary = doc.createElement("Salary");
        elementSalary.appendChild(doc.createTextNode(QString::number(employee.salary())));
        elementEmployee.appendChild(elementName);
        elementEmployee.appendChild(elementAge);
        elementEmployee.appendChild(elementSalary);
        root.appendChild(elementEmployee);
    }

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }
    QTextStream stream(&file);
    stream << doc.toString();
    file.flush();
    file.close();
}

void MainWindow::on_actionAdd_triggered()
{
    AddEmployeeDialog dialog;
    if(dialog.exec() == AddEmployeeDialog::Rejected)
    {
        return;
    }
    addEmployee(dialog.employee());
}

void MainWindow::on_actionRemove_triggered()
{

    auto currRow = ui->tableWidget->currentRow();
    auto name = ui->tableWidget->item(currRow, NAME);

    auto reply = QMessageBox::question(this, "Confirm deleting, please",
                         /*QString("Do you really want to delete %1?").arg(name),*/
                                       "Do you really want to delete current element?",
                         QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_actionQuit_triggered()
{
    auto reply = QMessageBox::question(this, "Confirm quit, please",
                          "Do you really want to quit?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        this->close();
    }
}
