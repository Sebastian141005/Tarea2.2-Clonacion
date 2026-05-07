import java.util.LinkedList;
import java.util.Queue;

class Nodo {
    int dato;
    Nodo izquierdo, derecho;
    public Nodo(int dato) {
        this.dato = dato;
        this.izquierdo = null;
        this.derecho = null;
    }
}

public class ejercicio2 {
    public static Nodo insertar(Nodo raiz, int valor) {
        if (raiz == null) return new Nodo(valor);
        if (valor < raiz.dato) raiz.izquierdo = insertar(raiz.izquierdo, valor);
        else if (valor > raiz.dato) raiz.derecho = insertar(raiz.derecho, valor);
        return raiz;
    }

    public static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");
        preorden(raiz.izquierdo); preorden(raiz.derecho);
    }

    public static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierdo);
        System.out.print(raiz.dato + " ");
        inorden(raiz.derecho);
    }

    public static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierdo); postorden(raiz.derecho);
        System.out.print(raiz.dato + " ");
    }

    public static void bfs(Nodo raiz) {
        if (raiz == null) return;
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);
        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            System.out.print(actual.dato + " ");
            if (actual.izquierdo != null) cola.add(actual.izquierdo);
            if (actual.derecho != null) cola.add(actual.derecho);
        }
    }

    public static void main(String[] args) {
        Nodo raiz = null;
        raiz = insertar(raiz, 10);
        insertar(raiz, 5); insertar(raiz, 15);
        insertar(raiz, 2); insertar(raiz, 7);
        insertar(raiz, 12); insertar(raiz, 20);
        
        insertar(raiz, 1); insertar(raiz, 3);
        insertar(raiz, 18); insertar(raiz, 25);

        System.out.println("--- EJERCICIO 2 (Modificado) ---");
        System.out.print("Preorden: "); preorden(raiz); System.out.println();
        System.out.print("Inorden: "); inorden(raiz); System.out.println();
        System.out.print("Postorden: "); postorden(raiz); System.out.println();
        System.out.print("BFS: "); bfs(raiz); System.out.println();
    }
}