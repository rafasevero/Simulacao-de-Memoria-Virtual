#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define TAM_PAGINA_FRAME 16 //offset = 4 bits
#define TAM_MEMORIA_VIRTUAL 256 //endereco de 8 bits
#define TAM_MEMORIA_FISICA 128  // edbereco de 7 bits

#define NUM_PAGINAS (TAM_MEMORIA_VIRTUAL / TAM_PAGINA_FRAME)
#define NUM_FRAMES (TAM_MEMORIA_FISICA / TAM_PAGINA_FRAME)
#define NUM_SEGMENTOS 4

struct EntradaPagina{ // mapeia uma pag virtual para um quadro fisico
    int frame;
    bool estaPresente; //vai indicar se a pagina esta na memoria fisica
};

struct EntradaSegmento{
    int base; //endereco fisico inicial
    int limite;//tamanho maximo
};

std::vector<EntradaPagina> tabelaPagina;//0 a 15
std::vector<EntradaSegmento> tabelaSegmento;//0 a 3

void inicializarTabelas(){ //redimensiona os vetores globais p tamanho correto e preenche essas tabelas com um mapeamento inicial ficticio
    cout << "Configurando tabelas de mapeamento... " << endl;

    tabelaPagina.resize(NUM_PAGINAS);
    cout << "[TABELA DE PAGINAS]: " << NUM_PAGINAS << " entradas criadas " << endl;

    for(int i = 0; i < NUM_PAGINAS; i++){
        tabelaPagina[i] = {-1, false}; //inicializa todas com page fault
    }

    tabelaPagina[0] = {5, true};
    tabelaPagina[1] = {1, true};
    tabelaPagina[7] = {3, true};
    tabelaPagina[10] = {6, true};

    cout << "Mapeamento Paginação: (0->5), (1->1), (7->3), (10->6). o restante está no disco. " << endl;

    tabelaSegmento.resize(NUM_SEGMENTOS);
    cout << "[TABELA DE SEGMENTOS]: " << NUM_SEGMENTOS << " entradas criadas" << endl;

    tabelaSegmento[0] = {16, 64}; //seg 0: base = 16, tamanho = 64 , vai até 16+64-1 = 79
    tabelaSegmento[1] = {80, 32};
    tabelaSegmento[2] = {112, 16};
    tabelaSegmento[3] = {0, 0}; //seg 3: nao alocou
    
cout << "Mapeamento Segmentação: Seg 0 (Base 16, Limite 64), Seg 1 (Base 80, Limite 32)..." << endl;
}



