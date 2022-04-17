/*Projeto prático de AP2S2
Tema 2: Locadora de Automóveis
Alunos: Michelle Tiburcio e Thiane Deprá Saravalle
Prontuários: SC3017311 e SC3013073
Etapa 1*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<time.h> 
#define max 10

//******************************************************
//***********Definindo as Estruturas de Dados***********
//******************************************************

//******************************************************
//Estrutura da Data
typedef struct {
    int dia, mes, ano;
} Data;

//******************************************************
//Estrutura de Clientes
typedef struct {
    char cpf[15], nome[50], endereco[80], telFixo[15], celular[15];
    Data dataNasc;
} Clientes;

//******************************************************
//Estrutura de Veículos
typedef struct {
    char codigo[6], descricao[100], categoria[10], combustivel[10], modelo[30];
    int capacidade;
    Data anoVeiculo;
} Veiculos;

//******************************************************
//Estrutura de Aluguéis
typedef struct {
    char cpf[15], codigo[6];
    Data dataEntrada, dataSaida;
} Alugueis;

//******************************************************
//*****************Definindo as Funções*****************
//******************************************************

//******************************************************
//Função que mostra o Menu principal
void menuPrincipal() {
    printf("\n----------------- MENU DE OPÇÕES -----------------\n");
    printf("\n[1] Submenu de Clientes");
    printf("\n[2] Submenu de Veículos");
    printf("\n[3] Submenu de Alugueis");
    printf("\n[4] Submenu de Relatórios");
    printf("\n[5] Sair\n\n");
}

//******************************************************
//MENU[1] Função que mostra o Submenu de Clientes
void subMenuClientes() {
    printf("\n--------------- SUBMENU DE CLIENTES --------------\n");
    printf("\n[1] Listar todos");
    printf("\n[2] Listar por cpf");
    printf("\n[3] Incluir");
    printf("\n[4] Alterar");
    printf("\n[5] Excluir");
    printf("\n[6] Voltar ao Menu Principal\n\n");
}

//******************************************************
//MENU[2] Função que mostra o Submenu de Veículos
void subMenuVeiculos() {
    printf("\n--------------- SUBMENU DE VEÍCULOS --------------\n");
    printf("\n[1] Listar todos");
    printf("\n[2] Listar por código");
    printf("\n[3] Incluir");
    printf("\n[4] Alterar");
    printf("\n[5] Excluir");
    printf("\n[6] Voltar ao Menu Principal\n\n");
}

//******************************************************
//MENU[3] Função que mostra o Submenu de Aluguéis
void subMenuAlugueis() {
    printf("\n-------------- SUBMENU DE ALUGUÉIS ---------------\n");
    printf("\n[1] Listar todos");
    printf("\n[2] Listar por cpf, código e datas de entrada - saída");
    printf("\n[3] Incluir");
    printf("\n[4] Alterar");
    printf("\n[5] Excluir");
    printf("\n[6] Voltar ao Menu Principal\n\n");
}

//******************************************************
//MENU[4] Função que mostra o Submenu Relatórios
void subMenuRelatorios() {
    printf("\n--------------- SUBMENU RELATÓRIOS ---------------\n");
    printf("\n[1] Listar aluguéis por cpf do cliente");
    printf("\n[2] Listar aluguéis por código do veículo");
    printf("\n[3] Listar aluguéis período de tempo");
    printf("\n[4] Voltar ao Menu Principal\n\n");
}

//******************************************************
//Função que cria exemplos de clientes
void criarExemplosClientes(Clientes cliente[], int *contCliente) {
    //Exemplo Cliente1
    strcpy(cliente[*contCliente].cpf, "111.111.111-11");
    strcpy(cliente[*contCliente].nome, "Maria da Rosa");    
    strcpy(cliente[*contCliente].endereco, "Rua das Orquídeas, nº 1, Centro");
    strcpy(cliente[*contCliente].telFixo, "016 3111-1111");
    strcpy(cliente[*contCliente].celular, "016 99999-9999");
    cliente[*contCliente].dataNasc.dia = 24;
    cliente[*contCliente].dataNasc.mes = 03;
    cliente[*contCliente].dataNasc.ano = 1990;
    (*contCliente)++;
    
    //Exemplo Cliente2
    strcpy(cliente[*contCliente].cpf, "222.222.222-22");
    strcpy(cliente[*contCliente].nome, "Joao da Silva");    
    strcpy(cliente[*contCliente].endereco, "Rua dos Lírios, nº 2, Centro");
    strcpy(cliente[*contCliente].telFixo, "016 3222-2222");
    strcpy(cliente[*contCliente].celular, "016 88888-8888");
    cliente[*contCliente].dataNasc.dia = 15;
    cliente[*contCliente].dataNasc.mes = 04;
    cliente[*contCliente].dataNasc.ano = 1998;
    (*contCliente)++;
}

//******************************************************
//Função que cria exemplos de veículos
void criarExemplosVeiculos(Veiculos veiculo[], int *contVeiculo) {
    //Exemplo Veiculo1
    strcpy(veiculo[*contVeiculo].codigo, "MT001");
    strcpy(veiculo[*contVeiculo].descricao, "motor 1.6, ar-condicionado, ABS ");
    strcpy(veiculo[*contVeiculo].categoria, "hatch");
    veiculo[*contVeiculo].capacidade = 5;
    strcpy(veiculo[*contVeiculo].combustivel, "gasolina");
    strcpy(veiculo[*contVeiculo].modelo, "HB20");
    veiculo[*contVeiculo].anoVeiculo.ano = 2020;
    (*contVeiculo)++;
    
    //Exemplo Veiculo2
    strcpy(veiculo[*contVeiculo].codigo, "MT002");
    strcpy(veiculo[*contVeiculo].descricao, "motor 1.8, automático, ABS");
    strcpy(veiculo[*contVeiculo].categoria, "SUV");
    veiculo[*contVeiculo].capacidade = 5;
    strcpy(veiculo[*contVeiculo].combustivel, "flex");
    strcpy(veiculo[*contVeiculo].modelo, "Jeep Renegade");
    veiculo[*contVeiculo].anoVeiculo.ano = 2021;
    (*contVeiculo)++;
}

//******************************************************
//Função que cria exemplos de aluguéis
void criarExemplosAlugueis(Alugueis aluguel[], int *contAluguel) {
    //Exemplo Aluguel1
    strcpy(aluguel[*contAluguel].cpf, "111.111.111-11");
    strcpy(aluguel[*contAluguel].codigo, "MT001");
	aluguel[*contAluguel].dataEntrada.dia = 15;
	aluguel[*contAluguel].dataEntrada.mes = 04;
	aluguel[*contAluguel].dataEntrada.ano = 2022;
	aluguel[*contAluguel].dataSaida.dia = 15;
	aluguel[*contAluguel].dataSaida.mes = 04;
	aluguel[*contAluguel].dataSaida.ano = 2022;
	(*contAluguel)++;
	
    //Exemplo Aluguel2
    strcpy(aluguel[*contAluguel].cpf, "222.222.222-22");
    strcpy(aluguel[*contAluguel].codigo, "MT002");
	aluguel[*contAluguel].dataEntrada.dia = 10;
	aluguel[*contAluguel].dataEntrada.mes = 04;
	aluguel[*contAluguel].dataEntrada.ano = 2022;
	aluguel[*contAluguel].dataSaida.dia = 12;
	aluguel[*contAluguel].dataSaida.mes = 0;
	aluguel[*contAluguel].dataSaida.ano = 2022;
    (*contAluguel)++;
}

//******************************************************
//Função que verifica a existência do CPF do cliente
int buscarCpf(Clientes cliente[], char *cpf, int *contCliente) {
    int i, verifica = 0;
    
    for(i = 0; i < *contCliente; i++) {       
        if(strcmp(cliente[i].cpf, cpf) == 0) { //strcmp compara duas strings e retorna 0 se forem iguais
            verifica = 1; // cpf existe
            return i;
        }
    }
    return -1; //cpf não existe
}

//******************************************************
//Função que verifica a existência do codigo do veículo
int buscarCodigo(Veiculos veiculo[], char *codigo, int *contVeiculo) {
    int i, verifica = 0;
    
    for(i = 0; i < *contVeiculo; i++) {       
        if(strcmp(veiculo[i].codigo, codigo) == 0) {
            verifica = 1;
            return i;
        }
    }
    return -1;
}

//******************************************************
//Função que verifica no aluguel a existencia do cpf do cliente, codigo do veiculo e as datas de entrada e saida
int buscarAluguel(Alugueis aluguel[], char *cpf, char *codigo, int *contAluguel, int *dia, int *mes, int *ano) {
	int i, verifica = 0;
    
    for(i = 0; i < *contAluguel; i++) {
		   
        if(strcmp(aluguel[i].cpf, cpf) == 0 && strcmp(aluguel[i].codigo, codigo) == 0 && 
 		aluguel[i].dataEntrada.dia == *dia && aluguel[i].dataEntrada.mes == *mes && aluguel[i].dataEntrada.ano == *ano &&
 		aluguel[i].dataSaida.dia, *dia && aluguel[i].dataSaida.mes == *mes && aluguel[i].dataSaida.ano == *ano) {
            verifica = 1;
            return i;
        }
    }
    return -1;
}

//******************************************************
//MENU[1][1] Função que lista os dados de todos os clientes
void listarTodosClientes(Clientes cliente[], int *contCliente) {
    int i;
    
    for(i = 0; i < *contCliente; i++) {
        printf("\n--- Dados do Cliente %d ---\n", i + 1);
        printf("\nNome: %s", cliente[i].nome);
        printf("\nCpf: %s", cliente[i].cpf);
        printf("\nEndereço: %s", cliente[i].endereco);  
        printf("\nTelefone Fixo: %s", cliente[i].telFixo);
        printf("\nCelular: %s", cliente[i].telFixo);
        printf("\nData de Nascimento: %d/%d/%d", cliente[i].dataNasc.dia, cliente[i].dataNasc.mes, cliente[i].dataNasc.ano);
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[1][2] Função que lista o cliente por CPF
void listarClientesPorCpf(Clientes cliente[], int *contCliente) {
	char cpf [15];
	int posicao = -1;	
	
	fflush(stdin);
 	printf("\nDigite o cpf do cliente: ");
	gets(cpf); 
	
	posicao = buscarCpf(cliente, cpf, contCliente);
    
    if (posicao != -1){
    	printf("\n--- Dados do Cliente ---\n");
        printf("\nNome: %s", cliente[posicao].nome);
        printf("\nCpf: %s", cliente[posicao].cpf);
        printf("\nEndereço: %s", cliente[posicao].endereco);  
        printf("\nTelefone Fixo: %s", cliente[posicao].telFixo);
        printf("\nCelular: %s", cliente[posicao].telFixo);
        printf("\nData de Nascimento: %d/%d/%d", cliente[posicao].dataNasc.dia, cliente[posicao].dataNasc.mes, cliente[posicao].dataNasc.ano);
        printf("\n\n--------------------------------------------------\n");
    }
    else {
    	printf("\nO cpf %s não é cadastrado.", cpf);
    	printf("\n\n--------------------------------------------------\n");
	}
}
    
//******************************************************
//MENU[1][3] Função que inclui novos clientes
void incluirCliente(Clientes cliente[], int *contCliente) {
	char cpf [15];
	int posicao = -1;
	
    printf("\n--- Digite os dados do Cliente %d ---\n", *contCliente + 1);    
    fflush(stdin);
    printf("\nDigite o cpf: ");
	gets(cpf);
		
	posicao = buscarCpf(cliente, cpf, contCliente);
    
    if (posicao != -1) {
		printf("\nO cpf %s já existe. Tente outro cpf!", cpf);
		printf("\n\n--------------------------------------------------\n");			
	}
	else {  
    	strcpy(cliente[*contCliente].cpf, cpf);//strcpy copia o cpf digitado para o cpf do vetor
		fflush(stdin); 
    	printf("\nDigite o nome: ");
   		gets(cliente[*contCliente].nome); 
    	printf("\nDigite o endereço: ");
    	gets(cliente[*contCliente].endereco);
    	printf("\nDigite o telefone fixo: ");
    	gets(cliente[*contCliente].telFixo);
    	printf("\nDigite o celular: ");
    	gets(cliente[*contCliente].celular);
    	fflush(stdin);
    	printf("\nDigite o dia de nascimento: ");
    	scanf("%d", &cliente[*contCliente].dataNasc.dia);
    	printf("\nDigite o mês de nascimento: ");
    	scanf("%d", &cliente[*contCliente].dataNasc.mes);
    	printf("\nDigite o ano de nascimento: ");
    	scanf("%d", &cliente[*contCliente].dataNasc.ano);
    	(*contCliente)++;
    
    	printf("\n\nCliente cadastrado com sucesso!\n");	
    	printf("\n\n--------------------------------------------------\n");
	}
}

//******************************************************
//MENU[1][4] Função que altera os dados dos cliente
void alterarCliente(Clientes cliente[], int *contCliente) {
	char cpf [15];
	int posicao = -1;	
	
	fflush(stdin);
 	printf("\nDigite o cpf do cliente: ");
	gets(cpf); 
	
	posicao = buscarCpf(cliente, cpf, contCliente);
    
    if (posicao != -1){
    	printf("\n\n--------------------------------------------------\n");
		fflush(stdin);
		printf("\nDigite o nome: ");
    	gets(cliente[posicao].nome);
		printf("\nDigite o endereço: ");
    	gets(cliente[posicao].endereco);
    	printf("\nDigite o telefone fixo: ");
    	gets(cliente[posicao].telFixo);
    	printf("\nDigite o celular: ");
    	gets(cliente[posicao].celular);
    	fflush(stdin);
    	printf("\nDigite o dia de nascimento: ");
    	scanf("%d", &cliente[posicao].dataNasc.dia);
    	printf("\nDigite o mês de nascimento: ");
    	scanf("%d", &cliente[posicao].dataNasc.mes);
    	printf("\nDigite o ano de nascimento: ");
    	scanf("%d", &cliente[posicao].dataNasc.ano);
        printf("\n\nCliente alterado com sucesso!\n");	
        printf("\n\n--------------------------------------------------\n");
 	}
 	else {
    	printf("\nO cpf %s não é cadastrado.", cpf);
    	printf("\n\n--------------------------------------------------\n");
	}
 }

//******************************************************
//MENU[1][5] Função que exclui o cliente por CPF
void excluirCliente(Clientes cliente[], int *contCliente) {
    int i, posicao;
    char cpf[15];
    fflush(stdin);
    printf("\nDigite o cpf do cliente: ");
    gets(cpf);
    posicao = buscarCpf(cliente, cpf, contCliente);
    if (posicao !=-1){
        for(i = posicao; i < *contCliente-1; i++) {
        	cliente[i] = cliente[i+1];    
        }
        printf("\nCliente excluído com sucesso!");
		printf("\n\n--------------------------------------------------\n");
    } else {
        printf("Cpf não cadastrado.");
        printf("\n\n--------------------------------------------------\n");
    }
    (*contCliente)--;
}

//******************************************************
//MENU[2][1] Função que lista os dados de todos os veículos
void listarTodosVeiculos(Veiculos veiculo[], int *contVeiculo ) {
    int i;
    
    for(i = 0; i < *contVeiculo; i++) {
        printf("\n--- Dados do Veículo %d ---\n", i + 1);
        printf("\nCódigo: %s", veiculo[i].codigo);
        printf("\nDescrição: %s", veiculo[i].descricao);
        printf("\nCategoria: %s", veiculo[i].categoria);  
        printf("\nCapacidade: %d", veiculo[i].capacidade);
        printf("\nTipo de combustivel: %s", veiculo[i].combustivel);
        printf("\nModelo: %s", veiculo[i].modelo);
        printf("\nAno: %d", veiculo[i].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[2][2] Função que lista o veículo por código
void listarVeiculoPorCodigo(Veiculos veiculo[], int *contVeiculo) {		
	char codigo [6];
	int posicao = -1;	
	
	fflush(stdin);
 	printf("\nDigite o código do veículo: ");
	gets(codigo); 
	
	posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1){
		printf("\n--- Dados do Veículo ---\n");
        printf("\nCódigo: %s", veiculo[posicao].codigo);
        printf("\nDescrição: %s", veiculo[posicao].descricao);
        printf("\nCategoria: %s", veiculo[posicao].categoria);  
        printf("\nCapacidade: %d", veiculo[posicao].capacidade);
        printf("\nTipo de combustivel: %s", veiculo[posicao].combustivel);
        printf("\nModelo: %s", veiculo[posicao].modelo);
        printf("\nAno: %d", veiculo[posicao].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
    	}
    	else {
    		printf("\nO código %s não é cadastrado.", codigo);
    		printf("\n\n--------------------------------------------------\n");
		}
    }

//******************************************************
//MENU [2][3] Função que inclui novos veículos
void incluirVeiculo(Veiculos veiculo[], int *contVeiculo ) {
	char codigo [6];
	int posicao = -1;
	
	printf("\n--- Digite os dados do Veículo %d ---\n", *contVeiculo + 1);
    fflush(stdin);
	printf("\nDigite o código: ");
    gets(codigo);    
		
	posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1) {
		printf("\nO código %s já existe. Tente outro código!", codigo);
		printf("\n\n--------------------------------------------------\n");			
	}
	else {  
    	strcpy(veiculo[*contVeiculo].codigo, codigo);
    	fflush(stdin);
    	printf("\nDigite a descricao: ");
    	gets(veiculo[*contVeiculo].descricao);
    	printf("\nDigite a categoria: ");
    	gets(veiculo[*contVeiculo].categoria);
    	fflush(stdin);
		printf("\nDigite a capacidade: ");
    	scanf("%d", &veiculo[*contVeiculo].capacidade);
    	fflush(stdin);
    	printf("\nDigite o tipo de combustível: ");
    	gets(veiculo[*contVeiculo].combustivel);
    	printf("\nDigite o modelo: ");
    	gets(veiculo[*contVeiculo].modelo);
    	fflush(stdin);
    	printf("\nDigite o ano: ");
    	scanf("%d", &veiculo[*contVeiculo].anoVeiculo.ano);
    
    	printf("\n\nVeiculo alterado com sucesso!\n");	
    	printf("\n\n--------------------------------------------------\n");
    	(*contVeiculo)++;
   }
}


//******************************************************
//MENU [2][4] Função que altera os dados dos veículo
void alterarVeiculo(Veiculos veiculo[], int *contVeiculo) {
	char codigo [6];
	int posicao = -1;	
	
	fflush(stdin);
 	printf("\nDigite o código do veículo: ");
	gets(codigo); 
	
	posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1){
    	printf("\n\n--------------------------------------------------\n");
		fflush(stdin);
		printf("\nDigite a descricao: ");
    	gets(veiculo[posicao].descricao);
    	printf("\nDigite a categoria: ");
    	gets(veiculo[posicao].categoria);
    	fflush(stdin);
    	printf("\nDigite a capacidade: ");
	    scanf("%d", &veiculo[posicao].capacidade);
	    fflush(stdin);
		printf("\nDigite o tipo de combustível: ");
   		gets(veiculo[posicao].combustivel);
    	printf("\nDigite o modelo: ");
    	gets(veiculo[posicao].modelo);
    	fflush(stdin);
    	printf("\nDigite o ano: ");
    	scanf("%d", &veiculo[posicao].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
        
        printf("\nVeículo alterado com sucesso!!");
		printf("\n\n--------------------------------------------------\n");
 	}
 	else {
    	printf("\nO código %s não é cadastrado.", codigo);
    	printf("\n\n--------------------------------------------------\n");
	}
 }

//******************************************************
//MENU[2][5] Função que exclui o veículo por código
void excluirVeiculo(Veiculos veiculo[], int *contVeiculo) {
    int i, posicao;
    char codigo[6];
    
    fflush(stdin);
    printf("\nDigite o código do veículo: ");
    gets(codigo);
    
    posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1) {
        for(i = posicao; i < *contVeiculo - 1; i++) {
            veiculo[i] = veiculo[i + 1];
        }
        printf("\nVeículo excluído com sucesso!!");
		printf("\n\n--------------------------------------------------\n");
    } else {
        printf("Código do veículo não é cadastrado.");
		printf("\n\n--------------------------------------------------\n");
    }
    (*contVeiculo)--;
}

//******************************************************
//MENU[3][1] Função que lista os dados de todos os alugueis
void listarTodosAlugueis(Alugueis aluguel[], int *contAluguel) {
    int i;
    
    for(i = 0; i < *contAluguel; i++) {
        printf("\n--- Dados do Aluguel %d ---\n", i + 1);
        printf("\nCpf do Cliente: %s", aluguel[i].cpf);
        printf("\nCódigo do veículo: %s", aluguel[i].codigo);
        printf("\nData de Entrada: %d/%d/%d", aluguel[i].dataEntrada.dia, aluguel[i].dataEntrada.mes, aluguel[i].dataEntrada.ano);
        printf("\nData de Saída: %d/%d/%d", aluguel[i].dataSaida.dia, aluguel[i].dataSaida.mes, aluguel[i].dataSaida.ano);
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[3][2] Função que lista o veículo por código
void listarAluguelPorTodosOsParametros(Alugueis aluguel[], int *contAluguel, Clientes cliente[], int *contClient, Veiculos veiculos[], int *contVeiculo) {
	char cpf [15], codigo [6];
	int posicaoAluguel, posicaoCpf, posicaoCodigo, dia, mes, ano;
	/*
	fflush(stdin);
 	printf("\nDigite o código do veículo: ");
	gets(codigo); 
	
	posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1){
		printf("\n--- Dados do Veículo ---\n");
        printf("\nCódigo: %s", veiculo[posicao].codigo);
        printf("\nDescrição: %s", veiculo[posicao].descricao);
        printf("\nCategoria: %s", veiculo[posicao].categoria);  
        printf("\nCapacidade: %d", veiculo[posicao].capacidade);
        printf("\nTipo de combustivel: %s", veiculo[posicao].combustivel);
        printf("\nModelo: %s", veiculo[posicao].modelo);
        printf("\nAno: %d", veiculo[posicao].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
    	}
    	else {
    		printf("\nO código %s não é cadastrado.", codigo);
    		printf("\n\n--------------------------------------------------\n");
		}
    }*/
}

//******************************************************
//MENU[3][3] Função que inclui um novo aluguel
void incluirAluguel(Alugueis aluguel[], int *contAluguel) {
	
	printf("\n--- Digite os dados do aluguel %d ---\n", *contAluguel + 1);
	printf("\nDigite o cpf: ");
	gets(aluguel[*contAluguel].cpf);
	//verifica se CPF está cadastrado
    printf("\nDigite o código do veículo: ");
	gets(aluguel[*contAluguel].codigo);  
	//verifica se Código está cadastrado
	printf("\nDigite o dia da data de entrada: ");
    scanf("%d", &aluguel[*contAluguel].dataEntrada.dia);
    printf("\nDigite o mês de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataEntrada.mes);
    printf("\nDigite o ano de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataEntrada.ano);
	printf("\nDigite o dia da data de saída: ");
    scanf("%d", &aluguel[*contAluguel].dataSaida.dia);
    printf("\nDigite o mês de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataSaida.mes);
    printf("\nDigite o ano de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataSaida.ano);
    (*contAluguel)++;
}

//******************************************************
//MENU[3][4] Função que altera aluguel com todos os dados
void alterarAluguel(Alugueis aluguel[], int *contAluguel) {
}

//******************************************************
//MENU[3][5] Função que lista o veículo por código
void excluirAluguel(Alugueis aluguel[], int *contAluguel) {
	
}

//******************************************************
//MENU[4][1] Função que mostra o relatório dos aluguéis por cpf do cliente
void listarAlugueisPorCpf() {
	
}

//******************************************************
//MENU[4][2] Função que mostra o relatório dos aluguéis por código do veículo
void listarAlugueisPorCodigo() {
	
}

//******************************************************
//MENU[4][3] Função que mostra o relatório dos aluguéis por período de tempo
void listarAlugueisPorTempo() {
	
}

//******************************************************
//Função principal- chama as demais funções do código
main() {
    setlocale(LC_ALL, "Portuguese");
    
    int contCliente = 0, contVeiculo = 0, contAluguel = 0, opcaoMenu = -1, opcaoSubmenu = -1;
    
    Clientes cliente[max];
    Veiculos veiculo[max];
    Alugueis aluguel[max];
    
    printf("--------------------------------------------------");
    printf("\n-------------- LOCADORA DE VEÍCULOS --------------");
    printf("\n--------------------------------------------------\n\n");
    
    criarExemplosClientes(cliente, &contCliente);
    criarExemplosVeiculos(veiculo, &contVeiculo);
    criarExemplosAlugueis(aluguel, &contAluguel);  
        
    do {
        menuPrincipal();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcaoMenu);
        switch(opcaoMenu){
            
            case 1:
                
                do {
                	system("cls");
                    subMenuClientes();
                    printf("\nDigite a opção desejada: ");
                    scanf("%d", &opcaoSubmenu);
                    switch(opcaoSubmenu){
                        case 1:
                        	system("cls");
                            printf("\n\t------ LISTAR TODOS OS CLIENTES ------\n\n");
                            listarTodosClientes(cliente, &contCliente); 
                           	system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                        	printf("\n\t------ LISTAR CLIENTE POR CPF ------\n\n");                                                
                            listarClientesPorCpf(cliente, &contCliente);
                            system("Pause"); 
                            break;
                        case 3:
                        	system("cls");
                        	printf("\n\t------ INCLUIR CLIENTE ------\n\n");
                            incluirCliente(cliente, &contCliente);
                            system("Pause"); 
                            break;
                        case 4:
                        	system("cls");
                        	printf("\n\t------ ALTERAR CLIENTE ------\n\n");
                           	alterarCliente(cliente, &contCliente);   
							system("Pause");                                               	
                            break;
                        case 5:
                        	system("cls");
                        	printf("\n\t------ EXCLUIR CLIENTE ------\n\n");
							excluirCliente(cliente, &contCliente);
                          	system("Pause");  
                            break;
                        case 6: 
                            printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                            break;      
                        default:
                            printf("\n\t******* Digite uma opção válida! *******\n\n");
                    }
                }
                while (opcaoSubmenu!=6);
                break;
            //Submenu de Veículos
            case 2:
                
                do{
                    system("cls");
                    subMenuVeiculos();
                    printf("\nDigite a opção desejada: ");
                    scanf("%d", &opcaoSubmenu);
                    switch(opcaoSubmenu){
                        case 1:
                        	system("cls");
                            printf("\n\t------ LISTAR TODOS OS VEÍCULOS ------\n\n");
                            listarTodosVeiculos(veiculo, &contVeiculo); 
                            system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                            printf("\n\t------ LISTAR VEÍCULOS POR CÓDIGO ------\n\n"); 
					  		listarVeiculoPorCodigo(veiculo, &contVeiculo); 
					  		system("Pause");
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ INCLUIR VEÍCULO ------\n\n");
                            incluirVeiculo(veiculo, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 4:
                        	system("cls");
                            printf("\n\t------ ALTERAR VEÍCULO ------\n\n");
                            alterarVeiculo(veiculo, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 5:
                            system("cls");
                            printf("\n\t------ EXCLUIR VEÍCULO ------\n\n");
                            excluirVeiculo(veiculo, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 6: 
                            printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                            break;      
                        default:
                            printf("\n\t******* Digite uma opção válida! *******");
                    }   
                }
                while (opcaoSubmenu!=6);
                break;
            //Submenu de Alugueis
            case 3:
                
                do{
                	system("cls");
                    subMenuAlugueis();
                    printf("\nDigite a opção desejada: ");
                    scanf("%d", &opcaoSubmenu);
                    switch(opcaoSubmenu){
                        case 1:
                        	system("cls");
                            printf("\n\t------ LISTAR TODOS OS ALUGUÉIS ------\n\n");
                            listarTodosAlugueis(aluguel, &contAluguel); 
                            system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGUEL POR CPF, CÓDIGO, DATAS DE ENTRADA E SAÍDA ------\n\n");   
                            system("Pause"); 
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ INCLUIR ALUGUEL ------\n");
                            incluirAluguel(aluguel, &contAluguel);
                            system("Pause"); 
                            break;
                        case 4:
                        	system("cls");
                            printf("\n\t------ ALTERAR ALUGUEL ------\n\n");
                            alterarAluguel(aluguel, &contAluguel);
                            system("Pause"); 
                            break;
                        case 5:
                        	system("cls");
                            printf("\n\t------ EXCLUIR ALUGUEL ------\n\n");
                            excluirAluguel(aluguel, &contAluguel);
                            system("Pause"); 
                            break;
                        case 6: 
                            printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                            break;      
                        default:
                            printf("\n\t******* Digite uma opção válida! *******\n\n");
                    }   
                }
                while (opcaoSubmenu!=6);
                break;
            //Submenu de Relatórios
            case 4:
                
                do{
                	system("cls");
                    subMenuRelatorios();
                    printf("\nDigite a opção desejada: ");
                    scanf("%d", &opcaoSubmenu);
                    switch(opcaoSubmenu){
                        case 1:
                           system("cls");
                            printf("\n\t------ LISTAR ALUGUÉIS POR CPF DO CLIENTE ------\n\n");
                            system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGUÉIS: CÓDIGO DE VEÍCULO ------\n\n");
                            incluirAluguel(aluguel, &contAluguel);
                            system("Pause"); 
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGUÉIS: PERÍODO DE TEMPO ------\n\n");
                            system("Pause"); 
                            break;
                        case 4:
                        	printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                        	system("Pause"); 
                            break;                        	                           
                        default:
                            printf("\n\t******* Digite uma opção válida! *******\n\n");
                    }   
                }
                while (opcaoSubmenu!=4); //Mi confere se é isso mesmo? tinha mais opções e acabei tirando
                break;
            default:
                printf("\n\t******* Digite uma opção válida! *******\n\n");           
        }
    }
    while (opcaoMenu!=5);
}
