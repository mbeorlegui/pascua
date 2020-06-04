#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define marzo 03
#define abril 04

void calculos(void);
void impresion_final(void);
void consulta_seguir(void);
unsigned int out_mmdd(unsigned int, unsigned int);

unsigned int anio, a,b,c,d,e,dia, seguir=1, mes, MMDD;

main(){
    while(seguir==1){

    system("cls");
    printf ("\n\n\n --> Pascua 2.0 <--\n");

    printf ("\n\n Inserte el Anio: ");
    scanf("%d", &anio);

    calculos();
    impresion_final();
    consulta_seguir();
    }
}

void calculos(void){
    a = anio % 19;
    b = anio % 4;
    c = anio % 7;
    d = (19*a+24) % 30;
    e = (2*b+4*c+6*d+5) % 7;

    dia = 22+d+e;
}

void impresion_final(void){

    printf("\n\n\tLa Fecha del Domingo de Pascua de %d es ",anio);

    if (dia<=31){                               //Ó  (d + e) < 10
        mes=marzo;
        printf("%d de Marzo ",dia);
        out_mmdd(mes, dia);
    }else{
        mes=abril;
        if (dia==26) dia=19;
        if (dia==25 && d==28 && e==6 && a>10) dia=18;
        printf("%d de Abril ",dia-31);          //dia-31= (d + e - 9)
        out_mmdd(mes, dia-31);
    }
}

void consulta_seguir(void){
    printf("\n\n\tDesea seguir? 1=seguir, 0=cerrar ");
    scanf("%d", &seguir);
}

unsigned int out_mmdd(unsigned int mes,unsigned int dia){
    MMDD=(mes*100)+dia;

    printf("\n\n0%d",MMDD);

    return MMDD;
}


