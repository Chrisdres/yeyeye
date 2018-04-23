#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *sig;//se crea la estructura de los nodos con los campos siguiente y anterior.
    struct Nodo *ant;
};
typedef struct Nodo tNodo;
typedef tNodo *Lista;//se renombra como lista.

Lista CreaNodo(int x)
{
    Lista aux;

    aux = (Lista)malloc(sizeof(tNodo));//se pide espacio en la memoria.
    if (aux != NULL)
    {
        aux->info = x;
        aux->sig = NULL; //se cre al nodo con el campo con la informacion y los punteros a ant y sig apuntan a null.
        aux->ant = NULL;
    }
    else
    {
        system("cls");
        printf("\n no hay memoria suficiente.");//mensaje que sale si no se encontro espacio.
        exit(1);
    }
    return aux;
}

Lista InsertaOrdenado(Lista L, int x)
{
    Lista pNodo,aux;

    pNodo = CreaNodo(x);
    if(L == NULL){
        L = pNodo; // si la lista esta vacia quda con el primer nodo.
    }
    else{
        if(x < L->info){
            pNodo->sig = L; // se ingresa en nodo cuando es menor al primer valor de la lista.
            L = pNodo;
        }
        else{
             aux = L;
             while(aux != NULL)
             {
                if(aux->info < x && aux->sig->info > x) // si el valor del nodo es menor al del nodo anterior y mayor del nodo siguiente queda al medio de ambos.
                {
                   pNodo->ant = aux;
                   pNodo->sig = aux->sig;
                   aux->sig->ant = pNodo;
                   aux->sig = pNodo;

                }
                else
                   aux = aux->sig;

            }

           }
        }

    return L;
}

Lista Elimina(Lista L,int x)
{
    Lista aux1, aux2;
    if(L->info == x){
       aux1 = L;
       L = L->sig;
       aux1->sig = NULL;
       free(aux1);;
    }
    else{
       aux1 = L;
       while(aux1->info != x) {
           aux1 = aux1->sig;
        }
       aux2 = L;
       while(aux2->sig != aux1){
           aux2 = aux2->sig;
        }
       aux2->sig = aux1->sig;
       aux1->sig = NULL;
       free(aux1);
       aux2 = NULL;

    return L;
}

void Imprime(Lista P)
{
    Lista aux;

    aux = P;
    printf("\nP: ");
    while(aux != NULL)
    {
        printf("%d > ", aux->info);// se muestra por pantalla los valores de lalista.
        aux = aux->sig;
    }

}
int main()
{
    Lista L;
    L = NULL;
    int x;
    char str[50];
    char *archivo;
    int i = 2;
    archivo = &str[i];
    char comando;
    FILE *arch;

   printf("TDA Listas Ordenadas> ");
   gets(str);
   comando = str[0];

   switch(comando){
       case 'I':
           arch = fopen(archivo,"r");
           if(arch == NULL){
            printf("\nno se encuentra el archivo.");
            exit(1);
           }
           fscanf(arch,"%d",&x);
           InsertaOrdenado(L,x);
           system("PAUSE");
           break;

       case 'L':
           Imprime(L);
           system("PAUSE");
           break;









   }

  return 0;
}
