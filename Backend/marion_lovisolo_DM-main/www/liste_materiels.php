<?php
include ("./partials/header.php");
require ("./classes/Materiel.php");
require ("./modeles/materiel.php");

if ($_SESSION != []) {
  ?>
  <main>
    <section class="text-center my-5">
      <table class="table">
        <thead>
          <th>Nom</th>
          <th>Référence</th>
          <th>Marque</th>
          <th>Prix</th>
          <th>Quantité</th>
          <th>Action</th>
        </thead>
        <tbody>
          <?php
          $materiel = getMateriels();
          foreach ($materiel as $key) {
            ?>
            <tr>
              <td>
                <?= $key['nom'] ?>
              </td>
              <td>
                <?= $key['reference'] ?>
              </td>
              <td>
                <?= $key['marque'] ?>
              </td>
              <td>
                <?= $key['prix'] ?>
              </td>
              <td>
                <?= $key['quantite'] ?>
              </td>
              <td>
                <?php $id = $key['id']; ?>
                <form action="materiel.php?id=<?= $id ?>" method="post">
                  <button class="btn btn-warning" type="submit">
                    Modifier
                  </button>
                </form>
              </td>
            </tr>
          <?php } ?>
        </tbody>
      </table>
    </section>
  </main>
  </body>
  </php>
  <?php
} else {
  header("Location: $path");
}