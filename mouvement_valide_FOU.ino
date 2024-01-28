#include <stdio.h>
#include <stdlib.h>

// Fonction pour vérifier si le déplacement du Fou est valide
int estDeplacementFouValide(int departX, int departY, int arriveeX, int arriveeY) {
    // Vérifier si le déplacement suit une diagonale
    int deltaX = abs(departX - arriveeX);
    int deltaY = abs(departY - arriveeY);

    if (deltaX == deltaY) {
        // Déplacement en diagonale, donc le déplacement du Fou est valide
        return 1;
    }

    // Si aucune condition n'est satisfaite, le déplacement n'est pas valide
    return 0;
}

int main() {
    // Exemple d'utilisation de la fonction estDeplacementFouValide
    int departX = 2;
    int departY = 3;
    int arriveeX = 5;
    int arriveeY = 6;

    if (estDeplacementFouValide(departX, departY, arriveeX, arriveeY)) {
        printf("Le deplacement du Fou est valide.\n");
    } else {
        printf("Le deplacement du Fou n'est pas valide.\n");
    }

    return 0;
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
