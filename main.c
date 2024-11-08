#include<stdio.h>


enum sexe {H,F};
struct contact_details
{
  int id;
  char surname[50];
  char name[50];
  char address[50];
  enum sexe;
  char telnumber[10];
};

/*

struct contact{
  struct contact_details **next;

};

struct carnet_address{
  struct contact *head;

};
*/

void contact_afficher(const struct contact_details* a){
  printf("Le contact est :\n Nom : %s \n Prénom : %s \n Adresse : %s \n Sexe : %s \n Tel : %s ",a->surname, a->name, a->address, a->sexe, a->telnumber);
}


struct contact_details contact_saisir(struct contact_details *a){
  a->id =  12;
  printf("Saisir le nom du contact : ");
  scanf("%s", a->surname);
  printf("Saisir le prénom du contact : ");
  scanf("%s", a->name);
  printf("Saisir l'adresse du contact : "); //fgets pour les chaines de caractére avec des espaces
  scanf("%s", a->address);
  printf("Saisir le sexe du contact (H/F): ");
  scanf("%d", a->sexe);
  printf("Saisir le numéro de téléphone du contact : ");
  scanf("%s", a->telnumber);

  return *a;

}


int main(int argc, char *argv[]){
  struct contact_details c1;
  contact_saisir(&c1);
  contact_afficher(&c1);
  return 0;

}
