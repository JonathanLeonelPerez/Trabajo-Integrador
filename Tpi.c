#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//estructura prueba
struct juego{
    char nombre[50];

}jugador;
//declaracion de funciones
char solicitarNombre(struct juego *jugador);
char saludarJugador(struct juego *jugador);


//funcion principal
int main(){
    //Bienvenida al programa
    solicitarNombre(&jugador);
    saludarJugador(&jugador);
    //Semilla de los numeros aleatorios
    srand(time(NULL));
    //Variables
    int numAleatorio[5];
    int numIngresado[5];
    int contadorIntentos = 0;
    //Genera un numero aleatorio tipo : [3,5,3,2,6,1]
    for(int i = 0; i < 5; i++){
        numAleatorio[i] = rand () % 10;
    }
    //Sintaxis del juego principal        
    //falta hacer que se repita 10 veces, si no adivina las 10 veces tiene que mostrar un fin del juego
    //variables para ver que numeros no estan en el arreglo numAleatorio
    int noRepetidos[5];
    //contador para mostrar un nuevo arreglo con los numeros que no se repiten en numAleatorio
    int contador = 0;

    
    
    printf("Ingrese un numero: ");
    scanf("%d %d %d %d %d", &numIngresado[0],&numIngresado[1],&numIngresado[2],&numIngresado[3], &numIngresado[4]);
    //Expresion que ve que numeros del arreglo numIngresado no se repiten en numAleatorio
    for(int i =0; i < 5; i++){
        int encontrado =0;
        for(int j =0; j < 5; j++){
            if(numIngresado[i] == numAleatorio[j]){
                encontrado = 1;
                break;
            }
        }
        if(!encontrado){
            noRepetidos[contador] = numIngresado[i];
            contador++;
        }
    }
    for(int i = 0;i < contador; i++){
        printf("El numero %d es incorrecto\n", noRepetidos[i]);
    }
    //Termina aca
    //Aca empieza la expresion que dice que numeros estan correctos y si estan o no en la posicion correcta
    for(int i=0; i < 5; i++){
        for(int j =0; j < 5;j++){
            if(numIngresado[i] == numAleatorio[j]){
                if(numIngresado[i] == numAleatorio[i]){
                    printf("El numero %d es correcto y la posicion es correcta\n", numIngresado[i]);
                } else {
                    printf("El numero %d es correcto pero la posicion esta incorrecta\n", numIngresado[i]);
                } 
                break;
            }
        }
    }
    //Esto es para ver nosotros si los numeros estan bien o mal, despues se tiene que borrar!
    for(int i = 0; i < 5; i++){
        printf("%d ", numAleatorio[i]);
    }
    
        
    
    







    return 0;
}

//Funcion que solicita el nombre del jugadoor
char solicitarNombre(struct juego *jugador){
    printf("Ingrese su usuario: ");
    fgets(jugador->nombre,sizeof(jugador->nombre), stdin);

}
//Funcion que saluda al jugador y muestra las instrucciones del juego.
char saludarJugador(struct juego *jugador){
    printf("Hola %s\n", jugador->nombre);
    printf("Consignas del juego 'adivina el numero':\n\n El juego es simple, tenes que adivinar un numero aleatorio de 5 digitos.\n Cada intento te marcara un color dependiendo que tan cerca estuviste de adivinar el numero:\n\n VERDE: Numero correcto en la posicion correcta.\n AMARILLO: Numero correcto en la posicion incorrecta.\n ROJO: Numero que no pertenece a los 5 digitos de numero.\n\n Una vez dicho esto, diviertete y A JUGAR!\n");

}
