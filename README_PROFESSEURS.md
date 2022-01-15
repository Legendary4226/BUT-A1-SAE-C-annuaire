#Travail effectué par :


* [Richard](#guilland-richard)
* [Yanis](#borie-yanis)


###Guilland-Richard
```
--> Fichier usefull_functions.h
--> Fichier usefull_defines.h
--> Fichier max_fields_length.h
--> Fichier command_handling.h
--> Fichier display.c
--> Fichier display.h
--> Fichier data_structure.c
--> Fichier data_structure.h
--> save.c
--> tri.c
```

###Borie-Yanis
```
--> missingInfo.c
--> add.c
--> delete.c
--> help.c
--> alter.c
```



##Notes pour Professeurs

```
# Richard
Je me suis renseigné sur internet pour deux choses :
--> Le structure padding
--> Le fonctionnement des includes

La structure Client (fichier data_structure.h) est organisé en fonction du structure  padding
pour optimiser le nombre de cycles CPU, il y a aussi une façon de dire au langage C de packer
les données mais elle me faisait gagner que 4 octets...


Les includes dans le projet ne sont pas super bien organisé, mais j'ai appris comment organiser
les fichiers d'un projet donc mieux optimiser et organiser les includes.


Concernant le tri :
Je me suis rendu compte que la structure de données n'était pas parfaite. C'est à dire que
la variable "clientsArray" n'est pas un tableau de pointeurs mais un simple tableau don't les pointeurs se suivent,
hors j'utilises cette variable partout. Il aurait fallu créer un tableau de pointeurs donc 
"struct Client**" cer qui aurait permis d'accéder aux valeurs par le biais de pointeurs mais aussi 
de changer la positions des pointeurs dans le tableau. J'ai compris avant le projet qu'il fallait faire
cela mais je n'avais pas encore compris comment le mettre en place. Maintenant j'ai compris malheureusement.

Je vais donc faire un tri qui permute les structures ce qui n'est pas optimisé mais qui répondra au moins
à la consigne.
```