#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// variaveis globais - por enquanto vai ficar aqui depois a gente ve 
#define QUANTIDADE_USUARIO 5
#define MAX_RECEITAS 100
#define MAX_DESPESAS 100
#define MAX_PRODUTOS 100
#define MAX_FORNECEDORES 100

//Banco de dados

//Empresa

  char nomeEmpresa[100] = "Lorenzete";
  char cnpjEmpresa[100] = "07900938000107";
  char enderecoEmpresa[100] = "Av cuiaba, 200, cuiaba - mt";
  float saldo = 0;

//Usuarios
  char usuarios[5][100];
  char senhas[5][100];
  int posicaoUsuario = 0;

// Categorias
  char categoriasDB[8][40] = {"Produto de uso interno", "Serviço", "Funcionario", "Para revenda", "Manutenção do local", "Produto", "Indefinida"};

// Dados Despesas
  char descricoesDespesasDB[MAX_DESPESAS][100];
  float valoresDespesasDB[MAX_DESPESAS];
  float quantidadesDespesasDB[MAX_DESPESAS];
  char fornecedoresDespesasDB[MAX_DESPESAS];
  char categoriasDespesasDB[MAX_DESPESAS];
  int qtdDespesas = 0;

// Dados Receitas

  char descricoesReceitasDB[MAX_RECEITAS][100];
  float valoresReceitasDB[MAX_RECEITAS];
  float quantidadesReceitasDB[MAX_RECEITAS];
  char fornecedoresReceitasDB[MAX_RECEITAS];
  char categoriasReceitasDB[MAX_RECEITAS];
  int qtdReceitas = 0;

// Dados Produtos e serviços
  char produtosServicosDB[MAX_PRODUTOS][100] = {"produto 1", "produto 2", "produto 3"};
  int qtdProdutosServicos = 2;
  


// Dados Fornecedores
char fornecedoresDB[MAX_FORNECEDORES][100];


//Funções -- 

//Funcoes base 

  char gerenciadorCategorias(char categoriasCadastradas[][40]){

    for(int i = 0; i<7; i++){
      printf("%d - %s\n", i+1, categoriasCadastradas[i]);
    }
 
  }

  void listarTransacoes(char descR[][100], float valR[], int qtdR, char descD[][100], float valD[], int qtdD) {
    printf("=== RECEITAS (%d) ===\n", qtdR);
    for (int i = 0; i < qtdR; i++) {
        printf("%2d) %s - R$ %.2f\n", i + 1, descR[i], valR[i]);
    }
    printf("=== DESPESAS (%d) ===\n", qtdD);
    for (int i = 0; i < qtdD; i++) {
        printf("%2d) %s - R$ %.2f\n", i + 1, descD[i], valD[i]);
    }
}

  int oqueFazerAposExecucao() {
  int opcaoSelecionada;
  printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - Recarregar menu atual | 2 - Finalizar programa]\n");
          scanf("%d", &opcaoSelecionada);
          getchar();

          /*if(opcaoSelecionada == 0){

            menuAtual = false;

          } else if(opcaoSelecionada == 1){

            menuAtual = true;

          } else if (opcaoSelecionada == 2) {
            menuAtual = false;
            condicaoGeralPrograma = false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            oqueFazerAposIsso(menuAtual, condicaoGeralPrograma);
            menuAtual = false;
          }*/ // só funcionaria com ponteiro, infelizmente:(

      return opcaoSelecionada;
}

  void dadosCadastraisEmpresa(){
    printf("Nome Empresa: %s\n", nomeEmpresa);
    printf("Endereço Empresa: %s\n", enderecoEmpresa);
    printf("CNPJ Empresa: %s\n", cnpjEmpresa);
    
  }

//Gerenciar usuario 

  char cadastrarUsuario(char usuarios[][100], char senhas[][100], int posicaoUsuario) {

 

  printf("Digite seu usuário: ");
  fgets(usuarios[posicaoUsuario], 100, stdin);
  usuarios[posicaoUsuario][strcspn(usuarios[posicaoUsuario], "\n")] = '\0'; 

  printf("Digite sua Senha: ");
  fgets(senhas[posicaoUsuario], 100, stdin);
  senhas[posicaoUsuario][strcspn(senhas[posicaoUsuario], "\n")] = '\0'; 

  printf("Resumo do cadastro\n");
  printf("usuario: %s\n", usuarios[posicaoUsuario]);
  printf("senha: %s\n", senhas[posicaoUsuario]);
  
  return posicaoUsuario + 1;

  
  
}

  bool efeituarLogin(char usuarios[][100], char senhas[][100], char usuarioInformado[100], char senhaInformada[100], bool logado){

  for(int i = 0; i<QUANTIDADE_USUARIO; i++) {

    if(strcmp(usuarios[i], usuarioInformado) == 0){
      printf("Usuário logado\n");
      logado = true;
    } 

    return logado;

  }
  //return logado;

}

//Gerenciar financas 

  void cadastrarNovaDespesa() {

  
  int categoriaSelecionadaCadastrarDespesas;
  int categoriaDaDespesaMenuCadastrarDespesas;
  float quantidadeMenuCadastrarDespesas;
  float valorDespesaMenuCadastrarDespesas;
  char descricaoDespesaMenuCadastrarDespesas[100];
  int fornecedorMenuCadastrarDespesas;

  printf("Cadastrar nova despesa\n");
  printf("Selecione a categoria: \n");
  gerenciadorCategorias(categoriasDB);
  scanf("%d", &categoriaSelecionadaCadastrarDespesas);
  getchar();

  printf("Valor da despesa: ");
  scanf("%f", &valorDespesaMenuCadastrarDespesas);
  getchar();

  printf("Produto ou serviço: ");
  listarProdutos();
  fgets(descricoesDespesasDB[qtdDespesas], 100, stdin);
  descricoesDespesasDB[qtdDespesas][strcspn(descricoesDespesasDB[qtdDespesas], "\n")] = '\0';

  printf("Fornecedor: \n");
  //chamar funcao que mostra fornecedores
  scanf("%d", &fornecedorMenuCadastrarDespesas);
  getchar();
  
  printf("Quantidade: ");
  scanf("%f", &quantidadeMenuCadastrarDespesas);
  getchar();

  printf("Cadastrando despesa...\n");         
  //descricoesDespesasDB[qtdDespesas][100] = descricaoDespesaMenuCadastrarDespesas;
  valoresDespesasDB[qtdDespesas] = valorDespesaMenuCadastrarDespesas;
  quantidadesDespesasDB[qtdDespesas] = quantidadeMenuCadastrarDespesas;
  fornecedoresDespesasDB[qtdDespesas] = fornecedorMenuCadastrarDespesas;
  categoriasDespesasDB[qtdDespesas] = categoriaDaDespesaMenuCadastrarDespesas;
  qtdDespesas++;
  printf("Despesa cadastrada\n");
        
}

  void cadastrarNovaReceita() {

 
  int categoriaReceitaMenuCadastrarReceitas;
  int fornecedorMenuCadastrarReceitas;
  float valorReceitaMenuCadastrarReceitas;
  float quantidadeMenuCadastrarReceitas;
  char descricaoReceitaMenuCadastrarReceitas[100];

  printf("Cadastrar nova Receitas\n");
  printf("Selecione a categoria: \n");
  gerenciadorCategorias(categoriasDB);
  scanf("%d", &categoriaReceitaMenuCadastrarReceitas);
  getchar();

  printf("Valor daReceitas: ");
  scanf("%f", &valorReceitaMenuCadastrarReceitas);
  getchar();

  printf("Produto ou serviço: ");
  fgets(descricoesReceitasDB[qtdReceitas], 100, stdin);
  descricoesReceitasDB[qtdDespesas][strcspn(descricoesReceitasDB[qtdReceitas], "\n")] = '\0';

  printf("Fornecedor: \n");
  //chamar funcao que mostra fornecedores
  scanf("%d", &fornecedorMenuCadastrarReceitas);
  getchar();
  
  printf("Quantidade: ");
  scanf("%f", &quantidadeMenuCadastrarReceitas);
  getchar();

  printf("Cadastrando despesa...\n");         
  //descricoesDespesasDB[qtdDespesas][100] = descricaoDespesaMenuCadastrarDespesas;
  valoresReceitasDB[qtdReceitas] = valorReceitaMenuCadastrarReceitas;
  quantidadesReceitasDB[qtdReceitas] = quantidadeMenuCadastrarReceitas;
  fornecedoresReceitasDB[qtdReceitas] = fornecedorMenuCadastrarReceitas;
  categoriasReceitasDB[qtdReceitas] = categoriaReceitaMenuCadastrarReceitas;
  qtdReceitas++;
  printf("Despesa cadastrada\n");
        
}

  float consultarSaldo(float receitas[], int qtdR, float despesas[], int qtdD) {
    //float saldo = 0.0f;
    for (int i = 0; i < qtdR; i++) saldo += receitas[i];
    for (int i = 0; i < qtdD; i++) saldo -= despesas[i];
    return saldo;
}

  float calcularLucro(){
    float saldo = consultarSaldo(valoresReceitasDB, qtdReceitas, valoresDespesasDB, qtdDespesas);
    float receitas; 

    for(int i; i<qtdReceitas; i++){
      receitas += valoresReceitasDB[i];
    }
    
    float porcentagemLucro = (saldo/receitas)*100;

    if(porcentagemLucro<0){
      printf("Houve um prejuízo de: %.2f\n", porcentagemLucro);
    } else if(porcentagemLucro>0){
      printf("Houve um lucro de: %.2f\n", porcentagemLucro);
    }

    return porcentagemLucro;
  }

// Gerenciar produtos

  char cadastrarProduto(){
    char produto[100];
    printf("Descrição do produto ou serviço: ");
      
    fgets(produtosServicosDB[qtdProdutosServicos], 100, stdin);
    produtosServicosDB[qtdProdutosServicos][strcspn(produtosServicosDB[qtdProdutosServicos], "\n")] = '\0';
    printf("produto: %s\n", produtosServicosDB[qtdProdutosServicos]);
    qtdProdutosServicos++;
      
  }

  void excluirProduto(int codigoProduto){

    printf("Produto %s excluido!\n", produtosServicosDB[codigoProduto]);
    produtosServicosDB[codigoProduto][0] = '\0';

    /*produtosServicosDB[codigoProduto][100] = '\0';
    char produto[100];
    fgets(produto, sizeof(produto), stdin);
      produto[strcspn(produto, "\n")] = '\0';
    for(int i = 0; i<MAX_PRODUTOS; i++){
      if(strcmp(produto, produtosServicosDB[i]) == 0){
        produtosServicosDB[i][100] = '\0';
        
      }
      }*/ //nao funcionou :( 
  }

  char listarProdutos(){
    printf("Produtos cadastrados\n");
    for(int i = 0; i<qtdProdutosServicos; i++){
      //char produtoAtual = produtosServicosDB[i];
      printf("%d - %s \n", i+1, produtosServicosDB[i]);
      /*if(strcmp(produtosServicosDB[i], '\0') != 0){
      }*/
    }

    printf("Fim da lista\n");

  }

  void gerenciadorMenuProdutoEServicos(){

    int opcaoSelecionada;
    int produtoSelecionado;

    printf("O que deseja fazer agora?\n");
    printf("1 - Listar Produtos e serviços\n");
    printf("2 - Cadastrar um novo produto/serviço\n");
    printf("3 - Excluir um produto/Serviço\n");
    scanf("%d", &opcaoSelecionada);
    getchar();

    switch (opcaoSelecionada)
    {
    case 1:
      listarProdutos();
      break;
    case 2: 
      cadastrarProduto();
      break;
    case 3:
      printf("Selecione o produto que deseja excluir\n");
      listarProdutos();
      scanf("%d", &produtoSelecionado);
      getchar();
      excluirProduto(produtoSelecionado-1);
      break;
    
    default:
      break;
    }

  }

  void comparador(){
    listarProdutos();
  }

//programa

  int main() {
  //Banco de dados local
  
  //Variaveis estados do sistema
  
  bool cadastroEfeituado = false;
  bool usuarioLogado = false;
  bool dadosIniciaisPreenchido = false;
  bool continuarMenuPrincipal = true;
  bool continuarMenuSaldo = true;
  bool continuarMenuHistorico = true;
  bool continuarMenuDespesa = true;
  bool continuarMenuReceitas = true;
  bool continuarMenuLucrosEDespesas = true;
  bool continuarMenuComparativo = true;
  bool continuarMenuFornecedor = true;
  bool continuarMenuProdutosServicos = true;
  bool continuarMenuListarCategoria = true;
  bool continuarMenuDadosCadastrais = true;
  bool continuarPrograma = true;
  

  //Variaveis fluxo do sistema
  int cadastrarMaisUmUsuario = 0;

  // Variaveis menu login
  char usuarioInformadoLogin[100];
  char senhaInformadaLogin[100];

  //Variaveis menu Principal
  int opcaoSelecionadaMenuPrincipal;

  //Variaveis menu Cadastrar despesas

  //Variaveis menu cadastrar receitas
  
  //Variaveis menu Comparativo
  int produtoOuServicoMenuComparativo;

  //Variaveis menu fornecedor
  int opcaoSelecionadaMenuFornecedores;
  //Variaveis menu produtos e serviços
  //Variaveis menu listar categorias
  //Variaveis menu dados cadastrais
  //Variaveis menu sair
  
 

  


  do{

    while(!cadastroEfeituado){

      printf("Menu de cadastro\n");

      posicaoUsuario = cadastrarUsuario(usuarios, senhas, posicaoUsuario);

      printf("Deseja cadastrar um novo usuário? [0 - Não | 1 - Sim]\n");
      scanf("%d", &cadastrarMaisUmUsuario);
      getchar();

      if(cadastrarMaisUmUsuario == 0){
        cadastroEfeituado = true;
        printf("Voltando ao menu principal...\n");
      } else if (cadastrarMaisUmUsuario == 1){
        cadastroEfeituado = false;
      }

    } 

    while(!usuarioLogado) {

      printf("Menu de login\n");

      printf("Usuário: ");
      fgets(usuarioInformadoLogin, sizeof(usuarioInformadoLogin), stdin);
      usuarioInformadoLogin[strcspn(usuarioInformadoLogin, "\n")] = '\0';

      printf("Senha: ");
      fgets(senhaInformadaLogin, sizeof(senhaInformadaLogin), stdin);
      senhaInformadaLogin[strcspn(senhaInformadaLogin, "\n")] = '\0';

      usuarioLogado = efeituarLogin(usuarios, senhas, usuarioInformadoLogin, senhaInformadaLogin, usuarioLogado);

      if(usuarioLogado){
        printf("Login efeituado\n");
        usuarioLogado = true;
      } else if(!usuarioLogado){
        printf("Credenciais inválidas, tente novamente!\n");
      }


    }

    while(!dadosIniciaisPreenchido){
      printf("Nome da empresa: \n");
      fgets(nomeEmpresa, sizeof(nomeEmpresa), stdin);
      nomeEmpresa[strcspn(nomeEmpresa, "\n")] = '\0';
      printf("Saldo Inicial: \n");
      scanf("%f", &saldo);
      getchar();
      dadosIniciaisPreenchido = true;

    }
    do {

      printf("Bem vindo ao gerênciador de despesas e receitas\n");
      printf("Selecione o que deseja fazer agora\n");
      printf("1 - Saldo atual;\n");
      printf("2 - Historico de compras;\n");
      printf("3 - Nova despeza;\n");
      printf("4 - Adicionar receita;\n");
      printf("5 - Lucros e despesas;\n");
      printf("6 - Comparativos;\n");
      printf("7 - Fornecedor;\n");
      printf("8 - Produtos e serviços;\n");
      printf("9 - Listar cadegorias;\n");
      printf("10 - Dados cadastrais;\n");
      printf("0 - Sair\n");
      scanf("%d", &opcaoSelecionadaMenuPrincipal);
      getchar();

      switch(opcaoSelecionadaMenuPrincipal) {

        case 0:
        printf("Finalizando programa\n");
        continuarMenuPrincipal = false;
        continuarPrograma = false;
        break;
        case 1:
        printf("Menu Saldo\n");
        printf("Consultado saldo...\n");
        sleep(1);
        // chamar funcao que consulta o saldo
        float saldo = consultarSaldo(valoresReceitasDB, qtdReceitas, valoresDespesasDB, qtdDespesas);
        printf("Saldo atual: R$ %.2f\n", saldo);
        break;
        case 2:
        do {
          printf("Menu Historio\n");
          printf("Buscando suas informações...\n");
          sleep(1);
          printf("Gerando Relatório\n");
          // chamar funcao que lista as transaçõoes
          listarTransacoes(descricoesReceitasDB, valoresReceitasDB, qtdReceitas, descricoesDespesasDB, valoresDespesasDB, qtdDespesas);

          int oqueFazerAposIsso = oqueFazerAposExecucao();
          if(oqueFazerAposIsso == 0){

            continuarMenuReceitas = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuReceitas = true;

          } else if (oqueFazerAposIsso == 2) {
              continuarMenuReceitas = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuReceitas = false;
          }

        } while (continuarMenuHistorico);

        break;
        case 3: 

        do {
          printf("Menu despesa\n");
          cadastrarNovaDespesa();
          int oqueFazerAposIsso = oqueFazerAposExecucao();
          if(oqueFazerAposIsso == 0){

            continuarMenuDespesa = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuDespesa = true;

          } else if (oqueFazerAposIsso == 2) {
              continuarMenuReceitas = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          }else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuDespesa = false;
          }
        
         

      } while (continuarMenuDespesa);
        break;

        case 4:

        do {
          printf("Menu receita\n");
          cadastrarNovaReceita();

          int oqueFazerAposIsso = oqueFazerAposExecucao();
          if(oqueFazerAposIsso == 0){

            continuarMenuReceitas = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuReceitas = true;

          } else if (oqueFazerAposIsso == 2) {
              continuarMenuReceitas = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuReceitas = false;
          }

        } while (continuarMenuReceitas);

        break;
        case 5:
        do {
          printf("Menu Lucros e Despesas\n");
          printf("Consultando dados ...\n");
          sleep(1);
          //chamar funcao que vai calcular a receita, as despesas, o lucro.
          calcularLucro();
        } while (continuarMenuLucrosEDespesas);
        break;
        case 6:
        do {
          printf("Menu de comparação de preços\n");
          printf("Qual produto/ serviço deseja comparar agora?\n");
          listarProdutos();
          scanf("%d", produtoOuServicoMenuComparativo);
          getchar();
          printf("Buscando dados...\b");
          //chamar função que vai comparar 
          comparador(produtoOuServicoMenuComparativo);

          int oqueFazerAposIsso = oqueFazerAposExecucao();

          if(oqueFazerAposIsso == 0){

            continuarMenuComparativo = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuComparativo = true;

          } else if (oqueFazerAposIsso == 2) {
              continuarMenuReceitas = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuComparativo = false;
          }

        } while(continuarMenuComparativo);
        break;
        case 7:
        do {
          printf("Menu Fornecedores\n");
          printf("O que deseja fazer agora?\n");
          printf("1 - Listar forncederes\n");
          printf("2 - Cadastrar um novo fonecedor\n");
          printf("3 - Excluir um fornecedor\n");
          scanf("%d", &opcaoSelecionadaMenuFornecedores);
          getchar();
          //chamar funcao com que vai lidar com isso, aqui da pra fazer um swith direto dentro da funcao, pq ai a propria funcao vai lidar com oq fazer em cada uma das opções selecionadas e retornar o que precisa. (podem fazer de outra forma também)
          
          int oqueFazerAposIsso = oqueFazerAposExecucao();
          if(oqueFazerAposIsso == 0){

            continuarMenuFornecedor = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuFornecedor = true;

          } else if (oqueFazerAposIsso == 2) {
              continuarMenuReceitas = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuFornecedor = false;
          }

        } while(continuarMenuFornecedor);
        break;
        case 8:
        do{
          printf("Menu Produtos e Serviços\n");
          printf("Buscando informações...\n");
          gerenciadorMenuProdutoEServicos();
          
          //chamar funcão que vai lidar em calcular todas as despesas e gastos e retornar o lucro

          int oqueFazerAposIsso = oqueFazerAposExecucao();
          if(oqueFazerAposIsso == 0){

            continuarMenuProdutosServicos = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuProdutosServicos = true;

          } else if (oqueFazerAposIsso == 2) {
              continuarMenuProdutosServicos = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuLucrosEDespesas = false;
          }

        } while(continuarMenuProdutosServicos);
        break;
        case 9:
        do{
          printf("Menu listar categorias\n");
          printf("Listando categorias...\n");
          gerenciadorCategorias(categoriasDB);
          printf("Fim da lista\n");

          int oqueFazerAposIsso = oqueFazerAposExecucao();
          if(oqueFazerAposIsso == 0){

            continuarMenuListarCategoria = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuListarCategoria = true;

          } else if (oqueFazerAposIsso == 2) {
              continuarMenuReceitas = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuListarCategoria = false;
          }

        } while(continuarMenuListarCategoria);
        break;
        case 10:
        do {
          printf("Menu Dados Cadastrais\n");
          dadosCadastraisEmpresa();
          //chamar fucao que vai mostrar os dados da empresa;
          //no fluxo grama não pede para editar, so para mostrar 
          int oqueFazerAposIsso = oqueFazerAposExecucao();
            if(oqueFazerAposIsso == 0){
  
              continuarMenuDadosCadastrais = false;
  
            } else if(oqueFazerAposIsso == 1){
  
              continuarMenuDadosCadastrais = true;
  
            } else if (oqueFazerAposIsso == 2) {
              continuarMenuReceitas = false;
              continuarMenuPrincipal = false;
              continuarPrograma=false;

          } else {
              printf("Opção invalida! Voltando ao menu principal ...\n");
              continuarMenuListarCategoria = false;
            }
        } while (continuarMenuDadosCadastrais);
        break;
      }

    } while (continuarMenuPrincipal);

  } while (continuarPrograma);

  printf("Programa finalizado!\n");

}
