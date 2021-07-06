#include "App.h"

App::App(char *nume,char *cat)
{

    this->nume=new char[strlen(nume)+1];
    this->cat=new char[strlen(cat)+1];
    strcpy(this->nume,nume);
    strcpy(this->cat,cat);
}
char *App::getnume() const{
    return this->nume;
}
char *App::getcat() const{
    return this->cat;
}
App::App(const App&a){
    this->nume=new char[strlen(a.nume)+1];
    this->cat=new char[strlen(a.cat)+1];
    strcpy(this->nume,a.nume);
    strcpy(this->cat,a.cat);
}
ostream& operator <<(ostream &os,const App&a){
    os<<"Nume="<<a.nume<<" Categorie="<<a.cat;
    return os;
}
void App::setnume(char *nume){
    if(this->nume!=nullptr){
        delete[] this->nume;
    }
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}
void App::setcat(char *cat){
    if(this->cat!=nullptr){
        delete[] this->cat;
    }
    this->cat=new char[strlen(cat)+1];
    strcpy(this->cat,cat);
}
istream& operator>>(istream& si ,App&a){
    si>>a.nume>>a.cat;
    return si;

}
App::~App()
{
    delete[] nume;
    delete[]cat;
}
