#include<stdio.h>


enum sexe {H,F};
struct contact_details
{
  int id;
  char surname[50];
  char name[50];
  char address[50];
  char sexe[1];
  char telnumber[10];
};

/*

struct contact{
  struct contact *next;
  struct contact_details value;

};

struct carnet_address{
  struct contact *head;

};
*/

void contact_afficher(const struct contact_details* contact){
  printf("Le contact est :\n Nom : %s \n Prénom : %s \n Adresse : %s \n Sexe : %s \n Tel : %s ",contact->surname, contact->name, contact->address, contact->sexe, contact->telnumber);
}


struct contact_details contact_saisir(struct contact_details* contact){
  contact->id =  12;
  printf("Saisir le nom du contact : ");
  scanf("%s", contact->surname);
  printf("Saisir le prénom du contact : ");
  scanf("%s", contact->name);
  printf("Saisir l'adresse du contact : "); //fgets pour les chaines de caractére avec des espaces
  scanf("%s", contact->address);
  printf("Saisir le sexe du contact (H/F) : ");
  scanf("%s", contact->sexe);
  printf("Saisir le numéro de téléphone du contact : ");
  scanf("%s", contact->telnumber);

  return *contact;

}


int main(int argc, char *argv[]){
  struct contact_details c1;
  contact_saisir(&c1);
  contact_afficher(&c1);
  return 0;

}
