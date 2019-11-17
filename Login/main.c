#include <stdio.h>
#include <string.h>

char loginsenha();
char intro();

int main () {


	intro();
	loginsenha();
    
    return 0;
}

char intro(){
	printf("                                              STEVE'S PIZZA SYSTEM CONTROL\n");

}
char loginsenha(){
	char login1[15] = "spsc"; //Tem que ter mais espaço que a string. Pelo menos 1 a mais que a palavra.
    char login2[15]; //Pode ser do mesmo tamanho que o login
    char senha1[15] = "spsctest"; //Tem que ter mais espaço que a string. Pelo menos 1 a mais que a palavra.
    char senha2[15]; //Pode ser do mesmo tamanho que o senha
		printf("LOGIN: ");
    	scanf("%s",login2); //String se lê com %s
    	if (strcmp(login1, login2) == 0) //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
    	{
	    	printf("SENHA: ");
	    	scanf("%s",senha2); //String se lê com %s
	    	if (strcmp(senha1, senha2) == 0) //strcmp() é uma função da biblioteca string.h que compara 2 strings. Se for igual a 0 é porque as duas são iguais.
	    	{
	    		printf("TAMO DENTRO \n");
	   		}else{
	    		printf("SENHA INCORRETA\n");
			}    	
		}else{
    		printf("USUARIO NAO CADASTRADO\n");
		}
    return login1;
}


