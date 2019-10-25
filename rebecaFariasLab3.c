#include <stdio.h>
#include <string.h>
#include <windows.h>




//FUN��O PARA PREENCHER DICIONARIO COM PALAVRA-SIGNIFICADO NO MESMO INDICE
void preenche_dicionario(int d,char palavras[100][30],char significado[100][30]){
    for(int i = 0;i<d;i++){
        setbuf(stdin,NULL);
        printf("palavra: ");
        gets(palavras[i]);
        setbuf(stdin,NULL);
        printf("significado: ");
        gets(significado[i]);
    }
}

//FUN��O PARA LER A MENSAGEM
void ler_mensagem(int n,char mensagem[100][60]){
    printf("\nMENSAGEM\n");
    for(int i = 0;i<n;i++){
        setbuf(stdin,NULL);
        gets(mensagem[i]);
    }
}

//FUN��O PARA TRADUZIR A MENSAGEM
void traducao(int n, int d,char mensagem[100][60],char traduzida[100][60],char palavras[100][30],char significado[100][30]){
   int i,j,k,l,teste = 0; //teste inicia com zero e muda caso encontre uma palavra do dicionario
   char caractere[1]; //para guardar os caracteres que nao formam palavras do dicionario

    //PRIMEIRO LA�O PERCORRE CADA LINHA DA MENSAGEM
    for(i = 0;i<n;i++){
        // SEGUNDO LA�O PERCORRE CADA CARACTERE
      for(k=0;k<strlen(mensagem[i]);k++){
       /*
       L�GICA DA TRADU��O:
       checa se a letra atual � igual a 1� da palavra em palavras[j],
       que pertence ao dicionario,
       se for igual,variavel teste recebe 1, faz la�o que conta se as letras seguintes
       tb sao iguais(se encontrar uma diferente,la�o recece zero novamente e break),
        Se  teste for 1 no final, concatena o significado � tradu��o
        e incrementa o len da palavra encontrara ao k para seguir aos prox caracteres
       se a 1� n�o for igual, concatena o caractere atual do jeito que t�;
       */
       //la�o que procura cada uma das palavras
      for(j = 0;j<d;j++){
       teste = 0;
       if(mensagem[i][k] == palavras[j][0]){ //testa se a  letra � igual a 1� da palavra
         teste = 1;
         //checa se as demais letras tamb�m s�o
         for( l = 0; l<strlen(palavras[j]); l++){
            if(k+l>strlen(mensagem[i])) //testa se nao vai extrapolar o tamanho da mensagem
                break;
            if(mensagem[i][k+l] != palavras[j][l]){ //se uma for diferente, teste volta a ser zero
                teste = 0;
                break;
            }
         }
        }
        else{
            continue; //se nao for igual, continua para ver se encontra a proxima palavra do dicionario
        }

        if(teste){ //se teste for 1, concatena o significado
            strcat(traduzida[i],significado[j]);
            k+=strlen(palavras[j]); //incrementa k
        }

      }

         caractere[0] = mensagem[i][k]; //atualiza a string caractere para poder concatenar
         strcat(traduzida[i],caractere); //concatena o caractere


    }
   }

}

//IMPRESSAO DA TRADU��O
void imprime_traduzida(int n, char traduzida[100][60]){
    printf("TRADUCAO: \n");
    for(int i = 0;i<n;i++){
        puts(traduzida[i]);
    }
}

main(){
    //void traducao(int n, int d,char mensagem[100][60],
    //char traduzida[100][60],char palavras[100][30],
    //char significado[100][30])
    int i,j;
    printf("INSTANCIAS:");
    scanf("%d",&i);
//la�o para instancias
   for(j = 0;j<i;j++){
    system("cls");
    //declaracao e inicializacao
    int n, d;
    char mensagem[100][60] = {" "}, traduzida[100][60]={" "},palavras[100][30] = {" "}, significado[100][30] = {" "};
    //LEITURAS
    printf("numero de palavras: ");
    scanf("%d",&d);

    preenche_dicionario(d,palavras,significado);

    printf("numero de linhas da mensagem: ");
    scanf("%d",&n);
    ler_mensagem(n,mensagem);

    traducao(n,d,mensagem,traduzida,palavras,significado);
    imprime_traduzida(n,traduzida);
    //continua para pr�xima instancia ou para finalizar
    printf("\n \npressione qualquer tecla para continuar");
    getchar();
   }
}
