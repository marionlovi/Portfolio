<?php

$dsn = "mysql:dbname=rc_technic;host=localhost;charset=utf8";
$username = "root";
$password = "";

try {
    $pdo = new PDO($dsn, $username, $password);
} catch (Exception $erreur) {
    echo "<h1>Erreur de connexion</h1>";
    exit();
}
