#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define QUANTIDADE_USUARIO 5



char usuariosCadastrado(){
  
  char usuarios[5][100];
  char senhas[5][100];

  
}

//cadastrar usuario 

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

char gerenciadorCategorias(char categoriasCadastradas[][40]){

  for(int i = 0; i<7; i++){
    printf("%d - %s\n", i+1, categoriasCadastradas[i]);
  }
 
}

char oqueFazerAposIsso(bool menuAtual, bool condicaoGeralPrograma) {
  int opcaoSelecionada;
  printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - Recarregar menu atual | 2 - Finalizar programa]\n");
          scanf("%d", &opcaoSelecionada);
          getchar();

          if(opcaoSelecionada == 0){

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
          }
      return {menuAtual, condicaoGeralPrograma};
}

int main() {

  //Banco de dados
  char categorias[8][40] = {"Produto de uso interno", "Serviço", "Funcionario", "Para revenda", "Manutenção do local", "Produto", "Indefinida"};
  char usuarios[5][100];
  char senhas[5][100];
  int posicaoUsuario = 0;

  //Variaveis estados do sistema
  bool cadastroEfeituado = false;
  bool usuarioLogado = false;
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
  int categoriaSelecionadaCadastrarDespesas;
  int categoriaDaDespesaMenuCadastrarDespesas;
  float quantidadeMenuCadastrarDespesas;
  float valorDespesaMenuCadastrarDespesas;
  char descricaoDespesaMenuCadastrarDespesas[100];
  char fornecedorMenuCadastrarDespesas[100];


  //Variaveis menu cadastrar receitas
  int categoriaSelecionadaCadastrarReceitas;
  int categoriaDaReceitaMenuCadastrarReceitas;
  float valorReceitaMenuCadastrarReceitas;
  float quantidadeMenuCadastrarReceitas;
  char descricaoReceitaMenuCadastrarReceitas[100];

  //Variaveis menu Comparativo
  char produtoOuServicoMenuComparativo[100];


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
        break;
        case 1:
        printf("Consultado saldo...\n");
        sleep(1);

        // chamar funcao que consulta o saldo

        break;
        case 2:
        printf("Buscando suas informações...\n");
        sleep(1);
        // chamar funcao que lista as transaçõoes

        break;
        case 3: 

        do {
          printf("Cadastrar nova despesa\n");
          printf("Selecione a categoria: \n");
          //printf("1- Produto de uso interno;\n");
          //printf("2 - Serviço;\n");
          //printf("3 - Funcionario;\n");
          //printf("4 - Para revenda;\n");
          //printf("5 - Manutenção do Local;\n");
          //printf("6 - Produto;\n");
          //printf("7 - Indedefinida;\n");
          //printf("0 - Voltar ao menu principal\n");
          // aqui da pra criar uma funcao que gerencia as categorias disponiveis
          gerenciadorCategorias(categorias);
          scanf("%d", &categoriaSelecionadaCadastrarDespesas);
          getchar();

          printf("Valor da despesa: ");
          scanf("%f", &valorDespesaMenuCadastrarDespesas);
          getchar();

          printf("Produto ou serviço: ");
          fgets(descricaoDespesaMenuCadastrarDespesas, sizeof(descricaoDespesaMenuCadastrarDespesas), stdin);
          descricaoDespesaMenuCadastrarDespesas[strcspn(descricaoDespesaMenuCadastrarDespesas, "\n")] = '\0';

          printf("Fornecedor: \n");
          fgets(fornecedorMenuCadastrarDespesas, sizeof(fornecedorMenuCadastrarDespesas), stdin);
          fornecedorMenuCadastrarDespesas[strcspn(fornecedorMenuCadastrarDespesas, "\n")] = '\0';
          //aqui acho que vamos ter que mudar ainda, pq na opção 7 tem como cadastrar e excluir fornecedores, então é melhor criar uma fucão que vai retornar quais fornecedores estão ativos no momento em que for execultada.

          printf("Quantidade: ");
          scanf("%f", &quantidadeMenuCadastrarDespesas);
          getchar();

          printf("Cadastrando despesa...\n");
          // chamar funcao que vai cadastrar a despesa
          printf("Despesa cadastrada\n");

          /*printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - cadastrar uma nova despesa]\n");
          scanf("%d", &oqueFazerAposIsso);
          getchar();

          if(oqueFazerAposIsso == 0){

            continuarMenuDespesa = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuDespesa = true;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuDespesa = false;
          }*/
        
         oqueFazerAposIsso(continuarMenuDespesa, continuarPrograma);

      } while (continuarMenuDespesa);
        break;

        case 4:

        do {
          printf("Cadastrar uma nova receita\n");
          printf("Valor da receita: ");
          scanf("%f", &valorReceitaMenuCadastrarReceitas);
          getchar();
          printf("Quantidade: ");
          scanf("%f", &quantidadeMenuCadastrarReceitas);
          getchar();
          printf("Produto ou serviço: \n");
          fgets(descricaoReceitaMenuCadastrarReceitas, sizeof(descricaoDespesaMenuCadastrarDespesas), stdin);
          descricaoReceitaMenuCadastrarReceitas[strcspn(descricaoReceitaMenuCadastrarReceitas, "\n")] = '\0';
          //mesma coisa que antes acho que vamos ter que mudar ainda, pq na opção 7 tem como cadastrar e excluir fornecedores.

          printf("Selecione uma categoria: \n");
          gerenciadorCategorias(categorias);
          //chamar funcao que vai listar as categorias disponiveis
          scanf("%d", &categoriaDaReceitaMenuCadastrarReceitas);
          getchar();

          printf("Registrando receita ...\n");
          //chamar funcao que vai cadastrar a receita 
          printf("Receita cadastrada!\n");

          printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - cadastrar uma nova despesa]\n");
          scanf("%d", &oqueFazerAposIsso);
          getchar();

          if(oqueFazerAposIsso == 0){

            continuarMenuReceitas = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuReceitas = true;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuReceitas = false;
          }

        } while (continuarMenuReceitas);

      
        break;
        case 5:
        
        printf("Consultando dados ...\n");
        //chamar funcao que vai calcular a receita, as despesas, o lucro.

        break;
        do {
          case 6:
          printf("Menu de comparação de preços\n");
          printf("Qual produto/ serviço deseja comparar agora?\n");
          fgets(produtoOuServicoMenuComparativo, sizeof(produtoOuServicoMenuComparativo), stdin);
          produtoOuServicoMenuComparativo[strcspn(produtoOuServicoMenuComparativo, "\n")] = '\0';
          printf("Buscando dados...\b");
          //chamar função que vai comparar 

          printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - cadastrar uma nova despesa]\n");
          scanf("%d", &oqueFazerAposIsso);
          getchar();

          if(oqueFazerAposIsso == 0){

            continuarMenuComparativo = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuComparativo = true;

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
          printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - cadastrar uma nova despesa]\n");
          scanf("%d", &oqueFazerAposIsso);
          getchar();

          if(oqueFazerAposIsso == 0){

            continuarMenuFornecedor = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuFornecedor = true;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuFornecedor = false;
          }

        } while(continuarMenuFornecedor);
        break;
        case 8:
        do{
          printf("Menu lucros e despesas\n");
          printf("Buscando informações...\n");
          //chamar funcão que vai lidar em calcular todas as despesas e gastos e retornar o lucro
          printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - Recarregar lucros e despesas | 2 - Finalizar programa]\n");
          scanf("%d", &oqueFazerAposIsso);
          getchar();

          if(oqueFazerAposIsso == 0){

            continuarMenuLucrosEDespesas = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuLucrosEDespesas = true;

          } else if (oqueFazerAposIsso == 2) {
            continuarMenuLucrosEDespesas = false;
            continuarPrograma = false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuLucrosEDespesas = false;
          }

        } while(continuarMenuLucrosEDespesas);
        break;
        case 9:
        do{
          printf("Menu listar categorias\n");
          printf("Listando categorias...\n");
          gerenciadorCategorias(categorias);
          printf("Fim da lista\n");

          printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - Recarregar categorias | 2 - Finalizar programa]\n");
          scanf("%d", &oqueFazerAposIsso);
          getchar();

          if(oqueFazerAposIsso == 0){

            continuarMenuListarCategoria = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuListarCategoria = true;

          } else if (oqueFazerAposIsso == 2) {
            continuarMenuListarCategoria = false;
            continuarPrograma = false;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuListarCategoria = false;
          }

        } while(continuarMenuListarCategoria);
        break;
        case 10:
        do {

          printf("Menu Dados Cadastrais\n");
          //chamar fucao que vai mostrar os dados da empresa;
          //no fluxo grama não pede para editar, so para mostrar 
          printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - Recarregar dados cadastrais | 2 - Finalizar programa]\n");
            scanf("%d", &oqueFazerAposIsso);
            getchar();
  
            if(oqueFazerAposIsso == 0){
  
              continuarMenuDadosCadastrais = false;
  
            } else if(oqueFazerAposIsso == 1){
  
              continuarMenuDadosCadastrais = true;
  
            } else if (oqueFazerAposIsso == 2) {
              continuarMenuDadosCadastrais = false;
              continuarPrograma = false;
  
            } else {
              printf("Opção invalida! Voltando ao menu principal ...\n");
              continuarMenuListarCategoria = false;
            }
        } while (continuarMenuDadosCadastrais);
        break;
        
        

      }

    } while (continuarMenuPrincipal);

  } while (continuarPrograma);

}