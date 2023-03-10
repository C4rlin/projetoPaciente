#include "paciente.h"

namespace ce{

QString Paciente::getNomeCompleto() const
{
    return nomeCompleto;
}

void Paciente::setNomeCompleto(const QString &newNomeCompleto)
{
    nomeCompleto = newNomeCompleto;
}

int Paciente::getPeso() const
{
    return peso;
}

void Paciente::setPeso(int newPeso)
{
    if(newPeso <= 0) throw QString("O peso nao pode ser <= 0");

    peso = newPeso;
}

float Paciente::getAltura() const
{
    return altura;
}

void Paciente::setAltura(float newAltura)
{
    if(newAltura <= 0) throw QString("A altura nao pode ser <= 0");

    altura = newAltura;
}

QString Paciente::getSexo() const
{
    return sexo;
}

void Paciente::setSexo(const QString &newSexo)
{
    sexo = newSexo;
}

Paciente::Paciente():
    nomeCompleto(""),
    peso(0),
    altura(0),
    sexo("")

{

}

Paciente::Paciente(QString nomeCompleto, int peso, float altura, QString sexo):
    nomeCompleto(""),
    peso(0),
    altura(0),
    sexo("")

{;
    this->nomeCompleto = nomeCompleto;
    if(peso <= 0) throw QString("Peso nao pode ser <=0");
    this->peso = peso;
    if(altura <=0) throw QString("Altura nao pode ser <=0");
    this->altura = altura;
    this->sexo = sexo;
}

float Paciente::calcularIMC() const{

    return (peso/(altura*altura));

}

QString Paciente::calcularFaixaDeRisco() const{

    float imc = calcularIMC();

    if(imc <= 20) return "Abaixo do peso ideal";
    if(imc <= 25) return "Peso ideal";
    if(imc <= 30) return "Exesso de peso";
    if(imc <= 35) return "Obesidade";
    return "Obesidade morbida";

}

float Paciente::calcularPesoIdeal() const{

    if(sexo == "MASCULINO") return 72.7 * altura - 58;
    else return 62.1 * altura - 44.7;

}




}
