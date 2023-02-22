#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro()
{	
	
	char arquivo[40]; //definindo string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf); //armazena os dados na string
	
	strcpy(arquivo, cpf); //responsável por copiar o valor das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //busca/abre o arquivo (file) da string (arquivo)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo e o atualiza
	fprintf(file,", "); //informação adicionda no arquivo
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nUsuário não encontado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n\t");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
	
}

int main()
{
	
	
	int opcao=0; //definindo variáveis
	int laco=1;
	char senhaDigitada[]="a";
	int comparacao;
	
	
	
	for(laco=1;laco=1;)//laço de repedição para senha
		{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese");
	
			printf("~~~ Catório da EBAC ~~~\n\n");
			printf("Login de administrador!\n\nDigite sua senha: ");
			scanf("%s",senhaDigitada);
			
			comparacao = strcmp(senhaDigitada, "admin");//comando responsavel por comparar string
				
			if(comparacao == 0)
			{
		
				
			for(laco=1;laco=1;)// laço de repetição para tela inicial
			{
		
				system("cls"); //limpar texto da janela
		
				setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
				printf("~~~ Catório da EBAC ~~~\n\n"); //inicio do menu
				printf("Escolha a opção desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n"); 
				printf("\t4 - Sair do menu\n\n");
				printf("Opção: "); //fim do menu
		
				scanf("%d", &opcao); //armazenando a escolha do usuário
		
				system("cls");
		
				switch(opcao) //inicio da seleção
				{
			
					case 1:
					registro(); //chmada de funções
					break;
			
					case 2:
					consulta();
					break;
			
					case 3:
					deletar();
					break;
				
					case 4:
					printf("Obrigado por utilizar o sistema!\n\n");
					return 0;
					break;	
			
					default:
					printf("Essa opção não está disponivel!\n");
					system("pause");
					break;
		
				} //fim da seleção
			}
		}
		else
			printf("\nSenha incorreta, por favor tente novamente!\n\n");
			system("pause");
	}
}

