<?php
function createUser($user)
{
    require ("./inc/db.php");

    $plainPassword = $user->getPassword();
    $hashedPassword = hash('sha512', $plainPassword);
    $sql = "INSERT INTO `user` (`email`, `nom`, `prenom`,`password`, `role`) VALUES (?, ?, ?, ?, ?);";
    $request = $pdo->prepare($sql);
    $request->execute(
        array(
            $user->email,
            $user->nom,
            $user->prenom,
            $hashedPassword,
            $user->role,
        )
    );
}

function checkEmail($email)
{
    require ("./inc/db.php");

    $sql = "SELECT * FROM `user` WHERE `email`= '$email';";
    $request = $pdo->query($sql);
    $result = $request->fetchAll(PDO::FETCH_ASSOC);
    return !empty ($result);
}

function login($user)
{
    require ("./inc/db.php");

    $email = $user->email;
    $hashedPassword = hash('sha512', $user->getPassword());
    $sql = "SELECT `nom`, `prenom`, `email`, `role` FROM `user` WHERE 
    `email`= \"$email\" AND `password`=\"$hashedPassword\";";
    $request = $pdo->query($sql);
    $result = $request->fetch(PDO::FETCH_ASSOC);
    return $result;
}