<?php

require ("./classes/User.php");
require ("./modeles/user.php");
include ("./partials/header.php");

if ($_SESSION != []) {
  $_SESSION = [];
}
if ($_POST != []) {
  $user = new User();
  foreach ($_POST as $key => $value) {
    if ($key == "password") {
      $user->setPassword($value);
    } else {
      $user->$key = $value;
    }
  }
  if (!empty(login($user))) {
    session_start();
    $_SESSION['user'] = login($user);
    header("Location: $path");
    exit();
  } else {
    $message = 'Utilisateur ou mot de passe inconnu';
  }
}
?>

<main>
  <form class="w-75 mx-auto my-5 border p-2" action="" method="post">
    <div class="mb-3 row">
      <label for="staticEmail" class="col-sm-2 col-form-label">Email</label>
      <div class="col-sm-10">
        <input name="email" type="text" class="form-control-plaintext" id="staticEmail" placeholder="email@example.com">
        <?= isset($erreur["email"]) ? "<div class = \"alert alert-danger\"
        role=\"alert\">" . $erreur['email'] . "</div>" : "" ?>
      </div>
    </div>
    <div class="mb-3 row">
      <label for="inputPassword" class="col-sm-2 col-form-label">Password</label>
      <div class="col-sm-10">
        <input name="password" type="password" class="form-control" id="inputPassword">
        <?= isset($message) ? "<div class = \"alert alert-danger\"
        role=\"alert\">" . $message . "</div>" : "" ?>
      </div>
    </div>
    <button class="btn btn-secondary mt-3">Valider</button>

  </form>
</main>
</body>

</html>