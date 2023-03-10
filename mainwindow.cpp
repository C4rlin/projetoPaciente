#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonExecutar_clicked()
{
    try {
        // comandos a serem monitorados

        ce::Paciente pessoa;

        pessoa.setNomeCompleto(ui->lineEditNome->text());
        pessoa.setPeso(ui->lineEditPeso->text().toFloat());
        pessoa.setAltura(ui->lineEditAltura->text().toFloat());
        pessoa.setSexo(ui->comboBoxSexo->currentText());

        //concatenação de String

        QString saida = "CLINICA GYN\n\n";
        saida += "DADOS DO PACIENTE\n";
        saida += "NOME COMPLETO: " + pessoa.getNomeCompleto() + "\n";
        saida += "PESO: " + QString::number(pessoa.getPeso()) + "\n";
        saida += "ALTURA: " + QString::number(pessoa.getAltura()) + "\n";
        saida += "SEXO: " + pessoa.getSexo() + "\n";
        saida += "IMC = " + QString::number(pessoa.calcularIMC()) + "\n";
        saida += "FAIXA DE RISCO = " + pessoa.calcularFaixaDeRisco() + "\n";
        saida += "PESO IDEAL = " + QString::number(pessoa.calcularPesoIdeal()) + "\n";

        ui->textEditSaida->setText(saida);
        ui->lineEditNome->clear();
        ui->lineEditPeso->clear();
        ui->lineEditAltura->clear();


    } catch (QString &erro) {
        // comando de solução

        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }

}

