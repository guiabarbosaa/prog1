#include <stdio.h>
#include <string.h>

typedef struct{
    char NomeAluno[50];
    int notas[3];
}tAluno;

typedef struct{
    char NomeDisciplina[50];
    tAluno alunos[30];
    int qtdAlunos;
}tDisciplina;

tDisciplina LeDisciplina();

void ImprimeAlunosDisciplina(tDisciplina disciplina);

int EhMesmaDisciplina(tDisciplina disciplina, char nomeDisciplina[]);

tAluno LeAluno();

int EstaAprovadoAluno(tAluno aluno);

void ImprimeAluno(tAluno aluno);

int main ()
{
    int i, j, numDisciplina, qtdDisciplina;
    int flagAchouIgual = 0;

    scanf("%d\n", &numDisciplina);

    tDisciplina disciplinas[numDisciplina];

    for(i = 0; i < numDisciplina; i++)
    {
        disciplinas[i] = LeDisciplina();
    }

    scanf("%d\n", &qtdDisciplina);
    char nome[qtdDisciplina][50];

    for(i = 0; i < qtdDisciplina; i++)
    {   
        scanf("%s", nome[i]);
        scanf("\n");
        for(j = 0; j < numDisciplina; j++)
        {
            if(EhMesmaDisciplina(disciplinas[j],nome[i]))
            {
                printf("%s:\n", nome[i]);
                ImprimeAlunosDisciplina(disciplinas[j]);
                flagAchouIgual = 1;
            }
            else if(j == numDisciplina - 1 && flagAchouIgual == 0)
            {
                printf("%s: DISCIPLINA INVALIDA\n", nome[i]);
            }
        }
        flagAchouIgual = 0;
    }
}
tDisciplina LeDisciplina()
{
    tDisciplina disciplina;
    int i;

    scanf("%s",disciplina.NomeDisciplina);
    scanf("%d\n",&disciplina.qtdAlunos);

    for(i = 0; i < disciplina.qtdAlunos; i++)
    {
        disciplina.alunos[i] = LeAluno();
    }
    return disciplina;
}
void ImprimeAlunosDisciplina(tDisciplina disciplina)
{
    int i;

    for(i = 0; i < disciplina.qtdAlunos; i++)
    {
        ImprimeAluno(disciplina.alunos[i]);
    }
}
int EhMesmaDisciplina(tDisciplina disciplina, char nomeDisciplina[])
{
    int i;

    if(strcmp(disciplina.NomeDisciplina,nomeDisciplina) == 0)
    {
        return 1;
    }
    return 0;
}
tAluno LeAluno()
{
    tAluno aluno;
    int i;
    scanf("%s",aluno.NomeAluno);
    for(i = 0; i < 3; i++)
    {
        scanf("%d",&aluno.notas[i]);
    }
    scanf("\n");
    return aluno;
}
int EstaAprovadoAluno(tAluno aluno)
{
    int soma = 0, i;
    for(i = 0; i < 3; i++)
    {
        soma += aluno.notas[i];
    }
    if(soma >= 21)
    {
        return 1;
    }
    return 0;
}
void ImprimeAluno(tAluno aluno)
{
    printf("%s: ", aluno.NomeAluno);
    if(EstaAprovadoAluno(aluno))
    {
        printf("APROVADO\n");
    }
    else
    {
        printf("REPROVADO\n");
    }
}