#ifndef FUNCIONES_H
#define FUNCIONES_H



/*Se imprimen estos valores*/
#define f "#f"
#define t "#t"

/*Punteros a funciones*/

/*Operaciones aritmetica*/

int (*sumar)(int,int);

int (*restar)(int,int);

int (*multiplicar)(int,int);

int (*quotient)(int,int);

int (*modulo)(int,int);

/*Operaciones comparativas*/
int (*igual)(int,int);

int (*mayor)(int,int);

int (*menor)(int,int);

int (*mayor_igual)(int,int);
	
int (*menor_igual)(int,int);


/*Operaciones logicas*/
int (*not)(int,int);//deberia de recibir solo un argumento
        //se coloca dos para que se encuentre 
        //la logicca en sincronia con las demas funciones.

int (*and)(int,int);

int (*or)(int,int);

#endif
