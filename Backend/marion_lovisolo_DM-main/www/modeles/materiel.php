<?php
require_once ("./inc/db.php");

function getMateriels()
{
    require ("./inc/db.php");

    $sql = "SELECT * FROM `materiels`;";
    $request = $pdo->query($sql);
    $result = $request->fetchAll(PDO::FETCH_ASSOC);
    return $result;
}

function get_this_materiel($id)
{
    require ("./inc/db.php");

    $sql = "SELECT * FROM `materiels` WHERE `id` = $id;";
    $request = $pdo->query($sql);
    $result = $request->fetchAll(PDO::FETCH_ASSOC);
    return $result;
}

function updateMateriel_ouvrier($materiel, $id)
{
    require ("./inc/db.php");

    $sql = "UPDATE materiels SET quantite = ? WHERE id = ?";
    $request = $pdo->prepare($sql);
    $request->execute($materiel->quantité, $id);
}

function updateMateriel_admin($materiel, $id)
{
    require ("./inc/db.php");

    $sql = "UPDATE materiels SET marque = ?, nom = ?, reference = ?, quantite = ?, prix = ? WHERE id = ?";
    $request = $pdo->prepare($sql);
    $values = [
        $materiel->marque,
        $materiel->nom,
        $materiel->reference,
        $materiel->quantite,
        $materiel->prix,
        $id,
    ];
    $request->execute($values);
}

function createMateriel($materiel)
{
    require ("./inc/db.php");

    $sql = "INSERT INTO `materiels` (`marque`, `nom`, `reference`, `quantite`, `prix`) VALUES(?, ?, ?, ?, ?);";
    $request = $pdo->prepare($sql);
    $request->execute(array($materiel->marque, $materiel->nom, $materiel->reference, $materiel->quantite, $materiel->prix));
}