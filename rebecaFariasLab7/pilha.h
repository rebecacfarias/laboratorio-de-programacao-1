#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct elemento *Pilha;

Pilha *cria_pilha();
void libera_pilha();
int tamanho_pilha(Pilha *pi);
int pilha_vazia(Pilha *pi);
int insere_pilha(Pilha *pi,int disco);
int remove_pilha(Pilha *pi);
int consulta_topo_pilha(Pilha *pi,int *disco);


#endif // PILHA_H_INCLUDED
