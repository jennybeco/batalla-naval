#include <iostream>
#include <windows.h> //esta se usa para que se pueden ver los colores
#include <conio.h> //no se para que es pero tambien estaba en el ejemplo de la maestra
#include <cstdlib> // para el random
#include <ctime>

using namespace std;

#define ROSA      "\033[95m"
#define RESET     "\033[0m" //este es para cuando quiera que regrese a su color original
#define ROJO      "\033[91m"
#define AZUL      "\033[94m"
#define MORADO    "\033[35m"

//este es el codigo que puso la maestra para que funcionaran los colores
//aunq en mi compu si se podia ver los colores sin este texto pero como no se porque mejor lo dejo asi por si acaso
void enableANSI()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    system("chcp 65001 > nul");
}
const int tam_tablero= 10, num_barcos= 5, tam_barcos[num_barcos]= {5, 4, 3, 3, 2};
const char espacio_barco= 'B', destruye_barco= 'X', no_barco= 'O', agua= '~';;
//La B indica donde estara el barco, la X cuando si le pegue al barco, la O para cuando no le pego a un barco

int menu(), juego();
void pantallaInicio(), limpiarConsola(), reglas(),  iniciar_tablero(char tablero[tam_tablero][tam_tablero]), colocar_barcos(char tablero[tam_tablero][tam_tablero]);
void mostrar_tableros(string primer_nombre, char tiros_jugador1[tam_tablero][tam_tablero], string segundo_nombre, char tiros_jugador2[tam_tablero][tam_tablero]);
bool realizar_disparo(char tablero_jugador[tam_tablero][tam_tablero],char tiros_jugador[tam_tablero][tam_tablero],int fila,int columna);
bool pedir_coordenada(string nombre, int &fila, int &columna,char tiros_jugador[tam_tablero][tam_tablero]), alguien_gano(char tablero[tam_tablero][tam_tablero]);

int main()
{
    enableANSI(); //para los ccolores
    system ("chcp 65001 > nul");
    srand(time(NULL));

    pantallaInicio();
    bool juegoActivo = true;
    do
    {
        switch (menu())
        {
            case 1:
                juego();
                break;

            case 2:
                reglas();
                break;

            case 3:
            juegoActivo = false;
        }
    }while (juegoActivo == true);

    return 0;
}

int menu()
{
    int opcion;
    cout << R"(
  __  __
 |  \/  |___ _ _ _  _
 | |\/| / -_) ' \ || |
 |_|  |_\___|_||_\_,_|

        )" << endl;
    cout << "ELIGE UNA OPCIÓN:" << endl;
    cout << "1. JUGAR" << endl;
    cout << "2. REGLAS DEL JUEGO" << endl;
    cout << "3. SALIR DEL JUEGO" << endl;
    do {
    cout << RESET << "\nOpcion: ";
    cin >> opcion;
    if (opcion < 1 || opcion > 3)
        cout << ROJO << "Esa opción no existe. Elige 1, 2 o 3." << RESET << endl;
    } while (opcion < 1 || opcion > 3);

    return opcion;
}

void pantallaInicio()
{
    cout << ROSA;
        cout << R"(
 .----.   .--.  .---.  .--.  .-.   .-.     .--.     .-. .-.  .--.  .-. .-.  .--.  .-.
| {}  } / {} \{_   _}/ {} \ | |   | |    / {} \    |  `| | / {} \ | | | | / {} \ | |
| {}  }/  /\  \ | | /  /\  \| `--.| `--./  /\  \   | |\  |/  /\  \\ \_/ //  /\  \| `--.
`----' `-'  `-' `-' `-'  `-'`----'`----'`-'  `-'   `-' `-'`-'  `-' `---' `-'  `-'`----'

        )" << endl;
    cout << "POR JENNY Y DIEGO " << endl;
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
cout << RESET;
cout << "\nPRESIONE ENTER: ";
cin.get();
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
    cin.ignore();
    cout << ROSA << R"(  ___          _              _     _      _
 | _ \___ __ _| |__ _ ___  __| |___| |  _ | |_  _ ___ __ _ ___
 |   / -_) _` | / _` (_-< / _` / -_) | | || | || / -_) _` / _ \
 |_|_\___\__, |_\__,_/__/ \__,_\___|_|  \__/ \_,_\___\__, \___/
         |___/                                       |___/     )" << RESET << endl;
    cout << "Cada jugador tiene un tablero en el que coloca sus barcos.\nLos jugadores se turnan para realizar disparos y tratar de hundir los barcos del oponente." << endl;
    cout << "El primer jugador en hundir todos los barcos del oponente gana la partida." << endl;
    cout << "Para rendirte una vez iniciada la partida, al pedir coordenadas presione la letra Q y debera aparecer un mensaje." << endl;
    cout << ROSA << "------------------------------------------------------------------------------------------------------------------------" << RESET << endl;
    cout << R"(   ___                          ___  _                    _ __   __
  / _ )___ ____________  ___   / _ \(_)__ ___  ___  ___  (_) /  / /__ ___
 / _  / _ `/ __/ __/ _ \(_-<  / // / (_-</ _ \/ _ \/ _ \/ / _ \/ / -_|_-<
/____/\_,_/_/  \__/\___/___/ /____/_/___/ .__/\___/_//_/_/_.__/_/\__/___/
                                       /_/                               )" << endl;
    cout << "  - 1 Portaaviones.       (5 espacios)" << endl;
    cout << "  - 1 Acorazado.          (4 espacios)" << endl;
    cout << "  - 2 Destructores.       (3 espacios)" << endl;
    cout << "  - 1 Lancha.             (2 espacios)" << endl;
    cout << ROSA << "------------------------------------------------------------------------------------------------------------------------" << RESET << endl;
    cout << "\nPRESIONE ENTER PARA REGRESAR AL MENU: ";
    cin.get();
    limpiarConsola();
    return;
}

int juego()
{
    limpiarConsola();

    string primer_nombre, segundo_nombre;
    cout << ROSA << R"(  ___          _    _                _          _                   _          ____
 | _ \___ __ _(_)__| |_ _ _ ___   __| |___   _ | |_  _ __ _ __ _ __| |___ _ _ / __ \ ___
 |   / -_) _` | (_-<  _| '_/ _ \ / _` / -_) | || | || / _` / _` / _` / _ \ '_/ / _` (_-<
 |_|_\___\__, |_/__/\__|_| \___/ \__,_\___|  \__/ \_,_\__, \__,_\__,_\___/_| \ \__,_/__/
         |___/                                        |___/                   \____/    )" << RESET;
    cout << ROSA << "--------------------------------------------------------------------------------------------------------------------" << RESET << endl;
    cout << "\n  Nombre Jugador 1: ";
    cin >> primer_nombre;

    cout << "  Nombre Jugador 2: ";
    cin >> segundo_nombre;

    char tablero_jugador1[tam_tablero][tam_tablero], tablero_jugador2[tam_tablero][tam_tablero];  //creo q se entiende pero es el tablero ya con los barcos
    char tiros_jugador1[tam_tablero][tam_tablero]; //los lugares donde ha disparado el primer jugador, no se como explicarlo
    char tiros_jugador2[tam_tablero][tam_tablero]; // lo mismo pero del segundo jugador
    iniciar_tablero(tablero_jugador1);
    iniciar_tablero(tablero_jugador2);
    iniciar_tablero(tiros_jugador1);
    iniciar_tablero(tiros_jugador2);
    //son 4 tableros porque son dos que muestran los tiros que se hacen y otro pues las tablas normal
    colocar_barcos(tablero_jugador1);
    colocar_barcos(tablero_jugador2);

      cout << ROSA << "\nLos barcos han sido colocados." << RESET << endl;
    cout << "\nPRESIONE ENTER PARA CONTINUAR: ";
    cin.ignore();
    cin.get();

    int turno = 1;
    bool activo = true;

    while (activo)
    {
        limpiarConsola();
        int fila, columna;

        if (turno == 1)
        {
            mostrar_tablero2(tiros_jugador1[tam_tablero][tam_tablero]); // muestra el tablero de la primera jugadora con A de mujer
            cout << ROSA << "Turno de " << primer_nombre << RESET << endl;
            cout << "Ingresa las coordenadas de tu disparo:" << endl;

            if (pedir_coordenada(primer_nombre, fila, columna, tiros_jugador1) == false)
            {
                limpiarConsola();
                cout << ROJO << "\n" << primer_nombre << " se rindio." << RESET;
                cout << "\nLERO LERO JAJJAJA" <<endl;
                cout << ROSA << segundo_nombre << " es la/el ganador(a).\n" << RESET;
                cout << "\nPRESIONE ENTER PARA CONTINUAR: ";
                cin.get();
                return 0;
            }

            if (realizar_disparo(tablero_jugador2, tiros_jugador1, fila, columna) == true)
                cout << ROJO << "\nLe pegaste a un barco enemigo." << RESET << endl;
            else
                cout << AZUL << "\nLe pegaste... pero al agua JAJAJA." << RESET << endl;

            if (alguien_gano(tablero_jugador2) == true) // BUG: antes revisaba tablero_jugador1, hay que revisar al que le dispararon
            {
                limpiarConsola();
                mostrar_tableros(segundo_nombre, tablero_jugador2, primer_nombre, tiros_jugador2);
                cout << ROSA << "\n" << primer_nombre << " Ganaste!!! Hundiste todos los barcos, suertudot@.\n" << RESET;
                cout << "\nPRESIONE ENTER PARA CONTINUAR: ";
                cin.get();
                activo = false;
            }
            else turno = 2; // BUG: antes decia turno = 1, nunca cambiaba de turno
        }
        else // turno == 2
        {
            mostrar_tablero1(tiros_jugador2[tam_tablero][tam_tablero]);

            cout << ROSA << "Turno de " << segundo_nombre << RESET << endl;
            cout << "Ingresa las coordenadas de tu disparo:" << endl;

            if (pedir_coordenada(segundo_nombre, fila, columna, tiros_jugador2) == false)
            {
                limpiarConsola();
                cout << ROJO << "\n" << segundo_nombre << " se rindio." << RESET;
                cout << "\nLERO LERO JAJJAJA" << endl;
                cout << ROSA << primer_nombre << " es la/el ganador(a).\n" << RESET;
                cout << "\nPRESIONE ENTER PARA CONTINUAR: ";
                cin.get();
                return 0;
            }

            if (realizar_disparo(tablero_jugador1, tiros_jugador2, fila, columna) == true)
                cout << ROJO << "\nLe pegaste a un barco enemigo." << RESET << endl;
            else
                cout << AZUL << "\nLe pegaste... pero al agua JAJAJA." << RESET << endl;

            if (alguien_gano(tablero_jugador1) == true)
            {
                limpiarConsola();
                mostrar_tableros(primer_nombre, tiros_jugador1, segundo_nombre, tiros_jugador2);
                cout << ROSA << "\n" << segundo_nombre << " Ganaste!!! Hundiste todos los barcos, suertudot@.\n" << RESET;
                cout << "\nPRESIONE ENTER PARA CONTINUAR: ";
                cin.get();
                activo = false;
            }
            else turno = 1;
        }

        if (activo)
        {
            cout << "\nPRESIONE ENTER PARA EL SIGUIENTE TURNO: ";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}

void iniciar_tablero(char tablero[tam_tablero][tam_tablero])
{
    for (int d = 0; d < tam_tablero; d++)
    {
        for (int j = 0; j < tam_tablero; j++) // abajo columnas arriba filas, lo pongo porque se me olvida cual es cual :/
        {
            tablero[d][j] = agua; //con ese se deberia de ver el simbolito del agua
        }
    }
}

void colocar_barcos(char tablero[tam_tablero][tam_tablero])
{
    for(int i = 0; i < num_barcos; i++)
    {
        bool colocado = false;
        while(colocado == false)
        {
            int columna, fila;
            int direccion = rand() % 2; // coin flip para decidir en que orientacion se coloca el barco

            if(direccion == 1) // el barco se pone de forma vertical
            {
                fila = rand() % (tam_tablero + 1 - tam_barcos[i]); // resta largo de barco para evitar que se salga del tablero cont ->
                columna = rand() % tam_tablero; // -> + 1 para hacer posible que el barco quede pegado a la ultima casilla
            }
            else // direccion = 0. el barco se pone de forma horizontal
            {
                columna = rand() % (tam_tablero + 1 - tam_barcos[i]);
                fila = rand() % tam_tablero;
            }

            bool choca = false;
            for(int j = 0; j < tam_barcos[i]; j++)
            {
                if(direccion == 1)
                {
                    if(tablero[fila + j][columna] != agua) // BUG: antes era [fila][columna+j] en vertical, estaba al reves
                        choca = true;
                }
                else
                {
                    if(tablero[fila][columna + j] != agua)
                        choca = true;
                }
            } // BUG: el if(choca==false) estaba DENTRO de este for, lo saque afuera para que revise todo el barco antes de colocarlo

            if(choca == false)
            {
                for(int j = 0; j < tam_barcos[i]; j++)
                {
                    if(direccion == 1)
                        tablero[fila + j][columna] = espacio_barco;
                    else
                        tablero[fila][columna + j] = espacio_barco;
                }
                colocado = true;
            }
        }
    }
}

bool alguien_gano(char tablero[tam_tablero][tam_tablero])
{
    for (int d = 0; d < tam_tablero; d++)
        for (int j = 0; j < tam_tablero; j++)
            if (tablero[d][j] == espacio_barco)
                return false;
    return true; // regresa true si ya no queda ninguna B y pues false si todavia hay alguno
}


void mostrar_tablero1(char jugador1[tam_tablero])
{
    for(int i = 0; i < 99; i++)
    {
        int cambio_Renglon = 4;
        cout << jugador1[i];
        if(i == cambio_Renglon)
        {
            cout << "\n";
            cambio_Renglon += 5;
        }
    }
}

void mostrar_tablero2(char jugador2[tam_tablero])
{
    for(int i = 0; i < 99; i++)
    {
        int cambio_Renglon = 4;
        cout << jugador2[i];
        if(i == cambio_Renglon)
        {
            cout << "\n";
            cambio_Renglon += 5;
        }
    }

}
