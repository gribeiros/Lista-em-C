#include<stdio.h>
#include<stdlib.h>


typedef struct lista{
int info;
struct lista* prox;
}Lista;

Lista* criaLista(){
    return NULL;
}

Lista* insereLista(Lista* l,int a){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = a;
    novo->prox=l;
    return novo;
}

void imprimiLista(Lista* l){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        printf("%d\n",p->info);
    }
}

int vazia(Lista* l){
    if(l==NULL){
        return 1;
    }
    return 0;
}

Lista* buscar(Lista* l,int v){
Lista* p;
for(p=l;p!=NULL;p=p->prox){
    if(p->info==v){
        return p;
        }
    }
    return NULL;
}

Lista* removeLista(Lista* l,int v){
 Lista* ant = NULL;
 Lista* p = l;
while(p != NULL && p->info != v){
    ant = p;
    p = p-> prox;
    }
    if(p == NULL){
        return l;
    }
    if(ant == NULL){
       l=p->prox;
    }
    else{
    ant->prox=p->prox;
    }
    free(p);
    return l;
}

void liberaLista(Lista* l){
Lista* p=l;
while(p != NULL){
    Lista* t=p->prox;
    free(p);
    p=t;
    }
}






int main(){
Lista* lista;
int op=0;

int a=0,b=0,d=0,e=0,w=0;

do{
printf("\n98Escolha uma das opções abaixo:\n\n1-Criar a lista\n2-Inserir na lista\n3-imprimir lista\n4-Busca\n5-Remover da lista\n6-Liberar lista\n0-Sair\n\nOP:");
scanf("%d",&op);
system("cls || clear");
switch (op)
{
case 0:
    w=1;
break;

case 1:
      lista = criaLista();
      printf("\nCriada\n\n");
break;

case 2:
      printf("Quantos numeros quer inserir:");
scanf("%d",&a);
for(int c=0;c<a;c++){
    printf("Numero %d: ",c+1);
    scanf("%d",&b);
lista = insereLista(lista,b);
}
system("cls || clear");
break;

case 3:
    system("cls || clear");
    printf("Lista Impressa:\n\n");
      imprimiLista(lista);
      printf("\n");
break;

case 4:
    system("cls || clear");
      printf("Buscar: ");
scanf("%d",&d);
if(buscar(lista,d)==NULL){
    printf("\nNão encontrou\n\n");
    }
    else{
        printf("Encontrou elemento\n\n");
    }

break;

case 5:
    system("cls || clear");
printf("\nRemover: ");
scanf("%d",&e);
lista = removeLista(lista,e);
printf("Depois da remoção:\n");
imprimiLista(lista);

break;

case 6:
    system("cls || clear");
    liberaLista(lista);
    printf("Liberada\n");
break;
default:
    system("cls || clear");
    printf("Opção nao e valida\n");
    }
}while(op);
return 0;
}
