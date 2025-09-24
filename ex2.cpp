#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Musica {
    string titulo;
    string artista;
public:
    Musica(const string& titulo, const string& artista)
        : titulo(titulo), artista(artista) {}

    void print() const {
        cout << "  - " << titulo << " por " << artista << endl;
    }
};

class Playlist {
    string nome;
    vector<Musica*> musicas;  // Agregação
public:
    Playlist(const string& nome) : nome(nome) {}

    void adicionarMusica(Musica* musica) {
        musicas.push_back(musica);
    }

    void listarMusicas() const {
        cout << "- Playlist: " << nome << endl;
        for (const auto* musica : musicas) {
            musica->print();
        }
    }
};

class Usuario {
    string nome;
    vector<Playlist> playlists;  // Composição
public:
    Usuario(const string& nome) : nome(nome) {}

    void criarPlaylist(const Playlist& playlist) {
        playlists.push_back(playlist);
    }

    void listarPlaylists() const {
        cout << "Playlists do user " << nome << ":" << endl;
        for (const auto& playlist : playlists) {
            playlist.listarMusicas();
        }
    }
};

int main() {
    
    Musica m1("musica 1", "artista 1");
    Musica m2("musica 2", "artista 2");
    Musica m3("musica 3", "artista 3");

    Usuario user("Matheus");
    
    Playlist rock("Rock Classico");
    rock.adicionarMusica(&m1);
    rock.adicionarMusica(&m2);

    Playlist grunge("Grunge");
    grunge.adicionarMusica(&m3);

    user.criarPlaylist(rock);
    user.criarPlaylist(grunge);

    user.listarPlaylists();
    
    return 0;
}