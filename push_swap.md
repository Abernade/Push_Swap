# push_swap - to-do

## PARSING

- parsing a faire sur la validité de la liste d'arguments composée de : `./exec` suivie de `--flag` si besoin et enfin `stack a`;
  - [x] récup les flags
    - [x] stucture pour les flags faite
    - [x] penser à faire une fonction qui verifie qu'il n'y a pas plusieurs flags de complexité : on retourne une erreur ?
    - [x] récupérer les entiers passés en arguments : ils sont transformées en liste chainée (à réfléchir)
  - sinon > error
  - [ ] lancer le bon algo selon la difficulté

## ALGORITHMS

- [x] fonction de calcul de disorder
- [ ] reste à lancer le bon algo au bon moment :
  - [ ] algo --simple (insertion sort)
  - [ ] algo --medium (bucket sort)
  - [ ] algo --complex (heap sort)
  - [ ] algo adaptatif
- [ ] recoder les fonctions de base qui manipulent les listes/stacks (8 en tout)

## PRINTER

- [ ] stocker la liste des opérations faites
- [ ] repasser sur cette liste si jamais une double opération est faite remplacer par son équivalent;
- [ ] faire une fonction qui respecte le print du benchmark ==> du coup besoin d'une fonction printer
