#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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


int main() {

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

  char usuarioInformadoLogin[100];
  char senhaInformadaLogin[100];

  int cadastrarMaisUmUsuario = 0;

  char usuarios[5][100];
  char senhas[5][100];
  int posicaoUsuario = 0;


  do{

    do{

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

    } while(!cadastroEfeituado);

    do {

      printf("Usuário: ");
      fgets(usuarioInformadoLogin, sizeof(usuarioInformadoLogin), stdin);
      usuarioInformadoLogin[strcspn(usuarioInformadoLogin, "\n")] = '\0';

      printf("Senha: ");
      fgets(senhaInformadaLogin, sizeof(senhaInformadaLogin), stdin);
      senhaInformadaLogin[strcspn(senhaInformadaLogin, "\n")] = '\0';

      usuarioLogado = efeituarLogin(usuarios, senhas, usuarioInformadoLogin, senhaInformadaLogin, usuarioLogado);

      if(usuarioLogado){
        printf("Login efeituado\n");
      } else if(!usuarioLogado){
        printf("Credenciais inválidas, tente novamente!\n");
      }


    } while (!usuarioLogado);

  } while (continuarPrograma);







  
}