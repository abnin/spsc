#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define conta_adm "root"
#define senha_adm "root"

void intro();
void menu_login_inicial();
void login_adm();
void login_usuario();
int validar_login_adm();
int validar_login_usuario();
int validar_cliente();
int validar_sabor();
int validar_bebida();
int validar_promo();
void cadastro_usuario();
void cadastro_cliente();
void cadastro_pizzaiolo();
void cadastro_sabor();
void cadastro_bebida();
void cadastro_promo();
void cadastro_recla();
void cadastro_elog();
void menu_principal();
void pedidos();
void cardapio();
void clientes();
void promo();
void recla_elog();
void estoque();
void relatorio();


void intro()
{
	printf("\n\t STEVE'S PIZZA SYSTEM CONTROL (SPSC)\n\n");
}

struct cardapio
{
	char nome[50];
	char tam[3];
	char custo[10];	
	int codigo;
}bebida[100],sabor[100],cad_bebida[100],cad_sabor[100];

struct clientes
{
	int codigo;
	char nome[50];
	char ender[300];
	char numcel[15];
}cliente[1000],cad_cliente[1000];

struct promocoes
{
	int codigo;
	char nome[50];
}promos[50],cad_promos[50];

struct recla_elog
{
	int codigo;
	char nome[50];
}recla[50],elog[50];

struct estoques
{
	char nome[50];
	char tam[3];
	char custo[10];	
	int codigo;
}bebida_est[100],sabor_est[100],cad_bebida_est[100],cad_sabor_est[100];

struct pizzaiolos
{
	char nome[50];
	int idade[2];
	float salario[10];
	char ender[300];
	float numcel[15];
	int codigo;
}pizzaiolo[100],cad_pizzaiolo[100];

struct cadastro
{
   char user[20];
   char pass[20];
   int codigo;
}usuario[1000],admin[50],cadastro_user[1000],cad_admin[50];

struct pedidos
{
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

int validar_cliente(int a,int c)
{
   int r;

   if (strcmp(cad_cliente[a].nome,cliente[c].nome)==0)
   {
       r = 1; //cliente ja existe
   }
   else r = 0; // nao existe
   return (r);
}

int validar_sabor(int a,int c)
{
   int r;

   if (strcmp(cad_sabor[a].nome,sabor[c].nome)==0)
   {
       r = 1; //sabor ja existe
   }
   else r = 0; // nao existe
   return (r);
}

int validar_bebida(int a,int c)
{
   int r;

   if (strcmp(cad_bebida[a].nome,bebida[c].nome)==0)
   {
       r = 1; //bebida ja existe
   }
   else r = 0; // nao existe
   return (r);
}

int validar_pizzaiolo(int a,int c)
{
   int r;

   if (strcmp(cad_pizzaiolo[a].nome,pizzaiolo[c].nome)==0)
   {
       r = 1; //cadastro ja existe
   }
   else r = 0; // nao existe
   return (r);
}

int validar_promo(int a,int c)
{
   int r;

   if (strcmp(cad_promos[a].nome,promos[c].nome)==0)
   {
       r = 1; //bebida ja existe
   }
   else r = 0; // nao existe
   return (r);
}

void cadastro_usuario(int a)
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

void cadastro_cliente(int a)
{
	int b,c;
	   system("cls");
	   cliente_existente:
	   cliente[a].codigo = a+1;
	   printf("\n\tCadastro %d",cliente[a].codigo);
	   puts("\n\n\tNome: ");
	   printf("\t");
	   scanf(" %s",cad_cliente[a].nome);
	   for (c=0;c<1000;c++)
	   {
	       b = validar_cliente(a,c);
	       if (b==1) break;
	   }
	   if (b==0)
	   {
	       memcpy(cliente[a].nome,cad_cliente[a].nome,50);
	       puts("\tEndereco: ");
	       printf("\t");
	       scanf(" %s",cliente[a].ender);
	       puts("\tTelefone: ");
	       printf("\t");
	       scanf(" %s",cliente[a].numcel);
	       
	   }
	   else if (b==1)
	   {
	       printf("\nCliente ja cadastrado!\n");
	       sleep(2);
	       goto cliente_existente;
	   }
	}	

void cadastro_pizzaiolo(int a)
{
	int b,c;
	   system("cls");
	   pizzaiolo_existente:
	   cliente[a].codigo = a+1;
	   printf("\n\tCadastro %d",pizzaiolo[a].codigo);
	   puts("\n\n\tNome: ");
	   printf("\t");
	   scanf(" %s",cad_pizzaiolo[a].nome);
	   for (c=0;c<1000;c++)
	   {
	       b = validar_pizzaiolo(a,c);
	       if (b==1) break;
	   }
	   if (b==0)
	   {
	       memcpy(pizzaiolo[a].nome,cad_pizzaiolo[a].nome,50);
	       puts("\tEndereco: ");
	       printf("\t");
	       scanf(" %s",pizzaiolo[a].ender);
	       puts("\tTelefone: ");
	       printf("\t");
	       scanf(" %s",pizzaiolo[a].numcel);
	       
	   }
	   else if (b==1)
	   {
	       printf("\nCliente ja cadastrado!\n");
	       sleep(2);
	       goto pizzaiolo_existente;
	   }
	}	
	
void cadastro_sabor(int a)
{
	int b,c;
	sabor_existente:
	   system("cls");
	   sabor[a].codigo = a+1;
	   printf("\n\tCadastro %d",sabor[a].codigo);
	   printf("\n\n\tNome: ");
	   scanf(" %s",cad_sabor[a].nome);
	    for (c=0;c<100;c++)
	   {
	       b = validar_sabor(a,c);
	       if (b==1) break;
	   }
	   if (b==0)
	   {
	   memcpy(sabor[a].nome,cad_sabor[a].nome,50);
       printf("\n\tTamanho: ");
       scanf(" %s",sabor[a].tam);
       printf("\n\tCusto: ");
       scanf(" %s",sabor[a].custo); 
       }
	   else if (b==1)
	   {
	       printf("\nSabor ja cadastrado!\n");
	       sleep(2);
	       goto sabor_existente;
	   }
	}	

void cadastro_bebida(int a)
{
	int b,c;
	bebida_existente:
	   system("cls");
	   bebida[a].codigo = a+1;
	   printf("\n\tCadastro %d",bebida[a].codigo);
	   printf("\n\n\tNome: ");
	   scanf(" %s",cad_bebida[a].nome);
	    for (c=0;c<100;c++)
	   {
	       b = validar_bebida(a,c);
	       if (b==1) break;
	   }
	   if (b==0)
	   {
		   memcpy(bebida[a].nome,cad_bebida[a].nome,50);
	       printf("\n\tTamanho: ");
	       scanf(" %s",bebida[a].tam);
	       printf("\n\tCusto: ");
	       scanf(" %s",bebida[a].custo); 
       }
	   else if (b==1)
	   {
	       printf("\nBebida ja cadastrada!\n");
	       sleep(2);
	       goto bebida_existente;
	}
}
			
void cadastro_promo(int a)
{
	int b,c;
	   promo_existente:
	   system("cls");
	   promos[a].codigo = a+1;
	   printf("\n\tCadastro %d",promos[a].codigo);
	   printf("\n\n\tNome: ");
	   scanf(" %s",cad_promos[a].nome);
	    for (c=0;c<100;c++)
	   {
	       b = validar_sabor(a,c);
	       if (b==1) break;
	   }
		if (b==1)
	   {
	       printf("\nPromocao ja cadastrado!\n");
	       sleep(2);
	       goto promo_existente;
	   }
}

void cadastro_recla(int a)
{
	int b,c;
	   system("cls");
	   recla[a].codigo = a+1;
	   printf("\n\tReclamacao %d",recla[a].codigo);
	   printf("\n\n\tEscreva a reclamacao: ");
	   scanf(" %s",recla[a].nome);
}	

void cadastro_elog(int a)
{
	int b,c;
	   system("cls");
	   elog[a].codigo = a+1;
	   printf("\n\tElogio %d",elog[a].codigo);
	   printf("\n\tEscreva o elogio: ");
	   scanf(" %s",elog[a].nome);
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
       printf("\n\t1- SPSC");   		
       printf("\n\t9- Voltar a tela inicial de login");
       printf("\n\t0- Fechar\n\t");
       scanf("%d",&op_user);
       if (op_user==1) menu_principal();		
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
           login_adm();
       }
}

void menu_principal()
{
   int op;
   intro();
   
   tela_inicial:
	   system("cls");
       printf("\n\t1- PEDIDOS\n");
       printf("\n\t2- CARDAPIO\n");
       printf("\n\t3- ESTOQUE\n");
       printf("\n\t4- CLIENTE\n");
       printf("\n\t5- RECLAMACOES E ELOGIOS (CLIENTES)\n");
       printf("\n\t6- PROMOCOES\n");
       printf("\n\t7- RELATORIOS\n");
       printf("\t");
       scanf("%d", &op);
       system("cls");
       if (op == 1) pedidos();	
	   if (op == 2) cardapio();
	   if (op == 3) cardapio();//estoque
	   if (op == 4) clientes();
       if (op == 4) promo();
       if (op == 5) recla_elog();
       if (op == 7) relatorio();
	
}

void pedidos()
{
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
				return menu_principal();
					}
				}
			}			
		}			
	
void cardapio()
{
	
	int op_card=0;
	int a=0,b=0,c=0,nc=0;
	char continua;
	tela_cardapio:
   	   system("cls"); 	
       printf("\n\t1- NOVO SABOR\n");
       printf("\n\t2- NOVA BEBIDA\n");
       printf("\n\t3- LISTAR SABORES\n");
       printf("\n\t4- LISTAR BEBIDAS\n");
       scanf("%d",&op_card);
       system("cls");	
       if (op_card == 1){
		novo_sabor:
			system("cls");	
			printf("\nQuantos sabores deseja cadastrar? \n");
	        scanf("%d",&nc);
	        if (a==0)
	        {
	          for (a=0;a<nc;a++)
	          {
	           cadastro_sabor(a);
	          }
	           goto tela_cardapio;
	        }
	        else if (a!=0)
	        {
	          b = a;
	          c = a+nc-1;
	          printf("\n%d\n",a);
	          for (a=b;a<=c;a++)
	          {
	           cadastro_sabor(a);
	          }
	        goto tela_cardapio;
	       }	
		}
	   if (op_card == 2){
			nova_bebida:
			system("cls");	
			printf("\nQuantos bebidas deseja cadastrar? \n");
	        scanf("%d",&nc);
	        if (a==0)
	        {
	          for (a=0;a<nc;a++)
	          {
	           cadastro_bebida(a);
	          }
	           goto tela_cardapio;
	        }
	        else if (a!=0)
	        {
	          b = a;
	          c = a+nc-1;
	          printf("\n%d\n",a);
	          for (a=b;a<=c;a++)
	          {
	           cadastro_bebida(a);
	          }
	        goto tela_cardapio;
	       }
		}
		if (op_card == 3)
		{
			system("cls");
			printf("\n\t---EM BREVE---\n");
			sleep(2);
			goto tela_cardapio;
	    }
		if (op_card == 4)
		{
			system("cls");
			printf("\n\t---EM BREVE---\n");
			sleep(2);
			goto tela_cardapio;
		}
	}

void clientes()
{
	int op_cliente;
	int a=0,adm_cad=0,b=0,c=0,nc=0;
	system("cls");
	tela_cliente:	
	printf("\n\t1- CADASTRAR CLIENTE\n");
	printf("\n\t2- LISTAR CLIENTES\n");
	printf("\n\t9- VOLTAR PARA O MENU\n");
	scanf("%d",&op_cliente);
	if (op_cliente == 1)
	{
		system("cls");	
		printf("\nQuantos cadastros deseja fazer? \n");
        scanf("%d",&nc);
        if (a==0)
        {
          for (a=0;a<nc;a++)
          {
           cadastro_cliente(a);
          }
           goto tela_cliente;
        }
        else if (a!=0)
        {
          b = a;
          c = a+nc-1;
          printf("\n%d\n",a);
          for (a=b;a<=c;a++)
          {
           cadastro_cliente(a);
          }
        goto tela_cliente;
       }
	}
	if (op_cliente == 2) goto tela_cliente;
	if (op_cliente == 9) menu_principal(); 	
}	

void promo()
{
	int op_promo=0;
	int a=0,adm_cad=0,b=0,c=0,nc=0;
	tela_promo:
	system("cls");
	printf("\n\t1- CADASTRAR PROMOCAO");
	printf("\n\t2- LISTAR PROMOCOES");
	scanf("%d",&op_promo);
	if(op_promo == 1) 
	{
		system("cls");	
		printf("\nQuantas promocoes deseja cadastrar? \n");
        scanf("%d",&nc);
        if (a==0)
        {
          for (a=0;a<nc;a++)
          {
           cadastro_promo(a);
          }
           goto tela_promo;
        }
        else if (a!=0)
        {
          b = a;
          c = a+nc-1;
          printf("\n%d\n",a);
          for (a=b;a<=c;a++)
          {
           cadastro_promo(a);
          }
        goto tela_promo;
       }
	if(op_promo == 2) 
	{
	system("cls");
	printf("\n\t---EM BREVE---\n");
	sleep(2);
	goto tela_promo;
    }
	
	}
}

void recla_elog()
{
	int op_re=0;
	int a=0,b=0,c=0,nc=0;
	tela_re:
	system("cls");
	printf("\n\t1- FAZER RECLAMACAO");
	printf("\n\t2- FAZER ELOGIOS");
	printf("\n\t3- LISTAR RECLAMACOES");
	printf("\n\t4- LISTAR ELOGIOS");
	scanf("%d",&op_re);
	
	if(op_re == 1)
	{
		system("cls");	
		printf("\nQuantas reclamacoes deseja fazer? \n");
        scanf("%d",&nc);
        if (a==0)
        {
          for (a=0;a<nc;a++)
          {
           cadastro_recla(a);
          }
           goto tela_re;
        }
        else if (a!=0)
        {
          b = a;
          c = a+nc-1;
          printf("\n%d\n",a);
          for (a=b;a<=c;a++)
          {
           cadastro_recla(a);
          }
        goto tela_re;
        }
	}
	if(op_re == 2)
	{
		system("cls");	
		printf("\nQuantas elogios deseja fazer? \n");
        scanf("%d",&nc);
        if (a==0)
        {
          for (a=0;a<nc;a++)
          {
           cadastro_elog(a);
          }
           goto tela_re;
        }
        else if (a!=0)
        {
          b = a;
          c = a+nc-1;
          printf("\n%d\n",a);
          for (a=b;a<=c;a++)
          {
           cadastro_elog(a);
          }
        goto tela_re;
        }
	}
	if(op_re == 3) 
	{
		system("cls");
		printf("\n\t---EM BREVE---\n");
		sleep(2);
		goto tela_re;
    }
	if(op_re == 4)
	{
		system("cls");
		printf("\n\t---EM BREVE---\n");
		sleep(2);
		goto tela_re;
    }	
}

void relatorio()
{
	system("cls");
	
	printf("\n\tSabor mais vendido:");
	printf("\n\tcabulosssso:");
	
}

void login_adm()
{
   int op_adm;
   int a=0,adm_cad=0,b,c,nc;
   intro();	
   tela_inicial_adm:
       printf("\n\t1- Cadastro de usuarios\n");
       printf("\n\t2- Cadastro de administradores\n");
       printf("\n\t3- SPSC\n");
       printf("\n\t9- Voltar a tela de login\n");
       printf("\n\t0- Fechar\n");
       printf("\t");
       scanf("%d", &op_adm);
       system("cls");
       if (op_adm == 1)
       {
           printf("\nQuantos cadastros deseja fazer? \n");
           scanf("%d",&nc);
           if (a==0)
           {
               for (a=0;a<nc;a++)
               {
                   cadastro_usuario(a);
               }
               goto tela_inicial_adm;
           }
           else if (a!=0)
           {
               b = a;
               c = a+nc-1;
               printf("\n%d\n",a);
               for (a=b;a<=c;a++)
               {
                   cadastro_usuario(a);
               }
               goto tela_inicial_adm;
           }
   		}
   		else if (op_adm == 2)
   		{
	       printf("\nQuantos cadastros deseja fazer? \n");
	       scanf("%d",&nc);
	       if (adm_cad==0)
	       {
	       for (adm_cad=0;adm_cad<nc;adm_cad++)
	       {
	           cadastro_administrador(adm_cad);
	       }
	       goto tela_inicial_adm;
	       }
	       else if (adm_cad!=0)
	       {
	           b = adm_cad;
	           c = adm_cad+nc-1;
	           printf("\n%d\n",a);
	           for (adm_cad=b;adm_cad<=c;adm_cad++)
	           {
	               cadastro_administrador(adm_cad);
	           }
	           goto tela_inicial_adm;
	       }
	   }
	   else if (op_adm == 3) menu_principal();
	   else if (op_adm == 0) exit(0);
	   else if (op_adm == 9) menu_login_inicial();
	}
	
void menu_login_inicial()
{
	   int op_login;
       intro();		
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
   menu_login_inicial();
   return 0;
}
