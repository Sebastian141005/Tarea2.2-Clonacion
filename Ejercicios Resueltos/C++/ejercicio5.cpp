#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct NodoWeb {
    string modulo;
    NodoWeb* izquierdo;
    NodoWeb* derecho;
};

NodoWeb* crearNodo(string nombre) {
    NodoWeb* nuevo = new NodoWeb();
    nuevo->modulo = nombre;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

void mostrarMenuPrincipal(NodoWeb* raiz, string sangria = "") {
    if (raiz == NULL) return;
    cout << sangria << "- " << raiz->modulo << endl;
    mostrarMenuPrincipal(raiz->izquierdo, sangria + "   ");
    mostrarMenuPrincipal(raiz->derecho, sangria + "   ");
}

void procesarModulosInternos(NodoWeb* raiz) {
    if (raiz == NULL) return;
    procesarModulosInternos(raiz->izquierdo);
    procesarModulosInternos(raiz->derecho);
    cout << "Cargando dependencias de: [" << raiz->modulo << "]" << endl;
}

void mostrarNivelPorNivel(NodoWeb* raiz) {
    if (raiz == NULL) return;
    queue<NodoWeb*> cola;
    cola.push(raiz);
    int nivel = 0;
    while (!cola.empty()) {
        int nodosEnNivel = cola.size();
        cout << "Profundidad " << nivel << ": ";
        for (int i = 0; i < nodosEnNivel; i++) {
            NodoWeb* actual = cola.front();
            cola.pop();
            cout << actual->modulo << " | ";
            if (actual->izquierdo != NULL) cola.push(actual->izquierdo);
            if (actual->derecho != NULL) cola.push(actual->derecho);
        }
        cout << endl;
        nivel++;
    }
}

int main() {
    NodoWeb* raiz = crearNodo("Sistema Web");
    raiz->izquierdo = crearNodo("Usuarios");
    raiz->derecho = crearNodo("Inventario");
    raiz->izquierdo->izquierdo = crearNodo("Registrar");
    raiz->izquierdo->derecho = crearNodo("Buscar");
    raiz->derecho->izquierdo = crearNodo("Productos");
    raiz->derecho->derecho = crearNodo("Reportes");

    int opcion;

    do {
        cout << "\n=== MENU INTERACTIVO: SISTEMA WEB ===" << endl;
        cout << "1. Mostrar Menu Principal (Preorden)" << endl;
        cout << "2. Procesar Modulos Internos (Postorden)" << endl;
        cout << "3. Mostrar Mapa del Sitio (BFS)" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        cout << "\n-----------------------------------" << endl;
        switch(opcion) {
            case 1:
                cout << "=== MENU PRINCIPAL ===" << endl;
                mostrarMenuPrincipal(raiz);
                break;
            case 2:
                cout << "=== PROCESANDO MODULOS ===" << endl;
                procesarModulosInternos(raiz);
                break;
            case 3:
                cout << "=== MAPA DEL SITIO ===" << endl;
                mostrarNivelPorNivel(raiz);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
        cout << "-----------------------------------" << endl;
        
    } while(opcion != 4);

    return 0;
}