#include <stdio.h>
#include <stdlib.h>

// estrutura 
struct arvore{
    char item;
    struct arvore *esquerda;
    struct arvore *direita;
}; 
arvore *tNO;  //ponteiro para ponteiro

int contador; //conta a quantidade de elementos da arvore

//cria a arvore sem elementos
void arvore_Construtor(){
    tNO=NULL; //valor "nulo" indeterminado
    contador=0; //zera o contador
}


//insere elementos na arvore
void arvore_Inserir(char letra, arvore *&tNO){
    if(tNO==NULL){ // verifica se é = a Nulo
        if((tNO=(arvore*)malloc(sizeof(arvore)))==NULL); // caso seja a arvore ira receber Nulo
        else{
            tNO->item=letra; // endereco do item = letra;
            tNO->esquerda=tNO->direita=NULL; // edereco da esquerda recebe o endereco da direita que é = Nulo
            contador++; //adiciona um numero no contador;
        }
    }
    else{
        if(letra<tNO->item) // letra menor que endereco do item 
            return arvore_Inserir(letra,tNO->esquerda); // retorna a letra , endereco da esquerda;
        else{
            if(letra>tNO->item) // se a letra mairo que endereco do item 
                return arvore_Inserir(letra,tNO->direita); // retorna a letra, endereco da direita;
        }
    }
}

//percorre a arvore
void arvore_Busca_em_Ordem(arvore *&tNO){
    if(tNO!=NULL){ // se tNO for diferente de nulo 
        arvore_Busca_em_Ordem(tNO->esquerda);
        printf(" %c",tNO->item);
        arvore_Busca_em_Ordem(tNO->direita);
    }
}

//menu com opcoes
void menu()
{
	printf("Digite a opcao desejada: \n");
	printf("1- Inserir \n");
	printf("2- Imprimir \n");
	printf("0 - Sair");
	printf("\nopcao:");
}

//complemento
//retorna o tamanho da arvore
int arvore_Tamanho(){
    return contador;
}
// 

int main(){
    arvore_Construtor(); //chama o construtor da arvore
    char x;  // variavel para receber a letra
    int op; // variavel para receber a opcao
    do{  // iniciar o loop
    menu(); // chama o menu
    scanf("%i",&op); 
    switch(op)
	{
		case 1: 
		   system("cls"); // limpar a tela
        	printf("\nInforme a letra: ");
        	scanf("%s",&x);
        	arvore_Inserir(x,tNO); // passando a "LETRA" para o endereco
        	printf("\n\n");
        break;
		case 2:
			system("cls"); // limpar a tela
			printf("\nQuantidade de elementos: %d\n",contador);
			printf("\nArvore em ordem:\n");
    		arvore_Busca_em_Ordem(tNO); //define como vai ser inserido na arvore
   			printf("\n\n");
			break;
		case 0:
			return 0;
			break;			
		default:
			printf("Opcao invalida!! \n");
			break;	
	}
	}while (op != 0);
};

