#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
//estructura prueba
struct juego{
    char nombre[50];

}jugador;
//declaracion de funciones
char solicitarNombre(struct juego *jugador);
char saludarJugador(struct juego *jugador);
int juego();
void mostrarRanking();

//funcion principal
int main(){
    int boton;
    //Bienvenida al programa
    solicitarNombre(&jugador);
    saludarJugador(&jugador);
    //Funcion del juego
    juego();
    //Bucle para hacer que el usuario juegue cuanto quiera
    for(int i = 0; i < 100; i++){
    printf("Desea jugar denuevo?\n");
    printf("1.Jugar denuevo\n2.Salir\n");
    scanf("%d", &boton);
    switch (boton)
    {
    case 1:{
        juego();
    }
    case 2:
        printf("Saliendo del programa xd...\n");
        return 0;
        break;
    
    default:
        break;
    }
    
    }
    
        
    
    

    return 0;
}


char solicitarNombre(struct juego *jugador){
    printf("Ingrese su usuario: ");
    fgets(jugador->nombre,sizeof(jugador->nombre), stdin);

}
char saludarJugador(struct juego *jugador){
    printf("Hola %s\n", jugador->nombre);
    printf("Consignas del juego 'adivina el numero':\n\n El juego es simple, tenes que adivinar un numero aleatorio de 5 digitos.\n Cada intento te marcara un color dependiendo que tan cerca estuviste de adivinar el numero:\n\n VERDE: Numero correcto en la posicion correcta.\n AMARILLO: Numero correcto en la posicion incorrecta.\n ROJO: Numero que no pertenece a los 5 digitos de numero.\n\n Una vez dicho esto, diviertete y A JUGAR!\n");
//(texto dispuesto a ser alterado)
}
int juego(){
    srand(time(NULL));
    //Variables
    int numAleatorio[5];
    int numIngresado[5];
    
    //Genera un numero aleatorio tipo : [3,5,3,2,6]
    for(int i = 0; i < 5; i++){
        numAleatorio[i] = rand () % 10;
    }
    //Variables para el juego  
    
    int noRepetidos[5];
    int contador = 0;
    //repetir 10 veces.
    for (int intento = 1; intento <= 10; intento++) { 
        printf("Intento %d:\n", intento);

        printf("Ingrese 5 números: ");
        scanf("%d %d %d %d %d", &numIngresado[0], &numIngresado[1], &numIngresado[2], &numIngresado[3], &numIngresado[4]);

        // Comprobar si los arreglos son iguales
        int iguales = 1;
        for (int i = 0; i < 5; i++) {
            if (numIngresado[i] != numAleatorio[i]) {
                iguales = 0;
                break;
            }
        }

        if (iguales) {
            printf("¡Los números ingresados son iguales a los números aleatorios!\n");
            break; 
            // Terminar el programa si son iguales
        } else {
            // Comprobar números correctos e incorrectos
            for (int i = 0; i < 5; i++) {
                int encontrado = 0;
                for (int j = 0; j < 5; j++) {
                    if (numIngresado[i] == numAleatorio[j]) {
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    noRepetidos[contador] = numIngresado[i];
                    contador++;
                }
            }
            for (int i = 0; i < contador; i++) {
                printf("El numero %d es incorrecto\n", noRepetidos[i]);
            }
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (numIngresado[i] == numAleatorio[j]) {
                        if (numIngresado[i] == numAleatorio[i]) {
                            printf("El numero %d es correcto y la posicion es correcta\n", numIngresado[i]);
                        } else {
                            printf("El numero %d es correcto pero la posicion esta incorrecta\n", numIngresado[i]);
                        }
                        break;
                    }
                }
            }
        }

        contador = 0; // Reiniciar contador de números no repetidos
    //BORRAR CUANDO TERMINEMOS TODO
    for(int i = 0; i < 5; i++){
        printf("%d ", numAleatorio[i]);
    }
    printf("\n");
    }
    printf("Fin del juego\n");
    //funcion rankings
    mostrarRanking();
}
