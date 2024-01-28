#include <stdio.h>
#include <stdlib.h>

// Fonction pour vérifier si le déplacement du Roi est valide
int estDeplacementRoiValide(int departX, int departY, int arriveeX, int arriveeY) {
    // Vérifier si le déplacement est d'une case autour du Roi
    if (abs(arriveeX - departX) <= 1 && abs(arriveeY - departY) <= 1) {
        // Déplacement d'au plus une case en horizontal ou vertical
        return 1;
    }

    // Si aucune condition n'est satisfaite, le déplacement n'est pas valide
    return 0;
}

int main() {
    // Exemple d'utilisation de la fonction estDeplacementRoiValide
    int departX = 4;
    int departY = 4;
    int arriveeX = 5;
    int arriveeY = 5;

    if (estDeplacementRoiValide(departX, departY, arriveeX, arriveeY)) {
        printf("Le deplacement du Roi est valide.\n");
    } else {
        printf("Le deplacement du Roi n'est pas valide.\n");
    }

    return 0;
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
