/*
*	Programa: TALLER CORTE 3
*	Fecha: 6/11/2017
*	Presentado por: CAMILA ANDREA BORJA SANCHEZ Y KELIN ALEJANDRA ARBOLEDA
*/

//Librerias;
#include <stdio.h>
#include <stdlib.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

//Estructura;
struct Nodo{
	int dato;
	Nodo *siguiente;
	Nodo *anterior;
};

//Prototipo de funciones;
void menu();
void lista_Simple();
void lista_Doble();
void lista_Circular_Doble();
void insertar_Simple();
void lista_Desordenada();
void lista_Ordenada(Nodo *&, int );
void mostrar_Simple();
void buscar_Simple();
void modificar_Simple();
void eliminar_Simple();
void insertar_Doble();
void mostrar_Doble();
void mostrar_D_Primero_Ultimo();
void mostrar_D_Ultimo_Primero();
void buscar_Doble();
void modificar_Doble();
void eliminar_Doble();
void insertar_Circular();
void mostrar_Circular();
void mostrar_Primero_Ultimo();
void mostrar_Ultimo_Primero();
void buscar_Circular();
void modificar_Circular();
void eliminar_Circular();

//prototipo de las funciones del juego de Josephus
void juegoJosephus();
int datosJuego(int n, int m);

//Variables globales;
Nodo* primero = NULL;
Nodo* ultimo = NULL; 

//Menu principal;
int main(){
	menu();
	return 0;
}
//Funcion principal;
void menu(){
	int opcion;
	do{
		printf("...........................\n");
        printf(".        BIENVENIDO       .\n");
        printf("...........................\n");
        printf(".                         .\n");
        printf(".    1. LISTA SIMPLE      .\n");
        printf(".    2. LISTA DOBLE       .\n");
        printf(".    3. LISTA CIRCULAR    .\n");
        printf(".    4. JUEGO JOSEPHUS    .\n");
        printf(".    0. SALIR             .\n");
        printf(".                         .\n");
        printf("...........................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: lista_Simple();
				break;
			case 2: lista_Doble();
				break;
			case 3: lista_Circular_Doble();
				break;
			case 4:  juegoJosephus();
				break;
			case 0: exit(0);
				break;
			default: printf("\nOpcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);	
}
//Funcion lista simple;
void lista_Simple(){
	int opcion;
	do{
		printf("...........................\n");
        printf(".       LISTA SIMPLE      .\n");
        printf("...........................\n");
        printf(".                         .\n");
        printf(".    1. Insertar          .\n");
        printf(".    2. Mostrar           .\n");
        printf(".    3. Buscar            .\n");
        printf(".    4. Modificar         .\n");
        printf(".    5. Eliminar          .\n");
        printf(".    0. Salir             .\n");
        printf("...........................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: insertar_Simple();
				break;
			case 2: mostrar_Simple();
				break;
			case 3: buscar_Simple();
				break;
			case 4: modificar_Simple();
				break;
			case 5: eliminar_Simple();
				break;
			case 0: (menu);
				break;
			default: printf("\nOpcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion menu insertar elemento;
void insertar_Simple(){
	int opcion, dato;
	do{
		printf("...........................\n");
        printf(".          INSERTE        .\n");
        printf("...........................\n");
        printf(".                         .\n");
        printf(".    1. Lista desordenada .\n");
        printf(".    2. Lista ordena      .\n");
        printf(".    0. salir             .\n");
        printf(".                         .\n");
        printf("...........................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: lista_Desordenada();
				break;
			case 2: printf("Ingrese un dato: ");
					scanf("%d", &dato);
			lista_Ordenada(primero,dato);
				break;
			case 0: (menu);
				break;
			default: printf("\nOpcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);	
}
//Funcion lista desordenada;
void lista_Desordenada(){
	Nodo* nuevo = reservar_memoria;
	printf("\nIngrese un dato: ");
	scanf("%d", &nuevo->dato);
	if(primero == NULL){
		primero = nuevo;
		primero -> siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo -> siguiente =nuevo;
		nuevo -> siguiente = NULL;
		ultimo = nuevo;
	}
	printf("\nDato ingresado con exito\n");
}
//Funcion lista ordenada;
void lista_Ordenada(Nodo *&primero, int n){
	int  inicio;
	Nodo* nuevo = reservar_memoria;
	nuevo -> dato = n; 
	nuevo -> siguiente = NULL;
	Nodo *aux = primero, *aux2 = NULL;
	while((aux != NULL) && (aux -> dato < n)){
		aux2 = aux;
		aux = aux -> siguiente;
	}
	if(primero == aux){
		primero = nuevo;
	}else{
		aux2 -> siguiente = nuevo;
		
	}
	nuevo -> siguiente = aux;
	printf("\nDato ingresado con exito\n");
}
	
//Funcion mostrar elemento;
void mostrar_Simple(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	if(primero != NULL){
		while(nuevo != NULL){
			printf("\n %d ", nuevo -> dato);
			nuevo = nuevo -> siguiente;
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}	
}
//Funcion buscar elemento;
void buscar_Simple(){	
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("\nIngrese el elemento a buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		while(nuevo != NULL && encontrado != 1){
			
			if(nuevo -> dato == nodoBuscado){
				printf("\nEl elemento %d fue encontrado\n", nodoBuscado);
				encontrado = 1;
			}
			
			printf("\n %d ", nuevo -> dato);
			nuevo = nuevo -> siguiente;
		}
		if(encontrado == 0){
			printf("\nElemento no encontrado\n");
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}
}
//Funcion modificar elemento;
void modificar_Simple(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("\nIngrese el elemento a buscar para modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		while(nuevo != NULL && encontrado != 1){
			
			if(nuevo -> dato == nodoBuscado){
				printf("\nEl elemento %d fue encontrado\n", nodoBuscado);
				printf("\nIngrese el nuevo dato: ");
				scanf("%d", &nuevo -> dato);
				printf("\nElemento modificado con exito\n");
				encontrado = 1;
			}
			
			printf("\n %d ", nuevo -> dato);
			nuevo = nuevo -> siguiente;
		}
		if(encontrado == 0){
			printf("\nElemento no encontrado\n");
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}
	
}
//Funcion eliminar elemento;
void eliminar_Simple(){
	int atras;
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	Nodo* anterior = reservar_memoria;
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf("\nIngrese el elemento a buscar para eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		while(nuevo != NULL && encontrado != 1){
			if(nuevo -> dato == nodoBuscado){
				if(nuevo == primero){
					primero = primero -> siguiente;	
				}else if(nuevo == ultimo){
					anterior -> siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior -> siguiente = nuevo -> siguiente;
						
				}
				printf("\nElemento eliminado con exito\n");
				encontrado = 1;
			}
			anterior = nuevo;
			nuevo = nuevo -> siguiente;
		}
		if(encontrado == 0){
			printf("\nElemento no encontrado\n");
			
		}else{
			free(anterior);
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}
}
//Funcion menu lista doble;
void lista_Doble(){
	int opcion;
	do{
		printf("...........................\n");
        printf(".       LISTA DOBLE       .\n");
        printf("...........................\n");
        printf(".                         .\n");
        printf(".    1. Insertar          .\n");
        printf(".    2. Mostrar           .\n");
        printf(".    3. Buscar            .\n");
        printf(".    4. Modificar         .\n");
        printf(".    5. Eliminar          .\n");
        printf(".    0. Salir             .\n");
        printf("...........................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: insertar_Doble();
				break;
			case 2: mostrar_Doble();
				break;
			case 3: buscar_Doble();
				break;
			case 4: modificar_Doble();
				break;
			case 5: eliminar_Doble();
				break;
			case 0: (menu);
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion insertar elemento lista doble;
void insertar_Doble(){
	Nodo* nuevo = reservar_memoria;
	printf("\nIngrese un dato: ");
	scanf("%d", &nuevo->dato);
	
	if(primero == NULL){
		primero = nuevo;
		primero -> siguiente = NULL;
		primero -> anterior = NULL;
		ultimo = primero;
	}else{
		ultimo -> siguiente = nuevo;
		nuevo -> siguiente = NULL;
		nuevo -> anterior = ultimo;
		ultimo = nuevo;
	}
	
	printf("\nElemento ingresado con exito\n");
}
//Funcion menu mostrar doble;
void mostrar_Doble(){
	int opcion;
	do{
		printf("...........................\n");
        printf(".          MOSTRAR        .\n");
        printf("...........................\n");
        printf(".                         .\n");
        printf(".    1. Primero al ultimo .\n");
        printf(".    2. Ultimo al primero .\n");
        printf(".    0. salir             .\n");
        printf(".                         .\n");
        printf("...........................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: mostrar_D_Primero_Ultimo();
				break;
			case 2: mostrar_D_Ultimo_Primero();
				break;
			case 0: (menu);
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
	
}
//Funcion mostrar elemento lista doble del primero elemto al ultimo;
void mostrar_D_Primero_Ultimo(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	if(primero != NULL){
		while(nuevo != NULL){
			printf("\n %d", nuevo -> dato);
			nuevo = nuevo -> siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n");
	}		
}
//Funcion mostrar elemento lista doble del ultimo al primero;
void mostrar_D_Ultimo_Primero(){
	Nodo* nuevo = reservar_memoria;
	nuevo = ultimo;
	if(primero != NULL){
		while(nuevo != NULL){
			printf("\n %d", nuevo -> dato);
			nuevo = nuevo -> anterior;
		}
	}else{
		printf("\n La lista se encuentra vacia\n");
	}	
}
//Funcion buscar elemento lista doble;
void buscar_Doble(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("\nIngrese el dato del elemento a buscar: ");
	scanf("%d", &nodoBuscado);
	
	if (primero != NULL){
		while(nuevo != NULL){
			
			if(nuevo->dato == nodoBuscado){
				printf("\nEl elemento %d fue encontrado\n", nodoBuscado);
				encontrado = 1;
			}
			
			nuevo = nuevo -> siguiente;
		}
		if(encontrado == 0){
			printf("\nElemento no encontrado\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n");
	}
}
//Funcion modificar elemento lista doble;
void modificar_Doble(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("\nIngrese el dato del elemento a buscar para modificar: ");
	scanf("%d", &nodoBuscado);
	
	if (primero != NULL){
		while(nuevo != NULL){
			
			if(nuevo->dato == nodoBuscado){
				printf("\nEl elemento %d fue encontrado\n", nodoBuscado);
				printf("\nIngrese el nuevo elemento: ");
				scanf("%d", &nuevo->dato);
				printf("\nElemento modificado con exito\n");
				encontrado = 1;
			}
			
			nuevo = nuevo -> siguiente;
		}
		if(encontrado == 0){
			printf("\nElemento no encontrado\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n");
	}
}
//Funcion eliminar elemento lista doble;
void eliminar_Doble(){
	Nodo *actual = reservar_memoria;
	actual = primero;
	Nodo *atras = reservar_memoria;
	atras = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf("Ingrese el dato que desea eliminar: ");
	scanf("%d", &nodoBuscado);
	
	if(primero != NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual -> dato == nodoBuscado){
				
				if(actual == primero){
					primero = primero -> siguiente;
					primero -> anterior = NULL;
				}else if(actual == ultimo){
					atras ->siguiente = NULL;
					ultimo = atras;
				}else{
					atras -> siguiente = actual ->siguiente;
					actual -> siguiente -> anterior = atras;
				}
				printf("\nDato eliminado con exito\n");
				
				encontrado = 1;
			}
			atras = actual;
			actual = actual -> siguiente;
		}
		if(encontrado == 0){
			printf("\nDato no encontrado\n");
		}else{
			free(atras);
		}
	}else{
		printf("\nLista vacia.\n");
	}
}
//Funcion lista circular doble;
void lista_Circular_Doble(){
		int opcion;
	do{
		printf("...........................\n");
        printf(".     LISTA CIRCULAR      .\n");
        printf("...........................\n");
        printf(".                         .\n");
        printf(".    1. Insertar          .\n");
        printf(".    2. Mostrar           .\n");
        printf(".    3. Buscar            .\n");
        printf(".    4. Modificar         .\n");
        printf(".    5. Eliminar          .\n");
        printf(".    0. Salir             .\n");
        printf("...........................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: insertar_Circular();
				break;
			case 2: mostrar_Circular();
				break;
			case 3: buscar_Circular();
				break;
			case 4: modificar_Circular();
				break;
			case 5: eliminar_Circular();
				break;
			case 0: (menu);
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funcion insertar lista circular doble;
void insertar_Circular(){
	Nodo* nuevo = reservar_memoria;
	printf("Ingrese un elemento: ");
	scanf("%d", &nuevo->dato);
	
	if(primero == NULL){
		primero = nuevo;
		primero -> siguiente = primero;
		ultimo = primero;
		primero -> anterior = ultimo;
	}else{
		ultimo -> siguiente = nuevo;
		nuevo -> siguiente = primero;
		nuevo -> anterior = ultimo;
		ultimo = nuevo;
		primero -> anterior = ultimo;
	}
	printf("Elemento ingresado con exito\n");
}

//Funcion mostrar lista circular doble;
void mostrar_Circular(){
	int opcion;
	do{
		printf("...........................\n");
        printf(".          MOSTRAR        .\n");
        printf("...........................\n");
        printf(".                         .\n");
        printf(".    1. Primero al ultimo .\n");
        printf(".    2. Ultimo al primero .\n");
        printf(".    0. salir             .\n");
        printf(".                         .\n");
        printf("...........................\n");
        printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		
		switch(opcion){
			case 1: mostrar_Primero_Ultimo();
				break;
			case 2: mostrar_Ultimo_Primero();
				break;
			case 0: (menu);
				break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);	
}

//Funcion mostrar de primero a ultimo elemento;
void mostrar_Primero_Ultimo(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	if(primero != NULL){
		do{
			printf("%d ", nuevo->dato);
			nuevo = nuevo -> siguiente;
		}while(nuevo != primero);
	}else{
		printf("La lista se encuentra vacia");
	}
}

//Funcion mostrar de ultimo a primer elemento;
void mostrar_Ultimo_Primero(){
		Nodo* nuevo = reservar_memoria;
	nuevo = ultimo;
	if(primero != NULL){
		do{
			printf("%d ", nuevo->dato);
			nuevo = nuevo -> anterior;
		}while(nuevo != ultimo);
	}else{
		printf("La lista se encuentra vacia");
	}
}

//Funcion buscar lista  circular doble;
void buscar_Circular(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("Ingrese el elemento a buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		do{
			if(nuevo -> dato == nodoBuscado){
				printf("Elemento encontrado\n", nodoBuscado);
				encontrado = 1;
			}
			nuevo = nuevo -> siguiente;
		}while(nuevo != primero && encontrado != 1);
		if(encontrado == 0){
			printf("El elemento no fue econtrado\n");
		}
	}else{
		printf("La lista se encuentra vacia\n");
	}
}

//Funcion modificar lista circular doble;
void modificar_Circular(){
		Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf("Ingrese el elemento a buscar para modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		do{
			if(nuevo -> dato == nodoBuscado){
				printf("Elemento encontrado\n", nodoBuscado);
				printf("\nIngrese el nuevo dato: ");
				scanf("%d",&nuevo->dato);
				printf("El elemento fue modificado con exito\n");
				encontrado = 1;
			}
			nuevo = nuevo -> siguiente;
		}while(nuevo != primero && encontrado != 1);
		if(encontrado == 0){
			printf("El elemento no fue econtrado\n");
		}
	}else{
		printf("La lista se encuentra vacia\n");
	}
}
//Funcion eliminar lista circular doble;
void eliminar_Circular(){
	Nodo* nuevo = reservar_memoria;
	nuevo = primero;
	Nodo* atras = reservar_memoria;
	atras = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf("\nIngrese el elemento a buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL){
		do{
			if(nuevo -> dato == nodoBuscado){
				printf("\nElemento encontrado", nodoBuscado);
				
				if(nuevo == primero){
					primero = primero -> siguiente;
					primero -> anterior = ultimo;
					ultimo -> siguiente = primero;
				}else if(nuevo == ultimo){
					ultimo = atras;
					ultimo -> siguiente = primero;
					primero -> anterior = ultimo;
				}else{
					atras -> siguiente = nuevo -> siguiente;
					nuevo -> siguiente -> anterior = atras;
				}
				
				encontrado = 1;
			}
			atras = nuevo;
			nuevo = nuevo -> siguiente;
		}while(nuevo != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\nEl elemento no fue econtrado\n");
		}else{
			free(atras);
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}
}

void juegoJosephus(){
	int NumPersonas, NumEliminacion; 
     
    printf("Ingrese el numero de personas a participar: "); 
    scanf("%d", &NumPersonas); 
 
    printf("Ingrese el numero de saltos para eliminar los participantes: "); 
    scanf("%d", &NumEliminacion); 
 
    printf("El sobreviviente es el: %d \n", datosJuego(NumPersonas,NumEliminacion));  
}
 
int datosJuego(int n, int m){ 
    int cantMax[100000], i; 
    int Cont1 = -1, Cont2 = 0, Cont3 = 0, Sobreviviente = 0;
    bool Salir = false; //Boolean para salir del while 
 
    while ((Cont1 < n) && (Salir == false)){ 
        Cont1++; 
        Cont2++; 
        if ((Cont2 == m) || (cantMax[Cont1] == 'X')){ 
            if (cantMax[Cont1] != 'X'){ 
                cantMax[Cont1] = 'X'; 
                Cont2=0; 
                Cont3++; 
            }else{
            	Cont2--; 
        	}
        } 
 
        if (Cont1 > n){ 
            Cont1 = -1; 
        } 
 
        if (Cont3 == (n-1)){
        	Salir=true; 
    	}
    } 
 
    for (i = 0; i < n; i++){ 
        if (cantMax[i] != 'X'){
        	Sobreviviente = i;
		}  
    } 
 
    return (Sobreviviente); 
}
