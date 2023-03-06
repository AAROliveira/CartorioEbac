#include<stdio.h> // biblioteca de comunicacao com o usuário
#include<stdlib.h> // biblioteca de alocação de espaço em memória
#include<locale.h> //biblioteca de alocação de textos por região
#include<string.h> //biblioteca responsável por cuidar das strings

int registro() // Responsável por cadastrar os usuários no sistema
{
	// inicio criação de variáveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", cpf); // %s refere-se a string - usado para salvar uma "string"
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; //comando para acessar o "FILE" (uma função pronta já criada pelo sistema) e criar um "file" (um novo arquivo)
	file = fopen(arquivo, "w");// instrução para o sistema entender de que será composto o "file" a ser criado. O "arquivo" entre parenteses é a copia da variavel "cpf" (instrução duas linhas acima). "w" (write) é o tipo de arquivo. Pode ser write, rewrite ou delete. Escrever um novo "arquivo".
	fprintf(file, cpf); //salvar o valor da variável inserida 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// instrução para o sistema acessar ("a") o arquivo já criado acima.
	fprintf(file, ", "); //Inserir uma "," para separar a 1a variável "cpf", da 2a variável "nome" que ainda será inserida 
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
		printf("Nâo foi possivel abrir o arquivo, não localizado. \n"); // informa usuário sobre falha no processo
		system("pause");
	}

	while(fgets(conteudo, 200, file) != NULL) // chamada de função para busca da informação 
	{
		printf("\n Dados do usuário (CPF, Nome, Sobrenome, Cargo): ");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");	
	}
	fclose(file);

}


int deletar()
{
	int status;
	char cpf[40]; // cria a variável (no caso string pois contém um grupo de informações) 
	
	printf("Digite o CPF do registro a ser deletado: "); // Apenas informa o texto ao usuário. Não salva ou registra o valor na variável "cpf".
	scanf("%s",cpf); // Salva o valor na varável (o que o usuário digitar será atrelado à variável cpf) e inicia as buscas. A variável neste caso é uma string (conjunto de variáveis), por isso usamos "%s".
	
	status = remove(cpf); // Essa função já irá deletar o registro. Daqui para baixo, as funções são somente para caso o arquivo não seja encontrado. 	

	if(status == 0) // Função "if" para uma condição e a condição é se o arquivo for igual a nulo
	{
		printf("Registro removido com sucesso! \n"); //informa ao usuário sobre sucesso da operação 
		system("pause");	
	}
	else
	{
		printf("Erro ao remover o registro! \n"); //informa ao usuário sobre falha da operação 
		system("pause");	
	}
	return 0; 
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1; //
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem 
	
		printf("### Cartório da EBAC ###\n\n");//Inicio do menu 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção:");//Fim do menu

		scanf("%d",&opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) // Inicio da seleção do menu
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
			
			default: 
			printf("Essa opção não está disponível\n"); //Fim da seleção 	
			system("pause");
			break;
		}		
		
	}
	} 	 	
