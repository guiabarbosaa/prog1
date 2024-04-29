#include <stdio.h>
#include <string.h>

typedef struct{
    char NomeAluno[50];
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

void ImprimeAluno(tAluno aluno);

int main ()
{
    int i, j, numDisciplina, qtdDisciplina;

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
            }
        }
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

    scanf("%s",aluno.NomeAluno);
    scanf("\n");
    return aluno;
}
void ImprimeAluno(tAluno aluno)
{
    printf("%s\n", aluno.NomeAluno);
}