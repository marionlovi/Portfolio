<?php
require ("./classes/Marque.php");
require ("./modeles/marque.php");
include ("./partials/header.php");

if ($_SESSION != [] && $_SESSION['user']['role'] != "ouvrier") {
  if ($_GET != []) {
    $MarqueToChange = get_this_marque($_GET['id']);
    if ($_POST != []) {

      $strRegex = '/[a-zA-Z]{1,20}$/';
      $contactRegex = '/[a-zA-Z\s\.]{1,40}/';
      $emailRegex = '/^[^\.\s][\w\-]+(\.[\w\-]+)*@([\w-]+\.)+[\w-]{2,}$/';
      $erreur = array();

      if (!isset($_POST['nom']) || !preg_match($strRegex, $_POST['nom'])) {
        $erreur['nom'] = "Le nom contient des caractères interdit";
      }
      if (!isset($_POST['contact']) || !preg_match($contactRegex, $_POST['contact'])) {
        $erreur['email'] = "Le contact contient des caractères interdit";
      }
      if (!isset($_POST['email']) || !preg_match($emailRegex, $_POST['email'])) {
        $erreur['email'] = "L'email contient des caractères interdit";
      }
      if ($erreur == []) {

        $marque = new Marque();
        foreach ($_POST as $key => $value) {
          $marque->$key = $value;
        }
        updateMarque($marque, $_GET['id']);
      }

      header("Location: $Link_MarqueList");
    }
    ?>
    <main>
      <form class="w-75 mx-auto my-5 border p-2" action="" method="post">
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Nom</label>
          <div class="col-sm-10">
            <input name="nom" type="text" class="form-control-plaintext" id="staticEmail"
              value="<?= $MarqueToChange[0]['nom'] ?>" placeholder="<?= $MarqueToChange[0]['nom'] ?>">
            <?= isset($erreur["nom"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['nom'] . "</div>" : "" ?>
          </div>
        </div>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Personne à contacter</label>
          <div class="col-sm-10">
            <input name="contact" type="text" class="form-control-plaintext" id="staticEmail"
              value="<?= $MarqueToChange[0]['contact'] ?>" placeholder="<?= $MarqueToChange[0]['contact'] ?>">
            <?= isset($erreur["contact"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['contact'] . "</div>" : "" ?>
          </div>
        </div>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Email</label>
          <div class="col-sm-10">
            <input name="email" type="text" class="form-control-plaintext" id="staticEmail"
              value="<?= $MarqueToChange[0]['email'] ?>" placeholder="<?= $MarqueToChange[0]['email'] ?>">
            <?= isset($erreur["email"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['email'] . "</div>" : "" ?>
          </div>
        </div>
        <button class="btn btn-secondary mt-3">Valider</button>
      </form>
    </main>
    </body>

    </html>
    <?php
  } else {
    if ($_POST != []) {
      $strRegex = '/[a-zA-Z]{1,20}$/';
      $contactRegex = '/[a-zA-Z\s\.]{1,40}/';
      $emailRegex = '/^[^\.\s][\w\-]+(\.[\w\-]+)*@([\w-]+\.)+[\w-]{2,}$/';
      $erreur = array();

      if (!isset($_POST['email']) || !preg_match($emailRegex, $_POST['email'])) {
        $erreur['email'] = "L'email contient des caractères interdit";
      }
      if (!isset($_POST['contact']) || !preg_match($contactRegex, $_POST['contact'])) {
        $erreur['email'] = "Le contact contient des caractères interdit";
      }
      if (!isset($_POST['nom']) || !preg_match($strRegex, $_POST['nom'])) {
        $erreur['email'] = "Le nom contient des caractères interdit";
      }

      if ($erreur == []) {

        $marque = new Marque();
        foreach ($_POST as $key => $value) {
          $marque->$key = $value;
        }
        createMarque($marque);
      }
    }
    ?>
    <main>
      <form class="w-75 mx-auto my-5 border p-2" action="" method="post">
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Nom</label>
          <div class="col-sm-10">
            <input name="nom" type="text" class="form-control-plaintext" id="staticEmail" placeholder="Schneider">
            <?= isset($erreur["nom"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['nom'] . "</div>" : "" ?>
          </div>
        </div>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Personne à contacter</label>
          <div class="col-sm-10">
            <input name="contact" type="text" class="form-control-plaintext" id="staticEmail" placeholder="M. Bidule">
            <?= isset($erreur["contact"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['contact'] . "</div>" : "" ?>
          </div>
        </div>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Email</label>
          <div class="col-sm-10">
            <input name="email" type="text" class="form-control-plaintext" id="staticEmail" placeholder=michel@fake.com>
            <?= isset($erreur["email"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['email'] . "</div>" : "" ?>
          </div>
        </div>
        <button class="btn btn-secondary mt-3">Valider</button>
      </form>
    </main>
    </body>

    </html>
    <?php
  }
} else {
  header("Location: $path");
}
?>