import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class NodoWeb {
    String modulo;
    NodoWeb izquierdo, derecho;

    public NodoWeb(String modulo) {
        this.modulo = modulo;
        this.izquierdo = null;
        this.derecho = null;
    }
}

public class ejercicio5 {

    public static void mostrarMenuPrincipal(NodoWeb raiz, String sangria) {
        if (raiz == null) return;
        System.out.println(sangria + "- " + raiz.modulo);
        mostrarMenuPrincipal(raiz.izquierdo, sangria + "   ");
        mostrarMenuPrincipal(raiz.derecho, sangria + "   ");
    }

    public static void procesarModulosInternos(NodoWeb raiz) {
        if (raiz == null) return;
        procesarModulosInternos(raiz.izquierdo);
        procesarModulosInternos(raiz.derecho);
        System.out.println("Cargando dependencias de: [" + raiz.modulo + "]");
    }

    public static void mostrarNivelPorNivel(NodoWeb raiz) {
        if (raiz == null) return;
        Queue<NodoWeb> cola = new LinkedList<>();
        cola.add(raiz);
        int nivel = 0;
        while (!cola.isEmpty()) {
            int nodosEnNivel = cola.size();
            System.out.print("Profundidad " + nivel + ": ");
            for (int i = 0; i < nodosEnNivel; i++) {
                NodoWeb actual = cola.poll();
                System.out.print(actual.modulo + " | ");
                if (actual.izquierdo != null) cola.add(actual.izquierdo);
                if (actual.derecho != null) cola.add(actual.derecho);
            }
            System.out.println();
            nivel++;
        }
    }

    public static void main(String[] args) {
        // Construcción manual del árbol del Sistema Web
        NodoWeb raiz = new NodoWeb("Sistema Web");
        raiz.izquierdo = new NodoWeb("Usuarios");
        raiz.derecho = new NodoWeb("Inventario");
        raiz.izquierdo.izquierdo = new NodoWeb("Registrar");
        raiz.izquierdo.derecho = new NodoWeb("Buscar");
        raiz.derecho.izquierdo = new NodoWeb("Productos");
        raiz.derecho.derecho = new NodoWeb("Reportes");

        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("\n=== MENU INTERACTIVO: SISTEMA WEB ===");
            System.out.println("1. Mostrar Menu Principal (Preorden)");
            System.out.println("2. Procesar Modulos Internos (Postorden)");
            System.out.println("3. Mostrar Mapa del Sitio (BFS)");
            System.out.println("4. Salir");
            System.out.print("Ingrese una opcion: ");
            
            opcion = scanner.nextInt();

            System.out.println("\n-----------------------------------");
            switch(opcion) {
                case 1:
                    System.out.println("=== MENU PRINCIPAL ===");
                    mostrarMenuPrincipal(raiz, "");
                    break;
                case 2:
                    System.out.println("=== PROCESANDO MODULOS ===");
                    procesarModulosInternos(raiz);
                    break;
                case 3:
                    System.out.println("=== MAPA DEL SITIO ===");
                    mostrarNivelPorNivel(raiz);
                    break;
                case 4:
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opcion no valida. Intente de nuevo.");
            }
            System.out.println("-----------------------------------");
            
        } while(opcion != 4);

        scanner.close();
    }
}