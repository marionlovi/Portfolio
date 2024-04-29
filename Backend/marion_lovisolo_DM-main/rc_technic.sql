-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le : jeu. 28 mars 2024 à 10:13
-- Version du serveur : 8.2.0
-- Version de PHP : 8.2.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `rc_technic`
--

-- --------------------------------------------------------

--
-- Structure de la table `marques`
--

DROP TABLE IF EXISTS `marques`;
CREATE TABLE IF NOT EXISTS `marques` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nom` varchar(155) NOT NULL,
  `contact` varchar(155) NOT NULL,
  `email` varchar(155) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `marques`
--

INSERT INTO `marques` (`id`, `nom`, `contact`, `email`) VALUES
(1, 'Toshiba', 'M. Toriyama', 'akira-rip@fake.com'),
(2, 'Schneider', 'M. Wolfy', 'dwolff@fake.com'),
(3, 'Legrand', 'Mme Ursula', 'ursula-legrand@fake.fr'),
(4, 'test', 'ezvdc', 'iezfdd@jer.com');

-- --------------------------------------------------------

--
-- Structure de la table `materiels`
--

DROP TABLE IF EXISTS `materiels`;
CREATE TABLE IF NOT EXISTS `materiels` (
  `id` int NOT NULL AUTO_INCREMENT,
  `marque` varchar(255) NOT NULL,
  `nom` varchar(155) NOT NULL,
  `reference` varchar(150) NOT NULL,
  `quantite` int NOT NULL,
  `prix` float NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `materiels`
--

INSERT INTO `materiels` (`id`, `marque`, `nom`, `reference`, `quantite`, `prix`) VALUES
(1, 'Toshiba', 'Cable', 'GT56U8', 20, 2),
(2, 'Toshiba', 'ef', 'erf', 6, 3),
(3, 'Toshiba', 'izde', 'GZT560', 28, 1.99),
(4, 'Toshiba', 'caMarche', '23FZE', 30, 3.9),
(5, 'Legrand', 'hahahhahaha', 'RE89', 10, 7);

-- --------------------------------------------------------

--
-- Structure de la table `user`
--

DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user` (
  `email` varchar(155) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `password` text NOT NULL,
  `role` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id` int NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `user`
--

INSERT INTO `user` (`email`, `nom`, `prenom`, `password`, `role`, `id`) VALUES
('marionlovi@hotmail.fr', 'Lovisolo', 'Marion', 'a73076cdfd45fa75e377c7a96baf21bb76ed970e7a4ab68a9b2e9f68637f0214b82ba6431f0a6a5d7f6cddb5a8bfb222da2ca988b64a71c36f0664ff59513aaa', 'administrateur', 3),
('nana@nouille.fr', 'Nanouille', 'Nouna', 'a73076cdfd45fa75e377c7a96baf21bb76ed970e7a4ab68a9b2e9f68637f0214b82ba6431f0a6a5d7f6cddb5a8bfb222da2ca988b64a71c36f0664ff59513aaa', 'gestionnaire', 4),
('tom@tommy.fr', 'Tommy', 'Tom', 'a73076cdfd45fa75e377c7a96baf21bb76ed970e7a4ab68a9b2e9f68637f0214b82ba6431f0a6a5d7f6cddb5a8bfb222da2ca988b64a71c36f0664ff59513aaa', 'ouvrier', 5),
('akezop@jezfd.ikjd', 'ompqsjd', 'lekodjk', 'a73076cdfd45fa75e377c7a96baf21bb76ed970e7a4ab68a9b2e9f68637f0214b82ba6431f0a6a5d7f6cddb5a8bfb222da2ca988b64a71c36f0664ff59513aaa', 'ouvrier', 6),
('lcn@jdsb.zelijdf', 'lizejfjd', 'ljefhh', 'a73076cdfd45fa75e377c7a96baf21bb76ed970e7a4ab68a9b2e9f68637f0214b82ba6431f0a6a5d7f6cddb5a8bfb222da2ca988b64a71c36f0664ff59513aaa', 'gestionnaire', 7),
('Azerty1234@haha.fr', 'dez', 'efdc', 'a73076cdfd45fa75e377c7a96baf21bb76ed970e7a4ab68a9b2e9f68637f0214b82ba6431f0a6a5d7f6cddb5a8bfb222da2ca988b64a71c36f0664ff59513aaa', 'ouvrier', 8),
('anais@prof.fr', 'Paris', 'Nana', 'a73076cdfd45fa75e377c7a96baf21bb76ed970e7a4ab68a9b2e9f68637f0214b82ba6431f0a6a5d7f6cddb5a8bfb222da2ca988b64a71c36f0664ff59513aaa', 'gestionnaire', 9),
('haha@haha.fr', 'haha', 'haha', '85f6cbec341dc295c2debcbc8bbed3b344897768b08c3695a002d639a3b4662f4dc736e986ff8637c7c01710412eae9e9bff4d4e0eef16f88af90f527933591d', 'ouvrier', 10);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
