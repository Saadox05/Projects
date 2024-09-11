#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define MAX_ETUDIANT 200

/*Structure de date pour la date de naissance */
typedef struct {
    int jour;
    int mois;
    int annee;
}Date;

/*enumeration qui represente les departements */
typedef enum {INFORMATIQUE, MATHEMATIQUES, PHYSIQUE, CHIMIE}Departement;

/*la structure principale de l'etudiant qui contient l'id , le nom, le prenom , la date de */
typedef struct {
    int id;
    char nom[MAX];
    char prenom[MAX];
    Date date_naissance;
    Departement departement;
    float note;
}Etudiant;

int count =0;
Etudiant classe[MAX_ETUDIANT];
int id = 0;
/*La fonction qui permet d'ajouter un etudiant a la liste de l'université */
void ajouterEtudiant(){
    if(count >= MAX_ETUDIANT){ printf("Il n'y a pas de places vides\n");}
    else{
        classe[count].id = id++;
        printf("Entrer le nom de l'etudiant\n");
        scanf(" %[^\n]s", &classe[count].nom);
        printf("Entrer le prenom de l'etudiant\n");
        scanf(" %[^\n]s", &classe[count].prenom);
        printf("Entrer la date de naissance (jour mois annee)\n");
        scanf("%d %d %d", &classe[count].date_naissance.jour, &classe[count].date_naissance.mois, &classe[count].date_naissance.annee );
        printf("Entrer la departement : \n0-INFORMATIQUE.\n1-MATHEMATIQUES.\n2-PHYSIQUE.\n3-CHIMIE\n");
        scanf("%d", &classe[count].departement);
        printf("Entrer la note generale de l'etudiant\n");
        scanf("%f", &classe[count].note);
        count++;
    }
}


void modifierEtudiant(){
    int id_;
    printf("Entrez l'id de l'etudiant que vous voulez modifier\n");
    scanf("%d", &id_);
    for(int i=0; i<count ; i++){
        if(classe[i].id == id_){
            printf("Entrer le nouveau nom de l'etudiant\n");
            scanf(" %[^\n]s", &classe[i].nom);
            printf("Entrer le nouveau prenom de l'etudiant\n");
            scanf(" %[^\n]s", &classe[i].prenom);
            printf("Entrer la nouvelle date de naissance (jour mois annee)");
            scanf("%d %d %d", &classe[i].date_naissance.jour, &classe[i].date_naissance.mois, &classe[i].date_naissance.annee );
            printf("Entrer la nouvelle departement : \n0-INFORMATIQUE.\n1-MATHEMATIQUES.\n2-PHYSIQUE.\n3-CHIMIE\n");
            scanf("%d", &classe[i].departement);
            printf("Entrer la nouvelle note generale de l'etudiant\n");
            scanf("%f", &classe[i].note);
            printf("Les infos de l'etudiant ont ete modifie avec succes\n");
            return ;
        }
    }
    printf("Il n'y a pas d'etudiant avec cet id \n");
}

void supprimerEtudiant(){
    int id_;
    printf("Entrer l'id de l'etudiant que vous voulez supprimer\n");
    scanf("%d",&id_);
    /*indexToRemove est l'indice a supprimé
    on l'obtient en comparant l'id de l'etudiant en cours avec l'id entré par l'utilisateur */
    int indexToRemove = -1;
    for (int i = 0; i < count; i++) {
        if (classe[i].id == id_) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        printf("Il n'y a pas d'etudiant avec cet id \n");
        return;
    }

    for(int i = indexToRemove; i< count -1; i++){
        classe[i]=classe[i+1];
    }
    count--;
    printf("l'etudiant a ete supprime avec succes\n");

}

/*la fonction qui renvoie la chaine de caractere associé a l'enumeration departement */

char *departement(Departement d ){
    char * str = malloc(20*sizeof(char));
    switch(d){
    case 0 :
        strcpy(str, "Informatique");
        break;
    case 1:
        strcpy(str, "Mathematiques");
        break;
    case 2:
        strcpy(str, "Physique");
        break;
    case 3:
        strcpy(str, "Chimie");
        break;
    default:
        break;
    }
    return str;
}
void afficherEtudiants() {
    if (count == 0) {
        printf("La liste des etudiants est vide\n");
    } else {
        printf("%-3s | %-12s | %-12s | %-12s | %-12s | %s\n",
               "ID", "Nom", "Prenom", "Date de Naissance", "Departement", "Note Generale");
        printf("-----+-------------+-------------+--------------+-------------+------------\n");

        for (int i = 0; i < count; i++) {
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
        }
    }
}

void rechercherEtudiant(){
    char  str[30];
    printf("entrer le nom de l'etudiant que vous recherchez\n");
    scanf("%s", &str);
    for(int i=0; i<count ; i++){
        if(!strcmp(str, classe[i].nom)){
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
                   return ;
        }
    }
    printf("Il n'y a pas d'etudiant correspondant au nom que vous avez entre\n");
}
/* une fonction qui permet d'afficher les etudiants d'une departement */
void afficherDepartement(){
    int dep;
    if(count ==0){
        printf("La liste des etudiants est vide \n");
    }else{
        printf("Entrer la departement que vous voulez afficher \n");
        printf("(0)-INFORMATIQUE.\n(1)-MATHEMATIQUES.\n(2)-PHYSIQUE.\n(3)-CHIMIE\n");
        scanf("%d", &dep);
        if(dep>3){
            printf("Cette departement n'existe pas \n");
            return ;
        }else{
        printf("id | nom | prenom | date de naissance | Departement | note generale\n");
        for(int i=0; i<count; i++){
            if(dep==classe[i].departement){
                printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
                }
            }
        }
    }
}

void claculMoyenne(){
    int choice;
    int dep;
    float sum = 0;
    float avg;
    int dep_count = 0; // le conteur qui compte le nombre d'etudiants dans une departement
    printf("1- Afficher la moyenne generale de l'universite entiere\n");
    printf("2- Afficher la moyenne generale d'une departement \n");
    scanf("%d", &choice);
    switch(choice){
case 1:
    if(count ==0){ printf("La liste des etudiants est vide \n");}else{
    for(int i=0; i<count; i++ ){
        sum+=classe[i].note;
    }
    avg = sum / count;
    printf("la moyenne generale de l'universite est : %.2f", avg);
    }
    break;
case 2:
    if(count == 0){ printf("La liste des etudiants est vide \n");}else{
        printf("Entrer la departement \n");
        printf("(0)-INFORMATIQUE.\n(1)-MATHEMATIQUES.\n(2)-PHYSIQUE.\n(3)-CHIMIE\n");
        scanf("%d",&dep);
        for(int i = 0; i< count ; i++){
            if(classe[i].departement == dep){
                sum+=classe[i].note;
                dep_count++;
            }
        }
        avg = sum / dep_count;
        printf("La moyenne generale du departement %s est %.2f", departement(dep), avg);
    }
    break ;
default:
    printf("Choix invalide \n");
    break ;
    }
}


/*fonction qui permet d'afficher le nbr d'etudiants dans chaque departement*/
void depCount(){
    int dep0 = 0 ;
    int dep1 = 0 ;
    int dep2 = 0 ;
    int dep3 = 0 ;
    if(count == 0){ printf("La liste des etudiants est vide \n");}else{
        for(int i = 0 ; i<count ; i++){
            switch(classe[i].departement){
                case 0 : dep0++;
                    break ;
                case 1 : dep1++;
                    break ;
                case 2 : dep2++;
                    break ;
                case 3 : dep3++;
                    break ;
            }
        }
        printf("(0) Informatique %d etudiants \n", dep0);
        printf("(1) Mathematiques %d etudiants \n", dep1);
        printf("(2) Physique %d etudiants \n", dep2);
        printf("(3) Chimie %d etudiants \n", dep3);
    }
}
/*une fonction qui parcourt un tableau de reels , et renvoi l 'indice de l element maximum et le met a zero */
int maxIndex(float t[], int n ){
    int max = 0;
    for (int i = 0 ; i< n ; i++){
        if(t[i]>t[max]){
            max = i;
        }
    }
    t[max]=0;
    return max;
}

/*fonction qui affiche le nombre d'etudiants ayant reussi dans chaque departement*/

void depCountSucces(){
    int succes0 = 0 ;
    int succes1 = 0 ;
    int succes2 = 0 ;
    int succes3 = 0 ;
    if(count == 0){ printf("La liste des etudiants est vide \n");}else{
        for(int i = 0 ; i<count ; i++){
            switch(classe[i].departement){
                case 0 :
                    if(classe[i].note > 10){ succes0++; }
                    break ;
                case 1 :
                    if(classe[i].note > 10){ succes1++; }
                    break ;
                case 2 :
                    if(classe[i].note > 10){ succes2++; }
                    break ;
                case 3 :
                    if(classe[i].note > 10){ succes3++; }
                    break ;
            }
        }
        printf("(0) Le nombre de reussite en departement Informatique est : %d \n", succes0);
        printf("(1) Le nombre de reussite en departement Mathematiques %d \n", succes1);
        printf("(2) Le nombre de reussite en departement Physique %d \n", succes2);
        printf("(3) Le nombre de reussite en departement Chimie %d \n", succes3);
    }

}

void afficherStats(){
    int choice ;
    int seuil ;
    float t[count];
    int max3[3];//tableau qui va stocker les indices des 3 premiers etudiants
    printf("1- Afficher le nbr total d'etudiants inscrits \n");
    printf("2- Afficher le nbr d'etudiants dans chaque departement\n");
    printf("3- Afficher les etudiants ayant une moyenne generale > seuil\n");
    printf("4- Afficher les 3 etudiants ayant les meilleures notes \n");
    printf("5- Afficher le nbr d'etudiants ayant reussi dans chaque departement\n");
    printf("6- Retourner au menu \n");
    scanf("%d", &choice);
    switch(choice){
case 1:
    printf("Le nombre total d'etudiants inscrits est %d\n", count);
    break ;
case 2:
    depCount();
    break ;
case 3:
    printf("entrer un seuil\n");
    scanf("%d", &seuil);
    printf("%-3s | %-12s | %-12s | %-12s | %-12s | %s\n",
               "ID", "Nom", "Prenom", "Date de Naissance", "Departement", "Note Generale");
    printf("-----+-------------+-------------+--------------+-------------+------------\n");

    for (int i = 0; i < count; i++) {
        if(classe[i].note> seuil ){
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
            }
        }
    break ;
case 4:
    for(int i = 0 ; i< count ; i++){
        t[i] = classe[i].note;
    }
    max3[0] = maxIndex(t, count);
    max3[1] = maxIndex(t, count);
    max3[2] = maxIndex(t, count);
    for (int i = 0; i < 3; i++) {
        printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                classe[max3[i]].id, classe[max3[i]].nom, classe[max3[i]].prenom,
                classe[max3[i]].date_naissance.jour, classe[max3[i]].date_naissance.mois,
                classe[max3[i]].date_naissance.annee, departement(classe[max3[i]].departement),
                classe[max3[i]].note);

        }
    break ;
case 5:
    depCountSucces();
    break ;
case 6:
    return ;
default :
    printf("Choix invalide\n");
    break ;
    }

}



void trierEtudiant(){
    int choice ;
    printf("1- Trier les etudiants alphabetiquement selon leur nom de A a Z \n");
    printf("2- Trier les etudiants alphabetiquement selon leur nom de Z a A\n");
    printf("3- Trier les etudiants par moyenne generale par ordre croissant \n");
    printf("4- Trier les etudiants par moyenne generale par ordre decroissant \n");
    printf("5- Trier les etudiants selon leur statut de reussite  \n");
    printf("6- Retourner au menu \n");
    scanf("%d", &choice);
    switch (choice){
    case 1:
        for( int i =0 ; i< count -1; i++){
            for(int j=0; j<count-i-1; j++){
                if(strcmp(classe[j].nom, classe[j+1].nom)>0){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 2:
        for( int i =0 ; i< count -1; i++){
            for(int j=0; j<count-i-1; j++){
                if(strcmp(classe[j].nom, classe[j+1].nom)<0){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 3:
        for(int i =0 ; i< count -1; i++){
            for(int j = 0 ; j< count -i -1 ; j++){
                if(classe[j].note>classe[j+1].note){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 4:
         for(int i =0 ; i< count -1; i++){
            for(int j = 0 ; j< count -i -1 ; j++){
                if(classe[j].note<classe[j+1].note){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        break ;
    case 5:
        for(int i =0 ; i< count -1; i++){
            for(int j = 0 ; j< count -i -1 ; j++){
                if(classe[j].note<classe[j+1].note){
                    Etudiant temp = classe[j];
                    classe[j] = classe[j+1];
                    classe[j+1]=temp;
                }
            }
        }
        for(int i =0 ; i< count ; i++){
            if(classe[i].note>10){
            printf("%-3d | %-12s | %-12s | %02d/%02d/%04d | %-12s | %.2f\n",
                   classe[i].id, classe[i].nom, classe[i].prenom,
                   classe[i].date_naissance.jour, classe[i].date_naissance.mois,
                   classe[i].date_naissance.annee, departement(classe[i].departement),
                   classe[i].note);
            }

        }
        break ;
    case 6:
        return ;
    default :
        printf("Choix invalide \n");
        break ;

    }
}

void remplirDonnee(){
    classe[count].id=id++;
    strcpy(classe[count].nom, "Razi");
    strcpy(classe[count].prenom, "Mohamed");
    classe[count].date_naissance.jour = 1;
    classe[count].date_naissance.mois = 3;
    classe[count].date_naissance.annee = 2000;
    classe[count].departement = INFORMATIQUE;
    classe[count].note = 13.23;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Kassaoui");
    strcpy(classe[count].prenom, "Yassine");
    classe[count].date_naissance.jour = 10;
    classe[count].date_naissance.mois = 9;
    classe[count].date_naissance.annee = 2003;
    classe[count].departement = INFORMATIQUE;
    classe[count].note = 15.21;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Arji");
    strcpy(classe[count].prenom, "Oussama");
    classe[count].date_naissance.jour = 5;
    classe[count].date_naissance.mois = 3;
    classe[count].date_naissance.annee = 2001;
    classe[count].departement = MATHEMATIQUES;
    classe[count].note = 13.23;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Zaid");
    strcpy(classe[count].prenom, "Abdellah");
    classe[count].date_naissance.jour = 7;
    classe[count].date_naissance.mois = 7;
    classe[count].date_naissance.annee = 2002;
    classe[count].departement = CHIMIE;
    classe[count].note = 9.87;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Bajou");
    strcpy(classe[count].prenom, "Houda");
    classe[count].date_naissance.jour = 3;
    classe[count].date_naissance.mois = 2;
    classe[count].date_naissance.annee = 2005;
    classe[count].departement = PHYSIQUE;
    classe[count].note = 10.23;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Mansouri");
    strcpy(classe[count].prenom, "Hajar");
    classe[count].date_naissance.jour = 12;
    classe[count].date_naissance.mois = 12;
    classe[count].date_naissance.annee = 2004;
    classe[count].departement = INFORMATIQUE;
    classe[count].note = 8.98;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Lazrak");
    strcpy(classe[count].prenom, "Mehdi");
    classe[count].date_naissance.jour = 8;
    classe[count].date_naissance.mois = 5;
    classe[count].date_naissance.annee = 1999;
    classe[count].departement = MATHEMATIQUES;
    classe[count].note = 11.23;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Achhab");
    strcpy(classe[count].prenom, "Rafik");
    classe[count].date_naissance.jour = 9;
    classe[count].date_naissance.mois = 8;
    classe[count].date_naissance.annee = 2003;
    classe[count].departement = CHIMIE;
    classe[count].note = 17.43;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Madani");
    strcpy(classe[count].prenom, "Mohamed");
    classe[count].date_naissance.jour = 9;
    classe[count].date_naissance.mois = 3;
    classe[count].date_naissance.annee = 1998;
    classe[count].departement = PHYSIQUE;
    classe[count].note = 12.87;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Moudi");
    strcpy(classe[count].prenom, "Mounir");
    classe[count].date_naissance.jour = 10;
    classe[count].date_naissance.mois = 11;
    classe[count].date_naissance.annee = 2001;
    classe[count].departement = INFORMATIQUE;
    classe[count].note = 16.76;
    count++;

    classe[count].id=id++;
    strcpy(classe[count].nom, "Wahbi");
    strcpy(classe[count].prenom, "Aziza");
    classe[count].date_naissance.jour = 6;
    classe[count].date_naissance.mois = 12;
    classe[count].date_naissance.annee = 2003;
    classe[count].departement = CHIMIE;
    classe[count].note = 15.76;
    count++;

}

int main(){
    remplirDonnee();
    int choix ;
    do{
        printf("---Menu---\n\n");
        printf("1- Ajouter un etudiant a l'universite\n");
        printf("2- Modifier un etudiant\n");
        printf("3- Supprimer un etudiant\n");
        printf("4- Afficher tous les etudiants\n");
        printf("5- Rechercher un etudiant\n");
        printf("6- Afficher les etudiants d'une departement\n");
        printf("7- Calculer la moyenne generale\n");
        printf("8- Afficher les statistiques\n");
        printf("9- Trier les etudiants \n");
        printf("0- Quitter \n");
        printf("\n Votre choix \n\n");
        scanf("%d", &choix);
        switch(choix){
            case 1: ajouterEtudiant();
                break;
            case 2: modifierEtudiant();
                break;
            case 3: supprimerEtudiant();
                break ;
            case 4: afficherEtudiants();
                break ;
            case 5: rechercherEtudiant();
                break;
            case 6: afficherDepartement();
                break;
            case 7: claculMoyenne();
                break;
            case 8: afficherStats();
                break;
            case 9: trierEtudiant();
                break;
            default:
                break ;
        }
    }while(choix!=0);
    return 0;
}
