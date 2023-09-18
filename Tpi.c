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
    //Otras variables        
    



    
    
    printf("Ingrese un numero: ");
    scanf("%d %d %d %d %d", &numIngresado[0],&numIngresado[1],&numIngresado[2],&numIngresado[3], &numIngresado[4]);

    for(int i=0; i < 5; i++){
        for(int j =0; j < 5;j++){
            if(numIngresado[i] == numAleatorio[j]){
                
                if(numIngresado[i] == numAleatorio[i]){
                    printf("El numero %d la posicion esta correcta\n", numIngresado[i]);
                } else {
                    printf("El numero %d se repit pero la posicion esta incorrecta\n", numIngresado[i]);
                }
                break;
            }
        }
    }
    
    for(int i = 0; i < 5; i++){
        printf("%d ", numAleatorio[i]);
    }
    
        
    
    







    return 0;
}


char solicitarNombre(struct juego *jugador){
    printf("Ingrese su usuario: ");
    fgets(jugador->nombre,sizeof(jugador->nombre), stdin);

}
char saludarJugador(struct juego *jugador){
    printf("Hola %s\n", jugador->nombre);
    printf("nose que poner(instrucciones)\n");
}