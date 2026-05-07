#include <iostream>
#include <queue>

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

void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierdo);
    preorden(raiz->derecho);
}

void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izquierdo);
    cout << raiz->dato << " ";
    inorden(raiz->derecho);
}

void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izquierdo);
    postorden(raiz->derecho);
    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {
    if (raiz == NULL) return;
    queue<Nodo*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";
        if (actual->izquierdo != NULL) cola.push(actual->izquierdo);
        if (actual->derecho != NULL) cola.push(actual->derecho);
    }
}

int main() {
    Nodo* raiz = NULL;
    // Nodos del ejercicio 1
    raiz = insertar(raiz, 10);
    insertar(raiz, 5); insertar(raiz, 15);
    insertar(raiz, 2); insertar(raiz, 7);
    insertar(raiz, 12); insertar(raiz, 20);
    
    // Nodos nuevos del ejercicio 2
    insertar(raiz, 1); insertar(raiz, 3);
    insertar(raiz, 18); insertar(raiz, 25);

    cout << "--- EJERCICIO 2 (Modificado) ---" << endl;
    cout << "Preorden: "; preorden(raiz); cout << endl;
    cout << "Inorden: "; inorden(raiz); cout << endl;
    cout << "Postorden: "; postorden(raiz); cout << endl;
    cout << "BFS: "; bfs(raiz); cout << endl;

    return 0;
}