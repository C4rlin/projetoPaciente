#ifndef PACIENTE_H
#define PACIENTE_H
#include <QString>

namespace ce{

class Paciente
{
    //Atributos

private:

    QString nomeCompleto;
    int peso;
    float altura;
    QString sexo;

    //Metodos

public:
    Paciente();
    Paciente(QString nomeCompleto, int peso, float altura, QString sexo);
    float calcularIMC() const;
    QString calcularFaixaDeRisco() const;
    float calcularPesoIdeal() const;


    QString getNomeCompleto() const;
    void setNomeCompleto(const QString &newNomeCompleto);
    int getPeso() const;
    void setPeso(int newPeso);
    float getAltura() const;
    void setAltura(float newAltura);
    QString getSexo() const;
    void setSexo(const QString &newSexo);
};

}
#endif // PACIENTE_H
