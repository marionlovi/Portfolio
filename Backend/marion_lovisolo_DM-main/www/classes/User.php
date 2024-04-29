<?php

class User
{
    public $nom;
    public $prenom;
    public $email;
    private $password;
    public $role;

    public function getPassword()
    {
        return $this->password;
    }

    public function setPassword($password)
    {
        $this->password = $password;
    }
}