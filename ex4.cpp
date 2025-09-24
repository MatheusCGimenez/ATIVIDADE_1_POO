#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Medico {
  string nome;

 public:
  Medico(const string& n) : nome(n) {}
  string getNome() const { return nome; }
};

class Paciente {
  string nome;

 public:
  Paciente(const string& n) : nome(n) {}
  string getNome() const { return nome; }
};

class Prontuario {
  Paciente paciente;  // Agregação
  Medico medico; // Agregação
  vector<string> anotacoes; // Composição

 public:
  Prontuario(const Paciente& p, const Medico& m) : paciente(p), medico(m) {}
  void adicionarAnotacao(const string& a) { anotacoes.push_back(a); }
  void mostrar() const {
    cout << "Prontuário de " << paciente.getNome()
         << " - Médico: " << medico.getNome() << "\n";
    for (auto& a : anotacoes) cout << " * " << a << "\n";
  }
};

int main() {
  Medico m("Dr. Matheus");
  Paciente p("Lucas");
  Prontuario pr(p, m);
  pr.adicionarAnotacao("Consulta inicial");
  pr.adicionarAnotacao("Receitado remésio de inflamação");
  pr.mostrar();
  return 0;
}
