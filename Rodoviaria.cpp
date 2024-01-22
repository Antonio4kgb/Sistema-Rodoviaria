#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

struct Passageiro
{
    int id;
    string nome;
    string CPF;
};

struct Onibus
{
    Passageiro* passageiros;
    string origem;
    string destino;
    int capacidade;
    int quantidade;
};

void Cadastro (Onibus& onibus){
    Passageiro novoPassageiro;
    string valorString;

    cin.clear();
    cout << "Digite o nome do passageiro: " << endl;
    cin >> novoPassageiro.nome;

    cout << "Digite o CPF do passageiro" << endl;
    cin >> valorString;
    novoPassageiro.CPF = valorString;

    srand(static_cast<unsigned>(time(nullptr)));
    mt19937 rng(rand());

    uniform_int_distribution<int> distribuicao(1, onibus.capacidade);

    novoPassageiro.id = distribuicao(rng);

    onibus.passageiros[onibus.quantidade] = novoPassageiro;
    onibus.quantidade++;

    cout << "Passageiro cadastrado na viagem" << endl;
}

void VisualizarPassageiros(const Onibus& onibus){

    cout << "" << endl;
    cout << "Origem: " << onibus.origem << "Destino: " << onibus.destino << "." << endl;
    cout << "Lista de passageiros: " << endl;
    cout << "\r" << flush;

    for (int i = 0; i < onibus.quantidade; i++)
    {
        cout << "Nome: " << onibus.passageiros[i].nome
        << "CPF: " << onibus.passageiros[i].CPF
        << "Cadeira: " << onibus.passageiros[i].id
        << ". " << endl;
    }
}

int main()
{
    Onibus nossoBuzu;
    bool executar = true;
    int limite;
    int escolha;

    cout << "Digite a origem da viagem: ";
    getline(cin, nossoBuzu.origem);
    cout << "Digite o destino da viagem: ";
    getline(cin, nossoBuzu.destino);

    cout << "\r" << flush;

    cout << "Digite a capacidade do onibus: ";
    cin >> nossoBuzu.capacidade;

    nossoBuzu.quantidade = 0;
    limite = nossoBuzu.quantidade;
    
    nossoBuzu.passageiros = new Passageiro[nossoBuzu.capacidade];

    do
    {
        Cadastro(nossoBuzu);
        limite++;

        if (nossoBuzu.quantidade < nossoBuzu.capacidade)
        {
            cout << "Deseja continuar a vender passagens? 0 - Sim ou 1 - Nao: ";
            cin >> escolha;
            if (escolha == 0)
            {
                executar = true;
            }else
            {
                executar = false;
            }
        }else
        {
            executar = false;
        }
    } while (executar);

    VisualizarPassageiros(nossoBuzu);

    delete[] nossoBuzu.passageiros;

    return 0;
    
}