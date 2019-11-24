#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <math.h>
#include <windows.h>

//INICIA O PRIMEIRO PINO
void insere_discos(Pilha *pino1,int t,int vetor[3][8]){
    for(int i = t;i>0;i--){
        insere_pilha(pino1,i);
        vetor[0][i-1]=i; //vetor de visualiza��o do primeiro pino
    }
}

//REALIZA MOVIMENTACOES NOS PINOS
int movimentacoes(Pilha *pilhas[3],int t,int vetores[3][8]){ //recebe um vetor com os pinos, o numero de discos e os vetores de visualizacao dos pinos
    int cont = 0,i,j; //
    int d,p,d2,pinoaux; //d receber� o topo, d2 � para testar se o disco que est� no pino � maior que o que ser� inserido. p � o pino, pinoaux � o auxiliar

    do{
      cont++; //conta as jogadas
      Sleep(200);
      system("cls");
      //MOSTRA A SITUA��O ATUAL DOS PINOS (SIMULA��O DOS PINOS ATRAV�S DE VETORES)
      for(i = 0;i<3;i++){
        printf("\t\tPINO %d\n",i+1);
        //cada linha da matriz simula os discos de cada pino: se nao estiver zerado, exibe;
        for(j = 0;j<8;j++){
           if(vetores[i][j])
            printf("\t\t%d\n",vetores[i][j]);
        }
        printf("\t\t_\n");
      }
      //PRIMEIRA JOGADA
      if(cont == 1){
        consulta_topo_pilha(pilhas[0],&d);
        vetores[0][d-1] = 0;
        remove_pilha(pilhas[0]);
        do{
           printf("Mover %d para qual pino?(2 ou 3) (digite 0 para desistir)-> ",d);
           scanf("%d",&p);
        }while(p!=2 && p!=3 && p!= 0);
        if(p==0)
            return 0;
        insere_pilha(pilhas[p-1],d);
        vetores[p-1][d-1] = d;
      }
      //DEMAIS JOGADAS
      else {
        do{
          printf("Deseja mover de qual pino?(1,2,3) (digite 0 para desistir)->");
          scanf("%d",&p);
        }while(p!=2 && p!=3 && p!= 0 && p!= 1);
        if(p==0)
            return 0;
        if(pilha_vazia(pilhas[p-1])){ //checa se o pino est� vazio, se tiver n�o h� como mover discos
            printf("Esse pino esta vazio!");
            continue;
        }
        consulta_topo_pilha(pilhas[p-1],&d); //pega o topo
        pinoaux = p-1;

        do{
          printf("Deseja mover para qual pino?(1,2,3) -> ");
          scanf("%d",&p);
        }while(p!=2 && p!=3 && p!= 1);
        if(pilha_vazia(pilhas[p-1])){  //inser��o para pino vazio
            vetores[pinoaux][d-1] = 0; //zera o valor correspondente no vetor de visualiza��o
            remove_pilha(pilhas[pinoaux]); //remove o disco do topo
            insere_pilha(pilhas[p-1],d); //insere no pino escolhido
            vetores[p-1][d-1] = d; //atualiza vetor de visualiza��o
        }
        else{
          consulta_topo_pilha(pilhas[p-1],&d2);
          if(d2>d){ //se nao estiver vazia, testa se o disco do topo � maior que o disco q ser� inserido
            vetores[pinoaux][d-1] = 0;
            remove_pilha(pilhas[pinoaux]);
            insere_pilha(pilhas[p-1],d);
            vetores[p-1][d-1] = d;
          }
          else{
            printf("Movimento invalido! O disco eh maior!\n");
          }
        }

      }

    }while(tamanho_pilha(pilhas[2])!=t); //se o tamanho do terceiro pino for igual ao numero de discos, finaliza o jogo

    //libera pilhas
    for(i = 0;i<3;i++){
        libera_pilha(pilhas[i]);
    }

    Sleep(200);
    system("cls");
    //MOSTRA RESULTADO FINAL
    for(i = 0;i<3;i++){
        printf("\t\tPINO %d\n",i+1);
       for(j = 0;j<8;j++){
           if(vetores[i][j])
            printf("\t\t%d\n",vetores[i][j]);
        }
        printf("\t\t_\n");
      }
    printf("\n JOGADAS: %d",cont);
    return 1;
}

int main()
{

    int t,jogadas;
    //CRIA PILHAS;
    Pilha *pino1,*pino2,*pino3;
    pino1 = cria_pilha();
    pino2 = cria_pilha();
    pino3 = cria_pilha();

    Pilha *vetor[3] = {pino1,pino2,pino3};
    //PEDE T
    do{
    printf("QUANTIDADE DE DISCOS(entre 3 e 8): ");
    scanf("%d",&t);
    }while(t>8 || t<3);
    jogadas = pow(2,t)-1;
    printf("QUANTIDADE MINIMA DE JOGADAS NECESSARIAS: %d\n",jogadas);
    //INICIALIZANDO VETORES DE VISUALIZA��O (PARA SIMULAR OS ELEMENTOS DA PILHA)
    int vetores[3][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    insere_discos(vetor[0],t,vetores);
    printf("\nPRESSIONE QUALQUER TECLA PARA INICIAR O JOGO");
    setbuf(stdin,NULL);
    getchar();
    //CHAMA MOVIMENTA��ES E MOSTRA MENSAGEM FINAL
    if(movimentacoes(vetor,t,vetores)){
       printf("\n VOCE CONSEGUIU! \n");
       }
    return 0;
}
