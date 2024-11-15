#include<stdio.h>

#define MAX_CONTACTS 100

typedef enum {H,F}sexe;


struct contact_details
{
  int id;
  char surname[50];
  char name[50];
  char address[50];
  sexe typesexe;
  char telnumber[10];
  struct contact_details *next;
};



struct contact{
  struct contact *next;
  struct contact_details *value;
};

struct pool{
  struct contact *available_head;
  struct contact *used_head;
};


void contact_afficher(const struct contact_details* contact){
  printf("Le contact est :\n Nom : %s \n Prénom : %s \n Adresse : %s \n Sexe : %s \n Tel : %s\n ID : %d ",contact->surname, contact->name, contact->address, contact->typesexe == H ? "Homme" : "Femme", contact->telnumber,contact->id); 
}
void pool_switch(struct contact* contact_add, struct contact *contact_head){
  if (contact_add == NULL|| contact_head == NULL){
    return ;
  }
  contact_add->next = contact_head->next;
  contact_head->next = contact_add;
}


void contact_saisir(struct contact_details* contact, struct pool *carnet){
  if (contact == NULL || carnet == NULL){
    return;
  }

  char sexe_temp[2];

  printf("Saisir le nom du contact : ");
  scanf("%s", contact->surname);

  printf("Saisir le prénom du contact : ");
  scanf("%s", contact->name);

  printf("Saisir l'adresse du contact : "); //fgets pour les chaines de caractére avec des espaces
  scanf("%s", contact->address);
  //fgets(contact->address, sizeof(int), stdin);
  printf("Saisir le sexe du contact (H/F) : ");
  scanf("%s", sexe_temp);
  if (sexe_temp[0] == 'H' || sexe_temp[0] == 'h') {
    contact->typesexe = H;
  } 
  else if (sexe_temp[0] == 'F' || sexe_temp[0] == 'f') {
    contact->typesexe = F;
  }
  printf("Saisir le numéro de téléphone du contact : ");
  scanf("%s", contact->telnumber);

  //pool_switch(contact,carnet);

}


int main(int argc, char *argv[]){
  struct contact_details pool_available[MAX_CONTACTS]={};

  struct contact_details cd1;
  struct contact c1 = {NULL, &cd1};
  struct pool carnet = {&c1,NULL};

  //struct pool Used;
  contact_saisir(&cd1, &carnet);
  contact_afficher(carnet.available_head->value);
  
  return 0;

}
