/**
 * @file Ruleta.c
 *
 * @brief TODO
 *
 * @author  Ismael <ismael@ismael-XPS-13-9380>
 * @version 2025-10-01
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intro.h"
#include "dibujo.h"
#include <stdlib.h>
#include <unistd.h>

int bola (void);

#define APUESTAS_SIZE 3



string color;
int numero;
char numero2[20];
float apuesta;
float fondos = 1000;
float universidad_hijos = 10000;
bool rojo;
bool negro;
bool verde;
bool fin = false;
bool admin = true;
int comision;
float tajada;

typedef struct apuestas {
    int decision;
    float dinero;
    int casilla;
} apuesta_t;

void tomar_decision (apuesta_t jugada[APUESTAS_SIZE]);

void procesar_resultado (apuesta_t jugada[APUESTAS_SIZE]);

void mostrar_opciones(bool admin);

void universidad(void);
int main (void) {
    
    srand (clock());
    
    apuesta_t jugada[APUESTAS_SIZE];
    
    bool all_in = true;

    
    
    
do{
    numero = rand () % 37;
    comision = fondos + 1;
    if (all_in){
    apuesta = fondos;    
    }
    switch (numero){
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
    case 12:
    case 16:
    case 18:
    case 19:
    case 21:
    case 23:
    case 25:
    case 27:
    case 30:
    case 32:
    case 34:
    case 36:
        color = "rojo";
        rojo = true;
        negro = false;
        verde = false;
        break;
    case 0: 
        color = "verde";
        verde = true;
        rojo = false;
        negro = false;
        break;
    default:
        color = "negro";
        negro = true;
        rojo = false;
        verde = false;
        break;
    }
    if (fondos == 0 && universidad_hijos > 0) {
        printf("Te has quedado sin dinero\n");
        sleep(2);
        printf("Pero todavia quedan fondos para la unviersidad de tus hijos ;)\n");
        sleep(2);
        printf("Como eres un ludopata de mierda ni siquiera voy a codificar la opcion \nde respetar ese dinero\n");
        sleep(2);
        printf("Deberia darte verguenza\n");
        sleep(2);
        clear_terminal();
        printf("Fondos Universidad hijos:%.2f", universidad_hijos);
        printf("\nCuanto quieres retirar:");
        tajada = get_user_float();
            universidad_hijos = universidad_hijos - tajada;
            if (universidad_hijos < 0) {
                printf("El banco ha detectado actividad fraudulenta en los fondos universitarios de tus hijos\n");
                printf("Te han cerrado la cuenta y ya no puedes apostar\n");
                return 0;
            }
        fondos = fondos + tajada; 
        printf("Hijo de puta\n");
        sleep(3);
        clear_terminal();
    }else if (fondos == 0 && universidad_hijos <= 0) {
        printf("Te has quedado sin dinero\n");
        sleep(2);
        printf("Puedes pedir un prestamo de 1000 euros o dejar de jugar porque ya te has fundido todo el dinero de la universidad de tus hijos\n");
        sleep(2);
        printf("Como eres un ludopata de mierda ni siquiera voy a codificar la opcion \nde dejar de jugar porque se que no la vas a usar\n");
        sleep(2);
        printf("Deberia darte verguenza\n");
        fondos = 1000;
        sleep(2);
        clear_terminal();
    }
    printf("\n================================================================================");
    printf("\n=========================CRAZY          WIN=====================================");
    printf("\n================================================================================");
    printf("\nBienvenido al simulador de ruleta\n");
    sleep (1);
    printf("Aquí podrás elegir la forma en la que gastas los ahorros para \nla universidad de tu hijo\n");
    sleep(1);
    
    tomar_decision(jugada);
    
    if (fin) {
        return 0;
    }
    procesar_resultado(jugada);
    
} while (fondos < 10000000);
    clear_terminal();
    printf("Vale ya soplapollas que me vas a romper el aparato");
}
int bola (void) {   
        crea_circulo (400,400,280, color);
        crea_ventana("resultado",800,800);
        sprintf(numero2, "%d", numero);
        crea_texto (300,300,numero2,"amarillo",200);
        pinta();
        sleep (1);
        destruye_ventana();
        return 0;
}

void tomar_decision (apuesta_t jugada[APUESTAS_SIZE]) {
    
    for (int i = 0; i < APUESTAS_SIZE; i++) {
        if (fondos == 0) {
            jugada[i].decision = 0;
            break;
        }
        mostrar_opciones(admin);
        printf ("Apuesta %d:", i);
        jugada[i].decision = get_user_int();

        if (jugada[i].decision == 12) {
            clear_terminal();
            printf("Parece que por fin quieres retirar lo que te queda\n");
            sleep(2);
            printf("Las comisiones de retirar dinero son %d euros \n", comision);
            sleep(2);
            printf("Vaya, vaya\n");
            sleep(2);
            printf("Solo tienes %.2f euros\n", fondos);
            sleep(2);
            printf("AL final no has ganado nada\n");
            sleep(2);
            printf("Que hemos aprendido hoy?\n");
            sleep(2);
            printf("La casa siempre gana niño\n");
            sleep(2);
            printf("Para mas programas puedes comprar la subscripcion a Codigos Lamsallak por 12.99 euros/mes \n");
            sleep(2);
            printf("Aunque viendo como has manejado el dinero dudo que puedas :(");
            fin = true;
            break;
        }
        if (jugada[i].decision == 4) {
            printf("Elije el numero al que apostar\n");
            jugada[i].casilla = get_user_int();
        }
        
        
        if (jugada[i].decision == 0) {
            jugada[i].dinero = 0;
        }
        else if (jugada[i].decision == 10) {
            printf("Estas a punto de hacer historia o de morir en el intento\n");
            printf("Elije el numero al que apostar\n");
            jugada[i].casilla = get_user_int();
            jugada[i].dinero = fondos;
        }
        else if (jugada[i].decision == 11) {
            clear_terminal();
            printf("Fondos Universidad hijos:%.2f", universidad_hijos);
            printf("\nCuanto quieres retirar:");
            tajada = get_user_float();
            universidad_hijos = universidad_hijos - tajada;
            if (universidad_hijos < 0) {
                printf("El banco ha detectado actividad fraudulenta en los fondos universitarios de tus hijos\n");
                printf("Te han cerrado la cuenta y ya no puedes apostar\n");
                fin = true;
                break;
            }
            fondos = fondos + tajada; 
            printf("Hijo de puta\n");
            sleep(3);
            clear_terminal();
            i = -1;
        }
        else
        {
            do {
            printf("Elije la cantidad a apostar\n");
            jugada[i].dinero = get_user_float();
            if (jugada[i].dinero > fondos) {
                printf("Hold your horses no tienes dinero\n");
            }
            if (jugada[i].dinero < 0) {
                printf("Puto notas apuesta bien\n");
            }
            } while ((jugada[i].dinero > fondos) || (jugada[i].dinero < 0));
       
         } 
    fondos = fondos - jugada[i].dinero;
    clear_terminal();
    }
}

void procesar_resultado (apuesta_t jugada[APUESTAS_SIZE]) {
    clear_terminal();
    bola();
    for (int i = 0; i < APUESTAS_SIZE; i++) {
        printf ("APUESTA %d:\n", i);
        switch (jugada[i].decision) {
            default:
            printf ("No hay apuesta registrada\n");
            break;
            case 1:
                if (rojo) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 2 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }

            break;
            case 2:
                if (negro) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 2 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }

            break;
            case 3:
                if (verde) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 4 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }

            break;
            case 4:
                if (jugada[i].casilla == numero) {
                    printf ("No te lo crees ni tu\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 10 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }
            break;
            case 5:
                if (numero < 13 && numero > 0) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 2.5 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }
            break;
            case 6:
                if (12 < numero && numero < 25) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 2.5 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }
            break;
            case 7:
                if (numero > 25) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 2.5 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }
            break;
            case 8:
                if (numero % 2 == 0) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 2 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }
            break;
            case 9:
                if (numero % 2 != 0) {
                    printf ("guay\n");
                    sleep(2);
                    printf ("\n\nTodavia puedes ganar mas dinero ;) juega otra mas\n");  
                    fondos = fondos + jugada[i].dinero * 2 + jugada[i].dinero;
                }else{
                    printf("cagaste\n");
                    sleep(2);
                    printf ("\n\nTienes que recuperar el dinero perdido si no tu hijo hara FP de carpinteria con gitanos\n");  
                }
            break;
            case 10:
                if (jugada[i].casilla == numero) {
                    printf ("X 100 X 100 hijueputa X 100\n");
                    sleep(2);
                    printf ("\n\nX 100 X 100 la baby se me puso gangtel\n");  
                    fondos = fondos + jugada[i].dinero * 100 + jugada[i].dinero;
                }else{
                    printf("Solo arturo puede hacer estas cosas\n");
                    sleep(2);
                    printf ("\n\nAhora a cagar\n");  
                }
            break;
        }
    sleep(3);
    clear_terminal();
    }
}

void mostrar_opciones(bool admin){
    printf ("Porfavor selecciona una opcion                                FONDOS:%.2f\n", fondos);
    printf ("  0.Omitir apuesta\n");
    printf ("  1.Rojo          (apuesta * 2)\n");
    printf ("  2.Negro         (apuesta * 2)\n");
    printf ("  3.Verde         (apuesta * 4\n");
    printf ("  4.Elegir número (apuesta * 4)\n");
    printf ("  5.Primer tercio (apuesta * 2.5)\n");
    printf ("  6.Segundo tercio(apuesta * 2.5)\n");
    printf ("  7.Tercer tercio (apuesta * 2.5)\n");
    printf ("  8.Par           (apuesta * 2)\n");
    printf ("  9.Impar         (apuesta * 2)\n");
    printf ("  10.MODO X 100   (all in obligado)\n");
    printf ("  11.Acceder a los fondos universitarios detus hijos\n");
    printf ("  12.Retirar dinero\n");
    
    if (admin){
        printf("%d,%s\n", numero, color);
    }
}
