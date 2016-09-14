#ifndef FUNCIONES_H
#define FUNCIONES_H



/*Se imprimen estos valores*/
#define f "#f"
#define t "#t"

/*Macros para simbolos de llaves en las funciones*/
#define SUM "+"         //43
#define RES "-"         //45
#define MUL "*"         //42
#define DIV "div"       //23
#define MOD "mod"       //20
#define IGUAL "="       //61
#define MAYOR ">"       //62
#define MENOR "<"       //60
#define MAYOR_IGUAL ">="//23
#define MENOR_IGUAL "<="//21
#define AND "and"       // 7
#define OR "or"         //25
#define NOT "not"       //36

/*Define puntero tipo funcion*/
typedef int(*f_ptr)(int,int);

/****Punteros a funciones****/

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
