// importo el archivo linkedlist.h
#include "linkedlist.h"
// Libreria estandar de C
#include <stdlib.h>

#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: debes completar las funciones que estan a continuacion
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Crea una lista inicialmente vacia y retorna el puntero */
LinkedList* linkedlist_init()
{
  LinkedList* list = malloc(sizeof(LinkedList*));
  list->cabeza = NULL;
  return list;
}


/** Inserta un elemento al final de la lista */
void linkedlist_append(LinkedList* list, int element)
{
  if (list->cabeza == NULL) {
    list->cabeza = malloc(sizeof(Nodo));
    list->cabeza->valor = element;
    list->cabeza->siguiente = NULL;
  }
  else {
    Nodo * actual = list->cabeza;
    while (actual->siguiente != NULL) {
      actual = actual->siguiente;
    }
    actual->siguiente = malloc(sizeof(Nodo));
    actual->siguiente->valor = element;
    actual->siguiente->siguiente = NULL;
  }
}

/** Inserta el elemento dado en la posicion indicada */
void linkedlist_insert(LinkedList* list, int element, int position)
{
  int contador = 0;
  Nodo * actual = list->cabeza;
  while (position != contador) {
    actual = actual->siguiente;
    ++contador;
  }
  Nodo * nuevo = malloc(sizeof(Nodo));
  nuevo->valor = actual->valor;
  nuevo->siguiente = actual->siguiente;
  actual->valor = element;
  actual->siguiente = nuevo;
}

/** Elimina el elemento de la posicion indicada y lo retorna */
int linkedlist_delete(LinkedList* list, int position)
{
  Nodo * antiguo;
  int valor;
  if (position==0) {
    antiguo = list->cabeza;
    list->cabeza = antiguo->siguiente;
  }
  else {
    int contador = 0;
    Nodo * actual = list->cabeza;
    while (position-1 != contador) {
      actual = actual->siguiente;
      ++contador;
    }
    antiguo = actual->siguiente;
    actual->siguiente = antiguo->siguiente;
  }
  valor = antiguo->valor;
  free(antiguo);
  return valor;

}

/** Retorna el valor del elemento en la posicion dada */
int linkedlist_get(LinkedList* list, int position)
{
  int contador = 0;
  Nodo * actual = list->cabeza;
  while (position != contador) {
    actual = actual->siguiente;
    ++contador;
  }
  return actual->valor;

}

/** Concatena a la lista una segunda lista */
void linkedlist_concatenate(LinkedList* list, LinkedList* list2)
{
  Nodo * actual = list->cabeza;
  while (actual->siguiente != NULL) {
    actual = actual->siguiente;
  }
  actual->siguiente = list2->cabeza;
  free(list2);
}

/** Libera recursos de un nodo */
void nodo_destroy(Nodo* nodo)
{
  if (nodo->siguiente == NULL) {
    free(nodo);
  }
  else {
    nodo_destroy(nodo->siguiente);
    free(nodo);
  }
}

/** Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list)
{
  nodo_destroy(list->cabeza);
  free(list);
}
