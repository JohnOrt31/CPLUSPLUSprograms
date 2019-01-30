#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

struct nodo {
    float num;
    struct nodo *sig;
};

typedef struct nodo *Tlista;

//insertar dato
void insertarInicio(Tlista &lista, float x)
{
    Tlista q;
    q = new(struct nodo); //Crea un nuevo nodo
    q->num = x;
    q->sig = lista;
    lista  = q;
}

// Inserta dato al final de la lista (para colas)
void insertarFinal(Tlista &lista, float x)
{
    Tlista t, q = new(struct nodo);
 
    q->num  = x;
    q->sig = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sig!=NULL)
        {
            t = t->sig;
        }
        t->sig = q;
    }
 
}


float sumatoria(Tlista &lista) {
    struct nodo *p;
    float sum = 0;
    p = lista;
    while (p != NULL) {
        sum += p->num;
        p = p->sig;
    }
    return sum;
}

// Realizar sumatoria para desviacion estandar
float sumadesv(struct nodo *lista, float promedio) {
    struct nodo *p;
    float sum = 0;
    p = lista;
    while (p != NULL) {
        sum += pow(p->num - promedio, 2);
        p = p->sig;
    }
    return sum;
}

// borrar lista 
void eliminaLista(Tlista &lista) {
    struct nodo *p,*q;
    p = lista;
    while (p != NULL) {
        q = p->sig; // para no perder el nodo
        free(p);
        p = q;
    }
    return;
}


int main(){
    // Definir e inicializar variables, incluyendo la lista
    int i=0, n;
    float x, prom, desv;
    Tlista lista = NULL;


    // Recibir numero de datos
    cout<<"---Promedio y Desviacion Estandar---\n\nIngrese el numero de datos deseados: "<<endl;
    cin>>n;

    // Recibir datos y llenar lista
    while (i < n) {
        cout<<"\nDato "<< i+1 << ": ";
        cin>>x;
        if (i < n - 1)
            insertarInicio(lista, x);
        else
            insertarFinal(lista, x);
        i++;
    }


    // Calcular promedio
    prom = sumatoria(lista)/(float)n;
    // Calcular Desviación estandar
    desv = sqrt(sumadesv(lista, prom)/(float)(n - 1));
    
    // Mostrar resultados
    cout<<"\nPromedio:" << prom << endl;
    cout <<"\nDesviacion estandar: " << desv <<endl;

    system("pause");

    // Eliminar lista y terminar la ejecucion
    eliminaLista(lista);
    return 0;
}