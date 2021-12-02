#include <iostream>
#include <cstdlib>

using namespace std;

int main (){

    int codloc, codarbol = 1, edad, arboles, npeligroso, arbmasviejo = 0, localarb, tarboptimo = 0, localsanas = 0, arbtotal, estado;
    float altura, taltoptimo, promaltopt, parbpel;
    bool sinenfermos;

    cout << "Ingrese el codigo de localidad en el que va a trabajar: ";
    cin >> codloc;


    while (codarbol != 0){

        npeligroso = 0;
        sinenfermos = true;

        for (arboles = 1; arboles <= 3; arboles++){

            estado = 5;

            cout << "Ingrese codigo de arbol: ";
            cin >> codarbol;

            if (codarbol != 0){

                cout << "Ingrese edad del arbol: ";
                cin >> edad;

                cout << "Ingrese la altura del arbol: ";
                cin >> altura;

                while ((estado > 4) || (estado < 1)){

                    cout << "Ingrese el estado general del arbol (1-Optimo, 2-Satisfactorio, 3-Enfermo, 4-Peligroso): ";
                    cin >> estado;
                }

                switch(estado){

                    case 1:
                        taltoptimo = taltoptimo + altura;
                        tarboptimo++;
                    break;

                    case 2:
                        ;
                    break;

                    case 3:
                        sinenfermos = false;
                    break;

                    case 4:
                        npeligroso++;
                    break;

                    default:
                        cout << "ERROR EN EL SISTEMA" << endl;
                        return 0;

                }

                if (arbmasviejo == 0){

                    arbmasviejo = edad;
                    localarb = codloc;

                }
                else if (codloc == localarb){

                    if (edad > arbmasviejo){

                        arbmasviejo = edad;

                    }

                }

            }
            else{

                arboles = 50;

            }

        }

        arbtotal = arboles;
        parbpel = ((float)npeligroso*100)/arbtotal;

        cout << "--------------" << endl;
        cout << "El porcentaje de arboles peligrosos en la localidad " << codloc << " es de: " << parbpel << "%." << endl;

        if (sinenfermos == true){

            localsanas++;

        }

        if (codarbol !=0){
            cout << "Ingrese el codigo de localidad en el que va a trabajar: ";
            cin >> codloc;
        }

    }
    cout << "--------------" << endl;
    cout << "La edad del arbol mas viejo de la primera localidad (" << localarb << ") es de: " << arbmasviejo << endl;
    cout << "--------------" << endl;
    promaltopt = taltoptimo/(float)tarboptimo;

    cout << "La altura promedio de los arboles optimos es de: " << promaltopt << endl;
    cout << "--------------" << endl;

    cout << "La cantidad de localidades sin arboles enfermos es de: " << localsanas;
    return 0;
}
