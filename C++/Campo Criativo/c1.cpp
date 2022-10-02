#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
    int id;
    string nome;
    int idade;

public:
    Pessoa(int _id, string _nome, int _idade);

    void setNome(string _nome);
    string getNome();

    void setID(int _id);
    int getID();

    void setIdade(int _idade);
    int getIdade();
};

Pessoa::Pessoa(int _id, string _nome, int _idade)
{
    this->id = _id;
    id = _id;
    nome = _nome;
    idade = _idade;
}

void Pessoa::setNome(string _nome)
{
    nome = _nome;
}

void Pessoa::setID(int _id)
{
    id = _id;
}

void Pessoa::setIdade(int _idade)
{
    idade = _idade;
}

string Pessoa::getNome()
{
    return nome;
}

int Pessoa::getID()
{
    return id;
}

int Pessoa::getIdade()
{
    return idade;
}

int main(void)
{

    Pessoa pessoa = Pessoa(1, "Pedro", 30);

    pessoa.getID();
    pessoa.getNome();
    pessoa.getIdade();

    return 0;
}