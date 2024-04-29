<?php
include ("./partials/header.php");
require ("./classes/Marque.php");
require ("./modeles/marque.php");

if ($_SESSION != []) {
  ?>
  <main>
    <section class="text-center my-5">
      <table class="table">
        <thead>
          <th>Nom</th>
          <th>Contact</th>
          <th>Email</th>
          <?php
          if (isset($_SESSION) && !empty($_SESSION)) {
            if ($_SESSION['user']['role'] === "administrateur" || $_SESSION['user']['role'] === "gestionnaire") {
              ?>
              <th>Action</th>
              <?php
            }
          } ?>
        </thead>
        <tbody>
          <?php
          $marque = getMarques();
          foreach ($marque as $key) {
            ?>
            <tr>
              <td>
                <?= $key['nom'] ?>
              </td>
              <td>
                <?= $key['contact'] ?>
              </td>
              <td>
                <?= $key['email'] ?>
              </td>
              <?php
              if (isset($_SESSION) && !empty($_SESSION)) {
                $id = $key['id'];
                if ($_SESSION['user']['role'] === "administrateur" || $_SESSION['user']['role'] === "gestionnaire") {
                  ?>
                  <td>
                    <form action="marque.php?id=<?= $id ?>" method="post">
                      <button class="btn btn-warning" type="submit">Modifier</button>
                    </form>
                  </td>
                  <?php
                }
              }
          }
          ?>
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