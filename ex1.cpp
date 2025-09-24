#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Livro {
    string titulo{}, autor{};
    int ano{};

public:
    Livro(const string& t, const string& a, int y) : titulo(t), autor(a), ano(y) {}
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getAno() const { return ano; }
};

class Biblioteca {
    string nome;
    vector<Livro> acervo; // Composição
    
public:
    Biblioteca(const string& n) : nome(n) {}
    void adicionarLivro(const Livro& l) { acervo.push_back(l); }
    void listar() const {
        cout << "Acervo da biblioteca " << nome << ":\n";
        for (auto& l : acervo)
            cout << l.getTitulo() << " - " << l.getAutor() << " (" << l.getAno() << ")\n";
    }
};

int main() {
    Biblioteca b("Central");
    Livro l1("POO IFMS", "Matheus Gimenez", 2025);
    Livro l2("Dados IFMS", "GMNZ", 2025);
    b.adicionarLivro(l1);
    b.adicionarLivro(l2);
    b.listar();
    return 0;
}
