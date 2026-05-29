#include <iostream>


using namespace std;

int main()
{
    int opcion;
    bool juegoActivo = true;
    system ("chcp 65001 > nul");
    
    do
    {
        cout << "MENU" << endl;
        cout << "BATALLA NAVAL" << endl;
        cout << "BY DIEGO & JENNY" << endl;
        cout << "\nElige una opción:" << endl;
        cout << "\n1. JUGAR" << endl;
        cout << "2. REGLAS DEL JUEGO" << endl;
        cout << "3. SALIR DEL JUEGO" << endl;
        cin >> opcion;
        switch (opcion)
            {
                case 1:
                    
                    break;
                
                case 2:
                    cout << "REGLAS DEL JUEGO" << endl;
                    cout << "Cada jugador tiene un tablero en el que coloca sus barcos.\nLos jugadores se turnan para realizar disparos y tratar de hundir los barcos del oponente." << endl; 
                    cout << "El primer jugador en hundir todos los barcos del oponente gana la partida." << endl;
                    cout << "----------------------------------------------------------------------------" << endl;
                    break;
                
                case 3:
                    return 0;
            }
        } while (juegoActivo == true);
    return 0;
}
