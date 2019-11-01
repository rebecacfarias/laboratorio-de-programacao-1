#include <stdio.h>
#include <string.h>
#define alunos 20 //constante p o numero de alunos

//lê as notas, calcula a média e retorna APROVADO ou REPROVADO;
char *alunoSituacao(char nome[16]){
    int i;
    float nota,media=0;
    for(i = 1;i<=4;i++){
        printf("> NOTA %d DE %s: ",i,nome);
        scanf("%f",&nota);
        //laço pra checar se a nota é válida
        while(nota<0||nota>10){
            printf("NOTA INVALIDA,DIGITE NOVAMENTE\n");
            printf("> NOTA %d DE %s: ",i,nome);
            scanf("%f",&nota);
        }
        media+=nota;
    }

    media = media/4;
    printf("> MEDIA DE %s: %.2f\n",nome,media);
    putchar('\n');
    if(media>=7)
      return "APROVADO";
    else
      return "REPROVADO";
}

//preenche o vetor com o nome do aluno no indice 0 e a situacao no indice 1
void nomesAlunos(char n[][2][16]){
    int i;
    putchar('\n');
    for(i = 0;i<alunos;i++){
        printf("NOME: ");
        setbuf(stdin,NULL);
        gets(n[i][0]);
        strupr(n[i][0]);
        strcpy(n[i][1],alunoSituacao(n[i][0]));
    }
}

//exibe a situacao de todos os alunos
void mostrar(char n[][2][16]){
    int i;
    putchar('\n');
    printf(">>>>>SITUACAO FINAL<<<<<");
    for(i=0;i<alunos;i++){
        printf("\n%s - %s",n[i][0],n[i][1]);
    }
}

main(){
    char n[alunos][2][16];
    printf(">>>>>NOTAS DA TURMA<<<<<\n");
    nomesAlunos(n);
    mostrar(n);
    putchar('\n');
}
