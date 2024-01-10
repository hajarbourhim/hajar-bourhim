#include <stdio.h>

// Fonction pour afficher le plateau de jeu
void afficherPlateau(char plateau[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", plateau[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Fonction pour vérifier si un joueur a gagné
int verifierGagnant(char plateau[3][3], char symbole) {
    // Vérification des lignes et colonnes
    for (int i = 0; i < 3; i++) {
        if (plateau[i][0] == symbole && plateau[i][1] == symbole && plateau[i][2] == symbole)
            return 1;  // Victoire sur une ligne
        if (plateau[0][i] == symbole && plateau[1][i] == symbole && plateau[2][i] == symbole)
            return 1;  // Victoire sur une colonne
    }

    // Vérification des diagonales
    if (plateau[0][0] == symbole && plateau[1][1] == symbole && plateau[2][2] == symbole)
        return 1;  // Victoire sur la diagonale principale
    if (plateau[0][2] == symbole && plateau[1][1] == symbole && plateau[2][0] == symbole)
        return 1;  // Victoire sur la diagonale inverse

    return 0;  // Aucune victoire
}

// Fonction principale pour jouer au morpion
int main() {
    char plateau[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char joueur = 'X';
    int ligne, colonne;

    printf("Bienvenue dans le jeu du morpion!\n");

    for (int tour = 1; tour <= 9; tour++) {
        afficherPlateau(plateau);

        // Demander au joueur actuel de choisir une case
        printf("Joueur %c, entrez la ligne (1-3) et la colonne (1-3) séparées par un espace : ", joueur);
        scanf("%d %d", &ligne, &colonne);

        // Vérifier si la case est valide
        if (ligne < 1 || ligne > 3 || colonne < 1 || colonne > 3 || plateau[ligne - 1][colonne - 1] != ' ') {
            printf("Case invalide. Veuillez réessayer.\n");
            tour--;  // Ne pas compter ce tour comme valide
            continue;
        }

        // Mettre le symbole du joueur sur la case choisie
        plateau[ligne - 1][colonne - 1] = joueur;

        // Vérifier s'il y a un gagnant
        if (verifierGagnant(plateau, joueur)) {
            afficherPlateau(plateau);
            printf("Le joueur %c a gagné!\n", joueur);
            return 0;
        }

        // Changer de joueur pour le tour suivant
        joueur = (joueur == 'X') ? 'O' : 'X';
    }

    // Si aucun joueur n'a gagné après 9 tours, c'est un match nul
    afficherPlateau(plateau);
    printf("Match nul!\n");

    return 0;
}
