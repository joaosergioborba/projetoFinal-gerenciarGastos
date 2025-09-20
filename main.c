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
  bool continuarMenuFornecedor = true;
  bool continuarMenuProdutosServicos = true;
  bool continuarPrograma = true;

  //Variaveis fluxo do sistema
  int oqueFazerAposIsso;
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

        break;
        case 2:
        printf("Buscando suas informações...\n");
        sleep(1);
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

          //Mudei essa parte em relação ao fluxograma, pois acho mais eficiente pedir a descrição da despesa que pedir um produto ou serviço, ja que pode haver opções onde nunhuma das duas se enquadra: obs.
          printf("Descrição: ");
          fgets(descricaoDespesaMenuCadastrarDespesas, sizeof(descricaoDespesaMenuCadastrarDespesas), stdin);
          descricaoDespesaMenuCadastrarDespesas[strcspn(descricaoDespesaMenuCadastrarDespesas, "\n")] = '\0';

          printf("Fornecedor: ");
          fgets(fornecedorMenuCadastrarDespesas, sizeof(fornecedorMenuCadastrarDespesas), stdin);
          fornecedorMenuCadastrarDespesas[strcspn(fornecedorMenuCadastrarDespesas, "\n")] = '\0';

          printf("Quantidade: ");
          scanf("%f", &quantidadeMenuCadastrarDespesas);
          getchar();

          printf("Cadastrando despesa...\n");
          printf("Despesa cadastrada\n");
          printf("O que deseja fazer agora? [0 - Voltar ao menu principal | 1 - cadastrar uma nova despesa]\n");
          scanf("%d", &oqueFazerAposIsso);
          getchar();

          // chamar funcao que vai cadastrar a despesa

          if(oqueFazerAposIsso == 0){

            continuarMenuDespesa = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuDespesa = true;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuDespesa = false;
          }
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
          printf("Produto ou serviço: ");
          fgets(descricaoReceitaMenuCadastrarReceitas, sizeof(descricaoDespesaMenuCadastrarDespesas), stdin);
          descricaoReceitaMenuCadastrarReceitas[strcspn(descricaoReceitaMenuCadastrarReceitas, "\n")] = '\0';

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

            continuarMenuDespesa = false;

          } else if(oqueFazerAposIsso == 1){

            continuarMenuDespesa = true;

          } else {
            printf("Opção invalida! Voltando ao menu principal ...\n");
            continuarMenuDespesa = false;
          }

        } while (continuarMenuReceitas);

      
        break;
        case 5:
        printf("Consultando dados ...\n");
        //chamar funcao que vai calcular a receita, as despesas, o lucro.
        break;
        case 6:
        printf("Menu de comparação de preços\n");
        printf("Qual produto/ serviço deseja comparar agora?\n");
        fgets(produtoOuServicoMenuComparativo, sizeof(produtoOuServicoMenuComparativo), stdin);
        produtoOuServicoMenuComparativo[strcspn(produtoOuServicoMenuComparativo, "\n")] = '\0';

        break;
        case 7:
        break;
        case 8:
        break;
        case 9:
        gerenciadorCategorias(categorias);
        break;
        case 10:
        break;
        
        

      }

    } while (continuarMenuPrincipal);

  } while (continuarPrograma);

}