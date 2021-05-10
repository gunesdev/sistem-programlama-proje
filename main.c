#include <stdio.h>
#include "fields.h"
#include "jrb.h"
#include "dllist.h"
#include "jval.h"

int main(int argc, char **argv)
{
    if( argc > 4 ) {
       printf("├──Hatali Kullanim. Fazla Parametre Girildi──├\n├──────────────Doğru Kullanim────────────├ : \n├──>$kripto -d giriş_metin cikis_metin───├\n├                   ya  da               ├\n├──>$kripto -e giriş_metin cikis_metin───├\n");
    }
    else if( argc < 4 ) {
        printf("\n├──Hatali Kullanim. Eksik Parametre Girildi──├\n├──────────────Doğru Kullanim────────────├ : \n├──>$kripto -d giriş_metin cikis_metin───├\n├                   ya  da               ├\n├──>$kripto -e giriş_metin cikis_metin───├\n");
    }
    else if( argc == 4 ) {
        printf("├──────────Girdiğiniz parametreler :  \n├           ├──%s\n├           ├──%s\n├           ├──%s\n", argv[1],argv[2],argv[3]);
     }
    return 0;
}
