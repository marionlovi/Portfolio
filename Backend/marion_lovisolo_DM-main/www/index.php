<?php
include ("./partials/header.php");
?>

<main>
    <section class="text-center my-5">
        <?php
        if ($_SESSION != []) {
            ?>
            <h1>Bonjour et bienvenue sur le site de gestion de RC-Technic,
                <?= $_SESSION['user']['prenom'] ?>
            </h1>
            <?php
        } else {
            ?>
            <h1>Bonjour merci de vous connecter : <a href="login.php">ici</a></h1>
            <?php
        }
        ?>
    </section>
</main>
</body>

</html>