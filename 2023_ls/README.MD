# Consignes

Implémenter un recode partiel de l'utilitaire ls. Notre programme affiche une liste de fichiers triés par ordre ASCII. Les options gérées sont les suivantes :

a : liste aussi les fichiers cachés
l: affiche les détails de chaque fichier
h : affiche la taille des fichier d'une façon plus facile à lire

Les options peuvent etre reçue sur n'importe quel argument du main et dans n'importe quelle combinaison.

- ./ls
- ./ls -a
- ./ls -a -l
- ./ls -la
- ./la -al
- ./ls -lah
- ./ls -h -al

Il est aussi possible de passer des noms de fichiers et de dossiers à ls. Lorsqu'un argument n'est pas un option :

si c'est un dossier : afficher son contenu
si c'est un fichier : afficher son nom (ou ses détails dans le cas de -l)
Il peut y avoir plusieurs fichiers/dossiers en argument en plus des options.
