#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()
{	
	
	char arquivo[40]; //definindo string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf); //armazena os dados na string
	
	strcpy(arquivo, cpf); //respons�vel por copiar o valor das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //busca/abre o arquivo (file) da string (arquivo)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo e o atualiza
	fprintf(file,", "); //informa��o adicionda no arquivo
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
		printf("\nUsu�rio n�o encontado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n\t");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
		
		
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
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
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
	
}

int main()
{
	
	
	int opcao=0; //definindo vari�veis
	int laco=1;
	char senhaDigitada[]="a";
	int comparacao;
	
	
	
	for(laco=1;laco=1;)//la�o de repedi��o para senha
		{
			system("cls");
			
			setlocale(LC_ALL, "Portuguese");
	
			printf("~~~ Cat�rio da EBAC ~~~\n\n");
			printf("Login de administrador!\n\nDigite sua senha: ");
			scanf("%s",senhaDigitada);
			
			comparacao = strcmp(senhaDigitada, "admin");//comando responsavel por comparar string
				
			if(comparacao == 0)
			{
		
				
			for(laco=1;laco=1;)// la�o de repeti��o para tela inicial
			{
		
				system("cls"); //limpar texto da janela
		
				setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
				printf("~~~ Cat�rio da EBAC ~~~\n\n"); //inicio do menu
				printf("Escolha a op��o desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n"); 
				printf("\t4 - Sair do menu\n\n");
				printf("Op��o: "); //fim do menu
		
				scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
				system("cls");
		
				switch(opcao) //inicio da sele��o
				{
			
					case 1:
					registro(); //chmada de fun��es
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
					printf("Essa op��o n�o est� disponivel!\n");
					system("pause");
					break;
		
				} //fim da sele��o
			}
		}
		else
			printf("\nSenha incorreta, por favor tente novamente!\n\n");
			system("pause");
	}
}

