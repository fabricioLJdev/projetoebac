# include <stdio.h> //biblioteca de comunica��o com o usu�rio
# include <stdlib.h> //biblioteca de aloca��o em espa�o de mem�ria
# include <locale.h> //biblioteca de aloca��o de texto por regi�o
# include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
    //cria��o das variavel/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das variaveis/strings
	
	printf("Digite seu CPF a ser cadastrado: "); //coletando informa��o do usuario 
	scanf("%s", cpf); //salvando na variavel e "%s" refere-se a strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecha 	o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo 
	fprintf(file,","); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando dados do usuario 
	scanf("%s", nome); //salvando na variavel/string "%s" refere-se a variavel
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salvando o valor da variavel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando dados do usuario 
	scanf("%s", sobrenome); //salvando na variavel/string "%s" refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando dados do usuario
	scanf("%s",cargo); //salvando na variavel/string "%s" refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	system("pause"); 
}


int consultar() //Fun��o responsavel por consultar os usuarios cadastrados 
{
	setlocale(LC_ALL, "Portuguese"); //Defini��o de Linguagem
	//cria��o das variaveis/strings
	char cpf[40];
	char conteudo[200];
	//terminado a cria��o das variaveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando dados do usuario
	scanf("%s",cpf); //salvando na variavel e "%s" refere-se a strings
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
	
	}
	
	
int deletar() //Fun��o responsavel por deletar as usuarios
{
	char cpf[40]; //criando a variavel
	
	printf("Digite o CPF a ser deletado: "); //coletando dados do usuario
	scanf("%s",cpf); //Salvando na variavel e "%s" refere-se a strings
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //abrir o arquivo para verificar se o CPF existe
	
	if(file == NULL) //Dando uma condi��o
	{
		printf("Usuario n�o se encontra no sistema\n"); //coletando dados do usuario
		system("pause");
	}
	
	fclose(file); //fecho o arquivo
	
	if(remove(cpf) == 0) //Remover o arquivo
	{
		printf("Usuario deletado com sucesso\n"); //coletando dados do usuario
		system("pause");
	} 
	
	else 
	
	{
		printf("Erro ao deletar o usuario\n"); //coletando dados do usuario
		system("pause"); 
	}
	
	}
	
int main() //fun��o principal
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //definindo repeti��o 
	
	for(laco=1;laco=1;)
	{
		
	 system("cls"); 
	
	 setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	 printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
   	 printf("Escolha a op��o desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
 	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n"); //fim do menu
	 printf("Op��o: ");
	
	 scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	 system("cls"); //responsavel por limpar a tela
	
	
	 switch(opcao) //inicio da sele��o do menu
	 {
	 	case 1: 
	 	registro(); //chama de fun��es 
	 	break;
	 	
	 	case 2:
	 	consultar();
	 	break;
	 	
	 	case 3:
	 	deletar();
	 	break;
	 	
	 	default:
	 	printf("Essa op��o n�o est� disponivel!\n");
	 	system("pause");
	 	break; //final da sele��o
		 		
	
	 }
	}
}
	
