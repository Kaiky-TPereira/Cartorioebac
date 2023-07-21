#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaça de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função que cadastra usuários no sistema
{
	//início criação variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); // %S refere-se a variável ou string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valeres das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
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
	
	printf("Digite o CPF a ser consultado: "); //Recebendo o usuário
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //'r' significa ler
	
	if(file== NULL) //"NULL" significa se não tiver nada
	{
		printf("Não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto conteudo de 200 letras for diferente de NULL e tudo ok
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //solicitando qual CPF é para ser deletado
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//abrir arquivo e ler ele "r"
	
	if(file == NULL)
	{
		printf("Esse usuário não se encontra mais no sistema!\n");
		system("pause");
	}
	
}
	

int main()
	{
	int opcao=0; //Definindo variáveis 
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartorio da EBAC ###\n\n"); //início do menu
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system("cls");
		for(laco=1;laco=1;)
		{	
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf(" Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls");
		
			switch(opcao) //início da seleção
			{
				case 1:
				registro(); //chamada de funções
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
			
				default://se o usuário não escolher certo
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
				
				}
			}
		
		
		}

		else
			printf("Senha incorreta!");

	}
