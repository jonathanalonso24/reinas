#include <stdio.h>
#include <stdbool.h>

// Funci�n para verificar si dos reinas se atacan mutuamente
bool seAtacan(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2 || (x1 - y1) == (x2 - y2) || (x1 + y1) == (x2 + y2);
}

// Funci�n para contar los caminos v�lidos
int contarCaminos(int n) {
    int caminos = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < n; y1++) {
            for (int x2 = 0; x2 < n; x2++) {
                for (int y2 = 0; y2 < n; y2++) {
                    if ((x1 != x2 || y1 != y2) && !seAtacan(x1, y1, x2, y2)) {
                        caminos++;
                    }
                }
            }
        }
    }
    return caminos / 2;  // Dividimos por 2 porque cada camino se cuenta dos veces
}

int main() {
    int n;
    printf("Ingrese el tama�o del tablero (n < 10): ");
    scanf("%d", &n);
    if (n >= 10) {
        printf("El tama�o del tablero debe ser menor que 10.\n");
        return 1;
    }
    int caminos = contarCaminos(n);
    printf("El n�mero de diferentes caminos donde las dos reinas no se atacan en un tablero de %dx%d es: %d\n", n, n, caminos);
    return 0;
}
