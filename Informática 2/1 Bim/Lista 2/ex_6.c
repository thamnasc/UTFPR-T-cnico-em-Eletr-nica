#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MI_VE 1
#define MA_VE 1000
#define MI_LIG 1
#define MA_LIG 1000000
#define MI_DURA 1
#define MA_DURA 30

    typedef struct vends {
        int id;
        int temp_lig;
        int qt_lig;
    } vends;

    inline int comp_temp(const vends a, const vends b){
        return a.temp_lig < b.temp_lig;
    }

    inline int comp_id(const vends a, const vends b){
        return a.id < b.id;
    }

    void insertion_sort( vends arr[], int ue, int (*nsei)(const vends, const vends)){

        int i, k;
        vends at;
        for (i = 1; i < ue; i++){
            at = arr[i];
            for (k = i - 1; k >= 0 && nsei(at, arr[k]); k-- ){
                arr[k + 1] = arr[k];
            }
            arr[k + 1] = at;
        }
    }

    int main() {
        int i, k;
        int dur;
        int qt_vend;
        int qt_lig;
        int assci1, assci2, assci3;
        vends *vend = NULL;
        vends fir;
        fprintf(stdout, "Insira a quantidade de vendedores e de liga%c%ces a serem feitas: ", assci1 = 135, assci2 = 228);
        fscanf(stdin,"%d", &qt_vend);

            if(qt_vend >= MI_VE && qt_vend <= MA_VE){
                vend = (vends *) malloc(sizeof(vends) * qt_vend);
                if (vend == NULL) {
                    fputs("Erro na alocacao!\n", stderr);
                    exit(1);
                }

                else{
                    for (i = 0; i < qt_vend; i++) {
                        vend[i].id = i;
                        vend[i].temp_lig = 0;
                        vend[i].qt_lig = 0;

                    }
                }

            }
            else {

                fprintf(stderr, "O numero de vendedores deve estar entre %d e %d!\n", MI_VE, MA_VE);
                exit(1);
            }

        fscanf(stdin, "%d", &qt_lig);
        fprintf(stdout, "\nInsira a dura%c%co de cada liga%c%co: ", assci1 = 135, assci3 = 198, assci1, assci3);
        for (i = 0; i < qt_lig && i < qt_vend; i++){

            fscanf(stdin, "%d", &dur);
            vend[i].temp_lig += dur;
            vend[i].qt_lig++;

        }

        if ( i < qt_lig){

            insertion_sort(vend, qt_vend, comp_temp);

            for (; i < qt_lig; i++){

                fscanf(stdin, "%d", &dur);
                vend[0].temp_lig += dur;
                vend[0].qt_lig++;
                fir = vend[0];

                for (k = 1; k < qt_vend && fir.temp_lig > vend[k].temp_lig; k++){

                    vend[k - 1] = vend[k];
                }
                vend[k - 1] = fir;
            }
        }
        insertion_sort(vend, qt_vend, comp_id);

        printf("\n\nId\tLiga%c%ces\n\n", assci1 = 135, assci2 = 228);

        for (i = 0; i < qt_vend; i++){
            fprintf(stdout, "%d\t%d\n", vend[i].id + 1, vend[i].qt_lig);
        }

        printf("\n\nPressione qualquer tecla para continuar. . . ");
        getch();

        return 0;
    }
