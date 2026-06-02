#include <iostream>


using namespace std;

int menu(), juego();
void pantallaInicio(), limpiarConsola(), reglas();
string cualquierBoton;

int main()
{
    bool juegoActivo = true;
    system ("chcp 65001 > nul");
    pantallaInicio();
    do
    {
        switch (menu())
        {
            case 1:
                        
                break;
                    
            case 2:
                reglas();
                break;
                    
            case 3:
            juegoActivo = false;
        }
    }while (juegoActivo == true);
    

}

int menu()
{
    int opcion;
    cout << "MENU PRINCIPAL" << endl;
    cout << "\nELIGE UNA OPCION:" << endl;
    cout << "1. JUGAR" << endl;
    cout << "2. REGLAS DEL JUEGO" << endl;
    cout << "3. SALIR DEL JUEGO" << endl;
    cin >> opcion;
       
    return opcion;
}

void pantallaInicio()
{
    cout << "BATALLA NAVAL POR JENNY Y DIEGO " << endl;
    cout << R"(                                
                                                                =.                                                                  
                     ..:..-%*..                                 =.                                  
            ..*#*:.....*#+:-*++..                           .:-.=.                                  
          ...*+#=+**=:..:++=.=+*=...                        .:-.-:                                  
          ..#+=*#+++++#*:.++*:.+=*:...                    ....=.::....                              
        ..:#====#+++++++++%*#+*.-+++...                   .*%%%%%%%%..                              
        .:#+====+*+++++++++++*##+.++*-...                 .=######%%:.                              
       .-*=======#+++++++++++++++#+=*+*.....              ..-######-..                              
     ..-#========+#+++++++++++++++++*%**++=*#:..         .::=*+++=+-..                              
     .=*==========*+++++++++++++++++++++#%++===#=.     ...+@@@@@@@%%*..                             
    .:#===========+#+++++*#*#*%++++++++++++*##===*:.   .+++*********#-.                             
     ..*+==========#%%%#*++++++++++++++++++++++##**...  :********++=+-...                           
      ..=+========+*%*****%%#*+++++++++++++++++++++%+:...:*+==++++*++*#+-...                        
        .-#======*#*##**********%@#+++++++++++++++++++*%=+%*=+#%@#*++%*===+.                        
        ..:#====*****%***************##%#+++++++++++++++++*#+=+++*###**=++:...                      
          ..+++#*****#%*******************#%##*++++++++++++++*##+=+#*+******=.                      
            .-%*******%*************************#%%**++++++++++++#%#=+*#*++#+..                     
             .:%******##*******#%%%*******************#%@*+++++++++++%%===+#*:..                    
              ..+#*****%********%@%#************************#%%*++++++++*#***+*.......              
              ...-#*****%******%#%*%%****************************#%##**+**++##**+=+*=.....          
                 ..#****##*******##************************************#%%**++++**+++%###:.....     
....................+****%***************************************************#%%*++*%#....+%%*..    
#*****************###%%**#********************************************************##%%##*:-.......  
*********************+++********************############################%%%%%%%%########%@%-===++==:
*****************************************************************************************+++++++++++
****************************************************************************************************)" << endl;
cout << "INGRESE CUALQUIER BOTON: ";
cin >> cualquierBoton;
limpiarConsola();
return;
}

void limpiarConsola()
{
    cout << "\033[2J\033[1;1H";
    return;
}

void reglas()
{
    cout << "REGLAS DEL JUEGO" << endl;
    cout << "Cada jugador tiene un tablero en el que coloca sus barcos.\nLos jugadores se turnan para realizar disparos y tratar de hundir los barcos del oponente." << endl; 
    cout << "El primer jugador en hundir todos los barcos del oponente gana la partida." << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "INGRESE CUALQUIER BOTON PARA REGRESAR AL MENU: ";
    cin >> cualquierBoton;
    limpiarConsola();
    return;
}