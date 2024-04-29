<?php
require_once ("./inc/db.php");

function getMarques()
{
    require ("./inc/db.php");

    $sql = "SELECT * FROM `marques`;";
    $request = $pdo->query($sql);
    $result = $request->fetchAll(PDO::FETCH_ASSOC);
    return $result;
}

function get_this_marque($id)
{
    require ("./inc/db.php");

    $sql = "SELECT * FROM `marques` WHERE `id` = $id;";
    $request = $pdo->query($sql);
    $result = $request->fetchAll(PDO::FETCH_ASSOC);
    return $result;
}

function updateMarque($marques, $id)
{
    require ("./inc/db.php");

    $sql = "UPDATE marques SET nom = ?, contact = ?, email = ? WHERE id = ?";
    $request = $pdo->prepare($sql);
    $request->execute([$marques->nom, $marques->contact, $marques->email, $id]);
}

function createMarque($marques)
{
    require ("./inc/db.php");

    $sql = "INSERT INTO `marques` (`nom`, `contact`, `email`) VALUES(?, ?, ?);";
    $request = $pdo->prepare($sql);
    $request->execute(array($marques->nom, $marques->contact, $marques->email));
}