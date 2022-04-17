# Projeto-Locadora-de-Veiculos-em-C

Tema 2: Locadora de Automóveis 
    Uma aplicação para um locadora de automóveis precisa gerenciar informações sobre os
aluguéis de veículos realizados por seus clientes, bem como armazenar os dados de cada cliente
e de cada carro disponível para locação. Os dados a serem armazenados sobre os clientes, carros
e aluguéis são apresentados a seguir: 

Clientes = (CPF, Nome, Endereço, Telefone fixo, Telefone celular, Data de nascimento)
Veículos = (Código, descrição, categoria, capacidade, combustível, ano, modelo)
Alugueis = (CPF do cliente, Código do veículo, data de entrada, data de saída)

    Atenção: os atributos (dados) grifados NÃO podem se repetir no cadastro.  
    Utilizando os conhecimentos aprendidos sobre Vetores, Strings, Registros e Funções
desenvolva um programa em C que apresente o seguinte menu de opções para o usuário e
implemente cada operação usando função. Escolha a estrutura de dados mais apropriada para
armazenar os dados de cada entidade descrita anteriormente.  
    
    Menu Principal:
    1. Submenu de Clientes
    2. Submenu de Veículos
    3. Submenu de Alugueis
    4. Submenu Relatórios
    5. Sair 

    Cada Submenu deverá oferecer as seguintes opções: Listar todos os elementos, Listar
um elemento específico cuja chave foi informada pelo usuário, Incluir (sem repetição), Alterar e
Excluir (após confirmação dos dados) um elemento informado pelo usuário. O Submenu
Relatórios deverá ter uma opção para cada um dos relatórios solicitados a seguir. 

    Relatórios:
a) Mostrar todas as reservas de determinado cliente cujo CPF deverá ser 
fornecido pelo usuário;
b) Mostrar todas as reservas de determinado veículo cujo código deverá 
ser fornecido pelo usuário;
c) Mostrar os dados de cada veículo e o CPF e nome de cada cliente que 
fizeram reservas para o período entre as datas X e Y, onde ambas as
datas devem ser fornecidas pelo usuário. 

Obs: Não utilize variáveis globais. Use parâmetros para fazer a transferência de valores entre as
funções. Dê nomes significativos para variáveis e funções. 
