# push_swap - to-do

<style>
red {
  color: red;
}
</style>

## PARSING

- parsing a faire sur la validité de la liste d'arguments composée de : `./exec` suivie de `--flag` si besoin et enfin `stack a`;
  - [x] récup les flags
    - [x] stucture flags + fonction qui verifie =/= plusieurs flags + retour d'une erreur
    - [x] vérifier le format des intergers envoyés par le $USER
    - [x] récupérer les entiers passés en arguments : ils sont transformées en liste chainée (à réfléchir)
  - sinon > error
  - [ ] lancer le bon algo selon la difficulté

## ALGORITHMS

- [x] fonction de calcul de disorder
- [ ] reste à lancer le bon algo au bon moment :
  - [x] algo --simple (insertion sort)
  - [ ] algo --medium (bucket sort) <red>(_ongoing_)</red>
  - [ ] algo --complex (heap sort)
  - [ ] algo adaptatif
- [x] recoder les fonctions de base qui manipulent les listes/stacks (8 en tout) (fait par Arthur)

## PRINTER

- [x] le --bench est géré **MAIS** il manque :
  - [ ] **completer les conditions de compte des opérations pour les doublées**
  - [ ] _**AND**_ **pour le flag `--adaptativ` activer si besoin le flag choisi selon le disorder de la liste pour que le print du `--bench` affiche bien ce qu'il faut**.
  - [ ] _**AND**_ **simplifier les printer dans la fonction des prints de la stratégie**.
  - [ ] **AND** ajouter au bon endroit du main l'appel à `print_bench()` qui n'affiche pas le reste.
- [ ] stocker la liste des opérations faites
- [ ] repasser sur cette liste si jamais une double opération est faite remplacer par son équivalent;
