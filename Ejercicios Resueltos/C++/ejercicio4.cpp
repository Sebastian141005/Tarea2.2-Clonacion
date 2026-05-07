#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) return crearNodo(valor);
    if (valor < raiz->dato) raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else if (valor > raiz->dato) raiz->derecho = insertar(raiz->derecho, valor);
    return raiz;
}

void imprimir(Nodo* raiz, string prefijo, bool esUltimo) {
    if (raiz == NULL) return;
    cout << prefijo << (esUltimo ? "\\--> " : "|--> ") << raiz->dato << endl;
    string nuevoPrefijo = prefijo + (esUltimo ? "     " : "|    ");
    bool izquierdoEsUltimo = (raiz->derecho == NULL);
    imprimir(raiz->izquierdo, nuevoPrefijo, izquierdoEsUltimo);
    imprimir(raiz->derecho, nuevoPrefijo, true);
}

int contarHojas(Nodo* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izquierdo == NULL && raiz->derecho == NULL) return 1;
    return contarHojas(raiz->izquierdo) + contarHojas(raiz->derecho);
}

int main() {
    Nodo* raiz = NULL;
    raiz = insertar(raiz, 10);
    insertar(raiz, 5); insertar(raiz, 15);
    insertar(raiz, 2); insertar(raiz, 7);
    insertar(raiz, 12); insertar(raiz, 20);
    insertar(raiz, 1); insertar(raiz, 3);
    insertar(raiz, 18); insertar(raiz, 25);

    cout << "--- EJERCICIO 4 ---" << endl;
    cout << "Arbol Estructurado:" << endl;
    if (raiz != NULL) {
        cout << raiz->dato << endl;
        imprimir(raiz->izquierdo, "", raiz->derecho == NULL);
        imprimir(raiz->derecho, "", true);
    }
    
    cout << "\n-----------------------" << endl;
    cout << "La cantidad total de hojas (nodos finales) es: " << contarHojas(raiz) << endl;

    return 0;
}