#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300

// Estrutura para armazenar datas
struct Data{
	int Dia;
	int Mes;
	int Ano;
};

// Estrutura para guardar dados dos livros
struct Livro{
	int CodLivro;
	char Titulo[100];
	char Autor[80];
	char Editora[60];
	int AnoPublicacao;
	int NumeroDisponiveis; // Exemplares
	int Status; // Ativo ou não
};

// Estrutura para guardar dados dos usuários
struct Usuario{
	struct Data DataCadastro;
	int Matricula;
	char Nome[100];
	char Curso[50];
	char Telefone[15];
};

// Estrutura para empréstimos
struct Emprestimo{
	struct Data DataEmprestimo;
	struct Data DataDevolucao;
	int CodEmprestimo;
	int MatriculaUsuario;
	int CodLivro;
	int Status; // 1 = ativo, 0 = devolvido
};

// Função para cadastrar livros
void CadastrarLivros(struct Livro Livros[],int *QtdLivros){
   	int opcao=1;
	while(opcao!=0){
		
		// Coleta os dados do livro
		printf("CODIGO: \n");
		scanf("%d",&Livros[*QtdLivros].CodLivro);
		printf("TITULO: \n");
		getchar();
		fgets(Livros[*QtdLivros].Titulo,100,stdin);
		printf("AUTOR: \n");
		fgets(Livros[*QtdLivros].Autor,80,stdin);
		printf("EDITORA: \n");
		fgets(Livros[*QtdLivros].Editora,60,stdin);
		printf("ANO: \n");
		scanf("%d",&Livros[*QtdLivros].AnoPublicacao);
		printf("NUMERO DISPONIVEIS: \n");
		scanf("%d",&Livros[*QtdLivros].NumeroDisponiveis);

		Livros[*QtdLivros].Status = 1; // Ativo
		(*QtdLivros)++; // Incrementa quantidade
		
		system("cls");
		printf("1-NOVO LIVRO\n");
		printf("0-VOLTAR\n");
		scanf("%d",&opcao);
		system("cls");
	}
}

// Pesquisa um livro pelo código
void PesquisaCodigo(struct Livro Livros[],int *QtdLivros){
	int i;
	int LivroBuscado;
	int encontrado=-1;

	printf("CODIGO LIVRO: \n");
	scanf("%d",&LivroBuscado);

	// Procura o livro
	for(i=0;i<*QtdLivros;i++){
		if(LivroBuscado == Livros[i].CodLivro){
			encontrado=i;
			break;
		}
	}
	
	if (encontrado == -1){
		printf("CODIGO DE LIVRO INVALIDO!\n");
		return;
	}

	// Exibe resultado
	printf("====LIVRO ENCONTRADO====\n");
	printf("CODIGO: %d\n",Livros[encontrado].CodLivro);
	printf("TITULO: %s\n",Livros[encontrado].Titulo);
	printf("AUTOR: %s\n",Livros[encontrado].Autor);
	printf("EDITORA: %s\n",Livros[encontrado].Editora);
	printf("ANO: %d\n",Livros[encontrado].AnoPublicacao);
}

// Pesquisa por título
void PesquisaTitulo(struct Livro Livros[], int *QtdLivros){
	int i;
	char LivroBuscado[100];
	int encontrado=-1;

	printf("TITULO LIVRO: \n");
	getchar();
	fgets(LivroBuscado,100,stdin);

	// Compara texto
	for(i=0;i<*QtdLivros;i++){
		if(strcmp(LivroBuscado,Livros[i].Titulo) == 0){
			encontrado=i;
			break;
		}
	}

	if (encontrado == -1){
		printf("TITULO INVALIDO!\n");
		return;
	}

	// Mostra dados encontrados
	printf("====LIVRO ENCONTRADO====\n");
	printf("CODIGO: %d\n",Livros[encontrado].CodLivro);
	printf("TITULO: %s\n",Livros[encontrado].Titulo);
	printf("AUTOR: %s\n",Livros[encontrado].Autor);
	printf("EDITORA: %s\n",Livros[encontrado].Editora);
	printf("ANO: %d\n",Livros[encontrado].AnoPublicacao);
}

// Pesquisa por autor
void PesquisaAutor(struct Livro Livros[],int *QtdLivros){
   	int i;
	char LivroBuscado[80];
	int encontrado=-1;

	printf("AUTOR DO LIVRO: \n");
	getchar();
	fgets(LivroBuscado,80,stdin);

	// Compara com autores cadastrados
	for(i=0;i<*QtdLivros;i++){
		if(strcmp(LivroBuscado,Livros[i].Autor) == 0){
			encontrado=i;
			break;
		}
	}

	if (encontrado == -1){
		printf("AUTOR INVALIDO!\n");
		return;
	}

	// Imprime informações
	printf("====LIVRO ENCONTRADO====\n");
	printf("CODIGO: %d\n",Livros[encontrado].CodLivro);
	printf("TITULO: %s\n",Livros[encontrado].Titulo);
	printf("AUTOR: %s\n",Livros[encontrado].Autor);
	printf("EDITORA: %s\n",Livros[encontrado].Editora);
	printf("ANO: %d\n",Livros[encontrado].AnoPublicacao);
}

// Menu de busca de livros
void PesquisarLivros(struct Livro Livros[],int *QtdLivros){
	int opcao;
	do{
		printf("1- PESQUISA POR CODIGO\n");
		printf("2-PESQUISA POR TITULO\n");
		printf("3-PESQUISA POR AUTOR\n");
		printf("0-VOLTAR\n");
		scanf("%d",&opcao);
		system("cls");

		switch(opcao){
			case 1: PesquisaCodigo(Livros,QtdLivros); break;
			case 2: PesquisaTitulo(Livros,QtdLivros); break;
			case 3: PesquisaAutor(Livros,QtdLivros); break;
			default: printf("OPCAO INVALIDA! \n");
		}
	}while(opcao != 0);
}

// Menu principal da parte de livros
void GerenciarLivros(struct Livro Livros[],int *QtdLivros){
	int opcao;
	do {
		printf("1-CADASTRAR LIVROS\n");
		printf("2-PESQUISAR LIVROS\n");
		printf("0-VOLTAR\n");
		scanf("%d",&opcao);
		system("cls");

		switch (opcao){
  			case 1: CadastrarLivros(Livros,QtdLivros); break;
			case 2: PesquisarLivros(Livros,QtdLivros); break;
			case 0: return;
			default: printf("OPCAO INVALIDA !");
		}
	}while(opcao!=0);
}

// Cadastro de usuários
void CadastrarUsuarios(struct Usuario Usuarios[],int *QtdUsuarios){
	int opcao;
	do{
		printf("MATRICULA: \n");
	    scanf("%d",&Usuarios[*QtdUsuarios].Matricula);

		printf("NOME: \n");
		getchar();
		fgets(Usuarios[*QtdUsuarios].Nome,100,stdin);

		printf("CURSO: \n");
		fgets(Usuarios[*QtdUsuarios].Curso,50,stdin);

		printf("TELEFONE: \n");
		fgets(Usuarios[*QtdUsuarios].Telefone,15,stdin);

		(*QtdUsuarios)++; // Acrescenta novo usuário
		
		printf("1-NOVO USUARIO\n");
		printf("0-VOLTAR\n");
		scanf("%d",&opcao);
		system("cls");

	}while(opcao!=0);
}

// Pesquisa usuário pela matrícula
void PesquisarMatricula(struct Usuario Usuarios[],int *QtdUsuarios){

   int i;
	int MatriculaBuscada;
	int encontrado=-1;

	printf("MATRICULA DE USUARIO: \n");
	getchar();
	scanf("%d",&MatriculaBuscada);

	// Busca simples
	for(i=0;i<*QtdUsuarios;i++){
		if(MatriculaBuscada == Usuarios[i].Matricula){
			encontrado=i;
			break;
		}
	}

	if (encontrado == -1){
		printf("MATRICULA INVALIDA!\n");
		return;
	}

	// Imprime resultados
	printf("====USUARIO ENCONTRADO====\n");
	printf("MATRICULA: %d\n",Usuarios[encontrado].Matricula);
	printf("NOME: %s\n",Usuarios[encontrado].Nome);
	printf("CURSO: %s\n",Usuarios[encontrado].Curso);
	printf("TELEFONE: %s\n",Usuarios[encontrado].Telefone);	
}

// Menu de pesquisa de usuários
void PesquisarUsuarios(struct Usuario Usuarios[],int *QtdUsuarios){
	int opcao=1;
	do{
    	printf("1-PESQUISAR POR MATRICULA\n");
    	printf("0-VOLTAR\n");
    	scanf("%d",&opcao);

    	switch(opcao){
		   case 1: PesquisarMatricula(Usuarios,QtdUsuarios); break;
		   case 0: return;
		   default: printf("OPCAO INVALIDA!\n");
	    }
   }while(opcao!=0);
}

// Menu de gerenciamento de usuários
void GerenciarUsuarios(struct Usuario Usuarios[],int *QtdUsuarios){
	int opcao;
	do{
		printf("1-CADASTRAR USUARIOS\n");
		printf("2-PESQUISAR USUARIOS\n");
		printf("0-VOLTAR\n");
		scanf("%d",&opcao);
		system("cls");

		switch (opcao){
			case 1: CadastrarUsuarios(Usuarios,QtdUsuarios); break;
			case 2: PesquisarUsuarios(Usuarios,QtdUsuarios); break;
			case 0: return;
			default: printf("OPCAO INVALIDA !");
		}
	}while(opcao!=0);
}

// Realiza empréstimo
void RealizarEmprestimo(struct Livro Livros[],struct Usuario Usuarios[],struct Emprestimo Emprestimos[],int *QtdLivros,int *QtdUsuarios,int *QtdEmprestimos){
    int i=0;
    int encontradoM=0;
    int encontradoC=-1;

    // Gera código automático
    Emprestimos[*QtdEmprestimos].CodEmprestimo = *QtdEmprestimos + 1;

    printf("MATRICULA USUARIO: \n");
    scanf("%d",&Emprestimos[*QtdEmprestimos].MatriculaUsuario);

    // Busca usuário
    for (i=0;i < *QtdUsuarios;i++){
        if (Usuarios[i].Matricula == Emprestimos[*QtdEmprestimos].MatriculaUsuario){
            encontradoM=1;
            break;
        }
    }

    if(encontradoM == 0){
        printf("MATRICULA INVALIDA!\n");
        return;
    }

    printf("CODIGO LIVRO: \n");
    scanf("%d",&Emprestimos[*QtdEmprestimos].CodLivro);

    // Busca livro
    for(i=0;i < *QtdLivros;i++){
        if(Livros[i].CodLivro == Emprestimos[*QtdEmprestimos].CodLivro){
            encontradoC=i;
            break;
        }
    }

    if (encontradoC == -1){
        printf("CODIGO INVALIDO!\n");
        return;
    }

    if (Livros[encontradoC].NumeroDisponiveis == 0){
        printf("SEM EXEMPLARES!\n");
        return;
    }

    // Lê data do empréstimo
    printf("INFORME DATA EMPRESTIMO DD/MM/AAAA\n");
    printf("DIA: \n");
    scanf("%d",&Emprestimos[*QtdEmprestimos].DataEmprestimo.Dia);
    printf("MES: \n");
    scanf("%d",&Emprestimos[*QtdEmprestimos].DataEmprestimo.Mes);
    printf("ANO: \n");
    scanf("%d",&Emprestimos[*QtdEmprestimos].DataEmprestimo.Ano);

    // Calcula devolução (+7 dias)
    Emprestimos[*QtdEmprestimos].DataDevolucao = Emprestimos[*QtdEmprestimos].DataEmprestimo;
    Emprestimos[*QtdEmprestimos].DataDevolucao.Dia += 7;

    // Ajuste simples de datas
    if(Emprestimos[*QtdEmprestimos].DataDevolucao.Dia > 30){
        Emprestimos[*QtdEmprestimos].DataDevolucao.Dia -= 30;
        Emprestimos[*QtdEmprestimos].DataDevolucao.Mes++;

        if(Emprestimos[*QtdEmprestimos].DataDevolucao.Mes > 12){
            Emprestimos[*QtdEmprestimos].DataDevolucao.Mes = 1;
            Emprestimos[*QtdEmprestimos].DataDevolucao.Ano++;
        }
    }

    // Reserva exemplar
    Livros[encontradoC].NumeroDisponiveis--;
    Emprestimos[*QtdEmprestimos].Status = 1;

    (*QtdEmprestimos)++;
    printf("EMPRESTIMO REALIZADO!\n");
}

// Devolução
void RealizarDevolucao(struct Livro Livros[],struct Usuario Usuarios[],struct Emprestimo Emprestimos[],int *QtdLivros,int *QtdUsuarios,int *QtdEmprestimos){
    int cod, i, encontrado = -1, livroIndex;

    printf("CODIGO DO EMPRESTIMO: \n");
    scanf("%d", &cod);

    // Localiza empréstimo ativo
    for(i = 0; i < *QtdEmprestimos; i++){
        if(Emprestimos[i].CodEmprestimo == cod && Emprestimos[i].Status == 1){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("NAO ENCONTRADO!\n");
        return;
    }

    // Acha livro
    livroIndex = -1;
    for(i = 0; i < *QtdLivros; i++){
        if(Livros[i].CodLivro == Emprestimos[encontrado].CodLivro){
            livroIndex = i;
            break;
        }
    }

    Livros[livroIndex].NumeroDisponiveis++;
    Emprestimos[encontrado].Status = 0;

    printf("DEVOLVIDO COM SUCESSO!\n");
}

// Lista empréstimos ativos
void EmprestimosAtivos(struct Emprestimo Emprestimos[], int *QtdEmprestimos){
    int i, cont = 0;

    printf("=== EMPRESTIMOS ATIVOS ===\n");

    for(i = 0; i < *QtdEmprestimos; i++){
        if(Emprestimos[i].Status == 1){
            printf("COD EMPRESTIMO: %d\n", Emprestimos[i].CodEmprestimo);
            printf("MATRICULA: %d\n", Emprestimos[i].MatriculaUsuario);
            printf("COD LIVRO: %d\n", Emprestimos[i].CodLivro);

            printf("--------------------------\n");
            cont++;
        }
    }

    if(cont == 0){
        printf("SEM EMPRESTIMOS.\n");
    }
}

// Menu de empréstimos
void GerenciarEmprestimo(struct Livro Livros[],struct Usuario Usuarios[],struct Emprestimo Emprestimos[],int *QtdLivros,int *QtdUsuarios,int *QtdEmprestimos){
	int opcao;
	do{
		printf("1-REALIZAR EMPRESTIMO\n");
		printf("2-REALIZAR DEVOLUCAO\n");
		printf("3-EMPRESTIMOS ATIVOS\n");
		printf("0-VOLTAR\n");
		scanf("%d",&opcao);
		system("cls");

		switch (opcao){
			case 1: RealizarEmprestimo(Livros,Usuarios,Emprestimos,QtdLivros,QtdUsuarios,QtdEmprestimos); break;
			case 2: RealizarDevolucao(Livros,Usuarios,Emprestimos,QtdLivros,QtdUsuarios,QtdEmprestimos); break;
			case 3: EmprestimosAtivos(Emprestimos,QtdEmprestimos); break;
			case 0: return;
		}
	}while(opcao!=0);
}

// Salva livros em arquivo
void SalvarLivros(struct Livro Livros[], int QtdLivros){
    FILE *arq = fopen("livros.txt", "w");
    if(arq == NULL){
        printf("ERRO AO SALVAR!\n");
        return;
    }

    for(int i=0; i<QtdLivros; i++){
        // Grava dados formatados
        fprintf(arq, "%d;%s;%s;%s;%d;%d;%d\n",
            Livros[i].CodLivro,
            Livros[i].Titulo,
            Livros[i].Autor,
            Livros[i].Editora,
            Livros[i].AnoPublicacao,
            Livros[i].NumeroDisponiveis,
            Livros[i].Status
        );
    }

    fclose(arq);
}

// Salva usuários
void SalvarUsuarios(struct Usuario Usuarios[], int QtdUsuarios){
    FILE *arq = fopen("usuarios.txt", "w");
    if(arq == NULL){
        printf("ERRO AO SALVAR!\n");
        return;
    }

    for(int i=0; i<QtdUsuarios; i++){
        fprintf(arq, "%d;%s;%s;%s;%d;%d;%d\n",
            Usuarios[i].Matricula,
            Usuarios[i].Nome,
            Usuarios[i].Curso,
            Usuarios[i].Telefone,
            Usuarios[i].DataCadastro.Dia,
            Usuarios[i].DataCadastro.Mes,
            Usuarios[i].DataCadastro.Ano
        );
    }

    fclose(arq);
}

// Salva empréstimos
void SalvarEmprestimos(struct Emprestimo Emprestimos[], int QtdEmprestimos){
    FILE *arq = fopen("emprestimos.txt", "w");
    if(arq == NULL){
        printf("ERRO AO SALVAR!\n");
        return;
    }

    for(int i=0; i<QtdEmprestimos; i++){
        fprintf(arq, "%d;%d;%d;%d/%d/%d;%d/%d/%d;%d\n",
            Emprestimos[i].CodEmprestimo,
            Emprestimos[i].MatriculaUsuario,
            Emprestimos[i].CodLivro,
            Emprestimos[i].DataEmprestimo.Dia,
            Emprestimos[i].DataEmprestimo.Mes,
            Emprestimos[i].DataEmprestimo.Ano,
            Emprestimos[i].DataDevolucao.Dia,
            Emprestimos[i].DataDevolucao.Mes,
            Emprestimos[i].DataDevolucao.Ano,
            Emprestimos[i].Status
        );
    }

    fclose(arq);
}

// Carrega livros do arquivo
void CarregarLivros(struct Livro Livros[], int *QtdLivros){
    FILE *arq = fopen("livros.txt", "r");
    if(arq == NULL) return;

    while(!feof(arq)){
        fscanf(arq, "%d;%[^;];%[^;];%[^;];%d;%d;%d\n",
            &Livros[*QtdLivros].CodLivro,
            Livros[*QtdLivros].Titulo,
            Livros[*QtdLivros].Autor,
            Livros[*QtdLivros].Editora,
            &Livros[*QtdLivros].AnoPublicacao,
            &Livros[*QtdLivros].NumeroDisponiveis,
            &Livros[*QtdLivros].Status
        );
        (*QtdLivros)++;
    }

    fclose(arq);
}

// Carrega usuários
void CarregarUsuarios(struct Usuario Usuarios[], int *QtdUsuarios){
    FILE *arq = fopen("usuarios.txt", "r");
    if(arq == NULL) return;

    while(!feof(arq)){
        fscanf(arq, "%d;%[^;];%[^;];%[^;];%d;%d;%d\n",
            &Usuarios[*QtdUsuarios].Matricula,
            Usuarios[*QtdUsuarios].Nome,
            Usuarios[*QtdUsuarios].Curso,
            Usuarios[*QtdUsuarios].Telefone,
            &Usuarios[*QtdUsuarios].DataCadastro.Dia,
            &Usuarios[*QtdUsuarios].DataCadastro.Mes,
            &Usuarios[*QtdUsuarios].DataCadastro.Ano
        );
        (*QtdUsuarios)++;
    }

    fclose(arq);
}

// Carrega empréstimos
void CarregarEmprestimos(struct Emprestimo Emprestimos[], int *QtdEmprestimos){
    FILE *arq = fopen("emprestimos.txt", "r");
    if(arq == NULL) return;

    while(!feof(arq)){
        fscanf(arq, "%d;%d;%d;%d/%d/%d;%d/%d/%d;%d\n",
            &Emprestimos[*QtdEmprestimos].CodEmprestimo,
            &Emprestimos[*QtdEmprestimos].MatriculaUsuario,
            &Emprestimos[*QtdEmprestimos].CodLivro,
            &Emprestimos[*QtdEmprestimos].DataEmprestimo.Dia,
            &Emprestimos[*QtdEmprestimos].DataEmprestimo.Mes,
            &Emprestimos[*QtdEmprestimos].DataEmprestimo.Ano,
            &Emprestimos[*QtdEmprestimos].DataDevolucao.Dia,
            &Emprestimos[*QtdEmprestimos].DataDevolucao.Mes,
            &Emprestimos[*QtdEmprestimos].DataDevolucao.Ano,
            &Emprestimos[*QtdEmprestimos].Status
        );
        (*QtdEmprestimos)++;
    }

    fclose(arq);
}

// Cria backup simples
void Backup(){
    system("copy livros.txt livros_backup.txt > nul");
    system("copy usuarios.txt usuarios_backup.txt > nul");
    system("copy emprestimos.txt emprestimos_backup.txt > nul");

    printf("Backup realizado com sucesso!\n");
}

// Programa principal
int main(int argc, char *argv[]) {

struct Livro Livros[MAX];
struct Usuario Usuarios[MAX];
struct Emprestimo Emprestimos[MAX];

int QtdLivros=0;
int QtdUsuarios=0;
int QtdEmprestimos=0;
int opcao;

// Carrega dados dos arquivos
CarregarLivros(Livros, &QtdLivros);
CarregarUsuarios(Usuarios, &QtdUsuarios);
CarregarEmprestimos(Emprestimos, &QtdEmprestimos);

// Menu geral
do {
	printf("=== MENU BIBLIOTECA ===\n");
	printf("1-GERENCIAR LIVROS\n");
	printf("2-GERENCIAR USUARIOS\n");
	printf("3-GERENCIAR EMPRESTIMOS\n");
	printf("0- ENCERRAR\n");
	scanf("%d",&opcao);
	system("cls");

	switch(opcao){
		case 1: GerenciarLivros(Livros,&QtdLivros); break;
		case 2: GerenciarUsuarios(Usuarios,&QtdUsuarios); break;
		case 3: GerenciarEmprestimo(Livros,Usuarios,Emprestimos,&QtdLivros,&QtdUsuarios,&QtdEmprestimos); break;

		case 0:
			// Salva tudo antes de sair
			SalvarLivros(Livros, QtdLivros);
			SalvarUsuarios(Usuarios, QtdUsuarios);
			SalvarEmprestimos(Emprestimos, QtdEmprestimos);
			Backup();
			return 0;
			break;

		default: printf("OPCAO INVALIDA !");
	}
}while(opcao!=0);

return 0;
}
