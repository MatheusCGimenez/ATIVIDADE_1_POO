#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Aluno {
    string nome;
public:
    Aluno(const string& nome) : nome(nome) {}
    string getNome() const { return nome; }
};

class Professor {
    string nome;
public:
    Professor(const string& nome) : nome(nome) {}
    string getNome() const { return nome; }
};

class Turma {
    string codigo; 
    Professor* professor; // Agregação
    vector<Aluno*> alunos; // Agregação
public:
    Turma(const string& cod, Professor* p) : codigo(cod), professor(p) {}

    void matricularAluno(Aluno* aluno) {
        alunos.push_back(aluno);
    }

    void print() const {
        cout << "- Turma: " << codigo << " (Prof. " << professor->getNome() << ")" << endl;
        cout << "  Alunos Matriculados:" << endl;
        for (const auto* aluno : alunos) {
            cout << "    - " << aluno->getNome() << endl;
        }
    }
};

class Curso {
    string nome;
    vector<Turma> turmas; // Composição
public:
    Curso(const string& nome) : nome(nome) {}

    void adicionarTurma(const Turma& turma) {
        turmas.push_back(turma);
    }

    void listarTurmas() const {
        cout << "Curso de " << nome << ":" << endl;
        for (const auto& turma : turmas) {
            turma.print();
        }
    }
};

int main() {
    
    Professor prof1("Matheus");
    Aluno aluno1("Ana");
    Aluno aluno2("Beto");
    Aluno aluno3("Carla");

    Curso cursoEC("Engenharia de Computacao");
    
    Turma turmaPOO("POO2025", &prof1);
    turmaPOO.matricularAluno(&aluno1);
    turmaPOO.matricularAluno(&aluno2);
    
    Turma turmaED("ED2025", &prof1);
    turmaED.matricularAluno(&aluno2);
    turmaED.matricularAluno(&aluno3);

    cursoEC.adicionarTurma(turmaPOO);
    cursoEC.adicionarTurma(turmaED);

    cursoEC.listarTurmas();

    return 0;
}