<?php
require ("./classes/User.php");
require ("./modeles/user.php");
include ("./partials/header.php");

if ($_SESSION != [] && $_SESSION['user']['role'] == "administrateur") {
  if ($_POST != []) {
    $strRegex = '/[a-z]{1,8}$/';
    $emailRegex = '/^[^\.\s][\w\-]+(\.[\w\-]+)*@([\w-]+\.)+[\w-]{2,}$/';
    $pwdRegex = '/^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?\d)(?=.*?[#?!@$ %^&*-]).{8,20}$/';
    $erreur = array();

    if (!isset($_POST['nom']) || !preg_match($strRegex, $_POST['nom'])) {
      $erreur['nom'] = "Le nom contient des caractères interdit";
    }
    if (!isset($_POST['prenom']) || !preg_match($strRegex, $_POST['prenom'])) {
      $erreur['prenom'] = "Le prenom contient des caractères interdit";
    }

    if (!isset($_POST['email']) || !preg_match($emailRegex, $_POST['email'])) {
      $erreur['email'] = "L'email contient des caractères interdit";
    }

    if (!isset($_POST['password']) || !preg_match($pwdRegex, $_POST['password'])) {
      $erreur['password'] = "Le mot de passe doit contenir au minimum:
       - une minuscule
       - une majuscule
       - une chiffre
       - un symbole
       - 8 caractères";
    }

    if ($_POST['role'] == "Rôle") {
      $erreur['role'] = "Veuillez choisir un role";
    }

    if (checkEmail($_POST["email"])) {
      $erreur['email'] = "l'email existe deja";
    }

    if ($erreur == []) {

      $user = new User();
      foreach ($_POST as $key => $value) {
        if ($key == "password") {
          $user->setPassword($value);
        } else {
          $user->$key = $value;
        }
      }
      createUser($user);
      header("Location: $path");
    }
  }

  ?>
  <main>
    <form class="w-75 mx-auto my-5 border p-2" action="" method="post">
      <div class="mb-3 row">
        <label for="staticEmail" class="col-sm-2 col-form-label">Email</label>
        <div class="col-sm-10">
          <input type="text" class="form-control-plaintext" id="staticEmail" name="email" placeholder="email@example.com">
          <?= isset($erreur["email"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['email'] . "</div>" : "" ?>
        </div>
      </div>
      <div class="mb-3 row">
        <label for="staticEmail" class="col-sm-2 col-form-label">Nom</label>
        <div class="col-sm-10">
          <input type="text" class="form-control-plaintext" id="staticEmail" name="nom" placeholder="votrenom">
          <?= isset($erreur["nom"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['nom'] . "</div>" : "" ?>
        </div>
      </div>
      <div class="mb-3 row">
        <label for="staticEmail" class="col-sm-2 col-form-label">Prénom</label>
        <div class="col-sm-10">
          <input type="text" class="form-control-plaintext" id="staticEmail" name="prenom" placeholder="votreprénom">
          <?= isset($erreur["prenom"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['prenom'] . "</div>" : "" ?>
        </div>
      </div>
      <div class="mb-3 row">
        <label for="inputPassword" class="col-sm-2 col-form-label">Password</label>
        <div class="col-sm-10">
          <input type="password" class="form-control" id="inputPassword" name="password">
          <?= isset($erreur["password"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['password'] . "</div>" : "" ?>
        </div>
      </div><select class="form-select" aria-label="Default select example" name="role">
        <option selected>Rôle</option>
        <option value="ouvrier">ouvrier</option>
        <option value="gestionnaire">gestionnaire</option>
        <option value="administrateur">administrateur</option>
      </select>
      <?= isset($erreur["role"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['role'] . "</div>" : "" ?>
      <button class="btn btn-secondary mt-3">Valider</button>
    </form>
  </main>
  </body>

  </html>
  <?php
} else {
  header("Location: $path");
}