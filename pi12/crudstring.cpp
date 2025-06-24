#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Livro {
    int id;
    string titulo;
    string autor;
    int ano;
};

vector<Livro> biblioteca;

void criarLivro() {
    Livro l;
    cout << "ID do Livro: ";
    cin >> l.id;
    cin.ignore();

    cout << "Título: ";
    getline(cin, l.titulo);

    cout << "Autor: ";
    getline(cin, l.autor);

    cout << "Ano de Publicação: ";
    cin >> l.ano;
    cin.ignore();

    biblioteca.push_back(l);
    cout << "Livro adicionado com sucesso!\n";
}

void listarLivros() {
    cout << "\n--- Lista de Livros ---\n";
    for (auto& l : biblioteca) {
        cout << "ID: " << l.id 
             << " | Título: " << l.titulo 
             << " | Autor: " << l.autor 
             << " | Ano: " << l.ano << endl;
    }
}

void atualizarLivro() {
    int id;
    cout << "ID do livro a atualizar: ";
    cin >> id;
    cin.ignore();

    for (auto& l : biblioteca) {
        if (l.id == id) {
            cout << "Novo título: ";
            getline(cin, l.titulo);
            cout << "Novo autor: ";
            getline(cin, l.autor);
            cout << "Novo ano de publicação: ";
            cin >> l.ano;
            cin.ignore();
            cout << "Livro atualizado com sucesso!\n";
            return;
        }
    }
    cout << "Livro não encontrado.\n";
}

void deletarLivro() {
    int id;
    cout << "ID do livro a deletar: ";
    cin >> id;

    for (auto it = biblioteca.begin(); it != biblioteca.end(); ++it) {
        if (it->id == id) {
            biblioteca.erase(it);
            cout << "Livro removido da biblioteca.\n";
            return;
        }
    }
    cout << "Livro não encontrado.\n";
}

int main() {
    int opcao;
    do {
        cout << "\n===== Menu de Gestão da Biblioteca =====\n";
        cout << "1. Adicionar Livro\n";
        cout << "2. Listar Livros\n";
        cout << "3. Atualizar Livro\n";
        cout << "4. Remover Livro\n";
        cout << "0. Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: criarLivro(); break;
            case 2: listarLivros(); break;
            case 3: atualizarLivro(); break;
            case 4: deletarLivro(); break;
            case 0: cout << "Saindo do sistema...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    return 0;
}

