#ifndef APP_H
#define APP_H
#include <iostream>
#include <string.h>
using namespace std;

class App
{
    char *cat, *nume;
    public:
        App(char *, char*);
        App(const App&);
        friend ostream& operator<<(ostream&,const App&);
        friend istream& operator>>(istream&,App&);
        void setnume(char*);
        void setcat(char*);
        char *getnume() const;
        char *getcat() const;
        virtual ~App();

    protected:

    private:
};

#endif // APP_H