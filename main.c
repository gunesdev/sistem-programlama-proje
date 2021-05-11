#include <stdio.h>
#include <stdlib.h>
#include "fields.h"
#include "jrb.h"
#include "dllist.h"
#include "jval.h"

#define MAX 505
#define MAXLINE 505

typedef struct partInfo {
    char kelime[19];
    char huffmankodu[15];
} Part;

//check file standard and exit if its out of homework requirements
static int foo(int foo) {
    FILE *fp;
    int count = 0;
    char c;  // To store a character read from file
    fp = fopen(".kilit", "r");
    if (fp == NULL) {
        printf(".Kilit Dosyasi Mevcut Degil");
        return 0;
   }
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            count = count + 1;
        }
    }
    // Close the file
    fclose(fp);
    if (count > MAXLINE) {
        return 0;
    } else {
        return count;
    }
}

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
	     /*---------------------Begin Read .Kilit -----------------------*/
	IS is;
        int i;
        int res;
        int npart = 0;
        Part part[MAX];
        Part *p = &part[npart];
        int fop=foo(1);
        JRB t, tmp;
        t = make_jrb();
        is = new_inputstruct(".kilit");
        if (is == NULL) {
            exit(1);
        }
        /*compliant with JSON data interchange syntax*/
        while (get_line(is) >= 0) {
            Part *p = &part[npart];
            for (i = 0; i < is->NF; i++) {
                if (i == 0) {
                    res = sscanf(is->fields[i],
                        " \"%18[^\"]\": ", // RFC 8259 and ECMA-404 syntax
                        p->kelime);
                } else {
                    res = sscanf(is->fields[i],
                            " \"%14[^\"]\", ", // RFC 8259 and ECMA-404 syntax
                            p->huffmankodu);
                }
            }
            if (strcmp(argv[1], "-e") == 0) {
                jrb_insert_str(t, p->kelime, new_jval_v((void *) p));
            } else {
                jrb_insert_str(t, p->huffmankodu, new_jval_v((void *) p));
            }        
            npart++;
            if (npart == MAX) {
                break; //break if it overflows due to project restrictions
            }
        }
        jettison_inputstruct(is);
	     /*---------------------End Read .Kilit -----------------------*/   
             /*---------------------Begin Encryption -----------------------*/
         if(strcmp(argv[1], "-e") == 0){
            
         }
             /*---------------------End Encryption -----------------------*/
            /*---------------------Begin Decription -----------------------*/
         else if(strcmp(argv[1], "-d") == 0){
            
         }
            /*---------------------End Decription -----------------------*/
         else{printf("├───────────────────HATA -e ya da -d girilmeli───────────────────├\n");}
     }
    return 0;
}
