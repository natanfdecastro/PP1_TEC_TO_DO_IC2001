
/*>>>>>>>>>>>>Cabecera<<<<<<<<<<<<<<*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "home.h"   //Include para el archivo de impresiÃ³n en ejecuciÃ³n
#include "ascii.h"  //Include para el archivo de conversiÃ³n char a caracteres ascii

/*-------------------------------------------------------------------------------*\
 * Estructuras de Datos - Primer Proyecto Programado - II Semestre 2018          *
 * NatÃ¡n FernÃ¡ndez de Castro -2017105774 | Pablo Venegas SÃ¡nchez - 2018          *
\*-------------------------------------------------------------------------------*/

//>>>>>>>>>>Declaraciones<<<<<<<<<<\\

//Lista enlazada simple que se utiliza para almacenar los to do de cada categoria
typedef struct simple {
	
	// Declaración
    char tarea[50];
    char estado[10];
    struct simple *siguiente;

}Tarea;


typedef struct nodo { //Nodos de la lista enlazada, tiene un puntero al siguiente, anterior y el nombre de una categoria
	
	// Declaración
	char categoria[50];
    int nTareas;
    Tarea *primer_tarea;
    Tarea *ultima_tarea;
	struct nodo *siguiente;
    struct nodo *anterior;

}Nodo;


typedef struct listaEnlazada { //Estructura que permite tener un mayor control sobre los nodos
	
	// Declaración
    Nodo *actual;
	Nodo *primero;
	Nodo *ultimo;
	int largo;

}Lista;

int color;
int actual = 0;
int menos = 0;
int mas = 0;

void setColor(int k)
{
    /*FunciÃ³n destinada para fijar color a una hilera de caracteres
      en el que provee un cÃ³digo distinto cada vez que se llama
      -> Entradas: Entero de nombre 'K'
      -> Salidas: CÃ³digo de color
      -> Restricciones: Ninguna                                    */

    color = 31;
    if(k == 1)
    {
        ++mas;
        color += mas;
    }

    else if(k == -1)
    {
        --menos;
        color += menos;
    }

    else if(k == 2)
    {
        ++actual;
        color += actual;
    }

    else if(k == 3)
    {
        color += actual;
    }

    else if(k == -2)
    {
        --actual;
        color += actual;
    }

    if(color > 36)
    {
        while(color > 36)
        {
            color -= 6;
        }
    }

    else if(color < 31)
    {
        while(color < 31)
        {
            color += 6;
        }
    }

    printf("\033[1;%dm", color);
    
}

void resetColor()
{
	/* Función destinada a rejustar el color en un char
	 -> Entrada: Ninguna
	 -> Salida: Impresión con color rejustado
	 -> Restricciones: Ninguna					 */

	
    printf("\033[0m"); 
    
}

void add_to_do(Lista *lista)
{

    /* FunciÃ³n que agrega una tarea a una categorÃ­a especÃ­fica
       -> Entrada: Lista doble que posee las categorÃ­as y tareas
       -> Salida: Lista doble con la tarea agregada en la categorÃ­a ingresada
       -> Restricciones: La categorÃ­a en la que se desea agregar la tarea
          debe estar en la lista doble                                       */

    system("clear"); //Limpia la pantalla de terminal

    //DeclaraciÃ³n de variables
    char categoria[50];
    char tarea[50];
    Nodo *ptr;

    ptr = lista -> primero;

    printf(">>> Ingrese el nombre de la categorÃ­a a la que desea agregar una tarea...\n");

    fgets(categoria, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en categoría

    system("clear"); //Limpia la pantalla de terminal
    
    for(int i = 0; ptr != NULL; i++) // Se recorre la listaDoble
    {
    	
        if(strcmp(ptr -> categoria, categoria) == 0) // Comparo el texto ingresado con la categoria actual de la lista doble
        {
        	
            break; // Rompo el ciclo
            
        }
        
        ptr = ptr -> siguiente; // Muevo el puntero al siguiente
        
    }
    
    if(ptr == NULL) // Caso en que no encuentre la categoría
    {
    	
        printf("ERROR\nCategorÃ­a Inexistente â€“ La categorÃ­a indicada no ha sido ingresada.\n");
        printf("Pulse ENTER para continuar...\n");
        
        getchar();
        
    }
    
    else // Caso en que encuentre la categoría, se procede a buscar en la lista simple de tareas
    {
    	
        Tarea *nuevaTarea = malloc (sizeof (Tarea)); // Reservación de memoria y declaración de variable

        system("clear"); //Limpia la pantalla de terminal

        printf(">>> Ingrese la tarea que desea agregar...\n");

        fgets(tarea, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en tarea

        strcpy(nuevaTarea -> estado, " â˜ "); // Se asigna al char estado el estado pendiente

        system("clear"); //Limpia la pantalla de terminal

        if(ptr -> primer_tarea == NULL) // ValidaciÃ³n si la categorÃ­a encontrada no tiene
        {                               // tarea
        
            ptr -> primer_tarea = nuevaTarea; // Asigna a nuevaTarea el valor de primerTarea
            
            ptr -> ultima_tarea = nuevaTarea; // Asigna a nuevaTarea el valor de ultimaTarea
            
            strcpy(nuevaTarea -> tarea, tarea); // Asigna el valor del char ingresado al char tarea del nodo
            
            nuevaTarea -> siguiente = NULL; // Asigna en NULL el valor de siguiente
            
        }
        
        else // Caso en que tenga tarea
        {
        	
            ptr -> ultima_tarea -> siguiente = nuevaTarea; // Asigna a nuevaTarea el valor de siguiente de la últimaTarea
            
            ptr -> ultima_tarea = ptr -> ultima_tarea -> siguiente; // Asigna a ultimaTarea el valor de siguiente
            
            strcpy(nuevaTarea -> tarea, tarea); // Asigna en valor del char capturado en el char de nuevaTarea
            
           nuevaTarea -> siguiente = NULL; // Asigna en NULL el valor de siguiente
           
        }
        
        ptr -> nTareas++; // Incrementa en uno el valor de numero de tareas
        
        printf("La tarea ha sido agregada con exito\n");
        
        printf("Pulse ENTER para continuar...\n");
        
        getchar();
    }
    
    system("clear"); //Limpia la pantalla de terminal
    
}

void mark_to_do_done(Lista *lista){
	
	/* Función destinada a marcar como hecha la tarea, que el usuario ingresó, en la lista simple 
	de tareas de dada categoría
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: listaDoble con la tarea marcada como hecha en la categoría especificada por el usuario
	 -> Restricciones: La categoría y la tarea deben existir en las listas correspondientes						 */

    system("clear"); //Limpia la pantalla de terminal
    
    //Declaración
    char categoria[50];
    char tarea[50];
    Nodo *ptr;
    
    ptr = lista -> primero; // Asignación 
    
    printf(">>> Ingrese el nombre de la categorÃ­a a la que desea marcar una tarea...\n");
    
    fgets(categoria, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en categoría
    
    system("clear"); //Limpia la pantalla de terminal
    
    for(int i = 0; ptr != NULL; i++) // Recorre la listaDoble en busca de la categoría
    {
    	
        if(strcmp(ptr -> categoria, categoria) == 0) // Caso en que coincidan los char
            {
            	
                break; // Rompe el ciclo
                
            }
            
            ptr = ptr -> siguiente; // Asigna el valor siguiente 
            
    }
    
    if(ptr == NULL) // Caso que no exista la categoría en la listaDoble
    {
    	
        printf("ERROR\nCategorÃ­a Inexistente â€“ La categorÃ­a indicada no ha sido ingresada.\n");
        printf("Pulse ENTER para continuar...\n");
        
        getchar();
        
    }
    
    else // Caso que encuentre la categoría
    {
    	
        printf(">>> Ingrese la tarea que desea marcar como hecha...\n");
        
        fgets(tarea, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en tarea
        
        system("clear"); //Limpia la pantalla de terminal

        Tarea *ptrTarea; // Declaración
        
        ptrTarea = ptr -> primer_tarea; // Asignación de la primera pos de la lista simple de tareas

        for(int i = 0; ptrTarea != NULL; i++) // Recorre la lista en busca de la tarea
        {
        	
            if(strcmp(ptrTarea -> tarea, tarea) == 0) // Caso en que coincidan char tarea
            {
            	
                break; // Se rompe el ciclo
                
            }
            
            ptrTarea = ptrTarea -> siguiente; // Se asigna el valor del siguiente 
        }

        if(ptrTarea == NULL) // Caso en que la tarea exista en la lista simple
        {
        	
            printf("ERROR\nLa tarea indicada no ha sido ingresada"); 
            printf("Pulse ENTER para continuar...\n");
            
            getchar();
            
        }
        
        else // Caso en que encuentre la tarea
        {
        	
            strcpy(ptrTarea -> estado, " â˜’ "); // Le asigna al estado el símbolo de tarea marcada
            
            printf("La tarea ha sido marcada como hecha con Ã©xito\n");
            printf("Pulse ENTER para continuar...\n");
            
            getchar();
            
        }
    }
    
    system("clear"); //Limpia la pantalla de terminal
    
}

void delete_to_do(Lista *lista){
	
	/*Función destinada a eliminar la tarea, que el usuario ingresó, en la lista simple de tareas de dada categoría
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: listaDoble con la tarea eliminada en la categoría especificadas por el usuario
	 -> Restricciones: La categoría y la tarea deben existir en las listas correspondientes						 */

    system("clear"); //Limpia la pantalla de terminal
    
    // Declaración
    char categoria[50];
    char tarea[50];
	Nodo *ptr;
	
    ptr = lista -> primero; // Asignación
    
    printf(">>> Ingrese el nombre de la categorÃ­a a la que desea eliminar una tarea...\n");
    
    fgets(categoria, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en categoría
    
    system("clear"); //Limpia la pantalla de terminal
    
    for(int i = 0; ptr != NULL; i++) // Recorro la listaDoble en busca de la categoría ingresada
    {
    	
        if(strcmp(ptr -> categoria, categoria) == 0) // Compara una por una la categoría con el char ingresado
            {
            	
                break; // Rompe el ciclo una vez lo encuentre
                
            }
            
            ptr = ptr -> siguiente; // Avanza el puntero al siguiente de no coincidir los char
            
    }
    
    if(ptr == NULL) // Caso que no encuentre la categoría en la listaDoble
    {
    	
        printf("ERROR\nCategorÃ­a Inexistente â€“ La categorÃ­a indicada no ha sido ingresada.\n");
        printf("Pulse ENTER para continuar...\n");
        
        getchar();
        
    }
    
    else // Caso que encuentre la categoría en la listaDoble
    {
    	
        printf(">>> Ingrese la tarea que desea eliminar...\n");
        
        fgets(tarea, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en tarea
        
        system("clear"); //Limpia la pantalla de terminal

        Tarea *ptrTarea; // Declaración
        
        ptrTarea = ptr -> primer_tarea; // Asignación

        //En caso de ser la primer tarea
        if(strcmp(ptrTarea -> tarea, tarea) == 0) // Validación en caso que la tarea coincida con el char tarea 
        {
        	
            if(ptr -> nTareas > 2) // Caso en que el número de tareas sea mayor a dos
            {
            	
                ptr -> primer_tarea = ptr -> primer_tarea -> siguiente;
                
            }
            
            else if(ptr -> nTareas == 1) // Caso en que el número de tareas sea igual a 1
            {
            	
                ptr -> primer_tarea = NULL; // Asigna en NULL la primer tarea
                ptr -> ultima_tarea = NULL; // Asigna en NULL la última tarea
                
            }
            
            free(ptrTarea); // Elimina la tarea
        }

        //Caso de no ser la primer tarea, la busca
        else 
        {
        	
            for(int i = 0; ptrTarea -> siguiente != NULL; i++) // Recorrer la lista en busca de la tarea
            {
            	
                if(strcmp(ptrTarea -> siguiente -> tarea, tarea) == 0)
                {
                	
                    break; // Rompe el ciclo una vez la encuentra
                    
                }
                
                ptrTarea = ptrTarea -> siguiente; // Asigna el valor del siguiente al actual
            }

            
            if(ptrTarea -> siguiente == NULL) // Validación en caso que no enccuentre la tarea
            {
            	
                printf("ERROR\nLa tarea indicada no ha sido ingresada\n");
                printf("Pulse ENTER para continuar...\n");
                
                getchar();
                
            }

            //Caso en que la tarea que se quiere eliminar es la ultima
            else if(ptrTarea -> siguiente -> siguiente == NULL)
            {
            	
                ptr -> ultima_tarea = ptrTarea;
                
                free(ptrTarea -> siguiente); // Elimino la tarea
                
                ptrTarea -> siguiente = NULL; // Asigno NULL al siguiente
                
                printf("Tarea eliminada\n");
                printf("Pulse ENTER para continuar...\n");
                
                getchar();
                
            }

            //Caso en que la tarea se encuentre entre dos tareas
            else
            {
            	
                Tarea *ptr_temporal; // Declaración
                
                ptr_temporal = ptrTarea -> siguiente -> siguiente; // Asignación
                
                free(ptrTarea -> siguiente); // Elimino la tarea
                
                ptrTarea -> siguiente = ptr_temporal; // Asigno el valor en temporal
                
                printf("Tarea eliminada\n");
                printf("Pulse ENTER para continuar...\n");
                
                getchar();
                
            }
            
            ptr -> nTareas--; // Reduzco en uno el número de tareas
            
        }
        
        system("clear"); //Limpia la pantalla de terminal
        
    }
}



void addLast(Lista *lista) { //Adjunta un nodo al final de la lista

	/*Función destinada a añadir la categoría, que el usuario ingresó, en la primera posición 
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: listaDoble con la categoría agregada al principio de la de dicha lista
	 -> Restricciones: Ninguna */
	
	Nodo *nuevoNodo = malloc (sizeof (Nodo)); // Asignación y reservación de memoria
	
    fgets(nuevoNodo -> categoria, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en categoría
    
    nuevoNodo -> primer_tarea = NULL; // Asigna en null el valor del puntero que apuntará a la lista simple de tareas
    
	nuevoNodo -> siguiente = NULL; // Asigna el puntero del nodo siguiente de la listaDoble en NULL
	
    if(lista -> primero == NULL)  // Validación en caso que no exista categoría en la primera posición
	{
		
		lista -> primero = nuevoNodo;
		
        lista -> actual = nuevoNodo;
        
        nuevoNodo -> anterior = NULL;
	}
	
    else { // Validación en caso que ya exista categoría en la última posición
    	
        lista -> ultimo -> siguiente = nuevoNodo;
        
        nuevoNodo -> anterior = lista -> ultimo;
        
    }
    
	lista -> ultimo = nuevoNodo; // Asigno a la última posición de la lista el nuevoNodo
	
	lista -> largo++; // Aumento en uno el largo de la listaDoble
}

//Adjunta un nodo al inicio de la lista
void addFirst(Lista *lista) 
{
	/*Función destinada a añadir la categoría, que el usuario ingresó, en la primera posición 
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: listaDoble con la categoría agregada al principio de la de dicha lista
	 -> Restricciones: Ninguna */
	
	Nodo *nuevoNodo = malloc (sizeof (Nodo)); // Asignación y reservación de memoria
	
    fgets(nuevoNodo -> categoria, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en categoría
    
    nuevoNodo -> primer_tarea = NULL; // Asigna en null el valor del puntero que apuntará a la lista simple de tareas
    
	nuevoNodo -> anterior = NULL; // Asigno el puntero anterior en NULL
	
    if(lista -> primero == NULL) { // Validación en caso que primer nodo sea NULL
    	
		lista -> ultimo = nuevoNodo;
		
        lista -> actual = nuevoNodo;
        
        nuevoNodo -> siguiente = NULL;
        
	}
	
    else { // Caso que exista nodo en la primera posición de la lista enlazada
    	
        lista -> primero -> anterior = nuevoNodo; 
        
        nuevoNodo -> siguiente = lista -> primero;
        
    }
    
	lista -> primero = nuevoNodo; // Asigno a la primera posición de la lista el nuevoNodo
	
	lista -> largo++; // Aumento en uno el largo
	
}

int delete(Lista *lista)
{
	/*Función destinada a eliminar la categoría en el nodo que el usuario ingresó
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: Impresión en pantalla de la categoría con sus tareas (en dado caso) en el nodo actual
	 -> Restricciones: Existir una categoría en el nodo actual, caso contrario da ERROR */
	
    char nombre[50]; // Declaración
    
    printf(">>> Ingrese el nombre de la categorÃ­a que desea eliminar...\n");
    
    fgets(nombre, 50, stdin); // Captura el char que ingrese el usuario y lo guarda en nombre
    
    system("clear"); //Limpia la pantalla de terminal
    
    Nodo *ptr; // Declaración
    
    ptr = lista -> primero; // Asignación
    
    for(int i = 0; i < lista -> largo; i++) // Recorro la listaDoble
    {
    	
        if(strcmp(ptr -> categoria, nombre) == 0) // Validación una vez que compara con char nombre
        {
        	
            
            if(ptr -> primer_tarea != NULL) // Validación en caso que la categoría contega tareas
            {
            	
            	//Declaración
                Tarea *ptrTarea; 
                Tarea *freeThis;
                
                ptrTarea = ptr -> primer_tarea; // Asignación
                
                for(int i = 0; ptrTarea != NULL; i++) // Recorro la lista simple eliminando las tareas 
                {
                	
                    freeThis = ptrTarea;
                    
                    ptrTarea = ptrTarea -> siguiente;
                    
                    free(freeThis);
                    
                }
            }

            //Elimina la categoria
            if(ptr -> anterior != NULL && ptr -> siguiente != NULL) // Validación en caso que la categoría tenga 
            {														// categoría antes y después
            	
                ptr -> anterior -> siguiente = ptr -> siguiente;
                
                ptr -> siguiente -> anterior = ptr -> anterior;
                
                lista -> largo--; // Reduzco el largo en uno 
                
                lista -> actual = ptr -> anterior; // Asigno al nodo actual el valor del anterior
                
                free(ptr); // Elimino la categoría
                
            }
            
            else if(ptr -> anterior == NULL && ptr -> siguiente == NULL) // Validación en caso que la categoría no 
            {															 //  tenga categoría antes y después
            	
                lista -> primero = NULL;
                
                lista -> ultimo = NULL;
                
                lista -> actual = NULL;
                
                lista -> largo--;
                
                free(ptr); // Elimino la categoría
                
            }
            
            else if(ptr -> anterior == NULL) // Validación en caso que la categoría no tenga categoría antes
            {
            	
                lista -> primero = lista -> primero -> siguiente;
                
                ptr -> siguiente -> anterior = NULL;
                
                lista -> largo--;
                
                lista -> actual = ptr -> siguiente;
                
                free(ptr); // Elimino la categoría 
                
            }
            else if(ptr -> siguiente == NULL) // Validación en caso que la categoría no tenga categoría siguiente
            {
            	
                lista -> ultimo = lista -> ultimo -> anterior; 
                
                ptr -> anterior -> siguiente = NULL; 
                
                lista -> largo--; // Reduzco el largo en uno 
                
                lista -> actual = ptr -> anterior; // Asigno los valores del nodo anterior
                
                free(ptr); // Elimino la categoría
                
            }
            
            return 1;
        }
        
        ptr = ptr -> siguiente;
    }
    
    return 0;
}

void show(Lista *lista)
{
	/*Función destinada a mostrar la categoría en el nodo actual de la listaDoble
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: Impresión en pantalla de la categoría con sus tareas (en dado caso) en el nodo actual
	 -> Restricciones: Existir una categoría en el nodo actual, caso contrario da ERROR */
	
    if(lista -> actual == NULL) // Validacion en caso de no exista categoría actual
    {
    	
        printf("ERROR\nNodos - Ningun nodo ha sido creado\n");
        
    }
    
    else
    {
    	
        setColor(3); // Fijo color
        
        toAsciiArt(lista -> actual -> categoria); // Llamada a la función de generación arte ASCII
        
        if(lista -> actual -> primer_tarea != NULL) // Validación en caso que la categoría contenga tareas
        {
        	
            Tarea *ptr; // Declaración
            
            ptr = lista -> actual -> primer_tarea; // Asignación
            
            for(int i = 0; ptr != NULL; i++) // Recorro la lista de tareas e imprimo cada una
            {
            	
                printf("%s", ptr -> estado);
                
                printf("%s", ptr -> tarea);
                
                ptr = ptr -> siguiente;
                
            }
        }
        
    resetColor(); // Reajusto color
    
    }
}

void showPrevious(Lista *lista)
{
	/*Función destinada a mostrar la categoría en el nodo anterior de la listaDoble
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: Impresión en pantalla de la categoría con sus tareas (en dado caso) en el nodo anterior
	 -> Restricciones: Existir una categoría en el nodo anterior, caso contrario da ERROR */
	
    if(lista -> actual == NULL) // Validacion en caso de que no haya categoría creada aún
    {
    	
        printf("ERROR\nNodos - Ningun nodo ha sido creado\n");
        
    }
    
    else if(lista -> actual -> anterior == NULL) // Validación en caso de no exista categoría antes 
    {
    	
        printf("ERROR\nNodo Anterior - Este es el primer nodo\n");
        
    }
    
    else
    {
    	
        setColor(-2); // Fija color
        
        toAsciiArt(lista -> actual -> anterior -> categoria); // Llamada a la función de generación arte ASCII
        
        lista -> actual = lista -> actual -> anterior; // Asigno a la categoría actual el valor de la anterior
        
        if(lista -> actual -> primer_tarea != NULL) // Validación en caso que la categoría contenga tareas
        {
        	
            Tarea *ptr; // Declaración
            
            ptr = lista -> actual -> primer_tarea; // Inicialización
            
            for(int i = 0; ptr != NULL; i++) // Recorro lista simple e imprimo las tareas que contenga
            {
            	
                printf("%s", ptr -> estado);
                
                printf("%s", ptr -> tarea);
                
                ptr = ptr -> siguiente;
                
            }
        }
        
        resetColor(); // Reajusto color
    }
}

void showNext(Lista *lista)
{
	/*Función destinada a mostrar la categoría en el nodo siguiente de la listaDoble
	 -> Entrada: Lista Doble con categorías y tareas
	 -> Salida: Impresión en pantalla de la categoría en el nodo siguiente
	 -> Restricciones: Existir una categoría en el nodo siguiente, caso contrario da ERROR */
	
    if(lista -> actual == NULL) // Validación en caso de que no hayan categorías creadas
    {
    	
        printf("ERROR\nNodos - Ningun nodo ha sido creado\n");
        
    }
    
    else if(lista -> actual -> siguiente == NULL) // Validación en caso de no existir categoría en nodo siguiente
    {
    	
        printf("ERROR\nNodo Siguiente - No hay nodos mÃ¡s adelante\n");
        
        lista -> actual = lista -> primero;
        
    }
    
    else
    {
    	
        setColor(2); // Fija color
        
        toAsciiArt(lista -> actual -> siguiente -> categoria); // Llama a la función de generación arte ASCII
        
        lista -> actual = lista -> actual -> siguiente; // Iguala categoría actual con la siguiente
        
        if(lista -> actual -> primer_tarea != NULL) // Validación caso que la categoría contenga tareas
        {
        	
            Tarea *ptr; //Declaración 
            
            ptr = lista -> actual -> primer_tarea; // Asignación
            
            for(int i = 0; ptr != NULL; i++) // Recorro lista simple de tareas y las imprimo
            {
            	
                printf("%s", ptr -> estado); 
                
                printf("%s", ptr -> tarea);
                
                ptr = ptr -> siguiente;
                
            }
        }
        
        resetColor(); // Reajusta color
    }
}

int main() {
	
	/*Función principal del programa, tiene como propósito capturar los comandos que ingrese
	 el usuario y mostrar o llamar las funciones dependiendo del comando
	 -> Entrada: Ninguna
	 -> Salida: LLamada a función o mostrar mensajes en terminal
	 -> Restricciones: Los comandos deben ser correctos. 									*/
	 
	FILE *registro;
    registro = fopen("registro.txt","a");
    fclose(registro);
    registro = fopen("registro.txt","r+");

    //char linea[50];
    /*
    while(!feof)
    {
        fgets(linea, 50, registro);
        cargar(linea);
    }
    */
	
	Lista *listaDoble = malloc (sizeof (Lista)); // Inicialización de la lista doble, contendrá 
												 // categorías y tareas	
    home();										 // Llamada a función de impresión en pantalla en home.h
    
	while(1) // Inicia el ciclo para recibir el comando
    {
    	
        char comando[50]; // Declaración variable comando tipo char
        
        fgets(comando, 50, stdin); // Captura el char que digite el usuario en ejecución
        
        if(strcmp(comando, "add_to_do\n") == 0)	// Validación en caso que comando coincida con función
        {
            add_to_do(listaDoble); // Llamada a función añadir tarea
            
            show(listaDoble); // Llamada a función mostrar listaDoble
        }
        
        else if(strcmp(comando, "mark_to_do_done\n") == 0) // Validación en caso que comando coincida con función
		{
        	
            mark_to_do_done(listaDoble); // Llamada a función marcar tarea como hecha
            
            show(listaDoble); // Llamada a función mostrar listaDoble
            
        }
        
        else if(strcmp(comando, "delete_to_do\n") == 0) // Validación en caso que comando coincida con función
		{

            delete_to_do(listaDoble); // Llamada a función eliminar tarea
            
            show(listaDoble); // Llamada a función mostrar listaDoble

        }
        
        else if(strcmp(comando, "add_first_category\n") == 0) // Validación en caso que comando coincida con función
        {
        	
            system("clear"); //Limpia la pantalla de terminal
            
            printf(">>> Porfavor ingrese un nombre para esta nueva categorÃ­a...\n");
            
            addFirst(listaDoble); // Llamada a función añadir categoría al principio
            
            system("clear"); //Limpia la pantalla de terminal
            
            printf("Se ha creado la categoria: ");
            
            if(listaDoble -> largo == 1)
            {
            	
                setColor(0); // Fijar color
                
            }
            else
            {
            	
                setColor(-1); // Fijar color
                
            }
            
            printf("%s", listaDoble -> primero -> categoria); // Imprimir categoría
            
            resetColor(); // Reajustar color
            
            printf("Pulse ENTER para continuar...\n");
            
            getchar();
            
            system("clear"); //Limpia la pantalla de terminal
            
            show(listaDoble); // Llamada a función mostrar listaDoble
            
        }
        else if(strcmp(comando, "add_last_category\n") == 0) // Validación en caso que comando coincida con función
        {
        	
            system("clear"); //Limpia la pantalla de terminal
            
            printf(">>> Porfavor ingrese un nombre para esta nueva categorÃ­a...\n");
            
            addLast(listaDoble); // Llamada a función añadir categoría al final
            
            system("clear"); //Limpia la pantalla de terminal
            
            printf("Se ha creado la categorÃ­a: ");
            
            if(listaDoble -> largo == 1)
            {
                setColor(0); // Fijar color
            }
            
            else
            {
                setColor(1); // Fijar color
            }
            
            printf("%s", listaDoble -> ultimo -> categoria); // Imprimir categoría
            
            resetColor(); // Reajustar color
            
            printf("Pulse ENTER para continuar...\n");
            
            getchar();
            
            system("clear"); //Limpia la pantalla de terminal
            
            show(listaDoble); // Llamada a función mostrar listaDoble
            
        }
        
        else if(strcmp(comando, "delete_category\n") == 0) // Validación en caso que comando coincida con función
        {
        	
            system("clear"); //Limpia la pantalla de terminal
            
            if(delete(listaDoble) == 0) // Llamada a función eliminar categoría, y valida 
            {
            	
                printf("ERROR\nCategorÃ­a Inexistente â€“ La categorÃ­a indicada no ha sido ingresada\n");
                
            }
            
            else
            {
                printf("CategorÃ­a eliminada.\n"); // Caso exitoso de eliminación
                printf("Pulse ENTER para continuar...\n");
                
                getchar();
                
                system("clear"); //Limpia la pantalla de terminal
            }
            
            if(listaDoble -> largo == 0)
            {
            	
                home();
                
                printf("Escriba help si desea conocer la lista de comandos.\n");
                
            }
            
            else
            {
            	
                show(listaDoble); // Llamada a función mostrar listaDoble
                
            }
        }
        else if(strcmp(comando, "show_current_category\n") == 0) // Validación en caso que comando coincida con función
        {
        	
            system("clear"); //Limpia la pantalla de terminal
            
            show(listaDoble); // Llamada a función mostrar listaDoble
            
        }
        else if(strcmp(comando, "show_previous_category\n") == 0) // Validación en caso que comando coincida con función
        {
        	
            system("clear"); //Limpia la pantalla de terminal
            
            showPrevious(listaDoble); // Llamada a función mostrar listaDoble
            
        }
        
        else if(strcmp(comando, "show_next_node\n") == 0) // Validación en caso que comando coincida con función
        {
        	
            system("clear"); //Limpia la pantalla de terminal 
            
            showNext(listaDoble); // Llamada a función mostrar listaDoble
            
        }
        
        else if(strcmp(comando, "help\n") == 0) // Validación en caso que comando coincida con función
        {
        	
        	
            system("clear"); //Limpia la pantalla de terminal
            home();
            printf("                | = = = = = = = = = = = = = = = = = H E L P = = = = = = = = = = = = = = = = = = |\n");
            printf("                |   add_first_category: Agregar una nueva categorÃ­a al inicio de la lista       |\n");
            printf("                |   add_last_category: Agregar una nueva categorÃ­a al final de la lista         |\n");
            printf("                |   delete_category: Eliminar una categorÃ­a                                     |\n");
            printf("                |   add_to_do: Agregar una tarea a una categorÃ­a especÃ­fica                     |\n");
            printf("                |   mark_to_do_done: Marcar una tarea como realizada                            |\n");
            printf("                |   delete_to_do: Eliminar una tarea                                            |\n");
            printf("                |   show_current_category: Mostrar la categorÃ­a actual                          |\n");
            printf("                |   show_next_node: Mostrar la siguiente categorÃ­a                              |\n");
            printf("                |   show_previous_category: Mostrar la categorÃ­a anterior                       |\n");
            printf("                |   help: Mostrar lista de comandos disponibles                                 |\n");
            printf("                |   about: Mostrar informaciÃ³n del programa, curso y desarrolladores            |\n");
            printf("                | = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = |\n");
        }
        
        else if(strcmp(comando, "about\n") == 0) // Validación en caso que comando coincida con función
		{

            system("clear"); //Limpia la pantalla de terminal
            home();
            printf("                | = = = = = = = = = = = = = = = = = A B O U T = = = = = = = = = = = = = = = = = |\n");
            printf("                |                                                                               |\n");
            printf("                |                       Organizador de tareas PROTEUS TO-DO                     |\n");
            printf("                |                                                                               |\n");
            printf("                |   Controla lo que tengas que hacer, ingresalo en el programa, estructuralo    |\n");
            printf("                |   mediante categorÃ­as, agrega todas las tareas y marcalas como hechas una     |\n");
            printf("                |   vez que la hayas realizado. AdemÃ¡s, puedes borrar categorÃ­as o tareas.      |\n");
            printf("                |                                                                               |\n");
            printf("                |   Instituto TecnolÃ³gico de Costa Rica                                         |\n");
            printf("                |   Estructuras de Datos II Semestre 2018                                       |\n");
            printf("                |   I Proyecto Programado                                                       |\n");
            printf("                |                                                                               |\n");
            printf("                |   Desarrolladores                                                             |\n");
            printf("                |   NatÃ¡n FernÃ¡ndez de Castro - 2017105774                                      |\n");
            printf("                |   Pablo Venegas SÃ¡nchez - 2018083497                                          |\n");
            printf("                | = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = |\n");

        }
        
        else
        {
        	
            system("clear"); //Limpia la pantalla de terminal
            
            if(listaDoble -> largo == 0)
            {
                home();
            }
            
            else
            {
                show(listaDoble);
            }
            
            // Caso que el comando sea erróneo
            printf("No existe el comando: %sEscriba help si desea conocer la lista de comandos.\n", comando);
            
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
