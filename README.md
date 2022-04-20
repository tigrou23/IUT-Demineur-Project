# Hugo Pereira & [Félix Liburski](https://github.com/felixlbr)

**IMPORTANT** : Ce projet est aucunement un projet personnel et a pour but éducatif - Projet pour Université Paris Cité. Ce dernier était à faire en binôme et il constitue notre deuxième projet de développement (premier en C++).

## Description du projet <a class="anchor" id="chapter1"></a>
<div align="justify">Ce projet consiste à reproduire le jeu du démineur tout en l’adaptant aux attentes du sujet. Notre applicatif est développé en langage C++ et <strong>le code est en anglais.</strong></div>

<div align="justify">L’objectif est que notre applicatif réussisse à traiter 5 commandes qui peuvent être rentrées par clavier ou par un fichier texte: </div>
<ol><li>problème</li>
<li>grille</li>
<li>partie gagnée</li>
<li>partie perdue</li>
<li>nouveau coup</li></ol>

## Les commandes <a class="anchor" id="chapter2"></a>
**Disclaimer :**
<center>Toute information que l’utilisateur rentrera sera à écrire de cette manière :</center>
<center><strong>[commande n°] « un espace » [information provenant de l’utilisateur]…  

</strong></center>
### Commande Problème (n°1) <a class="anchor" id="section2_1"></a>
<div align="justify">La commande « probleme » est la commande qui sert à créer un problème en fonction d’un nombre de ligne(s), de colonne(s) ainsi de bombe(s).</div>

### Commande Grille (n°2) <a class="anchor" id="section2_2"></a>
<div align="justify">La commande « grille » affiche une grille en fonction d’un nombre de ligne(s), de colonne(s), de bombe(s) et d’un historique de coup(s). De plus, la grille prend en compte l’entrée du placement de(s) bombe(s) ainsi que de(s) coup(s).  </div>
<strong>2 4 6 5 1 5 12 7 19 3 D15 M5 D0  </strong>

Exemple d’entrée :
<center>[2] [nombre lignes] [nombre colonnes] [nombre bombes] [placements…[]…]
[nombre coups] [coups…[]…]</center>

### Commande Partie gagnée (n°3) <a class="anchor" id="section2_3"></a>
<div align="justify">La commande « partie gagnee» va déterminer si la partie est « gagnée » ou « partie pas gagnée ».  

En anglais :
<ul>
<li>partie gagnee = game won</li>
<li>partie pas gagnee = game not won</li>
</ul>
 
### Commande Partie perdue (n°4) <a class="anchor" id="section2_4"></a>
<div align="justify">La commande « partie perdue» va déterminer si la partie est « perdue » ou « partie pas perde ».<div>

En anglais :
<ul>
<li>partie perdue = game lost</li>
<li>partie pas perdue = game not lost</li>
</ul>

### Commande Problème (n°5) <a class="anchor" id="section2_5"></a>
<div align="justify">La commande « nouveau coup » permet de déterminer un coup à faire en fonction d’un grille.</div>

## Structure du code <a class="anchor" id="chapter3"></a>
<div align="justify">Toutes les structures ainsi que les types sont codés dans le fichier Header.h. Les 5 commandes de notre application sont dans le fichier Commandes.cpp et la documentation se trouve dans son fichier
d’entête respectif (Commande.h), accompagnée des prototypes de chaque fonction. Les commandes fonctionnent grâce à toutes les fonctions qui se trouvent dans le fichier Fonction.cpp. Nous avons pris le parti de décomposer les deux fichiers .cpp en fichier .h car la documentation aurait conduit à un fichier trop long. Enfin, le fait de passer par le fichier Header.h nous a grandement facilité la tâche car l’architecture des structures a été l’un des piliers de notre projet. D’ailleurs, nous avons passé beaucoup de temps à concevoir ces dernières et le fichier .h s’est avéré être efficace lors de nos changements d’avis sur les structures/types. Enfin, l’absence de fichiers .h bien spécifiques (notamment aux structures) est un choix que nous avons pris. En effet, nous avons développé une structure principale, à savoir celle de la grille (Grid). Ainsi, toute la grille ainsi que ses paramètres passaient par celle-ci. C’est pourquoi toutes les structures/types se trouvent dans le un seul et même fichier .h.  </div>


## Organisation du projet <a class="anchor" id="chapter4"></a>
<center><i>Cela nous semblait important d'évoquer le fonctionnement
collaboratif que nous avons choisi au cours de projet.  

</i></center>
<div align="justify">Pour veiller au bon déroulé de ce projet. Nous avons utilisé le logiciel GIT qui est un logiciel de gestion de versions. En effet, ce logiciel s'est avéré très utile lors de ce projet collaboratif plutôt long. Cela nous a permis, entre autres, de pouvoir faire des modifications simultanées, c'est-à-dire une possibilité de fusionner intelligemment un travail simultané. De plus, l'avantage de cette méthode est d'avoir le pouvoir de garder en mémoire toutes les anciennes versions (historique) mais aussi QUI a modifié QUOI et QUAND.  </div>
<div align="justify">De plus, notre organisation a été complétée par l'utilisation de Discord pour échanger des messages, des fichiers ou même programmer des réunions hebdomadaires. Enfin nous avons utilisé Trello qui sert à planifier des taches dans le temps. Le respect de ces Deadlines a été primordial pour une avancée satisfaisante au cours du temps.</div>
<div align="justify">Infine, notre travail n'a été que plus efficace grâce à cette sélection de logiciels qui nous semble indispensable à tous projets de développement.</div>

## Organisation du projet <a class="anchor" id="chapter5"></a>
### Test 1 : <a class="anchor" id="section5_1"></a>
in : <center><strong>1 10 20 9</strong></center>
out (sortie possible) : <center><strong>10 20 9 165 190 146 135 158 182 86 85</strong></center>

### Test 2 : <a class="anchor" id="section5_2"></a>
in : <center><strong>2 4 4 2 0 15 1 D7</center></strong>
out : 
```mixed
44
 ___ ___ ___ ___
| . | 1 |   | 	|
 ___ ___ ___ ___
| 1 | 1 |   |   |
 ___ ___ ___ ___
|   |   | 1 | 1 |
 ___ ___ ___ ___
|   |   | 1 | . |
 ___ ___ ___ ___
```
### Test 3 : <a class="anchor" id="section5_3"></a>
in : <center><strong>3 2 2 1 0 4 D1 D2 D3</center></strong>
out (sortie voulue) : <center><strong>game won</center></strong>

### Test 4 : <a class="anchor" id="section5_4"></a>
in : <center><strong>4 5 8 2 34 21 1 D34</center></strong>
out (sortie voulue) : <center><strong>game lost</center></strong>

### Test 5 : <a class="anchor" id="section5_5"></a>
in : <center><strong>5 2 4</center></strong>
```mixed
44
 ___ ___ ___ ___
| . | . | 1 |	|
 ___ ___ ___ ___
| 1 | 1 | 1 |	|
 ___ ___ ___ ___
```
out : <center><strong>D0</center></strong>

### Réussite des différents tests : <a class="anchor" id="section5_6">
Ainsi, nous avons testé notre application au fur et à mesure du temps avec les tests que nous avions à disposition ou que nous avions écris. Notre application a passé tous les tests avec succès.

## Bilan du projet<a class="anchor" id="chapter6">
<div align="justify">Ce projet nous a permis d’apprendre à travailler en groupe, à séparer le programme pour coder à plusieurs. Le problème, et la difficulté principale rencontrée, repose sur les effets de bords qu’on a pu subir. C’est-à-dire que lorsqu’un bout de programme était faux, la suite l’était, et il était compliqué de voir les erreurs, même si le débogage nous a grandement aidé.</div>
<div align="justify">Nous sommes particulièrement fiers du code fourni, malgré le fait qu’on ait dû le modifier plusieurs fois, la structure choisie, ainsi que l’idée d’éviter de se répéter en créant plusieurs fonctions rend notre code très lisible.</div>
<div align="justify">Un problème remarquable, et améliorable, est le manque de convention interne dans notre équipe, nous voyons ainsi l’apparition de fonctions en anglais, en français ou même encore des variables à la fois en camelCase ou parfois en snake_case, ce qui donne l’impression que le programme est un peu brouillon. Cela nous a forcé à vérifier la façon dont nous écrivions nos / fonctions lorsque nous codions. Outre ce problème, nous pensons que le code reste de bonne qualité et reste facilement compréhensible à sa lecture.</div>
