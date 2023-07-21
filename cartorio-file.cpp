#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�a de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o que cadastra usu�rios no sistema
{
	//in�cio cria��o vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); // %S refere-se a vari�vel ou string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valeres das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fevho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //cadastrar o nome
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abrindo o arquivo e cadastrando o nome
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //cadastrar sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //adicionando no arquivo
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //adicionando (,) no arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //cadastro de cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //adicionando no arquivo
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Recebendo o usu�rio
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //'r' significa ler
	
	if(file== NULL) //"NULL" significa se n�o tiver nada
	{
		printf("N�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto conteudo de 200 letras for diferente de NULL e tudo ok
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //solicitando qual CPF � para ser deletado
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//abrir arquivo e ler ele "r"
	
	if(file == NULL)
	{
		printf("Esse usu�rio n�o se encontra mais no sistema!\n");
		system("pause");
	}
	
}
	

int main()
	{
	int opcao=0; //Definindo vari�veis 
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartorio da EBAC ###\n\n"); //in�cio do menu
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system("cls");
		for(laco=1;laco=1;)
		{	
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf(" Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls");
		
			switch(opcao) //in�cio da sele��o
			{
				case 1:
				registro(); //chamada de fun��es
				break;
		
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por acessar o sistema!\n");
				return 0;
				break;
			
				default://se o usu�rio n�o escolher certo
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
				
				}
			}
		
		
		}

		else
			printf("Senha incorreta!");

	}
