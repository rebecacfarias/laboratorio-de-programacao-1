#include <stdio.h>
#include <windows.h> //para usar a funcao sleep
#include <math.h>
int main(void) {
  char opcao;
//o primeiro laço permite que o usuário possa escolher diferentes operações na mesma execução do programa
do{
  system("cls");
  setbuf(stdin,NULL); //limpando o buffer para o getchar no final do laço
  printf("\n\t LAB1 - REBECA FARIAS");
  putchar('\n');
  //laço para obter uma opcao valida
  do{
    printf("\n\t 1. Sequencia de Fibonacci \n\t 2. Sequencia de termos \n\t 3. Operacoes aritmetica \n\t 4. Dobras \n\t 5. Sair do programa\n");
    printf("\n\t-> ");
    scanf("%c",&opcao);
    setbuf(stdin,NULL);
  }while(opcao!='1'&&opcao!='2'&&opcao!='3'&&opcao!='4'&&opcao!='5');
  //instruções para melhor exibição na tela
  Sleep(150);
  system("cls");
  //inicio de testes para a opcao escolhida
  if(opcao == '1'){
    int num,a,b=1,aux = 0; //b inicia com 1 para dar início à soma
    printf("\n\t SEQUENCIA DE FIBONACCI");
    printf("\n\t Digite um numero: ");
    scanf("%d",&num);
    putchar('\t');
    while(1){
        printf("%d ",aux);
        a = b; //numero anterior recebe o proximo na sequencia
        b = aux; //b recebe a variavel auxiliar, que é o seu sucessor na sequencia
        aux=a+b; //a auxiliar recebe a soma dos termos anteriores e gera o novo termo
        if(num<aux){ //teste para checar se a auxiliar ja ultrapassou o valor de entrada
            printf("%d ",aux); //exibe o primeiro maior que o valor de entrada
            break; //finaliza
        }
    }
  }else
    if(opcao=='2'){
        int n;
        printf("\n\t SEQUENCIA DE TERMOS ");
        printf("\n\t Digite um numero: ");
        scanf("%d",&n);
        putchar('\t');
        while(1){ //feito com laço infinito para que seja realizado mesmo que o usuario digite 1

          if(n%2==0)
            n = n/2;
          else
            n = 3*n+1;
          printf(" %d ",n);
          if(n<=1) //a condiçao de parada tem que ser <=1 para que não entre em loop infinito com valores negativos e zero
            break;
          printf("->");
        }
    }else
      if(opcao=='3'){
        float n1,n2; //result é inicializado com zero para o caso de operação inválida
        char op;
        printf("\n\tOPERACOES ARITMETICA");
        printf("\n\tDigite uma operacao entre dois numeros: ");
        scanf("%f %c %f",&n1,&op,&n2);
        setbuf(stdin,NULL);
        if((op=='/'||op==':')&& n2==0){  //testa a divisão invalida
            printf("\n\t OPERACAO INVALIDA,DIVISAO POR ZERO");
        }else{
        switch(op){
            case'+': printf("\n\t %.1f %c %.1f = %.1f",n1,op,n2,n1+n2);break;
            case'-': printf("\n\t %.1f %c %.1f = %.1f",n1,op,n2,n1-n2);break;
            case'*':
            case'x': printf("\n\t %.1f %c %.1f = %.1f",n1,op,n2,n1*n2);break;
            case'/':
            case':': printf("\n\t %.1f %c %.1f = %.1f",n1,op,n2,n1/n2);break;
            default: printf("\n\t OPERADOR INVALIDO");
        }
        }
      }else
        if(opcao=='4'){
          int n,p;
          printf("\n\t Numero de dobraduras: ");
          scanf("%d",&n);
          if(n<0) //testa valores negativos
            printf("\n\tFIM DE OPERACAO");
          else{
          //o numero de pedaços é igual ao quadrado de 2 elevado a n(numero de dobraduras) e acrescentando 1;
            p = (1+pow(2,n))*(1+pow(2,n));
            printf("\n\tPEDACOS: %d",p);
          }
      }else
        if(opcao=='5')
            break;
 //fim de testes para opcao escolhida
 //getchar para realizar outra operaçao
 printf("\n\n\tpressione qualquer tecla para voltar ao menu");
 setbuf(stdin,NULL);
 getchar();
}while(opcao!='5');
  return 0;
}
