/*Projeto pr�tico de AP2S2
Tema 2: Locadora de Autom�veis
Alunos: Michelle Tiburcio e Thiane Depr� Saravalle
Prontu�rios: SC3017311 e SC3013073
Etapa 1*/

//fazer um if pra ver se o contador passou do tamanho do vetor
//cadastro aquivo bin�rio
//exclus�o acessa o arquivo binario, carrega na memoria, (manipula da memoria) remove, d� pra dar um free (que remover da memoria e salva no arquivo)
//relat�rios em arquivos textos

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
typedef struct { //thiane
    char cpf[15], nome[50], endereco[80], telFixo[15], celular[15];
    Data dataNasc;
} Clientes;

//******************************************************
//Estrutura de Ve�culos
typedef struct { //thiane
    char codigo[6], descricao[100], categoria[10], combustivel[10], modelo[30];
    int capacidade;
    Data anoVeiculo;
} Veiculos;

//******************************************************
//Estrutura de Alugu�is
typedef struct { //thiane
    char cpf[15], codigo[6];
    Data dataEntrada, dataSaida;
} Alugueis, AlugueisPorCpf;

//******************************************************
//*****************Definindo as Fun��es*****************
//******************************************************

//******************************************************
//Fun��o que mostra o Menu principal  //michelle
void menuPrincipal() {
    printf("\n----------------- MENU DE OP��ES -----------------\n");
    printf("\n[1] Submenu de Clientes");
    printf("\n[2] Submenu de Ve�culos");
    printf("\n[3] Submenu de Alugueis");
    printf("\n[4] Submenu de Relat�rios");
    printf("\n[5] Sair\n\n");
}

//******************************************************
//MENU[1] Fun��o que mostra o Submenu de Clientes 
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
//MENU[2] Fun��o que mostra o Submenu de Ve�culos
void subMenuVeiculos() {
    printf("\n--------------- SUBMENU DE VE�CULOS --------------\n");
    printf("\n[1] Listar todos");
    printf("\n[2] Listar por c�digo");
    printf("\n[3] Incluir");
    printf("\n[4] Alterar");
    printf("\n[5] Excluir");
    printf("\n[6] Voltar ao Menu Principal\n\n");
}

//******************************************************
//MENU[3] Fun��o que mostra o Submenu de Alugu�is
void subMenuAlugueis() {
    printf("\n-------------- SUBMENU DE ALUGU�IS ---------------\n");
    printf("\n[1] Listar todos");
    printf("\n[2] Listar por cpf, c�digo, datas de entrada e sa�da");
    printf("\n[3] Incluir");
    printf("\n[4] Alterar");
    printf("\n[5] Excluir");
    printf("\n[6] Voltar ao Menu Principal\n\n");
}

//******************************************************
//MENU[4] Fun��o que mostra o Submenu Relat�rios
void subMenuRelatorios() {
    printf("\n--------------- SUBMENU RELAT�RIOS ---------------\n");
    printf("\n[1] Listar alugu�is por cpf do cliente");
    printf("\n[2] Listar alugu�is por c�digo do ve�culo");
    printf("\n[3] Listar alugu�is per�odo de tempo");
    printf("\n[4] Voltar ao Menu Principal\n\n");
}

//******************************************************
//Fun��o que cria exemplos de clientes           passando a vari�vel por refer�ncia
void criarExemplosClientes(Clientes cliente[], int *contCliente) { 
    //Exemplo Cliente1
    strcpy(cliente[*contCliente].cpf, "111.111.111-11");
    strcpy(cliente[*contCliente].nome, "Maria da Rosa");    
    strcpy(cliente[*contCliente].endereco, "Rua das Orqu�deas, n� 1, Centro");
    strcpy(cliente[*contCliente].telFixo, "016 3111-1111");
    strcpy(cliente[*contCliente].celular, "016 99999-9999");
    cliente[*contCliente].dataNasc.dia = 24;
    cliente[*contCliente].dataNasc.mes = 03;
    cliente[*contCliente].dataNasc.ano = 1990;
    (*contCliente)++;
    
    //Exemplo Cliente2
    strcpy(cliente[*contCliente].cpf, "222.222.222-22");
    strcpy(cliente[*contCliente].nome, "Joao da Silva");    
    strcpy(cliente[*contCliente].endereco, "Rua dos L�rios, n� 2, Centro");
    strcpy(cliente[*contCliente].telFixo, "016 3222-2222");
    strcpy(cliente[*contCliente].celular, "016 88888-8888");
    cliente[*contCliente].dataNasc.dia = 15;
    cliente[*contCliente].dataNasc.mes = 04;
    cliente[*contCliente].dataNasc.ano = 1998;
    (*contCliente)++;
}

//******************************************************
//Fun��o que cria exemplos de ve�culos
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
    strcpy(veiculo[*contVeiculo].descricao, "motor 1.8, autom�tico, ABS");
    strcpy(veiculo[*contVeiculo].categoria, "SUV");
    veiculo[*contVeiculo].capacidade = 5;
    strcpy(veiculo[*contVeiculo].combustivel, "flex");
    strcpy(veiculo[*contVeiculo].modelo, "Jeep Renegade");
    veiculo[*contVeiculo].anoVeiculo.ano = 2021;
    (*contVeiculo)++;
}

//******************************************************
//Fun��o que cria exemplos de alugu�is
void criarExemplosAlugueis(Alugueis aluguel[], int *contAluguel) {
    //Exemplo Aluguel1
    strcpy(aluguel[*contAluguel].cpf, "111.111.111-11");
    strcpy(aluguel[*contAluguel].codigo, "MT001");
	aluguel[*contAluguel].dataEntrada.dia = 15;
	aluguel[*contAluguel].dataEntrada.mes = 04;
	aluguel[*contAluguel].dataEntrada.ano = 2022;
	aluguel[*contAluguel].dataSaida.dia = 18;
	aluguel[*contAluguel].dataSaida.mes = 04;
	aluguel[*contAluguel].dataSaida.ano = 2022;
	(*contAluguel)++;
	
    //Exemplo Aluguel2
    strcpy(aluguel[*contAluguel].cpf, "222.222.222-22");
    strcpy(aluguel[*contAluguel].codigo, "MT002");
	aluguel[*contAluguel].dataEntrada.dia = 15;
	aluguel[*contAluguel].dataEntrada.mes = 04;
	aluguel[*contAluguel].dataEntrada.ano = 2022;
	aluguel[*contAluguel].dataSaida.dia = 18;
	aluguel[*contAluguel].dataSaida.mes = 04;
	aluguel[*contAluguel].dataSaida.ano = 2022;
    (*contAluguel)++;
    
    //Exemplo Aluguel3
    strcpy(aluguel[*contAluguel].cpf, "111.111.111-11");
    strcpy(aluguel[*contAluguel].codigo, "MT002");
	aluguel[*contAluguel].dataEntrada.dia = 25;
	aluguel[*contAluguel].dataEntrada.mes = 04;
	aluguel[*contAluguel].dataEntrada.ano = 2022;
	aluguel[*contAluguel].dataSaida.dia = 28;
	aluguel[*contAluguel].dataSaida.mes = 04;
	aluguel[*contAluguel].dataSaida.ano = 2022;
	(*contAluguel)++;
}

//******************************************************
//Fun��o que verifica a exist�ncia do CPF do cliente
int buscarCpf(Clientes cliente[], char cpf[], int *contCliente) { 
    int i, verifica = 0;
    
    for(i = 0; i < *contCliente && verifica == 0; i++) {
	      
        if(strcmp(cliente[i].cpf, cpf) == 0) { //strcmp compara duas strings e retorna 0 se forem iguais
            verifica = 1; // cpf existe
            return i;
        }
        
    }
    return -1; //cpf n�o existe
}

//******************************************************
//Fun��o que verifica a exist�ncia do codigo do ve�culo
int buscarCodigo(Veiculos veiculo[], char codigo[], int *contVeiculo) {
    int i, verifica = 0;
    
    for(i = 0; i < *contVeiculo && verifica == 0; i++) { 
	     
        if(strcmp(veiculo[i].codigo, codigo) == 0) {
            verifica = 1;
            return i;
        }
        
    }
    return -1;
}

//******************************************************
//Fun��o que verifica no aluguel a existencia do cpf do cliente, codigo do veiculo e as datas de entrada e saida
int buscarAluguel(Alugueis aluguel[], char cpf[], char codigo[], int *diaEntrada, int *mesEntrada, int *anoEntrada, int *diaSaida, int *mesSaida, int *anoSaida, int *contAluguel) {
	int i, verifica = 0;
    
    for(i = 0; i < *contAluguel && verifica == 0; i++) {
		   
        if(strcmp(aluguel[i].cpf, cpf) == 0 && strcmp(aluguel[i].codigo, codigo) == 0 && 
 		aluguel[i].dataEntrada.dia == *diaEntrada && aluguel[i].dataEntrada.mes == *mesEntrada && aluguel[i].dataEntrada.ano == *anoEntrada &&
 		aluguel[i].dataSaida.dia == *diaSaida && aluguel[i].dataSaida.mes == *mesSaida && aluguel[i].dataSaida.ano == *anoSaida) {
            verifica = 1;
            return i;
        }
        
    }
    return -1;
}

//******************************************************
//MENU[1][1] Fun��o que lista os dados de todos os clientes
void listarTodosClientes(Clientes cliente[], int *contCliente) {
    int i;
    
    for(i = 0; i < *contCliente; i++) {
        printf("\n--- Dados do Cliente %d ---\n", i + 1);
        printf("\nNome: %s", cliente[i].nome);
        printf("\nCpf: %s", cliente[i].cpf);
        printf("\nEndere�o: %s", cliente[i].endereco);  
        printf("\nTelefone Fixo: %s", cliente[i].telFixo);
        printf("\nCelular: %s", cliente[i].telFixo);
        printf("\nData de Nascimento: %d/%d/%d", cliente[i].dataNasc.dia, cliente[i].dataNasc.mes, cliente[i].dataNasc.ano);
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[1][2] Fun��o que lista o cliente por CPF
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
        printf("\nEndere�o: %s", cliente[posicao].endereco);  
        printf("\nTelefone Fixo: %s", cliente[posicao].telFixo);
        printf("\nCelular: %s", cliente[posicao].telFixo);
        printf("\nData de Nascimento: %d/%d/%d", cliente[posicao].dataNasc.dia, cliente[posicao].dataNasc.mes, cliente[posicao].dataNasc.ano);
        printf("\n\n--------------------------------------------------\n");
    }
    else {
    	printf("\nO cpf %s n�o � cadastrado.", cpf);
    	printf("\n\n--------------------------------------------------\n");
	}
}
    
//******************************************************
//MENU[1][3] Fun��o que inclui novos clientes
void incluirCliente(Clientes cliente[], int *contCliente) {
	char cpf [15];
	int posicao = -1;
	
    printf("\n--- Digite os dados do Cliente %d ---\n", *contCliente + 1);    
    fflush(stdin);
    printf("\nDigite o cpf: ");
	gets(cpf);
		
	posicao = buscarCpf(cliente, cpf, contCliente);
    
    if (posicao != -1) {
		printf("\nO cpf %s j� existe. Tente outro cpf!", cpf);
		printf("\n\n--------------------------------------------------\n");			
	}
	else {  
    	strcpy(cliente[*contCliente].cpf, cpf);//strcpy copia o cpf digitado para o cpf do vetor
		fflush(stdin); 
    	printf("\nDigite o nome: ");
   		gets(cliente[*contCliente].nome); 
    	printf("\nDigite o endere�o: ");
    	gets(cliente[*contCliente].endereco);
    	printf("\nDigite o telefone fixo: ");
    	gets(cliente[*contCliente].telFixo);
    	printf("\nDigite o celular: ");
    	gets(cliente[*contCliente].celular);
    	fflush(stdin);
    	printf("\nDigite o dia de nascimento: ");
    	scanf("%d", &cliente[*contCliente].dataNasc.dia);
    	printf("\nDigite o m�s de nascimento: ");
    	scanf("%d", &cliente[*contCliente].dataNasc.mes);
    	printf("\nDigite o ano de nascimento: ");
    	scanf("%d", &cliente[*contCliente].dataNasc.ano);
    	(*contCliente)++;
    
    	printf("\n\nCliente cadastrado com sucesso!\n");	
    	printf("\n\n--------------------------------------------------\n");
	}
}

//******************************************************
//MENU[1][4] Fun��o que altera os dados dos cliente
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
		printf("\nDigite o endere�o: ");
    	gets(cliente[posicao].endereco);
    	printf("\nDigite o telefone fixo: ");
    	gets(cliente[posicao].telFixo);
    	printf("\nDigite o celular: ");
    	gets(cliente[posicao].celular);
    	fflush(stdin);
    	printf("\nDigite o dia de nascimento: ");
    	scanf("%d", &cliente[posicao].dataNasc.dia);
    	printf("\nDigite o m�s de nascimento: ");
    	scanf("%d", &cliente[posicao].dataNasc.mes);
    	printf("\nDigite o ano de nascimento: ");
    	scanf("%d", &cliente[posicao].dataNasc.ano);
        printf("\n\nCliente alterado com sucesso!\n");	
        printf("\n\n--------------------------------------------------\n");
 	}
 	else {
    	printf("\nO cpf %s n�o � cadastrado.", cpf);
    	printf("\n\n--------------------------------------------------\n");
	}
 }

//******************************************************
//MENU[1][5] Fun��o que exclui o cliente por CPF
void excluirCliente(Clientes cliente[], int *contCliente) { 
    int i, posicao;
    char cpf[15];
    
    fflush(stdin);
    printf("\nDigite o cpf do cliente: ");
    gets(cpf);
    posicao = buscarCpf(cliente, cpf, contCliente);
    
    if (posicao !=-1) {    	
        for(i = posicao; i < *contCliente-1; i++) {
        	cliente[i] = cliente[i+1];    
        }
        printf("\nCliente exclu�do com sucesso!");
		printf("\n\n--------------------------------------------------\n");
		(*contCliente)--;
    } else {
        printf("Cpf n�o � cadastrado.");
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[2][1] Fun��o que lista os dados de todos os ve�culos
void listarTodosVeiculos(Veiculos veiculo[], int *contVeiculo ) {
    int i;
    
    for(i = 0; i < *contVeiculo; i++) {
        printf("\n--- Dados do Ve�culo %d ---\n", i + 1);
        printf("\nC�digo: %s", veiculo[i].codigo);
        printf("\nDescri��o: %s", veiculo[i].descricao);
        printf("\nCategoria: %s", veiculo[i].categoria);  
        printf("\nCapacidade: %d", veiculo[i].capacidade);
        printf("\nTipo de combustivel: %s", veiculo[i].combustivel);
        printf("\nModelo: %s", veiculo[i].modelo);
        printf("\nAno: %d", veiculo[i].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[2][2] Fun��o que lista o ve�culo por c�digo
void listarVeiculoPorCodigo(Veiculos veiculo[], int *contVeiculo) {		
	char codigo [6];
	int posicao = -1;	
	
	fflush(stdin);
 	printf("\nDigite o c�digo do ve�culo: ");
	gets(codigo); 
	
	posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1){
		printf("\n--- Dados do Ve�culo ---\n");
        printf("\nC�digo: %s", veiculo[posicao].codigo);
        printf("\nDescri��o: %s", veiculo[posicao].descricao);
        printf("\nCategoria: %s", veiculo[posicao].categoria);  
        printf("\nCapacidade: %d", veiculo[posicao].capacidade);
        printf("\nTipo de combustivel: %s", veiculo[posicao].combustivel);
        printf("\nModelo: %s", veiculo[posicao].modelo);
        printf("\nAno: %d", veiculo[posicao].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
    	}
    	else {
    		printf("\nO c�digo %s n�o � cadastrado.", codigo);
    		printf("\n\n--------------------------------------------------\n");
		}
    }

//******************************************************
//MENU [2][3] Fun��o que inclui novos ve�culos
void incluirVeiculo(Veiculos veiculo[], int *contVeiculo ) { 
	char codigo [6];
	int posicao = -1;
	
	printf("\n--- Digite os dados do Ve�culo %d ---\n", *contVeiculo + 1);
    fflush(stdin);
	printf("\nDigite o c�digo: ");
    gets(codigo);    
		
	posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1) {
		printf("\nO c�digo %s j� existe. Tente outro c�digo!", codigo);
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
    	printf("\nDigite o tipo de combust�vel: ");
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
//MENU [2][4] Fun��o que altera os dados dos ve�culo
void alterarVeiculo(Veiculos veiculo[], int *contVeiculo) { 
	char codigo [6];
	int posicao = -1;	
	
	fflush(stdin);
 	printf("\nDigite o c�digo do ve�culo: ");
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
		printf("\nDigite o tipo de combust�vel: ");
   		gets(veiculo[posicao].combustivel);
    	printf("\nDigite o modelo: ");
    	gets(veiculo[posicao].modelo);
    	fflush(stdin);
    	printf("\nDigite o ano: ");
    	scanf("%d", &veiculo[posicao].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
        
        printf("\nVe�culo alterado com sucesso!!");
		printf("\n\n--------------------------------------------------\n");
 	}
 	else {
    	printf("\nO c�digo %s n�o � cadastrado.", codigo);
    	printf("\n\n--------------------------------------------------\n");
	}
 }

//******************************************************
//MENU[2][5] Fun��o que exclui o ve�culo por c�digo
void excluirVeiculo(Veiculos veiculo[], int *contVeiculo) {
    int i, posicao;
    char codigo[6];
    
    fflush(stdin);
    printf("\nDigite o c�digo do ve�culo: ");
    gets(codigo);
    
    posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1) {
        for(i = posicao; i < *contVeiculo - 1; i++) {
            veiculo[i] = veiculo[i + 1];
        }
        printf("\nVe�culo exclu�do com sucesso!!");
		printf("\n\n--------------------------------------------------\n");
		(*contVeiculo)--;
    } else {
        printf("C�digo do ve�culo n�o � cadastrado.");
		printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[3][1] Fun��o que lista os dados de todos os alugueis
void listarTodosAlugueis(Alugueis aluguel[], int *contAluguel) { 
    int i;
    
    for(i = 0; i < *contAluguel; i++) {
        printf("\n--- Dados do Aluguel %d ---\n", i + 1);
        printf("\nCpf do Cliente: %s", aluguel[i].cpf);
        printf("\nC�digo do ve�culo: %s", aluguel[i].codigo);
        printf("\nData de Entrada: %d/%d/%d", aluguel[i].dataEntrada.dia, aluguel[i].dataEntrada.mes, aluguel[i].dataEntrada.ano);
        printf("\nData de Sa�da: %d/%d/%d", aluguel[i].dataSaida.dia, aluguel[i].dataSaida.mes, aluguel[i].dataSaida.ano);
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//MENU[3][2] Fun��o que lista o ve�culo por cpf, c�digo e datas de entrada e sa�da
void listarAluguelPorChaves(Alugueis aluguel[], Clientes cliente[], Veiculos veiculo[], int *contAluguel, int *contCliente, int *contVeiculo) { //fizemos juntas numa call
	char cpf [15], codigo [6];
	int posicaoAluguel, posicaoCpf, posicaoCodigo, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida;
	
	fflush(stdin);
 	printf("\nDigite o cpf do cliente que deseja obter o aluguel: ");
	gets(cpf);
	
	printf("\nDigite o c�digo do ve�culo: ");
	gets(codigo);
				
	printf("\nDigite a data de entrada: ");
	printf("\nDia (dd): ");
	scanf("%d", &diaEntrada);
	printf("M�s (mm): ");
    scanf("%d", &mesEntrada);
    printf("Ano (aaaa): ");
    scanf("%d", &anoEntrada);
    		
    printf("\nDigite a data de sa�da: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaSaida);
    printf("M�s (mm): ");
    scanf("%d", &mesSaida);
    printf("Ano (aaaa): ");
	scanf("%d", &anoSaida);
			
	posicaoAluguel = buscarAluguel(aluguel, cpf, codigo, &diaEntrada, &mesEntrada, &anoEntrada, &diaSaida, &mesSaida, &anoSaida, contAluguel);
			
	if (posicaoAluguel != -1) {
		printf("\n\n--------------------------------------------------\n");
		printf("\n--- Dados do Aluguel ---\n");
		printf("\nCpf do Cliente: %s", cliente[posicaoCpf].cpf);
    	printf("\nC�digo do ve�culo: %s", veiculo[posicaoCodigo].codigo);
    	printf("\nData de Entrada: %d/%d/%d", aluguel[posicaoAluguel].dataEntrada.dia, aluguel[posicaoAluguel].dataEntrada.mes, aluguel[posicaoAluguel].dataEntrada.ano);
    	printf("\nData de Sa�da: %d/%d/%d", aluguel[posicaoAluguel].dataSaida.dia, aluguel[posicaoAluguel].dataSaida.mes, aluguel[posicaoAluguel].dataSaida.ano);
    	printf("\n\n--------------------------------------------------\n");				
				
	} else {
		printf("\nN�o exite alugu�is com cpf %s e c�digo %s nessas datas.", cpf, codigo);
		printf("\n\n--------------------------------------------------\n");
	}
}
 
//******************************************************
//MENU[3][3] Fun��o que inclui um novo aluguel
void incluirAluguel(Alugueis aluguel[], Clientes cliente[], Veiculos veiculo[], int *contAluguel) {
	char cpf [15], codigo [6];
    int posicaoAluguel, posicaoCpf, posicaoCodigo, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida;
    
	fflush(stdin);
    printf("\nDigite o cpf do cliente que deseja obter o aluguel: ");
    gets(cpf);
    
	printf("\nDigite o c�digo do ve�culo: ");
    gets(codigo);
        
	printf("\nDigite a data de entrada: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaEntrada);
    printf("M�s (mm): ");
    scanf("%d", &mesEntrada);
    printf("Ano (aaaa): ");
    scanf("%d", &anoEntrada);
    printf("\nDigite a data de sa�da: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaSaida);
    printf("M�s (mm): ");
    scanf("%d", &mesSaida);
    printf("Ano (aaaa): ");
    scanf("%d", &anoSaida);
            
	posicaoAluguel = buscarAluguel(aluguel, cpf, codigo, &diaEntrada, &mesEntrada, &anoEntrada, &diaSaida, &mesSaida, &anoSaida, contAluguel);
    printf("Posi��o aluguel: %d",posicaoAluguel );
            
	if (posicaoAluguel == -1) { //-1 � PQ O ALUGUEL N�O EXISTE, ENT�O PODE CADASTRAR
        strcpy(aluguel[*contAluguel].cpf, cpf); 
        strcpy(aluguel[*contAluguel].codigo, codigo);            
        aluguel[*contAluguel].dataEntrada.dia = diaEntrada;
        aluguel[*contAluguel].dataEntrada.mes = mesEntrada;
        aluguel[*contAluguel].dataEntrada.ano = anoEntrada;
        aluguel[*contAluguel].dataSaida.dia = diaSaida;
        aluguel[*contAluguel].dataSaida.mes = mesSaida;
        aluguel[*contAluguel].dataSaida.ano = anoSaida;
                
		printf("\n\nAluguel inclu�do com sucesso!\n");  
        printf("\n\n--------------------------------------------------\n");
        (*contAluguel)++;   
    } else {
        printf("\nJ� exite aluguel com cpf %s e c�digo %s nessas datas.\nTente novamente.\n", cpf, codigo);
    }
	
}


//******************************************************
//MENU[3][4] Fun��o que altera aluguel com todos os dados
void alterarAluguel(Alugueis aluguel[], Clientes cliente[], Veiculos veiculo[], int *contAluguel, int *contCliente, int *contVeiculo) { //michelle
	char cpf [15], codigo [6];
    int posicaoAluguel, posicaoCpf, posicaoCodigo, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida;
    fflush(stdin);
    printf("\nDigite o cpf do cliente que deseja obter o aluguel: ");
    gets(cpf);
    
    printf("\nDigite o c�digo do ve�culo: ");
    gets(codigo);
    
    printf("\nDigite a data de entrada: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaEntrada);
    printf("M�s (mm): ");
    scanf("%d", &mesEntrada);
    printf("Ano (aaaa): ");
    scanf("%d", &anoEntrada);
    printf("\nDigite a data de sa�da: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaSaida);
    printf("M�s (mm): ");
    scanf("%d", &mesSaida);
    printf("Ano (aaaa): ");
    scanf("%d", &anoSaida);
    posicaoAluguel = buscarAluguel(aluguel, cpf, codigo, &diaEntrada, &mesEntrada, &anoEntrada, &diaSaida, &mesSaida, &anoSaida, contAluguel);
    if (posicaoAluguel != -1) { //-1 � PQ O ALUGUEL N�O EXISTE, ENT�O PODE CADASTRAR
        fflush(stdin);
        printf("\nDigite o c�digo do ve�culo: ");
        gets(codigo);
        fflush(stdin);
        int posicaoVeiculoAlterado; 
        posicaoVeiculoAlterado = buscarCodigo(veiculo, codigo, contVeiculo);
        if(posicaoVeiculoAlterado != -1) {
            fflush(stdin);
            strcpy(aluguel[posicaoAluguel].codigo,codigo );
            fflush(stdin);
            printf("\n\n--------------------------------------------------\n"); 
            printf("\nDigite a nova data de entrada: ");
            printf("\nDia (dd): ");
            scanf("%d", &aluguel[posicaoAluguel].dataEntrada.dia);
            printf("M�s (mm): ");
            scanf("%d", &aluguel[posicaoAluguel].dataEntrada.mes);
            printf("Ano (aaaa): ");
            scanf("%d", &aluguel[posicaoAluguel].dataEntrada.ano);
            printf("\nDigite a nova data de sa�da: ");
            printf("\nDia (dd): ");
            scanf("%d", &aluguel[posicaoAluguel].dataSaida.dia);
            printf("M�s (mm): ");
            scanf("%d", &aluguel[posicaoAluguel].dataSaida.mes);
            printf("Ano (aaaa): ");
            scanf("%d", &aluguel[posicaoAluguel].dataSaida.ano);
            printf("\n\nAluguel alterado com sucesso!\n");  
            printf("\n\n--------------------------------------------------\n");
        }
        else {
            printf("\nN�o exite alugu�is com cpf %s e c�digo %s nessas datas.", cpf, codigo);
			printf("\n\n--------------------------------------------------\n");
        }
	}
}

//******************************************************
//MENU[3][5] Fun��o que lista o ve�culo por c�digo
void excluirAluguel(Alugueis aluguel[], Clientes cliente[], Veiculos veiculo[], int *contAluguel) {
	char cpf [15], codigo [6];
	int i, posicaoAluguel, posicaoCpf, posicaoCodigo, diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida;
	
	fflush(stdin);
 	printf("\nDigite o cpf do cliente que deseja obter o aluguel: ");
	gets(cpf);
	
	printf("\nDigite o c�digo do ve�culo: ");
	gets(codigo);
				
	printf("\nDigite a data de entrada: ");
	printf("\nDia (dd): ");
	scanf("%d", &diaEntrada);
	printf("M�s (mm): ");
    scanf("%d", &mesEntrada);
    printf("Ano (aaaa): ");
    scanf("%d", &anoEntrada);
    		
    printf("\nDigite a data de sa�da: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaSaida);
    printf("M�s (mm): ");
    scanf("%d", &mesSaida);
    printf("Ano (aaaa): ");
	scanf("%d", &anoSaida);
			
	posicaoAluguel = buscarAluguel(aluguel, cpf, codigo, &diaEntrada, &mesEntrada, &anoEntrada, &diaSaida, &mesSaida, &anoSaida, contAluguel);
			
	if (posicaoAluguel != -1) {
		for(i = posicaoAluguel; i < *contAluguel - 1; i++) {
			aluguel[i] = aluguel[i + 1];
		}
		printf("\nAluguel exclu�do com sucesso!!");
		printf("\n\n--------------------------------------------------\n");
		(*contAluguel)--;			
	} else {
		printf("\nN�o exite alugu�is com cpf %s e c�digo %s nessas datas.", cpf, codigo);
	}
}

//******************************************************
//MENU[4][1] Fun��o que mostra o relat�rio dos alugu�is por cpf do cliente
void listarAlugueisPorCpfDoCliente(Alugueis aluguel[], int *contAluguel) {
	int i, contPorCpf=0;
	char cpf[15];
	
	fflush(stdin);
 	printf("\nDigite o cpf do cliente que deseja obter o aluguel: ");
	gets(cpf);
    
    for(i = 0; i < *contAluguel; i++) {
		   
        if(strcmp(aluguel[i].cpf, cpf) == 0) {
            printf("\n--- Dados do Aluguel %d ---\n", contPorCpf + 1);
        	printf("\nCpf do Cliente: %s", aluguel[i].cpf);
        	printf("\nC�digo do ve�culo: %s", aluguel[i].codigo);
        	printf("\nData de Entrada: %d/%d/%d", aluguel[i].dataEntrada.dia, aluguel[i].dataEntrada.mes, aluguel[i].dataEntrada.ano);
        	printf("\nData de Sa�da: %d/%d/%d\n", aluguel[i].dataSaida.dia, aluguel[i].dataSaida.mes, aluguel[i].dataSaida.ano);
        	
        	contPorCpf++;
        }
    }
    if(contPorCpf==0){
    	printf("\nN�o exite alugu�is com o cpf %s fornecido.\n", cpf);
	}
}
//******************************************************
//MENU[4][2] Fun��o que mostra o relat�rio dos alugu�is por c�digo do ve�culo
void listarAlugueisPorCodigo(Alugueis aluguel[], int *contAluguel) {
	int i, contPorCodigo=0;
	char codigo[6];
	
	fflush(stdin);
	printf("\nDigite o c�digo do ve�culo: ");
	gets(codigo);
	
	for(i = 0; i < *contAluguel; i++) {
		   
        if(strcmp(aluguel[i].codigo, codigo) == 0) {
            printf("\n--- Dados do Aluguel %d ---\n", contPorCodigo + 1);
        	printf("\nCpf do Cliente: %s", aluguel[i].cpf);
        	printf("\nC�digo do ve�culo: %s", aluguel[i].codigo);
        	printf("\nData de Entrada: %d/%d/%d", aluguel[i].dataEntrada.dia, aluguel[i].dataEntrada.mes, aluguel[i].dataEntrada.ano);
        	printf("\nData de Sa�da: %d/%d/%d\n", aluguel[i].dataSaida.dia, aluguel[i].dataSaida.mes, aluguel[i].dataSaida.ano);
        	
        	contPorCodigo++;
        }
    }
    
    if(contPorCodigo==0){
    	printf("\nN�o exite alugu�is com o c�digo de ve�culo %s fornecido.\n", codigo);
	}

}

//******************************************************
//MENU[4][3] Fun��o que mostra o relat�rio dos alugu�is por per�odo de tempo
void listarAlugueisPorTempo(Alugueis aluguel[], int *contAluguel) {
	int i, contPorData=0;
	int diaEntrada, mesEntrada, anoEntrada, diaSaida, mesSaida, anoSaida;
	char codigo[6];
	
	fflush(stdin);
	printf("\nDigite a data de entrada: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaEntrada);
    printf("M�s (mm): ");
    scanf("%d", &mesEntrada);
    printf("Ano (aaaa): ");
    scanf("%d", &anoEntrada);
    printf("\nDigite a data de sa�da: ");
    printf("\nDia (dd): ");
    scanf("%d", &diaSaida);
    printf("M�s (mm): ");
    scanf("%d", &mesSaida);
    printf("Ano (aaaa): ");
    scanf("%d", &anoSaida);
	
	for(i = 0; i < *contAluguel; i++) {
		   
        if(aluguel[i].dataEntrada.dia==diaEntrada && aluguel[i].dataEntrada.mes==mesEntrada && aluguel[i].dataEntrada.ano==anoEntrada &&
        aluguel[i].dataSaida.dia==diaSaida && aluguel[i].dataSaida.mes==mesSaida && aluguel[i].dataSaida.ano==anoSaida) {
            printf("\n--- Dados do Aluguel %d ---\n", contPorData + 1);
        	printf("\nCpf do Cliente: %s", aluguel[i].cpf);
        	printf("\nC�digo do ve�culo: %s", aluguel[i].codigo);
        	printf("\nData de Entrada: %d/%d/%d", aluguel[i].dataEntrada.dia, aluguel[i].dataEntrada.mes, aluguel[i].dataEntrada.ano);
        	printf("\nData de Sa�da: %d/%d/%d\n", aluguel[i].dataSaida.dia, aluguel[i].dataSaida.mes, aluguel[i].dataSaida.ano);
        	
        	contPorData++;
        }
    }
    
    if(contPorData==0){
    	printf("N�o existe alugu�is com essas datas fornecidas.\n");
	}
    
}

//******************************************************
//Fun��o principal- chama as demais fun��es do c�digo
main() {
    setlocale(LC_ALL, "Portuguese");
    
    int contCliente = 0, contVeiculo = 0, contAluguel = 0, opcaoMenu = -1, opcaoSubmenu = -1;
    
    Clientes cliente[max];
    Veiculos veiculo[max];
    Alugueis aluguel[max];
    
    printf("--------------------------------------------------");
    printf("\n-------------- LOCADORA DE VE�CULOS --------------");
    printf("\n--------------------------------------------------\n\n");
    
    criarExemplosClientes(cliente, &contCliente);
    criarExemplosVeiculos(veiculo, &contVeiculo);
    criarExemplosAlugueis(aluguel, &contAluguel);  
        
    do { //michelle
        menuPrincipal();
        printf("Digite a op��o desejada: ");
        scanf("%d", &opcaoMenu);
        switch(opcaoMenu){
            
            case 1:
                
                do {
                	system("cls");
                    subMenuClientes();
                    printf("\nDigite a op��o desejada: ");
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
                            printf("\n\t******* Digite uma op��o v�lida! *******\n\n");
                    }
                }
                while (opcaoSubmenu!=6);
                break;
            //Submenu de Ve�culos
            case 2:
                
                do{
                    system("cls");
                    subMenuVeiculos();
                    printf("\nDigite a op��o desejada: ");
                    scanf("%d", &opcaoSubmenu);
                    switch(opcaoSubmenu){
                        case 1:
                        	system("cls");
                            printf("\n\t------ LISTAR TODOS OS VE�CULOS ------\n\n");
                            listarTodosVeiculos(veiculo, &contVeiculo); 
                            system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                            printf("\n\t------ LISTAR VE�CULOS POR C�DIGO ------\n\n"); 
					  		listarVeiculoPorCodigo(veiculo, &contVeiculo); 
					  		system("Pause");
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ INCLUIR VE�CULO ------\n\n");
                            incluirVeiculo(veiculo, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 4:
                        	system("cls");
                            printf("\n\t------ ALTERAR VE�CULO ------\n\n");
                            alterarVeiculo(veiculo, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 5:
                            system("cls");
                            printf("\n\t------ EXCLUIR VE�CULO ------\n\n");
                            excluirVeiculo(veiculo, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 6: 
                            printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                            break;      
                        default:
                            printf("\n\t******* Digite uma op��o v�lida! *******");
                    }   
                }
                while (opcaoSubmenu!=6);
                break;
            //Submenu de Alugueis
            case 3:
                
                do{
                	system("cls");
                    subMenuAlugueis();
                    printf("\nDigite a op��o desejada: ");
                    scanf("%d", &opcaoSubmenu);
                    switch(opcaoSubmenu){
                        case 1:
                        	system("cls");
                            printf("\n\t------ LISTAR TODOS OS ALUGU�IS ------\n\n");
                            listarTodosAlugueis(aluguel, &contAluguel); 
                            system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGUEL POR CPF, C�DIGO, DATAS DE ENTRADA E SA�DA ------\n\n");
							listarAluguelPorChaves(aluguel, cliente, veiculo, &contAluguel, &contCliente, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ INCLUIR ALUGUEL ------\n");
                            incluirAluguel(aluguel, cliente, veiculo, &contAluguel);
                            system("Pause"); 
                            break;
                        case 4:
                        	system("cls");
                            printf("\n\t------ ALTERAR ALUGUEL ------\n\n");
                            alterarAluguel(aluguel, cliente, veiculo, &contAluguel, &contCliente, &contVeiculo);
                            system("Pause"); 
                            break;
                        case 5:
                        	system("cls");
                            printf("\n\t------ EXCLUIR ALUGUEL ------\n\n");
                            excluirAluguel(aluguel, cliente, veiculo, &contAluguel);
                            system("Pause"); 
                            break;
                        case 6: 
                            printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                            break;      
                        default:
                            printf("\n\t******* Digite uma op��o v�lida! *******\n\n");
                    }   
                }
                while (opcaoSubmenu!=6);
                break;
            //Submenu de Relat�rios
            case 4:
                
                do{
                	system("cls");
                    subMenuRelatorios();
                    printf("\nDigite a op��o desejada: ");
                    scanf("%d", &opcaoSubmenu);
                    switch(opcaoSubmenu){
                        case 1:
                           system("cls");
                            printf("\n\t------ LISTAR ALUGU�IS POR CPF DO CLIENTE ------\n\n");
                            listarAlugueisPorCpfDoCliente(aluguel, &contAluguel);
                            system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGU�IS: C�DIGO DE VE�CULO ------\n\n");
                            listarAlugueisPorCodigo(aluguel, &contAluguel); 
                            system("Pause"); 
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGU�IS: PER�ODO DE TEMPO ------\n\n");
                            listarAlugueisPorTempo(aluguel, &contAluguel);
                            system("Pause"); 
                            break;
                        case 4:
                        	printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                        	system("Pause"); 
                            break;                        	                           
                        default:
                            printf("\n\t******* Digite uma op��o v�lida! *******\n\n");
                    }   
                }
                while (opcaoSubmenu!=4); 
                break;
            default:
                printf("\n\t******* Digite uma op��o v�lida! *******\n\n");           
        }
    }
    while (opcaoMenu!=5);
}
