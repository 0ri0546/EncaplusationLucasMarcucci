# Escape the Dungeon
# Description du Projet
Escape the Dungeon est un jeu d'aventure en 2D où le joueur incarne un personnage tentant de s'échapper d'un donjon. Le joueur doit éviter les ennemis, collecter des objets, résoudre des énigmes et atteindre la porte de sortie dans un temps imparti. Ce projet a été réalisé dans le cadre d'un exercice pédagogique pour apprendre les concepts avancés de la programmation orientée objet, la gestion graphique avec SFML, et les mécanismes de jeu.


# Fonctionnalités
Personnage principal : contrôlé avec les touches directionnelles.

# Ennemis polymorphiques :
ChaserEnemy : poursuit le joueur.
PatrollingEnemy : suit un trajet prédéfini.

# Objets interactifs :
Potion : augmente la vitesse du joueur.
Clé : nécessaire pour ouvrir la porte de sortie.

# Carte et environnement :
Mur : bloque les mouvements du joueur.
Porte : nécessite une clé pour être ouverte.
Téléporteurs : renvoient le joueur à sa position initiale.

# Conditions de victoire et défaite :
Victoire : atteindre la porte après avoir collecté la clé.
Défaite : collision avec un ennemi ou dépassement du temps limite.

# Effets visuels :
Animations pour les ennemis et le joueur.
Sauvegarde d'une image de victoire en cas de succès.

# Spécifications Techniques
Langage : C++.
Bibliothèque utilisée : SFML (Simple and Fast Multimedia Library).
Résolution de la fenêtre : 1920x1080.
Titre de la fenêtre : Escape the Dungeon.

# Commandes du Jeu
Déplacement : Flèches directionnelles (←, ↑, →, ↓).
Objectif : Collecter une clé et atteindre la porte avant la fin du temps imparti.
Victoire : Un fichier image est généré pour immortaliser votre succès.

# Développement
Ce projet a été conçu pour mettre en pratique les concepts suivants :

# Héritage et polymorphisme.
Utilisation d'interfaces pour définir des comportements génériques.
Gestion des collisions et interactions.
Manipulation avancée de la mémoire avec des pointeurs polymorphiques.
Gestion d'une fenêtre graphique avec SFML.
Fonctionnalités Étendues
Ajout de téléporteurs qui renvoient le joueur à sa position initiale.
Génération automatique d'une image en cas de victoire.

# Crédits
Projet réalisé dans le cadre du programme Active Learning by Gaming Campus.
