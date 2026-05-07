class Nodo {
    int dato;
    Nodo izquierdo, derecho;
    public Nodo(int dato) {
        this.dato = dato;
        this.izquierdo = null;
        this.derecho = null;
    }
}

public class ejercicio3 {
    
    public static Nodo insertar(Nodo raiz, int valor) {
        if (raiz == null) return new Nodo(valor);
        if (valor < raiz.dato) raiz.izquierdo = insertar(raiz.izquierdo, valor);
        else if (valor > raiz.dato) raiz.derecho = insertar(raiz.derecho, valor);
        return raiz;
    }


    public static void imprimirConFlechas(Nodo raiz, String prefijo, boolean esUltimo) {
        if (raiz == null) return;

       
        System.out.println(prefijo + (esUltimo ? "\\--> " : "|--> ") + raiz.dato);


        String nuevoPrefijo = prefijo + (esUltimo ? "     " : "|    ");


        boolean izquierdoEsUltimo = (raiz.derecho == null);
        
        imprimirConFlechas(raiz.izquierdo, nuevoPrefijo, izquierdoEsUltimo);
        imprimirConFlechas(raiz.derecho, nuevoPrefijo, true); // El derecho siempre cierra la rama
    }

    public static int contarNodos(Nodo raiz) {
        if (raiz == null) return 0;
        return 1 + contarNodos(raiz.izquierdo) + contarNodos(raiz.derecho);
    }

    public static void main(String[] args) {
        Nodo raiz = null;
        

        raiz = insertar(raiz, 10);
        insertar(raiz, 5); insertar(raiz, 15);
        insertar(raiz, 2); insertar(raiz, 7);
        insertar(raiz, 12); insertar(raiz, 20);
        insertar(raiz, 1); insertar(raiz, 3);
        insertar(raiz, 18); insertar(raiz, 25);

        System.out.println("--- EJERCICIO 3 ---");
        System.out.println("Arbol Estructurado:");
        
        if (raiz != null) {
            System.out.println(raiz.dato);
            imprimirConFlechas(raiz.izquierdo, "", raiz.derecho == null);
            imprimirConFlechas(raiz.derecho, "", true);
        }
        
        System.out.println("\n-----------------------");
        System.out.println("La cantidad total de nodos es: " + contarNodos(raiz));
    }
}