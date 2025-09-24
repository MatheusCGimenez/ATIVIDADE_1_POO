#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Parada {
    string nome;
public:
    Parada(const string& nome) : nome(nome) {}
    string getNome() const { return nome; }
};

class Rota {
    string codigo;
    vector<Parada> paradas; // Composição
public:
    Rota(const string& codigo = "") : codigo(codigo) {}
    
    void adicionarParada(const Parada& parada) {
        paradas.push_back(parada);
    }

    void print() const {
        cout << "    Rota " << codigo << ": ";
        for (const auto& parada : paradas) {
            cout << parada.getNome() << " -> ";
        }
        cout << "Fim" << endl;
    }
};

class Onibus {
    string placa;
    Rota rota; // Composição
public:
    Onibus(const string& placa) : placa(placa) {}

    void definirRota(const Rota& r) {
        rota = r;
    }

    void print() const {
        cout << "- Onibus Placa: " << placa << endl;
        rota.print();
    }
};

class Motorista {
    string nome;
public:
    Motorista(const string& nome) : nome(nome) {}
    string getNome() const { return nome; }
};

class Empresa {
    string nome;
    vector<Onibus> frota;  // Composição
    vector<Motorista*> motoristas; // Agregação
public:
    Empresa(const string& nome) : nome(nome) {}

    void adicionarOnibus(const Onibus& onibus) {
        frota.push_back(onibus);
    }
    
    void contratarMotorista(Motorista* m) {
        motoristas.push_back(m);
    }

    void print() const {
        cout << "Empresa de Transporte: " << nome << endl;
        cout << "\nFrota de Onibus:" << endl;
        for (const auto& onibus : frota) {
            onibus.print();
        }
        cout << "\nMotoristas:" << endl;
        for (const auto* motorista : motoristas) {
            cout << "- " << motorista->getNome() << endl;
        }
    }
};

int main() {

    Motorista m1("Matheus Gimenez");
    Motorista m2("Danilo Silva");

    Rota r1("Centro");
    r1.adicionarParada(Parada("Terminal"));
    r1.adicionarParada(Parada("Praca Central"));
    r1.adicionarParada(Parada("Shopping"));

    Onibus o1("ABC-1234");
    o1.definirRota(r1);
    
    Empresa e("Viacao MOTTA");
    e.contratarMotorista(&m1);
    e.contratarMotorista(&m2);
    e.adicionarOnibus(o1);
    
    e.print();
    
    return 0;
}