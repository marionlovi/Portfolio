La société RC-Technic spécialisée dans l'installation de matériel électrique vous a demandé de mettre en place un site sur lequel les employés pourront consulter et mettre à jour des fiches de "matériel", c'est à dire connaître le stock et le mettre à jour lorsqu'ils utilisent ces matériels sur leurs chantiers.

La société désire que tous les employés connectés puissents modifier la quantié en stock dans les "fiches de matériel".

La société désire que seuls des gestionnaires ou des administrateurs puissent créer et mettre à jour les "fiches de matériel" et les "marques".

La société désire que seuls des administrateurs puissent créer des profils utilisateurs : on ne pourra pas s'inscrire sur le site, les profils devront être créés par un administrateur. Les administrateurs pourront mettre à jours les profils utilisateurs.

L'équipe "Front" a déjà développé les templates en HTML.

Les pages correspondant aux mises à jour des "fiches de matériel" ou des "profils utilisateur" ne sont pas fournies, mais doivent ressembler aux pages de création respectives.

# Le Minimal Viable Product
**Echéance** : Vendredi 30 mars 2024 23:59

**Personne à joindre** : M. Bonenfant (Gilles.BONENFANT@ecole-89.com)

**Projet à rendre sur Github**, dans l'espace de travail commun, dans un repo contenant vos nom et prénom. Merci d'ajouter un **fichier d'exportation de votre bdd** et le **diagramme de cas d'utilisations**.

## Etape 1
Etablissez un diagramme de cas d'utilisations pour schématiser le site, ses différents utilisateurs et les fonctionnalités.

## Etape 2
Découpez les templates développés par l'équipe "Front" pour pouvoir les exploiter avec du PHP. Modifier au besoin les formulaires pour pouvoir les traiter. Attention : ne modifier pas les champs et leurs énoncés : ils correspondent au cahier des charges imposé par la société RC-Technic.

## Etape 3
Mettez en place la connexion avec une bdd (nommez la comme vous le souhaitez).

## Etape 4
Mettez en place les différentes classes nécessaires au fonctionnement de votre application.
Mettez en place la bdd et les éventuelles relations dans celle-ci.

## Etape 5
Mettez en place la création de profil :
- le nom et le prénom ne doivent contenir que des lettres
- plusieurs utilisateurs ne peuvent avoir l'email
- le mot de passe devra être hâché et contenir au moins 1 minuscule, 1 majuscule et 1 chiffre, et devra compter entre 8 et 20 caractères
- on est redirigé vers l'accueil après la création d'un profil.

## Etape 6
Mettez en place la connexion :
- redirection vers l'accueil si la connexion est réussie, message d'erreur sinon
- être connecté signifie créer une session

Mettez en place la déconnexion

# Bonus
## Etape 7
Complétez la connexion :
- vous devrez afficher les liens utiles dans le header en fonction de l'existence d'une session et du rôle de l'utilisateur (ouvrier, gestionnaire ou administrateur)
- voire la page d'accueil pour savoir quoi afficher si l'on est connecté
- on ne doit pas pouvoir accéder au formulaire de connexion quand on est connecté.

# Super Bonus
## Etape 9
Mettez en place la création et la mise à jour des "marques".
Dynamisez la page liste des marques. Le bouton "modifier" dirigera vers le formulaire de modification.

## Etape 10
Mettez en place la création et la mise à jour des "matériels".
Dynamisez la page liste des matériels. Le bouton "modifier" dirigera vers le formulaire de modification.

# Méga bonus
## Etape 11
Protégez les accès aux pages "sensibles" dans le back : même si un lien n'est pas affiché, cela ne suffit pas à bloquer totalement l'accès à une url...
Si un employé avec le rôle "ouvrier" accède à une "fiche de matériel", il ne pourra modifier que la quantité.

