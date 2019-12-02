#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define conta_adm "root"
#define senha_adm "root"

char intro();
void login_adm();
void menu_login_inicial();
void login_usuario();
int validar_login_usuario();
void menu_adm();
void pedidos_adm();

char intro(){
	printf("                               STEVE'S PIZZA SYSTEM CONTROL (SPSC)\n");
}

struct cardapio{
	char nome[50];
	char tam;
	int custo[100];	
}car_bebida[100],car_sobremesa[100],car_sabor[100],cad_bedidas[100],cad_sobremesa[100],cad_sabores[100];

struct clientes{
	char nome[50];
	char ender[300];
	float numcel[15];
}cliente[1000],cad_cliente[1000];

struct cadastro{
   char user[20];
   char pass[20];
   int codigo;
}usuario[1000],admin[50],cadastro_user[1000],cad_admin[50];

struct pedidos{
	char nome[50];
	char tam;
	int custo[100];
}ped_sabor[50],ped_bebida[50],ped_sobremesa[50];

int validar_login_usuario(int a,int c)
{
   int r;

   if (strcmp(cadastro_user[a].user,usuario[c].user)==0)
   {
       r = 1; //usuario ja existe
   }
   else r = 0; //usuario nao existe
   return (r);
}

int validar_login_adm(int a,int c)
{
   int r;

   if (strcmp(cad_admin[a].user,admin[c].user)==0)
   {
       r = 1; //usuario ja existe
   }
   else r = 0; //usuario nao existe
   return (r);
}

void cadastro_cliente(int a)
{
   int b,c;
   system("cls");
   usuario_existente:
   usuario[a].codigo = a+1;
   printf("\n\tCadastro %d",usuario[a].codigo);
   puts("\n\n\tDigite o login: ");
   printf("\t");
   scanf(" %s",cadastro_user[a].user);
   for (c=0;c<1000;c++)
   {
       b = validar_login_usuario(a,c);
       if (b==1) break;
   }
   if (b==0)
   {
       memcpy(usuario[a].user,cadastro_user[a].user,50);
       puts("\tDigite a senha: ");
       printf("\t");
       scanf(" %s",usuario[a].pass);
   }
   else if (b==1)
   {
       printf("\nLogin ja existente!\n");
       goto usuario_existente;
   }
}

void cadastro_administrador(int a)
{
   int b,c;
   system("cls");
   admin_existente:
   admin[a].codigo = a+1;
   printf("\n\tCadastro %d",admin[a].codigo);
   puts("\n\n\tDigite o login: ");
   printf("\t");
   scanf(" %s",cad_admin[a].user);
   for (c=0;c<50;c++)
   {
       b = validar_login_adm(a,c);
       if (b==1) break;
   }
   if (b==0)
   {
       memcpy(admin[a].user,cad_admin[a].user,50);
       puts("\tDigite a senha: ");
       printf("\t");
       scanf(" %s",admin[a].pass);
   }
   else if (b==1)
   {
       printf("\nLogin ja existente!\n");
       goto admin_existente;
   }
}

void logar_usuario()
{
   int c;
   int logado;
   char login[1][20], senha[1][20];
   char fechar_login[] = {"EXIT"}, fechar_senha[] = {"EXIT"};

   erro_login:

   printf("\n\tPara fechar digite o usuario e a senha EXIT em maiusculo\n");
   printf("\n\tLogon\n");
   printf("\n\tLogin: ");
   scanf(" %s",login[0]);
   printf("\n\tSenha: ");
   scanf(" %s",senha[0]);

   if ((strcmp(login[0],fechar_login)==0)&&(strcmp(senha[0],fechar_senha)==0)) exit(0);
   else
   {
       for (c=0;c<1000;c++)
       {
           if ((strcmp(login[0],usuario[c].user)!=0) || (strcmp(senha[0],usuario[c].pass)!=0))
           {
               logado = 1; //login e/ou senha incorretos
           }
           else if((strcmp(login[0],usuario[c].user)==0) && (strcmp(senha[0],usuario[c].pass)==0))
               {
                   logado = 2; //logado com sucesso
                   break;
               }

       }

       if (logado==1)
       {
           system("cls");
           printf("\nLogin e/ou senha incorreto(s)\n");
           printf("\nTente Novamente!\n");
           goto erro_login;
       }
       else if (logado==2)
       {
           system("cls");
           printf("\nLogado com sucesso!\n\nBem-vindo(a) %s\n",login[0]);
           printf("Codigo do usuario: %d\n\n",usuario[c].codigo);
           login_usuario();
       }
   }
}

void login_usuario()
{
   int op_user;

   tela_inicial_user:
       printf("\n\t9- Voltar a tela inicial de login");
       printf("\n\t0- Fechar\n\t");
       scanf("%d",&op_user);

       if (op_user==9) {system("cls");menu_login_inicial();}
       else if (op_user==0) exit(0);
       else {system("cls"); printf("\n\tOpcao Invalida\n"); goto tela_inicial_user;}
}

void logar_adm()
{
   int c;
   int logado;
   char login[1][20], senha[1][20];
   char fechar_login[] = {"EXIT"}, fechar_senha[] = {"EXIT"};

   erro_login:

   printf("\n\tPara fechar digite o usuario e a senha EXIT em maiusculo\n");
   printf("\n\tLogon\n");
   printf("\n\tLogin: ");
   scanf(" %s",login[0]);
   printf("\n\tSenha: ");
   scanf(" %s",senha[0]);

   if ((strcmp(login[0],conta_adm)==0)&&(strcmp(login[0],senha_adm)==0)) logado = 2;
   else if ((strcmp(login[0],fechar_login)==0)&&(strcmp(senha[0],fechar_senha)==0)) exit(0);
   else
   {
       for (c=0;c<1000;c++)
       {
           if ((strcmp(login[0],admin[c].user)!=0) || (strcmp(senha[0],admin[c].pass)!=0))
           {
               logado = 1; //login e/ou senha incorretos
           }
           else if((strcmp(login[0],admin[c].user)==0) && (strcmp(senha[0],admin[c].pass)==0))
               {
                   logado = 2; //logado com sucesso
                   break;
               }

       }
   }

       if (logado==1)
       {
           system("cls");
           printf("\nLogin e/ou senha incorreto(s)\n");
           printf("\nTente Novamente!\n");
           goto erro_login;
       }
       else if (logado==2)
       {
           system("cls");
           printf("\n\tLogado com sucesso!\n\n\tBem-vindo(a) [ADM]%s\n",login[0]);
          // printf("Codigo do ADMIN: %d\n\n",admin[c].codigo);
           menu_adm();
       }
}

void menu_adm(){
   int op_adm;


   tela_inicial_adm:
       printf("\n\t1- PEDIDOS\n");
       printf("\n\t2- CARDAPIO\n");
       printf("\n\t3- ESTOQUE\n");
       printf("\n\t4- CLIENTE\n");
       printf("\n\t5- USUARIO\n");
       printf("\t");
       scanf("%d", &op_adm);
       system("cls");
       if (op_adm == 1)
       { 
	   	pedidos_adm();	
    	}
	   if (op_adm == 2)
	   {
	   	cardapio_adm();
				   }			
}
void pedidos_adm(){
	int op_adm=0;
	char continua;
   	tela_pedidos:
       printf("\n\t1- NOVO PEDIDO\n");
       printf("\n\t2- EM PROCESSO\n");
       printf("\n\t3- CONCLUIDOS\n");
       scanf("%d",&op_adm);
       system("cls");	
       if (op_adm == 1){
		novo_pedido:
		printf("\nSABOR:");
		scanf("%s",&ped_sabor->nome);
		printf("\nTAMANHO:");
		scanf("%s",&ped_sabor->tam);
		printf("\nBEBIDA:");
		scanf("%s",&ped_bebida->nome);
		printf("\nENDERECO:");
		scanf("%s",&cliente->ender);
		printf("\nNOME:");
		scanf("%s",&cliente->nome);
		printf("\nTELEFONE:");
		scanf("%d",&cliente->numcel);
		system("cls");
		printf("\n\t----EM PROCESSO----\n");
		printf("\n\tSABOR: %s\n",ped_sabor->nome);
		printf("\n\tBEBIDA: %s\n",ped_bebida->nome);
		printf("\n\tENDERECO: %s\n",cliente->ender);
		printf("\n\tNOME: %s\n",cliente->nome);
		printf("\n\tTELEFONE: %d\n",cliente->numcel);
		printf("\n\t-------------------\n");
		printf("Deseja fazer um novo pedido (s/n)?:");
		scanf(" %c",&continua);
		if(continua == 's'){
			system("cls");
			goto novo_pedido;
		}	
		if(continua == 'n'){
			printf("Deseja voltar ao menu principal (s/n)?:");
			scanf(" %c",&continua);
			if (continua == 's'){
				system("cls");
				return menu_adm();
					}
				}
			}			
		}			
	
void cardapio_adm(){
	int op_adm=0;
	int cod_sab=0, cod_beb=0, cod_sob=0;
	char continua;
   	tela_cardapio:
       printf("\n\t1- NOVO SABOR\n");
       printf("\n\t2- NOVA BEBIDA\n");
       printf("\n\t3- NOVA SOBREMESA\n");
       printf("\n\t4- LISTAR SABORES\n");
       printf("\n\t4- LISTAR BEBIDAS\n");
       printf("\n\t3- LISTAR SOBREMESAS\n");
       scanf("%d",&op_adm);
       system("cls");	
       if (op_adm == 1){
		novo_pedido:
		printf("\n NOME SABOR:");
		scanf("%s",&ped_sabor->nome);
		printf("\nTAMANHO:");
		scanf("%s",&ped_sabor->tam);
		printf("\nBEBIDA:");
		scanf("%s",&ped_bebida->nome);
		printf("\nENDERECO:");
		scanf("%s",&cliente->ender);
		printf("\nNOME:");
		scanf("%s",&cliente->nome);
		printf("\nTELEFONE:");
		scanf("%d",&cliente->numcel);
		system("cls");
}

void menu_login_inicial()
{
   int op_login;

   menu_de_login:
   printf("1- Login de USUARIO\n");
   printf("2- Login de ADMINISTRADOR\n");
   printf("0- FECHAR\n");
   scanf(" %d",&op_login);
   if (op_login==1) logar_usuario();
   else if (op_login==2) logar_adm();
   else if (op_login==0) exit(0);
   else
   {
       system("cls");
       printf("Opcao invalida!\n");
       goto menu_de_login;
   }
}

int main(void)
{
	intro();	
   menu_login_inicial();
   return 0;
}
