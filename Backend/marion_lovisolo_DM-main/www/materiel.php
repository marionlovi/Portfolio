<?php
require ("./classes/Materiel.php");
require ("./modeles/materiel.php");
require ("./classes/Marque.php");
require ("./modeles/marque.php");
include ("./partials/header.php");

if ($_SESSION != []) {
  if ($_GET != []) {
    $materielToChange = get_this_materiel($_GET['id']);

    if ($_POST != []) {
      $strRegex = '/[a-zA-Z]{1,20}$/';
      $prixRegex = '/^([1-9][0-9]{,2}(,[0-9]{3})*|[0-9]+)(\.[0-9]{1,9})?$/';
      $nbRegex = '/\d{1,10}/';
      $refRegex = '/\w/';
      $erreur = array();

      if (!isset($_POST['nom']) || !preg_match($strRegex, $_POST['nom'])) {
        $erreur['nom'] = "Caractères invalides";
      }
      if (!isset($_POST['reference']) || !preg_match($refRegex, $_POST['reference'])) {
        $erreur['reference'] = "Caractères invalides";
      }
      if (!isset($_POST['quantite']) || !preg_match($nbRegex, $_POST['quantite'])) {
        $erreur['quantite'] = "Caractères invalides";
      }
      if (!isset($_POST['prix']) || !preg_match($prixRegex, $_POST['prix'])) {
        $erreur['prix'] = "Caractères invalides";
      }

      if ($erreur == []) {
        $materiel = new Materiel();
        foreach ($_POST as $key => $value) {
          $materiel->$key = $value;
        }
        if ($_SESSION == "ouvrier") {
          updateMateriel_ouvrier($materiel, $_GET['id']);
        } else {
          updateMateriel_admin($materiel, $_GET['id']);
        }
        header("Location: $Link_MaterielList");
      }
    }
    ?>
    <main>
      <form class="w-75 mx-auto my-5 border p-2" action="" method="post">
        <select name="marque" class="form-select" aria-label="Default select example">
          <option selected>
            <?= $materielToChange[0]['marque'] ?>
          </option>
          <?php
          $marque = getMarques();
          if ($_SESSION['user']['role'] == "administrateur" || $_SESSION['user']['role'] == "gestionnaire") {
            foreach ($marque as $key) {
              if ($key['nom'] != $materielToChange[0]['marque']) {
                ?>
                <option value="<?= $key['nom'] ?>">
                  <?= $key['nom'] ?>
                </option>
              <?php }
            }
          } ?>
        </select>
        <?= isset($erreur["marque"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['marque'] . "</div>" : "" ?>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Nom</label>
          <div class="col-sm-10">
            <?php
            if ($_SESSION['user']['role'] == "ouvrier") {
              ?>
              <input name="nom" type="text" class="form-control-plaintext" id="staticEmail" readonly
                value="<?= $materielToChange[0]['nom'] ?>" placeholder="<?= $materielToChange[0]['nom'] ?>">
              <?= isset($erreur["nom"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['nom'] . "</div>" : "" ?>
              <?php
            } else {
              ?>
              <input name="nom" type="text" class="form-control-plaintext" id="staticEmail"
                value="<?= $materielToChange[0]['nom'] ?>" placeholder="<?= $materielToChange[0]['nom'] ?>">
              <?= isset($erreur["nom"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['nom'] . "</div>" : "" ?>
              <?php
            }
            ?>
          </div>
        </div>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Référence</label>
          <div class="col-sm-10">
            <?php
            if ($_SESSION['user']['role'] == "ouvrier") {
              ?>
              <input name="reference" type="text" class="form-control-plaintext" id="staticEmail"
                placeholder="<?= $materielToChange[0]['reference'] ?>" readonly
                value="<?= $materielToChange[0]['reference'] ?>">
              <?php
            } else {
              ?>
              <input name="reference" type="text" class="form-control-plaintext" id="staticEmail"
                placeholder="<?= $materielToChange[0]['reference'] ?>" value="<?= $materielToChange[0]['reference'] ?>">
              <?= isset($erreur["reference"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['reference'] . "</div>" : "" ?>
              <?php
            }
            ?>
          </div>
        </div>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Quantité</label>
          <div class="col-sm-10">
            <input name="quantite" type="number" class="form-control-plaintext" id="staticEmail"
              placeholder=<?= $materielToChange[0]['quantite'] ?> value=<?= $materielToChange[0]['quantite'] ?>>
            <?= isset($erreur["quantite"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['quantite'] . "</div>" : "" ?>
          </div>
        </div>
        <div class="mb-3 row">
          <label for="staticEmail" class="col-sm-2 col-form-label">Prix d'achat</label>
          <div class="col-sm-10">
            <?php
            if ($_SESSION['user']['role'] == "ouvrier") {
              ?>
              <input name="prix" type="float" class="form-control-plaintext" id="staticEmail"
                placeholder=<?= $materielToChange[0]['prix'] ?> readonly value=<?= $materielToChange[0]['prix'] ?>>
              <?php
            } else {
              ?>
              <input name="prix" type="float" class="form-control-plaintext" id="staticEmail"
                placeholder=<?= $materielToChange[0]['prix'] ?> value=<?= $materielToChange[0]['prix'] ?>>
              <?= isset($erreur["prix"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['prix'] . "</div>" : "" ?>
              <?php
            }
            ?>
          </div>
        </div>
        <button class="btn btn-secondary mt-3">Valider</button>
      </form>
    </main>
    </body>

    </html>
    <?php
  } else {
    if ($_SESSION['user']['role'] == "administrateur" || $_SESSION['user']['role'] == "gestionnaire") {

      if ($_POST != []) {
        $strRegex = '/[a-zA-Z]{1,20}$/';
        $prixRegex = '/^([1-9][0-9]{,2}(,[0-9]{3})*|[0-9]+)(\.[0-9]{1,9})?$/';
        $nbRegex = '/\d{1,10}/';
        $refRegex = '/\w/';
        $erreur = array();

        if ($_POST['marque'] == "materiel") {
          $erreur['marque'] = "Merci de selectionner marque";
        }
        if (!isset($_POST['nom']) || !preg_match($strRegex, $_POST['nom'])) {
          $erreur['nom'] = "Caractères invalides";
        }
        if (!isset($_POST['reference']) || !preg_match($refRegex, $_POST['reference'])) {
          $erreur['reference'] = "Caractères invalides";
        }
        if (!isset($_POST['quantite']) || !preg_match($nbRegex, $_POST['quantite'])) {
          $erreur['quantite'] = "Caractères invalides";
        }
        if (!isset($_POST['prix']) || !preg_match($prixRegex, $_POST['prix'])) {
          $erreur['prix'] = "Caractères invalides";
        }

        if ($erreur == []) {
          $materiel = new Materiel();
          foreach ($_POST as $key => $value) {
            $materiel->$key = $value;
          }
          createMateriel($materiel);
        }
      }
      ?>
      <main>
        <form class="w-75 mx-auto my-5 border p-2" action="" method="post">
          <select name="marque" class="form-select" aria-label="Default select example">
            <option selected>materiel</option>
            <?php
            $marque = getMarques();
            foreach ($marque as $key) {
              ?>
              <option value="<?= $key['nom'] ?>">
                <?= $key['nom'] ?>
              </option>
            <?php } ?>
          </select>
          <?= isset($erreur["marque"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['marque'] . "</div>" : "" ?>
          <div class="mb-3 row">
            <label for="staticEmail" class="col-sm-2 col-form-label">Nom</label>
            <div class="col-sm-10">
              <input name="nom" type="text" class="form-control-plaintext" id="staticEmail" placeholder="Interrupteur">
              <?= isset($erreur["nom"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['nom'] . "</div>" : "" ?>
            </div>
          </div>
          <div class="mb-3 row">
            <label for="staticEmail" class="col-sm-2 col-form-label">Référence</label>
            <div class="col-sm-10">
              <input name="reference" type="text" class="form-control-plaintext" id="staticEmail" placeholder="RX1385">
              <?= isset($erreur["reference"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['reference'] . "</div>" : "" ?>
            </div>
          </div>
          <div class="mb-3 row">
            <label for="staticEmail" class="col-sm-2 col-form-label">Quantité</label>
            <div class="col-sm-10">
              <input name="quantite" type="number" class="form-control-plaintext" id="staticEmail" placeholder=10>
              <?= isset($erreur["quantite"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['quantite'] . "</div>" : "" ?>
            </div>
          </div>
          <div class="mb-3 row">
            <label for="staticEmail" class="col-sm-2 col-form-label">Prix d'achat</label>
            <div class="col-sm-10">
              <input name="prix" type="float" class="form-control-plaintext" id="staticEmail" placeholder=2.30>
              <?= isset($erreur["prix"]) ? "<div class=\"alert alert-danger\" role=\"alert\">" . $erreur['prix'] . "</div>" : "" ?>
            </div>
          </div>
          <button class="btn btn-secondary mt-3">Valider</button>
        </form>
      </main>
      </body>

      </html>
      <?php
    } else {
      ?>
      <h1> Vous n'avez pas acces à cette page,
        <?= $_SESSION['user']['prenom'] ?>. Veuillez cliquer <a href="login.php">ici</a>
      </h1>
      <?php
    }
  }
} else {
  header("Location: $path");
}
?>