/*Projeto pr�tico de AP2S2
Tema 2: Locadora de Autom�veis
Alunos: Michelle Tiburcio e Thiane Depr� Saravalle
Prontu�rios: SC3017311 e SC3013073
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
//Estrutura de Ve�culos
typedef struct {
    char codigo[6], descricao[100], categoria[10], combustivel[10], modelo[30];
    int capacidade;
    Data anoVeiculo;
} Veiculos;

//******************************************************
//Estrutura de Alugu�is
typedef struct {
    char cpf[15], codigo[6];
    Data dataEntrada, dataSaida;
} Alugueis;

//******************************************************
//*****************Definindo as Fun��es*****************
//******************************************************

//******************************************************
//Fun��o que mostra o Menu principal
void menuPrincipal() {
    printf("\n----------------- MENU DE OP��ES -----------------\n");
    printf("\n[1] Submenu de Clientes");
    printf("\n[2] Submenu de Ve�culos");
    printf("\n[3] Submenu de Alugueis");
    printf("\n[4] Submenu de Relat�rios");
    printf("\n[5] Sair\n\n");
}

//******************************************************
//Fun��o que mostra o Submenu de Clientes
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
//Fun��o que mostra o Submenu de Ve�culos
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
//Fun��o que mostra o Submenu de Alugu�is
void subMenuAlugueis() {
    printf("\n-------------- SUBMENU DE ALUGU�IS ---------------\n");
    printf("\n[1] Listar todos");
    printf("\n[2] Listar por cpf, c�digo e datas de entrada - sa�da");
    printf("\n[3] Incluir");
    printf("\n[4] Alterar");
    printf("\n[5] Excluir");
    printf("\n[6] Voltar ao Menu Principal\n\n");
}

//******************************************************
//Fun��o que mostra o Submenu Relat�rios
void subMenuRelatorios() {
    printf("\n--------------- SUBMENU RELAT�RIOS ---------------\n");
    printf("\n[1] Listar alugu�is por cpf do cliente");
    printf("\n[2] Listar alugu�is por c�digo do ve�culo");
    printf("\n[3] Listar alugu�is per�odo de tempo");
    printf("\n[4] Voltar ao Menu Principal\n\n");
}

//******************************************************
//Fun��o que cria exemplos de clientes
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
//Fun��o que verifica a exist�ncia do CPF
int buscarCpf(Clientes cliente[], char *cpf, int *contCliente) {
    int i, verifica = 0;
    
    for(i = 0; i < *contCliente && verifica == 0; i++) {       
        if(strcmp(cliente[i].cpf, cpf) == 0) { //strcmp compara duas strings e retorna 0 se forem iguais
            verifica = 1;
            return i;
        }
    }
    return -1; 
}

//******************************************************
//Fun��o que verifica a exist�ncia do codigo do ve�culo
int buscarCodigo(Veiculos veiculo[], char *codigo, int *contVeiculo) {
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
//MENU [1][1]
//Fun��o que lista os dados de todos os clientes
void listarTodosClientes(Clientes cliente[], int *contCliente) {
    system("cls"); //limpa a tela
    int i;
    for(i = 0; i < *contCliente; i++) {
        printf("\n\nDados do Cliente %d\n", i + 1);
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
//MENU [1][2]
//Fun��o que lista o cliente por CPF
void listarClientesPorCpf(Clientes cliente[], int *contCliente) {
	char cpf [15];
	int i, posicao = -1;	
	
	fflush(stdin);
 	printf("\n\nDigite o cpf do cliente: ");
	scanf("%s", &cpf); 
	
	posicao = buscarCpf(cliente, cpf, contCliente);
    
    if (posicao !=-1){
			printf("\n\nDados do Cliente \n");
        	printf("\nNome: %s", cliente[i].nome);
        	printf("\nCpf: %s", cliente[i].cpf);
        	printf("\nEndere�o: %s", cliente[i].endereco);  
        	printf("\nTelefone Fixo: %s", cliente[i].telFixo);
        	printf("\nCelular: %s", cliente[i].telFixo);
        	printf("\nData de Nascimento: %d/%d/%d", cliente[i].dataNasc.dia, cliente[i].dataNasc.mes, cliente[i].dataNasc.ano);
        	printf("\n\n--------------------------------------------------\n");
    	}
    	else {
    		printf("\nO cpf %s n�o � cadastrado.", cpf);
    		printf("\n\n--------------------------------------------------\n");
		}
    }
    
//******************************************************
//MENU [1][3]
//Fun��o que inclui novos clientes
void incluirCliente(Clientes cliente[], int *contCliente ){
    printf("\n\nDigite os dados do Cliente %d\n", *contCliente + 1);
    //fflush(stdin);
    printf("\nDigite o cpf: ");
    scanf("%s", &cliente[*contCliente].cpf);  
    //COLOCAR A FUN��O VERIFICA CPF 0 se o cpf existe mensagem que 
    printf("\nDigite o nome: ");
    scanf("%s", &cliente[*contCliente].nome);    
    printf("\nDigite o endere�o: ");
    scanf("%s", &cliente[*contCliente].endereco);
    fflush(stdin);
    printf("\nDigite o telefone fixo: ");
    scanf("%s", &cliente[*contCliente].telFixo);
    fflush(stdin);
    printf("\nDigite o celular: ");
    scanf("%s", &cliente[*contCliente].celular);
    printf("\nDigite o dia de nascimento: ");
    scanf("%d", &cliente[*contCliente].dataNasc.dia);
    printf("\nDigite o m�s de nascimento: ");
    scanf("%d", &cliente[*contCliente].dataNasc.mes);
    printf("\nDigite o ano de nascimento: ");
    scanf("%d", &cliente[*contCliente].dataNasc.ano);
    (*contCliente)++;
}

//******************************************************
//MENU [1][4]
//Fun��o que altera os dados dos cliente
void alterarCliente(Clientes cliente[], int *contCliente) {
	//Thiane vai fazer
}


//******************************************************
//MENU [1][5]
//Fun��o que exclui o cliente por CPF
void excluirCliente(Clientes cliente[], int *contCliente) {
    int i, posicao;
    char cpf[15];
    
    fflush(stdin);
    printf("Digite o cpf do cliente que deseja excluir: ");
    scanf("%s", &cpf);
    
    posicao = buscarCpf(cliente, cpf, contCliente);
    
    if (posicao !=-1) {
        for(i = posicao; i < *contCliente-1; i++) {
            cliente[i] = cliente[i+1];
            printf("\nCliente exclu�do com sucesso!");
			printf("\n\n--------------------------------------------------\n");
			(*contCliente)--;
        }
        
    } else {
        printf("\nCpf n�o cadastrado.");
		printf("\n\n--------------------------------------------------\n");
    }
    
}

//******************************************************
//MENU [2][1]
//Fun��o que lista os dados de todos os ve�culos
void listarTodosVeiculos(Veiculos veiculo[], int *contVeiculo ) {
    int i;
    
    for(i = 0; i < *contVeiculo; i++) {
        printf("\n\nDados do Ve�culo %d\n", i + 1);
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
//MENU [2][2]
//Fun��o que lista o ve�culo por c�digo
void listarVeiculoPorCodigo(Veiculos veiculo[], int *contVeiculo) {		
	char codigo [6];
	int i, posicao = -1;	
	
	fflush(stdin);
 	printf("\n\nDigite o c�digo do ve�culo: ");
	scanf("%s", &codigo); 
	
	posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao !=-1){
		printf("\n\nDados do Ve�culo %d\n", i + 1);
        printf("\nC�digo: %s", veiculo[i].codigo);
        printf("\nDescri��o: %s", veiculo[i].descricao);
        printf("\nCategoria: %s", veiculo[i].categoria);  
        printf("\nCapacidade: %d", veiculo[i].capacidade);
        printf("\nTipo de combustivel: %s", veiculo[i].combustivel);
        printf("\nModelo: %s", veiculo[i].modelo);
        printf("\nAno: %d", veiculo[i].anoVeiculo.ano);
        printf("\n\n--------------------------------------------------\n");
    	}
    	else {
    		printf("\nO c�digo %s n�o � cadastrado.", codigo);
    		printf("\n\n--------------------------------------------------\n");
		}
    }

//******************************************************
//menu [2][3]
//Fun��o que inclui novos ve�culos
void incluirVeiculo(Veiculos veiculo[], int *contVeiculo ){
    printf("\n\nDigite os dados do Ve�culo %d\n", *contVeiculo + 1);
    printf("\nDigite o c�digo: ");
    scanf("%s", &veiculo[*contVeiculo].codigo);
    //COLOCAR A FUN��O VERIFICA C�DIGO 0 se o c�digo existe mensagem que 
    printf("\nDigite a descricao: ");
    scanf("%s", &veiculo[*contVeiculo].descricao);
    printf("\nDigite a categoria: ");
    scanf("%s", &veiculo[*contVeiculo].categoria);
    printf("\nDigite a capacidade: ");
    scanf("%d", &veiculo[*contVeiculo].capacidade);
    fflush(stdin);
    printf("\nDigite o tipo de combust�vel: ");
    scanf("%s", &veiculo[*contVeiculo].combustivel);
    printf("\nDigite o modelo: ");
    scanf("%s", &veiculo[*contVeiculo].modelo);
    printf("\nDigite o ano: ");
    scanf("%d", &veiculo[*contVeiculo].anoVeiculo.ano);
    (*contVeiculo)++;
}


//******************************************************
//MENU [2][4]
//Fun��o que altera os dados dos ve�culo
void alterarVeiculo(Veiculos veiculo[], int *contVeiculo) {
	//Thiane vai fazer
}

//******************************************************
//MENU [2][5]
//Fun��o que exclui o ve�culo por c�digo
void excluirVeiculo(Veiculos veiculo[], int *contVeiculo) {
    int i, posicao;
    char codigo[6];
    
    fflush(stdin);
    printf("Digite o c�digo do ve�culo que deseja excluir: ");
    scanf("%s", &codigo);
    
    posicao = buscarCodigo(veiculo, codigo, contVeiculo);
    
    if (posicao != -1) {
        for(i = posicao; i < *contVeiculo - 1; i++) {
            veiculo[i] = veiculo[i + 1];
            printf("\nCliente excluido com sucesso!!");
			printf("\n\n--------------------------------------------------\n");
			(*contVeiculo)--;
        }
        
    } else {
        printf("C�digo do ve�culo n�o � cadastrado.");
		printf("\n\n--------------------------------------------------\n");
    }
    
}

//******************************************************
//menu [3][1]
//Fun��o que lista os dados de todos os alugueis
void listarTodosAlugueis(Alugueis aluguel[], int *contAluguel ){
    system("cls"); //limpa a tela
    int i;
    
    for(i = 0; i < *contAluguel; i++) {
        printf("\n\nDados do Aluguel %d\n", i + 1);
        printf("\nCpf do Cliente: %s", aluguel[i].cpf);
        printf("\nC�digo do ve�culo: %s", aluguel[i].codigo);
        printf("\nData de Entrada: %d/%d/%d", aluguel[i].dataEntrada.dia, aluguel[i].dataEntrada.mes, aluguel[i].dataEntrada.ano);
        printf("\nData de Sa�da: %d/%d/%d", aluguel[i].dataSaida.dia, aluguel[i].dataSaida.mes, aluguel[i].dataSaida.ano);
        printf("\n\n--------------------------------------------------\n");
    }
}

//******************************************************
//menu [2][3]
//Fun��o que inclui um novo aluguel
void incluirAluguel(Alugueis aluguel[], int *contAluguel ){
	printf("\n\nDigite os dados do aluguel %d\n", *contAluguel + 1);
	printf("\nDigite o cpf: ");
	scanf("%s", &aluguel[*contAluguel].cpf);
	//verifica se CPF est� cadastrado
    printf("\nDigite o c�digo do ve�culo: ");
	scanf("%s", &aluguel[*contAluguel].codigo);  
	//verifica se C�digo est� cadastrado
	printf("\nDigite o dia da data de entrada: ");
    scanf("%d", &aluguel[*contAluguel].dataEntrada.dia);
    printf("\nDigite o m�s de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataEntrada.mes);
    printf("\nDigite o ano de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataEntrada.ano);
	printf("\nDigite o dia da data de sa�da: ");
    scanf("%d", &aluguel[*contAluguel].dataSaida.dia);
    printf("\nDigite o m�s de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataSaida.mes);
    printf("\nDigite o ano de nascimento: ");
    scanf("%d", &aluguel[*contAluguel].dataSaida.ano);
    (*contAluguel)++;
}

//******************************************************
//Fun��o que lista o ve�culo por c�digo
void listarAluguelPorTodosOsParametros (/*COLOCAR OS PAR�METROS*/) {
	
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
        
    do {
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
                            break;
                        case 4:
                        	system("cls");
                        	printf("\n\t------ ALTERAR CLIENTE ------\n\n");
                           	alterarCliente(cliente, &contCliente);
                            break;
                        case 5:
                        	system("cls");
                        	printf("\n\t------ EXCLUIR CLIENTE ------\n\n");
							excluirCliente(cliente, &contCliente);
                          //  system("Pause");  
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
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ INCLUIR VE�CULO ------\n\n");
                            incluirVeiculo(veiculo, &contVeiculo);
                            break;
                        case 4:
                        	system("cls");
                            printf("\n\t------ ALTERAR VE�CULO ------\n\n");
                            alterarVeiculo(veiculo, &contVeiculo);
                            break;
                        case 5:
                            system("cls");
                            printf("\n\t------ EXCLUIR VE�CULO ------\n\n");
                            excluirVeiculo(veiculo, &contVeiculo);
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
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ INCLUIR ALUGUEL ------\n");
                            incluirAluguel(aluguel, &contAluguel);
                            break;
                        case 4:
                        	system("cls");
                            printf("\n\t------ ALTERAR ALUGUEL ------\n\n");
                            break;
                        case 5:
                        	system("cls");
                            printf("\n\t------ EXCLUIR ALUGUEL ------\n\n");
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
                            system("Pause");     
                            break;
                        case 2:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGU�IS: CPF DE CLIENTE ------\n\n");   
                            break;
                        case 3:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGU�IS: C�DIGO DE VE�CULO ------\n\n");
                            incluirAluguel(aluguel, &contAluguel);
                            break;
                        case 4:
                        	system("cls");
                            printf("\n\t------ LISTAR ALUGU�IS: PER�ODO DE TEMPO ------\n\n");
                            break;
                        case 5:
                        	printf("\n\n---------- RETORNANDO AO MENU PRINCIPAL ----------\n\n");
                            break;                            
                        default:
                            printf("\n\t******* Digite uma op��o v�lida! *******\n\n");
                    }   
                }
                while (opcaoSubmenu!=6);
                break;
            default:
                printf("\n\t******* Digite uma op��o v�lida! *******\n\n");           
        }
    }
    while (opcaoMenu!=5);
}
