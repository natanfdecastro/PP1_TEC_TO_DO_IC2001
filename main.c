#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "home.h"

//Nodos de la lista enlazada, tiene un puntero al siguiente, anterior y el nombre de una categoria
typedef struct nodo {
	char categoria[50];
	struct nodo *siguiente;
    struct nodo *anterior;
}Nodo;

//Estructura que permite tener un mayor control sobre los nodos
typedef struct listaEnlazada {
    Nodo *actual;
	Nodo *primero;
	Nodo *ultimo;
	int largo;
}Lista;

int color;
int menos = 0;
int mas = 0;
void setColor(int k)
{
    color = 31;
    if(k > 0)
    {
        mas += k;
        color += mas;
        if(color > 36)
        {
            while(color > 36)
            {
                color -= 6;
            }
        }
    }
    else
    {
        menos += k;
        color += menos;
        if(color < 31)
        {
            while(color < 31)
            {
                color += 6;
            }
        }
    }
    printf("\033[1;%dm", color);
}

void resetColor()
{
    printf("\033[0m");
}

//Adjunta un nodo al final de la lista
void addLast(Lista *lista) {
	Nodo *nuevoNodo = malloc (sizeof (Nodo));
    fgets(nuevoNodo -> categoria, 50, stdin);
	nuevoNodo -> siguiente = NULL;
    if(lista -> primero == NULL) {
		lista -> primero = nuevoNodo;
        lista -> actual = nuevoNodo;
        nuevoNodo -> anterior = NULL;
	}
    else {
        lista -> ultimo -> siguiente = nuevoNodo;
        nuevoNodo -> anterior = lista -> ultimo;
    }
	lista -> ultimo = nuevoNodo;
	lista -> largo++;
}

//Adjunta un nodo al inicio de la lista
void addFirst(Lista *lista) {
	Nodo *nuevoNodo = malloc (sizeof (Nodo));
    fgets(nuevoNodo -> categoria, 50, stdin);
	nuevoNodo -> anterior = NULL;
    if(lista -> primero == NULL) {
		lista -> ultimo = nuevoNodo;
        lista -> actual = nuevoNodo;
        nuevoNodo -> siguiente = NULL;
	}
    else {
        lista -> primero -> anterior = nuevoNodo;
        nuevoNodo -> siguiente = lista -> primero;
    }
	lista -> primero = nuevoNodo;
	lista -> largo++;
}

int delete(Lista *lista)
{
    char nombre[50];
    printf("Ingrese el nombre de la categoria que desea eliminar...\n");
    fgets(nombre, 50, stdin);
    /*system("clear");*/
    Nodo *ptr;
    ptr = lista -> primero;
    for(int i = 0; i < lista -> largo; i++)
    {
        if(strcmp(ptr -> categoria, nombre) == 0)
        {
            if(ptr -> anterior != NULL && ptr -> siguiente != NULL)
            {
                ptr -> anterior -> siguiente = ptr -> siguiente;
                ptr -> siguiente -> anterior = ptr -> anterior;
                lista -> largo--;
                lista -> actual = ptr -> anterior;
                free(ptr);
            }
            else if(ptr -> anterior == NULL && ptr -> siguiente == NULL)
            {
                lista -> primero = NULL;
                lista -> ultimo = NULL;
                lista -> actual = NULL;
                lista -> largo--;
                free(ptr);
            }
            else if(ptr -> anterior == NULL)
            {
                lista -> primero = lista -> primero -> siguiente;
                ptr -> siguiente -> anterior = NULL;
                lista -> largo--;
                lista -> actual = ptr -> siguiente;
                free(ptr);
            }
            else if(ptr -> siguiente == NULL)
            {
                lista -> ultimo = lista -> ultimo -> anterior;
                ptr -> anterior -> siguiente = NULL;
                lista -> largo--;
                lista -> actual = ptr -> anterior;
                free(ptr);
            }
            return 1;
        }
        ptr = ptr -> siguiente;
    }
    return 0;
}
void add_to_do(){
	
	
	
}
void show(Lista *lista)
{
    if(lista -> actual == NULL)
    {
        printf("ERROR\nNodos - Ningun nodo ha sido creado\n");
    }
    else
    {
        setColor(0);
        printf("%s", lista -> actual -> categoria);
        resetColor();
    }
}

void showPrevious(Lista *lista)
{
    if(lista -> actual == NULL)
    {
        printf("ERROR\nNodos - Ningun nodo ha sido creado\n");
    }
    else if(lista -> actual -> anterior == NULL)
    {
        printf("ERROR\nNodo Anterior - Este es el primer nodo\n");
    }
    else
    {
        setColor(0);
        printf("%s", lista -> actual -> anterior -> categoria);
        lista -> actual = lista -> actual -> anterior;
        resetColor();
    }
}

void showNext(Lista *lista)
{
    if(lista -> actual == NULL)
    {
        printf("ERROR\nNodos - Ningun nodo ha sido creado\n");
    }
    else if(lista -> actual -> siguiente == NULL)
    {
        printf("ERROR\nNodo Siguiente - No hay nodos mÃ¡s adelante\n");
        lista -> actual = lista -> primero;
    }
    else
    {
        setColor(0);
        printf("%s", lista -> actual -> siguiente -> categoria);
        lista -> actual = lista -> actual -> siguiente;
        resetColor();
    }
}

int main() {
	

	Lista *listaDoble = malloc (sizeof (Lista));
    home();
	while(1)
    {
        char comando[50];
        fgets(comando, 50, stdin);
        if(strcmp(comando, "add_first_category\n") == 0)
        {
            
			/*system("clear");*/
            printf("Porfavor ingrese un nombre para esta nueva categoria...\n");
            addFirst(listaDoble);
            /*system("clear");*/
            printf("Se ha creado la categoria: ");
            if(listaDoble -> largo == 1)
            {
                setColor(0);
            }
            else
            {
                setColor(-1);
            }
            printf("%s", listaDoble -> primero -> categoria);
            resetColor();
            printf("Pulse ENTER para continuar...\n");
            getchar();
            home();
        }
        else if(strcmp(comando, "add_last_category\n") == 0)
        {
            /*system("clear");*/
            printf("Porfavor ingrese un nombre para esta nueva categoria...\n");
            addLast(listaDoble);
            /*system("clear");*/
            printf("Se ha creado la categoria: ");
            if(listaDoble -> largo == 1)
            {
                setColor(0);
            }
            else
            {
                setColor(1);
            }
            printf("%s", listaDoble -> ultimo -> categoria);
            resetColor();
            printf("Pulse ENTER para continuar...\n");
            getchar();
            home();
        }
        else if(strcmp(comando, "delete_category\n") == 0)
        {
            /*system("clear");*/
            if(delete(listaDoble) == 0)
            {
                printf("ERROR\nCategorÃ­a Inexistente â€“ La categorÃ­a indicada no ha sido ingresada\n");
            }
            else
            {
                printf("Categoria eliminada.\n");
            }
            printf("Pulse ENTER para continuar...\n");
            getchar();
            home();
        }
        else if(strcmp(comando, "add_to_do\n") == 0){
        	
			add_to_do(listaDoble);	
        
		}
        else if(strcmp(comando, "show_current_category\n") == 0)
        {
            /*system("clear");*/
            show(listaDoble);
            printf("Pulse ENTER para continuar...\n");
            getchar();
            home();
        }
        else if(strcmp(comando, "show_previous_category\n") == 0)
        {
            /*system("clear");*/
            showPrevious(listaDoble);
            printf("Pulse ENTER para continuar...\n");
            getchar();
            home();
        }
        else if(strcmp(comando, "show_next_node\n") == 0)
        {
            /*system("clear");*/
            showNext(listaDoble);
            printf("Pulse ENTER para continuar...\n");
            getchar();
            home();
        }
        else if(strcmp(comando, "help\n") == 0)
        {
            printf("add_first_category: Agrega una nueva categoria al inicio de la lista\n");
            printf("add_last_category: Agrega una nueva categoria al final de la lista\n");
            printf("delete_category: Elimina una categoria\n");
            printf("add_to_do: Agregar una tarea a una categoria\n");
            printf("show_current_category: Muestra la categoria actual\n");
            printf("show_previous_category: Muestra la categoria anterior\n");
            printf("show_next_node: Muestra la siguiente categoria\n");
        }
        /*
        else if(strcmp(comando, "todos\n") == 0)
        {
            system("clear");
            Nodo *ptr = listaDoble -> primero;
            for(int i = 0; i < listaDoble -> largo; i++)
            {
                printf("%s", ptr -> categoria);
                ptr = ptr -> siguiente;
            }
            printf("Pulse ENTER para continuar...\n");
            getchar();
            home();
        }
        */
    }
	return 0;
}