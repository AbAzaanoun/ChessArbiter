#include <stdio.h>
#include <stdlib.h>

// Fonction pour vérifier si le déplacement du Cavalier est valide
int estDeplacementCavalierValide(int departX, int departY, int arriveeX, int arriveeY) {
    // Vérifier si le déplacement suit le motif en L du Cavalier
    int deltaX = abs(departX - arriveeX);
    int deltaY = abs(departY - arriveeY);

    if ((deltaX == 1 && deltaY == 2) || (deltaX == 2 && deltaY == 1)) {
        // Déplacement en forme de L, donc le déplacement du Cavalier est valide
        return 1;
    }

    // Si aucune condition n'est satisfaite, le déplacement n'est pas valide
    return 0;
}

int main() {
    // Exemple d'utilisation de la fonction estDeplacementCavalierValide
    int departX = 2;
    int departY = 3;
    int arriveeX = 4;
    int arriveeY = 4;

    if (estDeplacementCavalierValide(departX, departY, arriveeX, arriveeY)) {
        printf("Le deplacement du Cavalier est valide.\n");
    } else {
        printf("Le deplacement du Cavalier n'est pas valide.\n");
    }

    return 0;
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
