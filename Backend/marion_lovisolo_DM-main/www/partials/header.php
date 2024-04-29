<?php
session_start();

$path = "http://localhost/projets/marion_lovisolo_DM/www/";
$MaterielListe = "liste_materiels.php";
$MarqueListe = "liste_marques.php";

$Link_MarqueList = $path . $MarqueListe;
$Link_MaterielList = $path . $MaterielListe;
?>



<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet"
        integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz"
        crossorigin="anonymous"></script>
    <title>Document</title>
</head>

<body>
    <header>
        <nav class="navbar navbar-expand-lg bg-primary-subtle">
            <img src="bdd.jpg" alt="" width="100">
            <div class="container-fluid">
                <a class="navbar-brand" href="#">RC-Technic</a>
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav"
                    aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarNav">
                    <ul class="navbar-nav">
                        <li class="nav-item">
                            <a class="nav-link active" aria-current="page" href="index.php">Accueil</a>
                        </li>
                        <li class="nav-item">
                            <?php
                            if ($_SESSION != []) {
                                ?>
                                <a class="nav-link active" aria-current="page" href="liste_materiels.php">Matériels</a>
                            </li>
                            <li class="nav-item">
                                <a class="nav-link active" aria-current="page" href="liste_marques.php">Marques</a>
                            </li>
                            <?php
                            }
                            if (isset($_SESSION) && !empty($_SESSION)) {
                                if ($_SESSION['user']['role'] === "administrateur" || $_SESSION['user']['role'] === "gestionnaire") {
                                    ?>
                                <li class="nav-item">
                                    <a class="nav-link active" aria-current="page" href="materiel.php">Créer un matériel</a>
                                </li>
                                <li class="nav-item">
                                    <a class="nav-link active" aria-current="page" href="marque.php">Créer une marque</a>
                                </li>
                                <?php
                                }
                            }
                            if ($_SESSION != []) {
                                if ($_SESSION['user']['role'] == "administrateur") {
                                    ?>
                                <li class="nav-item">
                                    <a class="nav-link" href="register.php">Créer un profil</a>
                                </li>
                                <li class="nav-item">
                                    <?php
                                }
                            }
                            if ($_SESSION == []) {
                                ?>
                                <a class="nav-link" href="login.php">Connexion</a>
                            </li>
                            <?php
                            } else {
                                ?>
                            <li class="nav-item">
                                <a class="nav-link" href="deco.php">Déconnexion</a>
                            </li>
                            <?php
                            }
                            ?>
                    </ul>
                </div>
            </div>
        </nav>
    </header>