# GNU Debugger (GDB)

## Symboles de débogage

Les symboles de débogage sont des information additionnelles qui seront ajoutés
à votre programme compilé. Ces informations permettront notamment de lier votre
code source au code compilé (et permettre de savoir quelle ligne de code source
représente quelles instructions assembleurs) et de faire le lien entre les noms
de variables et de fonctions et les adresses respectives dans le binaire
compilé.

## Compilation

Pour compiler avec les symboles de débogage, il vous suffit de rajouter 
l'option `-g` lors de la compilation de votre exécutable.

``` bash
gcc -o hello -g hello.c
gdb hello
(gdb) list main
```

### Le cas de malt

Sur malt, vous devrez également ajouter une option supplémentaire afin d'avoir
la table des symboles dans votre binaire compilé. Cette option est `-gstabs`.

``` bash
gcc -o hello -g -gstabs hello.c
gdb hello
(gdb) list main
```
