#include <iostream>
#include <cstring>
#include <fstream>
#include "App.cpp"
using namespace std;

/*Sistem pentru gestionarea aplicațiilor
Aplicația permite vizualizarea unui catalog de aplicații per categorii. Utilizatorul poate instala
aplicațiile dorite și ulterior le poate vizualiza per categorii (exemplu: Entertainment, Social,
Productivity etc.). Utilizatorul poate dezinstala aplicațiile de care nu mai are nevoie. Totodată, acesta
are acces la statistici despre numărul de aplicații instalate per categorie. La începutul aplicației,
utilizatorul trebuie înregistrat pentru a avea acces la aplicațiile sale și la catalog.*/

void meniu();
void login();
void meniulogin(char[]);
void registrare();
void install(char[],App**,int&);
void uninstall(char[],App**,int&);
void stat(char[],App **,int &);
void installapp(char[],char[],App**,int&);
App** add(App**,int&,char[],char[]);
App** removeapp(App**,int&,int);
void save(char[],App**,int&);
int verf,contornuser=0;

void meniu(){
    int opt;
    opt=3;
    while(opt!=0){
        cout<<"Bine ati venit! Selectati o optiune din urmatoarele:"<<endl;
        cout<<"1. Logare"<<endl<<"2. Registrare"<<endl<<"0. Iesire"<<endl<<"Introduceti optiunea dorita:";
        cin>>opt;
        if(opt==1){
            system("clear");
            login();
        }
        if(opt==2){
            system("clear");
            registrare();
        }
        if(opt==0){
            system("clear");
            cout<<"La revedere"<<endl;
            exit(0);
        }
        if(opt!=0 && opt!=1 && opt!=2){
            system("clear");
            cout<<"Ati introdus o optiune gresita! Incercati inca odata:"<<endl;
        }

    };
}

void login(){
    char nume[100],prenume[100],path[500];
    bool open=false;
         cout<<"Introduceti numele si prenumele dvs. pentru logare!"<<endl;
            while(!open){
            cout<<"Nume:";
            cin>>nume;
            cin.ignore();
            cout<<"Prenume:";
            cin>>prenume;
            cin.ignore();
            strcpy(path,"util/");
            strcat(path,nume);
            strcat(path," ");
            strcat(path,prenume);
            strcat(path,".txt");
            ifstream util(path);
                if(util){
                    system("clear");
                    open=true;
                    util.close();
                    cout<<"Logare reusita!"<<endl<<"Selectati o optiune din urmatoarele:"<<endl;
                    meniulogin(path);


                }else{
                    cout<<"Utilizatorul nu a fost gasit! Incercati inca odata!"<<endl;
                }
            };

}
void meniulogin(char path[]){
    int n, opt=-1;
    char a[101],b[101];
    ifstream util(path);
    util>>n;
    contornuser = n;
    App **user=new App*[n];
    for(int i=0;i<n;i++){
            util>>a;
            util>>b;
        user[i]=new App(a,b);
    }
    util.close();
    while(opt!=0){
        cout<<"1. Instalare"<<endl<<"2. Deinstalare"<<endl<<"3. Statistica"<<endl<<"0. Inapoi"<<endl<<"Introduceti optiunea dorita:";
        cin>>opt;
        if(opt==0){
            system("clear");
            meniu();
        }
        if(opt==1){
            system("clear");
            install(path,user,n);
        }
        if(opt==2){
            system("clear");
            uninstall(path,user,n);
        }
        if(opt==3){
            system("clear");
            stat(path,user,n);
            system("clear");
        }
        if(opt!=0 && opt!=1 && opt!=2 && opt!=3){
            system("clear");
            cout<<"Ati introdus o optiune gresita! Incercati inca odata:"<<endl;
        }

    };
}


void registrare(){
    char nume[100],prenume[100],path[500];
        cout<<"Introduceti numele si prenumele dvs. pentru inregistrare!"<<endl;
            cout<<"Nume:";
            cin>>nume;
            cout<<"Prenume:";
            cin>>prenume;
            cin.ignore();
            strcpy(path,"util/");
            strcat(path,nume);
            strcat(path," ");
            strcat(path,prenume);
            strcat(path,".txt");
            ifstream util(path);
            if(util){
                system("clear");
                cout<<"Utilizator deja inregistrat!"<<endl;
            }
            else{
                util.close();
                ofstream util(path);
                util<<0;
                util.close();
                system("clear");
                cout<<"Registrare reusita!"<<endl;
            }
}


void install(char path[],App **user,int &nuser){
    cout<<"Ati selectat instalare! ";
    int opt=-1;
    while(opt!=0){
        cout<<"Selectati o categorie:"<<endl<<"1. Economic"<<endl<<"2. Entertainment"<<endl<<"3. Learning"<<endl<<"4. Social-Media"<<endl<<"0. Inapoi"<<endl;
        cout<<"Introduceti optiunea dorita:";
        cin>>opt;
        if(opt==1){
            system("clear");
            installapp(path,(char*)"Economic",user,nuser);
        }
        if(opt==2){
            system("clear");
            installapp(path,(char*)"Entertainment",user,nuser);
        }
        if(opt==4){
            system("clear");
          installapp(path,(char*)"Social-Media",user,nuser);
        }
        if(opt==3){
            system("clear");
            installapp(path,(char*)"Learning",user,nuser);
        }
        if(opt==0){
            system("clear");
            meniulogin(path);
        }
        if(opt!=0 && opt!=1 && opt!=2 && opt!=3 && opt!=4){
            system("clear");
            cout<<"Ati introdus o optiune gresita! Incercati inca odata:"<<endl;
        }
    }
    system("clear");


}
void installapp(char path[],char cat[],App **user,int &nuser){
    nuser = contornuser;
    char pathcat[500],a[101];
    int opt=-1,n;
    strcpy(pathcat,"catalog/");
    strcat(pathcat,cat);
    strcat(pathcat,".txt");
    ifstream catf(pathcat);
    catf>>n;
    char **cats=new char*[n];
    for(int i=0;i<n;i++){
        catf>>a;
        cats[i]=new char[strlen(a)+1];
        strcpy(cats[i],a);
    }
    catf.close();
    while(opt!=0){
        cout<<"Selectati o optiune din urmatoarele:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<". "<<cats[i]<<endl;
        }
        cout<<"0. Inapoi"<<endl;
        cout<<"Introduceti optiunea dorita:";
        cin>>opt;
        if(opt == 0) {
            system("clear");
            install(path,user,n);
        }
        if(opt!=0 && opt!=1 && opt!=2 && opt!=3 && opt!=4){
            system("clear");
            cout<<"Ati introdus o optiune gresita! Incercati inca odata:"<<endl;
        }else{
            App **auxx=new App*[0];
            auxx[0]=new App(cats[n-1],cat);
            user=add(user,nuser,cat,cats[opt-1]);
            save(path,user,nuser);
            system("clear");
            if(verf == 1) {
                cout<<"Aplicatia este deja instalata."<<endl;
            }
            else {
                cout<<"Aplicatia s-a instalat cu succes."<<endl;
            }
        }
        install(path,user,nuser);
    }

}

void uninstall(char path[],App **user,int &nuser){
    int opt=-1,k=1;
    while(opt!=0){
        k=1;
        for(int i=0;i<nuser;i++){
            cout<<k<<". "<<*user[i]<<endl;
            k++;
        }
        cout<<"0. Iesire"<<endl;
        cout<<"Introduceti optiunea dorita:"<<endl;
        cin>>opt;
        if(opt!=0 && opt<=nuser){
            user=removeapp(user,nuser,opt);
            save(path,user,nuser);
            system("clear");

        }

        else if(opt>nuser){
                system("clear");
            cout<<"Ati introdus o optiune gresita! Incercati inca odata!"<<endl;
        }

    }
    if(opt == 0) {
        system("clear");
        meniulogin(path);
    }

}

void stat(char path[],App **user,int &nuser){
    int opt = -1;
    while(opt != 0) {
        int a=0,b=0,c=0,d=0;
        cout<<endl;
        cout<<"Economic:"<<endl;
        for (int i = 0; i < nuser; i++) {
            if (strcmp(user[i]->getcat(),"Economic") == 0) {
                cout << user[i]->getnume() << " "<<endl;
                a++;
            }
        }
        cout<<endl;
        cout<<"Entertainment:"<<endl;
        for (int i = 0; i < nuser; i++) {
            if (strcmp(user[i]->getcat(),"Entertainment") == 0) {
                cout << user[i]->getnume() << " "<<endl;
                b++;
            }
        }
        cout<<endl;
        cout<<"Learninig:"<<endl;
        for (int i = 0; i < nuser; i++) {
            if (strcmp(user[i]->getcat(),"Learning") == 0) {
                cout << user[i]->getnume() << " "<<endl;
                c++;
            }
        }
        cout<<endl;
        cout<<"Social-Media:"<<endl;
        for (int i = 0; i < nuser; i++) {
            if (strcmp(user[i]->getcat(),"Social-Media") == 0) {
                cout << user[i]->getnume() << " "<<endl;
                d++;
            }
        }
        cout<<endl;
        cout<<"Numarul de aplicatii din categoria Economic: " << a <<endl;
        cout<<"Numarul de aplicatii din categoria Entertainment: " << b <<endl;
        cout<<"Numarul de aplicatii din categoria Learning: " << c <<endl;
        cout<<"Numarul de aplicatii din categoria Social-Media: " << d <<endl;
        cout<<endl;
        cout<<"0.Inapoi"<<endl;
        cin>>opt;
        system("clear");
        if(opt == 0) {
            system("clear");
            meniulogin(path);
        }
    }
}

App** add(App **user,int &nuser, char cat[],char catnume[]){
    verf = 0;
    App **aux=new App*[nuser+1];
    aux[0]=new App(catnume,cat);
    for(int i=0;i<nuser;i++){
        if(strcmp(aux[0]->getnume(), user[i]->getnume())==0) {
            verf = 1;
            return user;
        }
    }
    for(int i=0;i<nuser;i++){
        aux[i]=new App(*user[i]);
    }
    for(int i=0;i<nuser;i++){
        delete user[i];
    }
    delete[]user;
    nuser++;
    aux[nuser-1]=new App(catnume,cat);
    contornuser++;
    return aux;
}


App** removeapp(App **user,int &nuser, int opt){
    for(int i = opt-1; i<nuser; i++){
        user[i] = user[i+1];
    }
    nuser--;
    return user;
}

void save(char path[],App **user,int &nuser){
    ofstream outf(path);
    outf<<nuser<<endl;
    for(int i=0;i<nuser;i++){
        outf<<user[i]->getnume()<<" "<<user[i]->getcat()<<endl;
    }
    outf.close();
}


int main()
{
    meniu();
    return 0;
}