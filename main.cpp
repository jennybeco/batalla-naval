#include <iostream>


using namespace std;

int menu(), juego();
void pantallaInicio(), limpiarConsola(), reglas();

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
    cout << "MENU" << endl;
    cout << "BATALLA NAVAL" << endl;
    cout << "BY DIEGO & JENNY" << endl;
    cout << "\nElige una opción:" << endl;
    cout << "\n1. JUGAR" << endl;
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
cout << "PRESIONE ENTER: ";
cin.get();
limpiarConsola();
return;
}

void limpiarConsola()
{
    cout << "\033[2J\033[1;1H";
    return;
     switch (opcion)
        {
            case 1:
                
                break;
            
            case 2:
                cout << "REGLAS DEL JUEGO" << endl;
                cout << "Cada jugador tiene un tablero en el que coloca sus barcos.\nLos jugadores se turnan para realizar disparos y tratar de hundir los barcos del oponente." << endl; 
                cout << "El primer jugador en hundir todos los barcos del oponente gana la partida. " << endl;
                cout << "BY DIEGO & JENNY" << endl;
                cout << "\nElige una opción:" << endl;
                break;
            
            case 3:
                break;
        }
    return 0;
}

void reglas()
{
    cin.ignore();
    cout << "REGLAS DEL JUEGO" << endl;
    cout << "Cada jugador tiene un tablero en el que coloca sus barcos.\nLos jugadores se turnan para realizar disparos y tratar de hundir los barcos del oponente." << endl; 
    cout << "El primer jugador en hundir todos los barcos del oponente gana la partida." << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "PRESIONE ENTER PARA REGRESAR AL MENU: ";
    cin.get();
    limpiarConsola();
    return;
}