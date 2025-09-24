#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produto {
    string nome;
    double preco;
public:
    Produto(const string& n, double p) : nome(n), preco(p) {}
    double getPreco() const { return preco; }
    string getNome() const { return nome; }
};

class Item {
    Produto produto; // Agregação
    int quantidade;
public:
    Item(const Produto& p, int q) : produto(p), quantidade(q) {}
    double getSubtotal() const { return produto.getPreco() * quantidade; }
    string getInfo() const { return produto.getNome() + " x" + to_string(quantidade); }
};

class Cliente {
    string nome;
public:
    Cliente(const string& n) : nome(n) {}
    string getNome() const { return nome; }
};

class Pedido {
    Cliente cliente; // Agregação
    vector<Item> itens; // Composição
public:
    Pedido(const Cliente& c) : cliente(c) {}
    void adicionarItem(const Item& i) { itens.push_back(i); }
    void listar() const {
        cout << "Pedido do cliente " << cliente.getNome() << ":\n";
        double total = 0;
        for (auto& i : itens) {
            cout << " - " << i.getInfo() << " = R$ " << i.getSubtotal() << "\n";
            total += i.getSubtotal();
        }
        cout << "Total: R$ " << total << "\n";
    }
};

int main() {
    Cliente c("Ana");
    Pedido p(c);
    Produto prod1("Notebook", 3500);
    Produto prod2("Mouse", 80);
    p.adicionarItem(Item(prod1, 1));
    p.adicionarItem(Item(prod2, 2));
    p.listar();
    return 0;
}
