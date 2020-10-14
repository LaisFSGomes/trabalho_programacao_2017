//AGNIS, DANIEL, LAIS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define total 1000

typedef struct alunos{
    char nome [101];
    float notas [3];
    int matricula;
    int frequencia;
    int ativo;
} Aluno;

Aluno turma[total];
static int posicao=0;

void  menu();
void cadastrar();
void lista();
void frequencia ();
void notas ();
void consultar ();
void excluir ();
void limpar();
int resultado();

int main(void){

    menu();
    return 0;
}

void menu(){
	int op;
	printf ("\n\n\n");
    printf ("********************SIGAA********************");
    printf ("\n\n\n");

    do {
    printf("\n1 - Cadastrar aluno\n"); //ja foi
    printf("2 - Consultar aluno\n"); //ja foi
    printf("3 - Cadastrar frequencia de aluno\n"); //ja foi
    printf("4 - Cadastrar notas de aluno\n"); //ja foi
    printf("5 - Relatorio de alunos\n"); //metade
    printf("6 - Excluir aluno\n");
    printf("7 - Limpar memoria\n");
    printf("8 - Sair do programa\n\n"); //ja foi

    printf("Digite o numero da opcao desejada: ");
    scanf ("%i",&op);
    setbuf(stdin,NULL);
    switch (op){
    case 1:
        cadastrar();
        break;
    case 2:
        consultar();
        break;
    case 3:
        frequencia();
        break;
    case 4:
        notas();
        break;
    case 5:
        lista();
        break;
    case 6:
        excluir();
        break;
    case 7:
        limpar();
        break;
    case 8:
        break;
    }
    }while (op!=8);
    }

    void cadastrar(){
        char nome[101];
        int matricula;
        int op;
    do {

        printf("Nome do Aluno: ");
        fgets(nome,sizeof(nome),stdin);

        //printf("\n\n\n\n%d\n\n\n",posicao);
        strcpy(turma[posicao].nome, nome);
        matricula = posicao+1;
        turma[posicao].matricula = matricula;
        turma[posicao].ativo = 1;
        turma[posicao].frequencia = -1;
        turma[posicao].notas[0] = -1;
        turma[posicao].notas[1] = -1;
        turma[posicao].notas[2] = -1;

        posicao = posicao+1;


        printf("1 - Continuar \n0 - Sair\n");
        scanf("%i",&op);
        getchar();
    }while (op!=0);
    }


   void lista(){
    char troca[101];
    int i, resultfinal, op, j;
    printf("1 - ordenar por matricula\n2 - ordem alfabetica ");
    scanf("%d", &op);

    switch (op){
        case 1:
        for (i=0 ; i < posicao ; i++){
			if (turma[i].ativo==1){
            printf("-------------------------------\n");
            printf("\nNome: %s\n", turma[i].nome);
            printf("Matricula: %d\n", turma[i].matricula);

            if (turma[i].notas[0] == -1){
                printf("\nAP1 nao cadastrada!");
            }else{
                printf("\nAP1: %f\n", turma[i].notas[0]);
				}

			if(turma[i].notas[1] == -1){
                	 printf("\nAP2 nao cadastrada!");
			}else{
					printf("AP2: %f\n", turma[i].notas[1]);
				}

			if(turma[i].notas[2] == -1){
					printf("\nAP3 nao cadastrada!");
				}else{
					printf("\nAP3: %f\n", turma[i].notas[2]);
				}

			if (turma[i].frequencia == -1){
            printf("\nFrequencia nao cadastrada!");
           	    }else{
            		printf("\nFrequencia: %d horas", turma[i].frequencia);
           		 	printf("\n");
			}
			resultfinal = resultado(turma[i].notas, turma[i].frequencia);

			if (resultfinal == 1){
                printf("\nAluno Aprovado");
			}else {
                if (resultfinal == 2){
                    printf("\nAluno esta de AF");
                }else {
                    if (resultfinal == 4){
                        printf("\nResultado Final Indeterminado");
                    }else{
                    printf("\nAluno Reprovado");
                    }
                }
			}

		}
        printf("\n\n");
   }
   break;
        case 2:
            for (i=0;i<posicao;i++){
                j=i+1;
                if (strcmp(turma[i].nome, turma[j].nome)>0){
                    strcpy(troca, turma[i].nome);
                    strcpy(turma[i].nome, turma[j].nome);
                    strcpy(turma[j].nome, troca);
                }
            }

            for (i=0; i < posicao +1; i++){
                if (turma[i].ativo==1){
                    printf("-------------------------------\n");
                    printf("\nNome: %s\n", turma[i].nome);
                    printf("Matricula: %d\n", turma[i].matricula);

                if (turma[i].notas[0] == -1){
                    printf("\nAP1 nao cadastrada!");
                }
                else{
                    printf("\nAP1: %f\n", turma[i].notas[0]);
				}

                if(turma[i].notas[1] == -1){
                	 printf("\nAP2 nao cadastrada!");
			}
                else{
					printf("AP2: %f\n", turma[i].notas[1]);
				}

                if(turma[i].notas[2] == -1){
					printf("\nAP3 nao cadastrada!");
				}
				else{
					printf("\nAP3: %f\n", turma[i].notas[2]);
				}

                if (turma[i].frequencia == -1){
                    printf("\nFrequencia nao cadastrada!");
           	    }
           	    else{
            		printf("\nFrequencia: %d horas", turma[i].frequencia);
           		 	printf("\n");
			}
			resultfinal = resultado(turma[i].notas, turma[i].frequencia);

                if (resultfinal == 1){
                    printf("\nAluno Aprovado");
			}
                else {
                if (resultfinal == 2){
                    printf("\nAluno esta de AF");
                }else {
                    if (resultfinal == 4){
                        printf("\nResultado Final Indeterminado");
                    }else{
                    printf("\nAluno Reprovado");
                    }
                }
			}

		}
        printf("\n\n");
   }
    }
        }




void frequencia(){
    int horas,i,lermatricula, posivet;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &lermatricula);
    posivet = lermatricula - 1;
    //printf("\n\n%s\n\n", turma[posivet].nome);
    do{
    printf("Informe o total de horas que o aluno compareceu: ");
    scanf("%d", &horas);
    }while (horas<=0 && horas >=96);

    turma[posivet].frequencia = horas;
}

void notas(){
    float aps[3];
    int lermatricula, posivet;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &lermatricula);
    posivet = lermatricula -1;

        printf("Digite a nota da AP1: ");
        scanf("%f", &aps[0]);
        printf("Digite a nota da AP2: ");
        scanf("%f", &aps[1]);
        printf("Digite a nota da AP3: ");
        scanf("%f", &aps[2]);

        turma[posivet].notas[0] = aps[0];
        turma[posivet].notas[1] = aps[1];
        turma[posivet].notas[2] = aps[2];

}


void consultar(){
    char consultanome[101];
    int i, op, lermatricula, resultfinal;

    printf("1 - busca por matricula\n");
    printf("2 busca por nome\n");
    scanf("%d", &op);
    getchar();

    if (op == 1){
        printf("Digite a matricula: \n");
        scanf("%d", &lermatricula);
        getchar();

                for (i=0 ; i < posicao ; i++){
			if (turma[i].ativo==1){
            printf("-------------------------------\n");
            printf("\nNome: %s\n", turma[i].nome);
            printf("Matricula: %d\n", turma[i].matricula);

            if (turma[i].notas[0] == -1){
                printf("\nAP1 nao cadastrada!");
            }else{
                printf("\nAP1: %f\n", turma[i].notas[0]);
				}

			if(turma[i].notas[1] == -1){
                	 printf("\nAP2 nao cadastrada!");
			}else{
					printf("AP2: %f\n", turma[i].notas[1]);
				}

			if(turma[i].notas[2] == -1){
					printf("\nAP3 nao cadastrada!");
				}else{
					printf("\nAP3: %f\n", turma[i].notas[2]);
				}

			if (turma[i].frequencia == -1){
            printf("\nFrequencia nao cadastrada!");
           	    }else{
            		printf("\nFrequencia: %d horas", turma[i].frequencia);
           		 	printf("\n");
			}
			resultfinal = resultado(turma[i].notas, turma[i].frequencia);

			if (resultfinal == 1){
                printf("\nAluno Aprovado");
			}else {
                if (resultfinal == 2){
                    printf("\nAluno esta de AF");
                }else {
                    printf("\nAluno Reprovado");
                }
			}

		}

   }


        }else {
            if(op == 2){
                printf("Digite o nome do aluno: ");
                fgets(consultanome, sizeof(consultanome), stdin);
                getchar();

                if (strstr(turma[i].nome, consultanome)!= NULL){
                printf("\n\n\n");
                printf("Nome: %s\n", turma[i].nome);
                printf("Matricula: %d\n", turma[i].matricula);
                printf("AP1: %f\n", turma[i].notas[0]);
                printf("AP2: %f\n", turma[i].notas[1]);
                printf("AP3: %f\n", turma[i].notas[2]);
                printf("Frequencia: %d horas\n", turma[i].frequencia);
                }
            }
        }
    }

void excluir(){
    int i, lermatricula, posivet;

    for (i=0;i<posicao;i++){
        printf("%d    %s\n", turma[i].matricula, turma[i].nome);
    }
    printf("\n");

    printf("Informe a matricula do aluno que deseja excluir: ");
    scanf("%d", &lermatricula);
    posivet = lermatricula-1;

    turma[posivet].ativo = 0;

    printf("Aluno excluido!");


}

int resultado(float n[3], int freq){
    float media;
    int result;

    media = (n[0]+n[1]+n[2])/3;

    if (freq>=72){
        if (media >=7){
            result = 1;
        }else{
        if(media>=4){
            result = 2;
        }else{
            if (media<0){
                result = 4;
            }else {
                if (media<4){
                    result = 4;
                }
            }
        }
        }
    }else {
        if (freq<0){
            result = 4;
        }
    }

    return result;
}
void limpar(){
    int i;
    for(i=0; i < total ; i++){
        turma[i].ativo = 0;
    }
    printf("\nMemoria limpa");
}
