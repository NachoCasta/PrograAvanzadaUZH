// Importo el archivo arraylist.h
#include "arraylist.h"
// Libreria estandar de C
#include <stdlib.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: Debes completar las siguientes funciones
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Crea una arraylist inicialmente vacia y retorna su puntero */
ArrayList* arraylist_init()
{
  ArrayList* list = malloc(sizeof(ArrayList*));
  list->size = 1;
  list->arreglo = calloc(1, sizeof(int*));
  list->elementos = 0;

  return list;
}

/** Duplica el tamaño de la lista */
void arraylist_expand(ArrayList* list)
{
  list->arreglo = realloc(list->arreglo, list->size*2*sizeof(int*));
  list->size = list->size*2;
}

/** Inserta un elemento al final de la arraylist */
void arraylist_append(ArrayList* list, int element)
{
  if (list->elementos >= list->size){
    arraylist_expand(list);
  }
  list->arreglo[list->elementos] = element;
  ++list->elementos;
}

/** Inserta el elemento dado en la posicion indicada */
void arraylist_insert(ArrayList* list, int element, int position)
{
  if (list->elementos >= list->size){
    arraylist_expand(list);
  }
  int i;
  for (i=list->elementos; i>position; --i) {
    list->arreglo[i] = list->arreglo[i-1];
  }
  list->arreglo[position] = element;
  ++list->elementos;

}

/** Elimina el elemento de la posicion indicada y lo retorna */
int arraylist_delete(ArrayList* list, int position)
{
  int elemento = list->arreglo[position];
  int i;
  for (i=position; i<list->elementos-1; ++i) {
    list->arreglo[i] = list->arreglo[i+1];
  }
  --list->elementos;
  return elemento;
}

/** Retorna el valor del elemento en la posicion dada */
int arraylist_get(ArrayList* list, int position)
{
  return list->arreglo[position];
}

/** Concatena la segunda arraylist a la primera arraylist */
void arraylist_concatenate(ArrayList* list1, ArrayList* list2)
{
  int nuevos_elementos = list1->elementos + list2->elementos;
  while (nuevos_elementos > list1->size) {
    arraylist_expand(list1);
  }
  int i;
  printf("%d es la cantidad de elementos\n", list1->elementos);
  for (i=0; i<list2->elementos; ++i) {
    list1->arreglo[list1->elementos+i] = list2->arreglo[i];
  }
  list1->elementos = nuevos_elementos;
  arraylist_destroy(list2);
}

/** Libera todos los recursos asociados a la lista */
void arraylist_destroy(ArrayList* list)
{
  free(list->arreglo);
  free(list);
}
