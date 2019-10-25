#include <stdio.h>
#include <ctype.h>  //para usar  toupper()
#include <windows.h> //para usar  system("cls")
#define LIM 20


//funcao para ler imagem
void ler_imagem(char imagem[LIM][LIM],int x,int y){
   printf("\n\tIMAGEM: \n");
   for(int i = 0;i<x;i++){
    putchar('\t');
    for(int j = 0;j<y;j++){
        scanf(" %c",&imagem[i][j]);
        imagem[i][j] = toupper(imagem[i][j]);

    }
   }
}

//funcao para exibir imagem
void exibir(char imagem[LIM][LIM],int x,int y){
    for(int i = 0; i<x;i++){
        putchar('\n');
        putchar('\t');
        for(int j = 0; j<y; j++){
        printf("%c ",imagem[i][j]);
        }

    }
}

//funcao para igualar vetor auxiliar com a imagem, sera util para ir atualizando os elementos
void igualar_vetores(char vetor1[LIM][LIM],char vetor2[LIM][LIM],int x,int y){
    for(int i = 0;i<x;i++){
        for(int j=0;j<y;j++){
            vetor1[i][j] = vetor2[i][j];
        }
    }
}

//funcao para fazer movimentacoes
void movimentos(char imagem[LIM][LIM],char aux[LIM][LIM],int x,int y,int v,int h){
    // declaração de vetor auxiliar

    int i,j;

  //PRIMEIRO MODIFICAÇOES VERTICAIS POSITIVAS, OU SEJA, AS LINHAS SOBEM
    if(v>0){
    for( i = 0;i<y;i++){
            for( j = 0;j<v;j++){
                for(int k=x-1;k>=0;k--){
                 if(k==(x-1)){ //teste para não exceder o limite, o último elemento recebe o que era o primeiro;
                    imagem[k][i] = aux[0][i];
                }
                 else{
                    imagem[k][i] = aux[k+1][i];
                }
             }
               igualar_vetores(aux,imagem,x,y); //atualiza auxiliar
            }
        }

    } else
    //AGORA MODIFICAÇÕES NEGATIVAS, AS LINHAS DESCEM
        if(v<0){
            for( i = 0;i<y;i++){
            for( j = v;j<0;j++){
                for(int k=x-1;k>=0;k--){
                 if(k==0){ //teste para não exceder limite, dessa vez o primeiro elemento recebe o que seria o último
                    imagem[k][i] = aux[x-1][i];
                }
                 else{
                    imagem[k][i] = aux[k-1][i];
                }

               }
               igualar_vetores(aux,imagem,x,y);
            }
          }
        }

 //AGORA MODIFICAÇÕES HORIZONTAIS POSITIVAS,OU SEJA, ELEMENTOS ANDAM PARA A DIREITA
   if(h<0){
     for (i = 0;i<x;i++){
        for(j = h;j<0;j++){
            for(int k=y-1;k>=0;k--){
                if(k==(y-1)){ //o último recebe o que seria o primeiro
                    imagem[i][k] = aux[i][0];
                }
                else{
                    imagem[i][k] = aux[i][k+1];
                }
            }
            igualar_vetores(aux,imagem,x,y);
        }
     }
    }else
//POR FIM, MODIFICACOES HORIZONTAIS NEGATIVAS, OS ELEMENTOS SE MOVEM PARA A ESQUERDA
        if(h>0){
        for (i = 0;i<x;i++){
          for(j = 0;j<h;j++){
            for(int k=y-1;k>=0;k--){
                if(k==0){ //o primeiro recebe o que seria o último
                    imagem[i][k] = aux[i][y-1];
                }
                else{
                    imagem[i][k] = aux[i][k-1];
                }
            }
            igualar_vetores(aux,imagem,x,y);
        }
      }
    }
 }
//funcao apenas para exibicao
void linha(){
    printf("\n\t___________________");
}


//-----------------------------------MAIN
int main(){
 int x,y,v,h,somaV,somaH; //VARIAVEIS PARA DIMENSAO(X E Y) E MOVIMENTACOES(V,H,SOMAV,SOMAH)
 char imagem[LIM][LIM],aux[LIM][LIM]; //declaracao da imagem e do vetor auxiliar
 while(1){
    system("cls");  //limpa a tela para outras alterações de imagem
    linha();
    somaV=0,somaH=0; //zerar os somatórios
    //leitura das dimensoes
    do{     //trata dimensoes invalidas
        printf("\n\t DIM DA TV: ");
        scanf("%d %d",&x,&y);
        if(x==0&&y==0)
          break;
    }while(x<=0||y<=0||x>20||y>20);
    if(x==0&&y==0)     //teste para fim de laço
        break;
    //preenchimento da imagem e vetor auxiliar
    ler_imagem(imagem,x,y);
    igualar_vetores(aux,imagem,x,y); //iguala para realizar movimentacoes
    //inicio das movimentações
    printf("\n\tMOVIMENTACOES: \n");
    while(1){
        putchar('\t');
        scanf("%d %d",&v,&h);
        somaV+=v; //somatorio das movimentações
        somaH+=h;
        if(v==0 && h==0) //condição de parada
            break;
    }
    movimentos(imagem,aux,x,y,somaV,somaH);

    //exibição de resultado final
    exibir(imagem,x,y);
    linha();

    printf("\n\n\tpressione qualquer tecla para novo ajuste");
    setbuf(stdin,NULL);
    getchar();

 }

return 0;
}
