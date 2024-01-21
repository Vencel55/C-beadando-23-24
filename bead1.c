#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>

typedef struct {
    char borregio[30];
    char termeloNev[50];
    int mennyiseg;
    char fajta[20];
} Szallitmany;

typedef struct{
    int mennyiseg;
    char fajta[20];
}Osszegzett;


int sorSzam = 0;
const char* borregiok[6] = {"BalatoniBorrégió", "DunaBorrégió", "TokajiBorvidék","PannonBorrégió","EgriBorrégió","Felső-PannonBorrégió"};
const char* borok[3] = {"Aszú","Kabar","Olaszrizling"};
Szallitmany szallitmanyok[100];
Osszegzett osszeg[3];


void Fajlbetolt(){
    FILE *f = fopen("szolo.dat", "rb");
    if (f == NULL) {
        printf("Nincs ilyen fájl így létrehozok egyet.");
        int nf = creat("szolo.dat", S_IRUSR | S_IWUSR);
        close(nf);

        f = fopen("szolo.dat", "wb");
        if (f != NULL) {
            fprintf(f, "TokajiBorvidék BorostyánPince 420 Aszú\n");
            fclose(f);
        }
        f = fopen("szolo.dat", "rb");
    }    
    while (fscanf(f, "%s %s %d %s\n", szallitmanyok[sorSzam].borregio, szallitmanyok[sorSzam].termeloNev, &szallitmanyok[sorSzam].mennyiseg, szallitmanyok[sorSzam].fajta) ==4) {
        sorSzam++;
    }

    printf("Fájl betöltése sikeres!\n");
}

void Fajlir() {
    FILE *f = fopen("szolo.dat", "w");

    for (int i = 0; i < sorSzam; i++) {
        fprintf(f, "%s %s %d %s\n", szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
    }

    fclose(f);
}

void Kilista(){
    for (int i = 0; i < sorSzam; i++) {
        printf("%d. Borrégió: %s, Termelő: %s, Mennyiség: %dKg, Fajta: %s\n", i+1, szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
    }
}

void RegioLista(){
    int valasz;
    printf("--------------------\n");
    printf("Adja meg melyik régió alapján szeretne listázni:\n");
    for (int i = 0; i < 6; i++) {
            printf("%d. %s\n", i + 1, borregiok[i]);
           
    }
    printf("7. Kilépés\n");
    scanf("%d", &valasz);

    switch (valasz) {
        case 1:
            for (int i = 0; i < sorSzam; i++) {
                if(strcmp(szallitmanyok[i].borregio, borregiok[valasz-1]) == 0){
                    printf("Borrégió: %s, Termelő: %s, Mennyiség: %dKg, Fajta: %s\n", szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
                }
            }
            break;
        case 2:
            for (int i = 0; i < sorSzam; i++) {
                if(strcmp(szallitmanyok[i].borregio, borregiok[valasz-1]) == 0){
                    printf("Borrégió: %s, Termelő: %s, Mennyiség: %dKg, Fajta: %s\n", szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
                }
            }
            break;
        case 3:
           for (int i = 0; i < sorSzam; i++) {
                if(strcmp(szallitmanyok[i].borregio, borregiok[valasz-1]) == 0){
                    printf("Borrégió: %s, Termelő: %s, Mennyiség: %dKg, Fajta: %s\n", szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
                }
            }
            break;
        case 4:
           for (int i = 0; i < sorSzam; i++) {
                if(strcmp(szallitmanyok[i].borregio, borregiok[valasz-1]) == 0){
                    printf("Borrégió: %s, Termelő: %s, Mennyiség: %dKg, Fajta: %s\n", szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
                }
            }
            break;
        case 5:
            for (int i = 0; i < sorSzam; i++) {
                if(strcmp(szallitmanyok[i].borregio, borregiok[valasz-1]) == 0){
                    printf("Borrégió: %s, Termelő: %s, Mennyiség: %dKg, Fajta: %s\n", szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
                }
            }
            break;
        case 6:
            for (int i = 0; i < sorSzam; i++) {
                if(strcmp(szallitmanyok[i].borregio, borregiok[valasz-1]) == 0){
                    printf("Borrégió: %s, Termelő: %s, Mennyiség: %dKg, Fajta: %s\n", szallitmanyok[i].borregio, szallitmanyok[i].termeloNev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
                }
            }
            break;
        default:
            printf("Kilépés.\n");
    }
}

void listaMenu(){   
    printf("--------------------\n");
    printf("Adja meg mi szerint szeretne listázni:\n");
    printf("1. Teljes lista\n2. Borrégióra osztott lista\n");
    int menuvalasz;
    scanf("%d", &menuvalasz);
    
    switch (menuvalasz) {
        case 1:
            Kilista();
            break;
        case 2:
            RegioLista();
            break;
        default:
            printf("Kilépés.\n");
    }
}

void Modositas(){
    int index;
    int menuvalasz;
    int valasztott;

    printf("--------------------\n");
    Kilista();
    printf("--------------------\n");

    for (;;) {
        printf("Adja meg melyik szállítmányt szeretné módosítani (1-%d): ", sorSzam);
        scanf("%d", &index);

        index--; // Nullás kezdés miatt

        if (index >= 0 && index < sorSzam-1) {
            break;
        }

        printf("Nem megfelelő sorszám, adjon meg másikat.\n");
    }

    //index--;
    printf("--------------------\n");
    printf("Adja meg mit kíván módosítani:");
    printf("\n1. Borrégió \n2. Termelő\n3. Mennyiség \n4. Fajta \n5. Kilépés\n");
    scanf("%d", &menuvalasz);
    switch (menuvalasz) {
        case 1:
            for (;;) {
                printf("Borvidék sorszáma:\n");
                for (int i = 0; i < 6; i++) {
                    printf("%d. %s\n", i + 1, borregiok[i]);
                }
                scanf("%d", &valasztott);

                if (valasztott > 1 || valasztott < 6) {
                    break;
                }

                printf("Nem megfelelő sorszám, adjon meg másikat.\n");
            }   

            strcpy(szallitmanyok[index].borregio, borregiok[valasztott - 1]);
            //szallitmanyok[index].borregio = borregiok[valasztott - 1];

            printf("Adat módosítva.\n");
            break;
        case 2:
            printf("--------------------\n");
            printf("Új termelő neve(Szóköz nélkül):\n");
            scanf(" %s", szallitmanyok[index].termeloNev);//[^\n]
            printf("Adat módosítva.\n");
            break;
        case 3:
            printf("--------------------\n");
            printf("Új mennyiség:\n");
            scanf("%d", &szallitmanyok[index].mennyiseg);
            printf("Adat módosítva.\n");       
            break;
        case 4:
            printf("--------------------\n");
            printf("Új szőlőfajta:\n");
            printf("Adja meg a szőlőfajtát:\n1. Aszú\n2. Kabar\n3. Olaszrizling\n");
            int a;
            for (;;) {         
                scanf("%d", &a);

                if (a > 1 || a < 3) {
                break;
                }
                printf("Nem megfelelő sorszám, adjon meg másikat.\n");
            }
            char aszu[]="Aszú";
            char kabar[]="Kabar";
            char olasz[]="Olaszrizling";
            //szallitmanyok[index].fajta
            switch(a){
                case 1:
                    strcpy(szallitmanyok[index].fajta,borok[a - 1]);
                    break;
                 case 2:
                    strcpy(szallitmanyok[index].fajta, borok[a - 1]);
                    break;
                 case 3:
                    strcpy(szallitmanyok[index].fajta, borok[a - 1]);
                    break;    
            }
            
            printf("Adat módosítva.\n");
            break;
        default:
            printf("Kilépés.\n"); 
    }
}

void UjSzallitmany(){
    int index;
    printf("--------------------\n"); 
    printf("Válasszon borrégiót:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d %s \n", i+1, borregiok[i]);
    }
    for (;;) {         
        scanf("%d", &index);

        if (index > 1 || index < 3) {
            break;
        }
        printf("Nem megfelelő sorszám, adjon meg másikat.\n");
    }

    strcpy(szallitmanyok[sorSzam].borregio, borregiok[index - 1]);

    printf("Adja meg a termelő nevét: ");
    scanf("%s", szallitmanyok[sorSzam].termeloNev);
    printf("Adja meg az átvett mennyiséget: ");
    scanf("%d", &szallitmanyok[sorSzam].mennyiseg);
    printf("Adja meg a szőlőfajtát:\n1. Aszú\n2. Kabar\n3. Olaszrizling\n");
    int b;
    for (;;) {         
        scanf("%d", &b);

        if (b > 1 || b < 3) {
            break;
        }
        printf("Nem megfelelő sorszám, adjon meg másikat.\n");
    }
    strcpy(szallitmanyok[sorSzam].fajta, borok[b - 1]);

    sorSzam++;    
    printf("Új adat hozzáadva.\n");
}

void Torles(){
    int index=1;
    int torlendo;

    FILE *ideiglenesFile = fopen("ideiglenes.txt","w");
    FILE *f = fopen("szolo.dat", "rb");
    if(ideiglenesFile == NULL ||f == NULL){
        printf("Fájl hiba!");
        exit(1);
    }

    //rewind(f);

    printf("--------------------\n");
    Kilista();
    printf("--------------------\n");
    printf("Adja meg a törlendő szállítmány sorszámát!");
    scanf("%d", &torlendo);

    // for(int i = 0; i<sorSzam;i++){
    //     if(i!=torlendo){
    //         fscanf(f, "%s %s %d %s", borregio, termeloNev, &mennyiseg, fajta);

    //         fprintf(ideiglenesFile, "%s %s %d %s\n",borregio,termeloNev,mennyiseg,fajta);

    //     }
    // }

    while (fscanf(f, "%s %s %d %s", szallitmanyok[index].borregio, szallitmanyok[index].termeloNev, &szallitmanyok[index].mennyiseg, szallitmanyok[index].fajta)==4) {
        
        if (index != torlendo) {
             fprintf(ideiglenesFile, "%s %s %d %s\n",szallitmanyok[index].borregio,szallitmanyok[index].termeloNev,szallitmanyok[index].mennyiseg,szallitmanyok[index].fajta);
        }
        index++;
    }

    fclose(f);
    fclose(ideiglenesFile);

    remove("szolo.dat");
    rename("ideiglenes.txt", "szolo.dat");

    printf("A sor sikeresen törölve.\n");
}

// bool OsszegContains(char sz[20]){
//     bool result = false;
//     for(int i = 0; i<sorSzam; i++){
//         if (strcmp(osszeg[i].fajta, sz) == 0) {
//             result = true;
//             printf("asdasd");
//         }
//     }
//     return result;
// }

// void Csoportosit(){
//     memset(osszeg, 0, sizeof(osszeg)); //nulláz
//     char asd[] = "Aszú";
//     strcpy(osszeg[1].fajta,asd);
    
//     for(int i = 0; i < sorSzam; i++) {
//         if(OsszegContains(szallitmanyok[i].fajta)){
//             for(int j =0; j<sorSzam;j++){
//                 if(strcmp(szallitmanyok[i].fajta, osszeg[j].fajta)==0){
//                     osszeg[j].mennyiseg += szallitmanyok[i].mennyiseg;
//                 }
//             }
//         }        
//         else{
//             int meret = sizeof(osszeg) / sizeof(osszeg[0]);
//             strcpy(osszeg[meret+1].fajta, szallitmanyok[i].fajta);
//             osszeg[meret].mennyiseg += szallitmanyok[i].mennyiseg;
//         }  
//     }

//     for (int i = 0; i < 5; i++) {
//             printf("Fajta: %s, Mennyiseg: %d\n", osszeg[i].fajta, osszeg[i].mennyiseg);
//     }
// }

void kuldesHandler(int signumber){
  printf("Gyerek készen áll, kód: %i\n",signumber);
}

void fogadasHandler(int signumber){
  printf("Adatokat megkaptam(gyerek), kód: %i\n",signumber);
}

double randomBetween06And08() {
    srand(time(NULL));
    double randomValue = (double)rand() / RAND_MAX;
    double scaledValue = 0.6 + randomValue * 0.2;

    return scaledValue;
}

void Feldolgozas(){
    int pipeKuld[2];
    int pipefogad[2];
    int aszu=0;
    int kabar=0;
    int olasz=0;
    int min= 100;
    bool ures = true;

    printf("Feldolgozás elkeződött!\n");

    if (pipe(pipeKuld) == -1) 
	{
        perror("Hiba a pipe nyitaskor!\n");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipefogad) == -1) 
	{
        perror("Hiba a pipe nyitaskor!\n");
        exit(EXIT_FAILURE);
    }
    
    pid_t  child=fork();

    if (child<0){perror("A fork hívás nem sikerült.\n"); exit(EXIT_FAILURE);} //hiba

    

    if(child>0){
        //parent
        //feldolgoz
        for(int i=0; i<sorSzam;i++){
            if(strcmp(szallitmanyok[i].fajta,borok[0])==0){
                aszu+=szallitmanyok[i].mennyiseg;
            }
            if(strcmp(szallitmanyok[i].fajta,borok[1])==0){
                kabar+=szallitmanyok[i].mennyiseg;
            }
            if(strcmp(szallitmanyok[i].fajta,borok[2])==0){
                olasz += szallitmanyok[i].mennyiseg;
            }
        }

        strcpy(osszeg[0].fajta,borok[0]);
        strcpy(osszeg[1].fajta,borok[1]);
        strcpy(osszeg[2].fajta,borok[2]);

        if(aszu>=min){         
            osszeg[0].mennyiseg=aszu;
        }
        else{
            osszeg[0].mennyiseg=0;
        }
        if(kabar>=min){           
            osszeg[1].mennyiseg=kabar;
        }
        else{
            osszeg[1].mennyiseg=0;
        }
        if(olasz>=min){       
            osszeg[2].mennyiseg=olasz;
        }
        else{
            osszeg[2].mennyiseg=0;
        }

        for (int i = 0; i < 3; ++i) {
            if (osszeg[i].mennyiseg != 0) {
                ures = true;
                break; 
            }
            else{
                ures = false;
            }
        }

        if (!ures) {
            kill(child,SIGKILL);
            printf("Nincs elég szőlő!\n");
            exit(1);
        } 

        printf("Adatok feldolgozva!(szülő)\n");

        pause();//signal fogad

        printf("Adatok elküldve!(szülő)\n");
        close(pipeKuld[0]);
        write(pipeKuld[1],osszeg,sizeof(Osszegzett) * 3);//pipe megy
        close(pipeKuld[1]);
        fflush(stdout);


        pause();//signal fogad
        Osszegzett kiiras[3];
        close(pipefogad[1]);
        read(pipefogad[0],kiiras,sizeof(Osszegzett) * 3);//pipefogad

        //vegeredmeny
        sleep(1);
        for (int i = 0; i < 3; ++i) {
            if(kiiras[i].mennyiseg !=0){
                printf("Szülőfolyamat - Adatok: Mennyiség: %i, Fajta: %s\n", kiiras[i].mennyiseg, kiiras[i].fajta);
            }
             
        }
        close(pipefogad[0]);
        fflush(stdout);
    }
    else{
        //child
        sleep(1);
        kill(getppid(),SIGUSR1);//signal kuld
        Osszegzett vegeredmeny[3];
        strcpy(vegeredmeny[0].fajta,borok[0]);
        strcpy(vegeredmeny[1].fajta,borok[1]);
        strcpy(vegeredmeny[2].fajta,borok[2]);
        int osszSzolo;

        close(pipeKuld[1]);
        Osszegzett receivedData[3];
        read(pipeKuld[0], receivedData, sizeof(Osszegzett) * 3);//pipee fogad
        close(pipeKuld[0]);
        fflush(stdout);

        for (int i = 0; i < 3; ++i) {
            printf("Gyerekfolyamat - Adatok: Mennyiség: %i, Fajta: %s\n", receivedData[i].mennyiseg, receivedData[i].fajta);
        }

        sleep(2);
        kill(getppid(),SIGUSR2);//signal kuld

        //feldolgoz
        double randomResult = randomBetween06And08();
        printf("Szőlő minősége: %lf\n", randomResult);

        for(int i=0;i<3;i++){
            if(receivedData[i].mennyiseg!=0){
                osszSzolo = receivedData[i].mennyiseg * randomResult;
                if(strcmp(receivedData[i].fajta,borok[0])==0){
                    vegeredmeny[0].mennyiseg = osszSzolo;
                }
                if(strcmp(receivedData[i].fajta,borok[1])==0){
                    vegeredmeny[1].mennyiseg = osszSzolo;
                }
                if(strcmp(receivedData[i].fajta,borok[2])==0){
                    vegeredmeny[2].mennyiseg = osszSzolo;
                }
            }
            else{
                vegeredmeny[i].mennyiseg = 0;
            }
            osszSzolo = 0;     
        }

        close(pipefogad[0]);
        write(pipefogad[1],vegeredmeny,sizeof(Osszegzett) * 3);//pipe kuld
        close(pipefogad[1]);   
        fflush(stdout);
    }
}


void Menu(int valasz){
    switch (valasz) {
        case 1:
            listaMenu();
            break;
        case 2:
            UjSzallitmany();
            Fajlir();
            break;
        case 3:
            Modositas();
            Fajlir();
            break;
        case 4:
            Torles();
            break;
        case 5:
            Feldolgozas();
            break;    
        default:
            printf("Kilépés.\n");
    }
}

int main(){
    signal(SIGUSR1,kuldesHandler);
    signal(SIGUSR2,fogadasHandler);

    int valasz;
    Fajlbetolt();

    printf("Válasszon egyet a lehetőseg közül!");
    printf("\n1. Szállítmany adatok listázása\n2. Új szállítmány hozzáadása\n3. Szállítmany adat módosítása\n4. Szállítmany adat törlése\n5. Csoportosít \n6. Kilépés\n");
    scanf("%d", &valasz);
    Menu(valasz);
    return 0;
}