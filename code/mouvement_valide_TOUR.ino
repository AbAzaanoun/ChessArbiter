#include <stdio.h>
#include <stdlib.h>

// Fonction pour vérifier si le déplacement de la Tour est valide
int estDeplacementTourValide(int departX, int departY, int arriveeX, int arriveeY) {
    // Vérifier si le déplacement est horizontal, vertical ou les deux
    if ((departX == arriveeX) || (departY == arriveeY)) {
        // Déplacement de la Tour est valide
        return 1;
    }

    // Si aucune condition n'est satisfaite, le déplacement n'est pas valide
    return 0;
}

int main() {
    // Exemple d'utilisation de la fonction estDeplacementTourValide
    int departX = 1;
    int departY = 2;
    int arriveeX = 5;
    int arriveeY = 2;

    if (estDeplacementTourValide(departX, departY, arriveeX, arriveeY)) {
        printf("Le deplacement de la Tour est valide.\n");
    } else {
        printf("Le deplacement de la Tour n'est pas valide.\n");
    }

    return 0;
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
