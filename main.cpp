#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

using namespace std;

void get_package_name(char * argv1 , string * pkg_n){
    FILE * mainpkg = fopen(argv1 , "r") ;
    char ch ; char cro[20] ; int i= 0 ;
    while ((ch = getc(mainpkg)) != ';')
    {
        cro[i] = ch ;
        i++ ;

   }
    cro[i] = '\0' ;
    fclose(mainpkg);
    string whole_name (cro) ;
    size_t pos = whole_name.find("package");
    string pkg_ns = whole_name.substr(pos + 8);
    size_t pos_space = pkg_ns.find(" ");
    *pkg_n = pkg_ns.substr(0, pos_space);
}



void exec_process(string cmd){
        system(cmd.c_str()) ;

}

int main(int argc, char* argv[])
{
    string  command = "javac -d . " ;
    string command2 ;

    for (int i=1 ; i<argc ; i++){

        command = command + argv[i] + " " ;

    }
    string argv1(argv[1]) ;
    size_t java =  argv1.find(".java") ;
    string main_class_name = argv1.substr(0,java) ;
    string package_name ;
    get_package_name(argv[1] , &package_name);
    exec_process(command);
    command2 = "java " + package_name + "." + main_class_name ;
    exec_process(command2);
    return 0;
}
