// Libreria de input y output (para leer y escribir archivos o leer y escribir en consola)
#include <stdio.h>

#include <string.h>

// Importo los archivos .h de las listas
#include "arraylist/arraylist.h"
#include "linkedlist/linkedlist.h"

// Recibe como input los parametros del programa en un arreglo de strings y un numero que indica cuantos argumentos son
int main(int argc, char *argv[])
{
  if (argc==1) {

  }
  else if (argc==2) {
    if (!strcmp(argv[1], "arraylist")) {
      ArrayList* lista = arraylist_init();
      printf("Agregar cosas\n");
      arraylist_append(lista, 3);
      arraylist_append(lista, 6);
      arraylist_append(lista, 5);
      arraylist_append(lista, 7);
      arraylist_append(lista, 8);
      arraylist_append(lista, 25);
      arraylist_append(lista, 1000);
      arraylist_append(lista, 300);
      int i;
      for (i=0; i<lista->elementos; ++i){
        printf("%d\n", lista->arreglo[i]);
      }
      printf("\nGET 3\n");
      printf("%d\n", arraylist_get(lista, 3));
      printf("\n");
      printf("\nELIMINAR 3\n");
      int eliminado = arraylist_delete(lista, 3);
      for (i=0; i<lista->elementos; ++i){
        printf("%d\n", lista->arreglo[i]);
      }
      printf("\n");
      printf("%d", eliminado);
      printf("\nINSERTAR 120 en 4\n");
      arraylist_insert(lista, 120, 4);
      for (i=0; i<lista->elementos; ++i){
        printf("%d\n", lista->arreglo[i]);
      }

      printf("\nCrear nueva lista\n");
      ArrayList* lista2 = arraylist_init();
      arraylist_append(lista2, 101);
      arraylist_append(lista2, 102);
      arraylist_append(lista2, 103);
      arraylist_append(lista2, 104);
      for (i=0; i<lista2->elementos; ++i){
        printf("%d\n", lista2->arreglo[i]);
      }

      printf("\nConcatenar\n");
      arraylist_concatenate(lista, lista2);
      for (i=0; i<lista->elementos; ++i){
        printf("%d\n", lista->arreglo[i]);
      }

      arraylist_destroy(lista);
    }
    else if (!strcmp(argv[1], "linkedlist")) {
      printf("Listas ligadas\n");
      LinkedList* lista = linkedlist_init();
      linkedlist_append(lista, 5);
      linkedlist_append(lista, 6);
      linkedlist_append(lista, 7);
      linkedlist_append(lista, 8);
      linkedlist_append(lista, 9);
      linkedlist_append(lista, 10);
      printf("%d\n", lista->cabeza->valor);
      printf("%d\n", lista->cabeza->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->valor);
      printf("Insertar 111 en 3\n");
      linkedlist_insert(lista, 111, 3);
      printf("%d\n", lista->cabeza->valor);
      printf("%d\n", lista->cabeza->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->siguiente->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->siguiente->siguiente->siguiente->valor);
      printf("Borrar 3\n");
      linkedlist_delete(lista, 3);
      printf("%d\n", lista->cabeza->valor);
      printf("%d\n", lista->cabeza->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->siguiente->siguiente->valor);
      printf("%d\n", lista->cabeza->siguiente->siguiente->siguiente->siguiente->siguiente->valor);
      printf("Obtener 3\n");
      printf("%d\n", linkedlist_get(lista, 3));
      printf("Nueva lista2\n");
      LinkedList* lista2 = linkedlist_init();
      linkedlist_append(lista2, 55);
      linkedlist_append(lista2, 66);
      linkedlist_append(lista2, 77);
      linkedlist_append(lista2, 88);
      linkedlist_append(lista2, 99);
      linkedlist_append(lista2, 1010);
      int i;
      for (i=0; i<6; ++i) {
        printf("%d\n", linkedlist_get(lista2, i));
      }
      printf("\nConcatenar\n");
      linkedlist_concatenate(lista, lista2);
      for (i=0; i<12; ++i) {
        printf("%d\n", linkedlist_get(lista, i));
      }
      linkedlist_destroy(lista);

    }
    else if (!strcmp(argv[1], "testa")) {
      ArrayList* lista = arraylist_init();
      int i;
      for (i=0; i<10000; ++i) {
        arraylist_append(lista, 1);
      }
      for (i=0; i<5000; ++i) {
        arraylist_delete(lista, 400);
      }
    }
    else if (!strcmp(argv[1], "testl")) {
      LinkedList* lista = linkedlist_init();
      int i;
      for (i=0; i<10000; ++i) {
        linkedlist_delete(lista, 1);
      }
      for (i=0; i<5000; ++i) {
        linkedlist_delete(lista, 400);
      }
    }
  }


  // Retorna 0 cuando la ejecucion del programa es correcta
  return 0;
}
