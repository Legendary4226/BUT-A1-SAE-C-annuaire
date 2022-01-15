#include <stdio.h>
#include <string.h>

#include "commands.h"



void help(char* commandName) {
    if (strcmp(commandName, "add") == 0){
        printf("\nCommande : add -name (nom) -surname (prenom) -city (ville) -codepostal (code postal) -phone (numero telephone) -email (email) -profession (profession)\n"
               "Remplacer les valeurs entre parenthese par les informations indiquees dedans.\n"
               "Vous n'etes pas oblige d'indiquer tous les arguments, vous pouvez juste ajouter votre nom comme ceci :\n"
               "add -name (nom)\n");
        return;
    }
    if (strcmp(commandName, "delete") == 0){
        printf("\nCommande : delete -lineNumber (valeur)\n"
               "Remplacer le '(valeur)' par la ligne du client que vous souhaitez supprimer.\n");
        return;
    }
    if (strcmp(commandName, "alter") == 0){
        printf("\nCommande : alter -lineNumber (valeur) -name (nom) -surname (prenom) -city (ville) -codepostal (code postal) -phone (numero telephone) -email (email) -profession (profession)\n"
               "Remplacer le '(valeur)' par la ligne du client que vous souhaitez modifier.\n"
               "Remplacer les valeurs entre parenthese par les informations indiquees dedans.\n"
               "Vous n'etes pas oblige d'indiquer tous les arguments a l'exception de '-lineNumber', vous pouvez juste modifier votre nom comme ceci :\n"
               "alter -lineNumber (valeur) -name (nom)\n");
        return;
    }
    if (strcmp(commandName, "missingInfo") == 0){
        printf("\nCommande : missingInfo\n");
        return;
    }
    if (strcmp(commandName, "display") == 0){
        printf("\nCommande : display\n");
        return;
    }
    if (strcmp(commandName, "loadFile") == 0){
        printf("\nCommande : loadFile -path (chemin du fichier)\n"
               "Remplacer le '(chemin du fichier)' par le chemin du fichier que vous souhaitez charger.\n");
        return;
    }
    if (strcmp(commandName, "filter") == 0){
        printf("\nCommande : filter -champ (nom du champ) -value (valeur)\n"
               "Remplacer les valeurs entre parenthese par les informations indiquees dedans.\n"
               "Remplacer '(nom du champ)' par l'un des termes suivants : name, surname, city, codepostal, phone, email ou profession.\n");
        return;
    }
    if (strcmp(commandName, "save") == 0){
        printf("\nCommande : save -fileName (nom du fichier)\n"
               "Remplacer '(nom du fichier)' par le nom du fichier que vous voulez sauvegarder.\n");
        return;
    }
    if (strcmp(commandName, "tri") == 0){
        printf("\nCommande : tri -champ (nom du champ)\n"
               "Remplacer '(nom du fichier)' par le nom du fichier que vous voulez sauvegarder.\n");
        return;
    }
    if (strcmp(commandName, "list") == 0){
        printf("\n/* //   Liste des commandes   // */\n\n"
               ">  add : Permet d'ajouter un client.\n"
               ">  alter : Permet de modifier un client existant.\n"
               ">  delete : Permet de supprimer un client existant.\n"
               ">  missingInfo : Permet d'afficher les clients dont des informations sont manquantes.\n"
               ">  loadFile : Permet de charger le fichier que vous souhaitez editer.\n"
               ">  filter : Permet de rechercher/filtrer un champs en fonction d'une valeur dans le fichier.\n"
               ">  display : Permet d'afficher la totalite du contenu du fichier.\n"
               ">  save : Permet d'enregistrer les modifications apportées au fichier.\n"
               ">  tri : Tri la liste selon un champ.\n\n"
               "Pour connaitre les details des commandes tapez la commande dans le format suivant :\n"
               "help -cmdName (nom de la commande)\n");
        return;
    }


    printf("\nLa commande n'a pas ete trouvee.\n");

}