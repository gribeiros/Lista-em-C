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

int main(){

Lista* lista;
lista = criaLista();
if(vazia(lista)){
   printf("Vazia!\n");
}
else{
    printf("Cheia\n");
}
int a=0,b=0,d=0,e=0;
printf("Quantos numeros quer inserir:");
scanf("%d",&a);
for(int c=0;c<a;c++){
    printf("Numero %d: ",c+1);
    scanf("%d",&b);
lista = insereLista(lista,b);
}
imprimiLista(lista);
printf("Buscar: ");
scanf("%d",&d);
if(buscar(lista,d)==NULL){
    printf("Não encontrou");
    }
    else{
        printf("Encontrou elemento");
    }
printf("\nRemover: ");
scanf("%d",&e);
lista = removeLista(lista,e);
printf("Depois da remoção:\n");
imprimiLista(lista);
}
