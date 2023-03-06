#include<stdio.h> // biblioteca de comunicacao com o usu�rio
#include<stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include<locale.h> //biblioteca de aloca��o de textos por regi�o
#include<string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Respons�vel por cadastrar os usu�rios no sistema
{
	// inicio cria��o de vari�veis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a string - usado para salvar uma "string"
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; //comando para acessar o "FILE" (uma fun��o pronta j� criada pelo sistema) e criar um "file" (um novo arquivo)
	file = fopen(arquivo, "w");// instru��o para o sistema entender de que ser� composto o "file" a ser criado. O "arquivo" entre parenteses � a copia da variavel "cpf" (instru��o duas linhas acima). "w" (write) � o tipo de arquivo. Pode ser write, rewrite ou delete. Escrever um novo "arquivo".
	fprintf(file, cpf); //salvar o valor da vari�vel inserida 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// instru��o para o sistema acessar ("a") o arquivo j� criado acima.
	fprintf(file, ", "); //Inserir uma "," para separar a 1a vari�vel "cpf", da 2a vari�vel "nome" que ainda ser� inserida 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); 
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); 
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // abrir o arquivo e consultar ("r" read/consultar)
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado. \n"); // informa usu�rio sobre falha no processo
		system("pause");
	}

	while(fgets(conteudo, 200, file) != NULL) // chamada de fun��o para busca da informa��o 
	{
		printf("\n Dados do usu�rio (CPF, Nome, Sobrenome, Cargo): ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");	
	}
	fclose(file);

}


int deletar()
{
	int status;
	char cpf[40]; // cria a vari�vel (no caso string pois cont�m um grupo de informa��es) 
	
	printf("Digite o CPF do registro a ser deletado: "); // Apenas informa o texto ao usu�rio. N�o salva ou registra o valor na vari�vel "cpf".
	scanf("%s",cpf); // Salva o valor na var�vel (o que o usu�rio digitar ser� atrelado � vari�vel cpf) e inicia as buscas. A vari�vel neste caso � uma string (conjunto de vari�veis), por isso usamos "%s".
	
	status = remove(cpf); // Essa fun��o j� ir� deletar o registro. Daqui para baixo, as fun��es s�o somente para caso o arquivo n�o seja encontrado. 	

	if(status == 0) // Fun��o "if" para uma condi��o e a condi��o � se o arquivo for igual a nulo
	{
		printf("Registro removido com sucesso! \n"); //informa ao usu�rio sobre sucesso da opera��o 
		system("pause");	
	}
	else
	{
		printf("Erro ao remover o registro! \n"); //informa ao usu�rio sobre falha da opera��o 
		system("pause");	
	}
	return 0; 
}

int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1; //
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem 
	
		printf("### Cart�rio da EBAC ###\n\n");//Inicio do menu 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:");//Fim do menu

		scanf("%d",&opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) // Inicio da sele��o do menu
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
			
			default: 
			printf("Essa op��o n�o est� dispon�vel\n"); //Fim da sele��o 	
			system("pause");
			break;
		}		
		
	}
	} 	 	
