#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento(void){
    printf("\n[Compra con Descuento]\n");
    Carrito c;
    carrito_init(&c);

    Producto prodUno = {"Pan", 200, 3};
    Producto prodDos = {"Leche", 350, 2};

    carrito_agregar(&c, prodUno);
    carrito_agregar(&c, prodDos);

    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);

    int total_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1170, total_descuento);

}


/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar(){
    printf("\n[Agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);

    Producto p = {"Chocolinas", 100, 1};

    for(int i = 0; i < 4; i++){
        carrito_agregar(&c, p);
    }

    //Conteo es MAX_ITEMS 
    ASSERT_IGUAL(4, carrito_contar(&c));

    //Verificar que intentar agregar otro producto devuelve error
    ASSERT_IGUAL(0, carrito_agregar(&c, p));

    //Corroborar que el conteo sigue siento igual que MAX_ITEMS 
    ASSERT_IGUAL(4, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
