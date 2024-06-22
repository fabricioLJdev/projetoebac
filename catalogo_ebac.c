# include <stdio.h> //biblioteca de comunicação com o usuário
# include <stdlib.h> //biblioteca de alocação em espaço de memória
# include <locale.h> //biblioteca de alocação de texto por região
# include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
    //criação das variavel/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variaveis/strings
	
	printf("Digite seu CPF a ser cadastrado: "); //coletando informação do usuario 
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


int consultar() //Função responsavel por consultar os usuarios cadastrados 
{
	setlocale(LC_ALL, "Portuguese"); //Definição de Linguagem
	//criação das variaveis/strings
	char cpf[40];
	char conteudo[200];
	//terminado a criação das variaveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando dados do usuario
	scanf("%s",cpf); //salvando na variavel e "%s" refere-se a strings
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
	
	}
	
	
int deletar() //Função responsavel por deletar as usuarios
{
	char cpf[40]; //criando a variavel
	
	printf("Digite o CPF a ser deletado: "); //coletando dados do usuario
	scanf("%s",cpf); //Salvando na variavel e "%s" refere-se a strings
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //abrir o arquivo para verificar se o CPF existe
	
	if(file == NULL) //Dando uma condição
	{
		printf("Usuario não se encontra no sistema\n"); //coletando dados do usuario
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
	
int main() //função principal
{
	int opcao=0; //Definindo variáveis
	int laco=1; //definindo repetição 
	
	for(laco=1;laco=1;)
	{
		
	 system("cls"); 
	
	 setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	 printf("### Cartório da EBAC ###\n\n"); //inicio do menu
   	 printf("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
 	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n"); //fim do menu
	 printf("Opção: ");
	
	 scanf("%d", &opcao); //armazenando a escolha do usuário
	
	 system("cls"); //responsavel por limpar a tela
	
	
	 switch(opcao) //inicio da seleção do menu
	 {
	 	case 1: 
	 	registro(); //chama de funções 
	 	break;
	 	
	 	case 2:
	 	consultar();
	 	break;
	 	
	 	case 3:
	 	deletar();
	 	break;
	 	
	 	default:
	 	printf("Essa opção não está disponivel!\n");
	 	system("pause");
	 	break; //final da seleção
		 		
	
	 }
	}
}
	
