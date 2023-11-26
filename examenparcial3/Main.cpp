#include <windows.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInstGlob = 0;
struct eventos {
    char fecha[100];
    char hora[100];
    char nombre[50]; 
    char recinto[50];
    char lugar[50];
    int numE;
    eventos* ant;
    eventos* sig;
};
eventos* inicio, * aux, * fin = NULL;
char fechaf[100] = {0}; char horaf[100]; char nombref[50]; char recintof[50]; char lugarf[50]; int num;
char fechad[100] = { 0 }; char horad[100]; char nombred[50]; char contrasena[50] = {0};char recintod[50]; char lugard[50]; 
eventos* nodo_eventos = new eventos;
LRESULT CALLBACK Login(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PantallaInicio(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Promociones(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hwnd;
    MSG mensaje;
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(ID_PROMOCIONES), NULL, Promociones);
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(103), NULL, PantallaInicio);
    hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(101), NULL, Login);
    ShowWindow(hwnd, SW_SHOWDEFAULT);


    while (TRUE == GetMessage(&mensaje, 0, 0, 0))
    {
        TranslateMessage(&mensaje);
        DispatchMessage(&mensaje);
    }

    return mensaje.wParam;
}
int totalfinal = 0;
char precio[150] = {};
int res = 0; int subtotal = 0; float total = 0; int recuperar = 0;
int preciO = 1040; int preciO1 = 810; int preciO2 = 460;
int cont = 0; int boletos = 0; int boletos1 = 0;
char UsuarioLog[50] = { "Berenice" };

//mensajes
LRESULT CALLBACK Login(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND: {
        if (LOWORD(wParam) == 1003)
        {

            GetDlgItemText(hwnd, ID_EDIT_USUARIO_LOGIN, UsuarioLog, sizeof(UsuarioLog));
            GetDlgItemText(hwnd, ID_EDIT_CONTRA_LOGIN, contrasena, sizeof(contrasena));
            if (UsuarioLog != "Berenice") {
                MessageBox(hwnd, "Usuario Correcto", "Aviso", MB_OK | MB_ICONINFORMATION);
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(103), NULL, PantallaInicio);
            }
            else {
                MessageBox(hwnd, "Usuario Incorrecto", "ERROR", MB_OK | MB_ICONINFORMATION);

            }
            /*
            MessageBox(hwnd, "Ingrese todos los datos", "Advertencia", MB_OK | MB_ICONINFORMATION);
            EndDialog(hwnd, 0);
            DialogBox(hInstGlob, MAKEINTRESOURCE(103), NULL, PantallaInicio);*/
        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}
LRESULT CALLBACK PantallaInicio(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{/*
    char fechaf[] = "25/11/2023";
    strcpy_s(nodo_eventos->fecha, fechaf);
    char horaf[] = "20:30";
    strcpy_s(nodo_eventos->hora, horaf);
    char nombref[] = "The Warning";
    strcpy_s(nodo_eventos->nombre, nombref);
    char recintof[] = "Teatro Morelos";
    strcpy_s(nodo_eventos->recinto, recintof);
    char lugarf[] = "Toluca, Estado de México";
    strcpy_s(nodo_eventos->lugar, lugarf);
    //int num = 1;
    //nodo_eventos->numE = num;
    agregar_evento(nodo_eventos);
   

    char fechaf[] = "26/11/2023";
    strcpy_s(nodo_eventos->fecha, fechaf);
    char horaf[] = "20:30";
    strcpy_s(nodo_eventos->hora, horaf);
    char nombref[] = "The Warning 2";
    strcpy_s(nodo_eventos->nombre, nombref);
    char recintof[] = "Teatro Morelos";
    strcpy_s(nodo_eventos->recinto, recintof);
    char lugarf[] = "Toluca, Estado de México";
    strcpy_s(nodo_eventos->lugar, lugarf);
    //int num = 2;
    //nodo_eventos->numE = num;
    agregar_evento(nodo_eventos);

    char fechaf[] = "27/11/2023";
    strcpy_s(nodo_eventos->fecha, fechaf);
    char horaf[] = "20:30";
    strcpy_s(nodo_eventos->hora, horaf);
    char nombref[] = "The Warning 3";
    strcpy_s(nodo_eventos->nombre, nombref);
    char recintof[] = "Teatro Morelos";
    strcpy_s(nodo_eventos->recinto, recintof);
    char lugarf[] = "Toluca, Estado de México";
    strcpy_s(nodo_eventos->lugar, lugarf);
    //int num = 3;
    //nodo_eventos->numE = num;
    agregar_evento(nodo_eventos);*/

    char fechaf[] = "25/11/2023";
    char horaf[] = "20:30";
    char nombref[] = "The Warning";
    char recintof[] = "Teatro Morelos";
    char lugarf[] = "Toluca, Estado de México";
    int num = 1;
    
    switch (msg)
    {
    case WM_INITDIALOG: {

        EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), FALSE);

        SetWindowText(GetDlgItem(hwnd, 1013), nombref);
        SetWindowText(GetDlgItem(hwnd, 1014), fechaf);
        SetWindowText(GetDlgItem(hwnd, 1015), horaf);
        SetWindowText(GetDlgItem(hwnd, 1016), recintof);
        SetWindowText(GetDlgItem(hwnd, 1017), lugarf);

        char fechaf[] = "1/12/2023";
        char horaf[] = "20:30";
        char nombref[] = "The Warning 2";
        char recintof[] = "Domo Care";
        char lugarf[] = "Guadalupe, Nuevo León";
        SetWindowText(GetDlgItem(hwnd, 1019), nombref);
        SetWindowText(GetDlgItem(hwnd, 1020), fechaf);
        SetWindowText(GetDlgItem(hwnd, 1021), horaf);
        SetWindowText(GetDlgItem(hwnd, 1022), recintof);
        SetWindowText(GetDlgItem(hwnd, 1023), lugarf);

        SetWindowText(GetDlgItem(hwnd, 1027), "1");

       

    }break;
    case WM_COMMAND: {
        if (LOWORD(wParam) == ID_BOTON_VENTA_PI)
        {
            MessageBox(hwnd, "Seleccione un evento", "Advertencia", MB_OK | MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == 1025)
        {
            char fechaf[] = "9/02/2024";
            char horaf[] = "21:00";
            char nombref[] = "LP LOVE LINES TOUR";
            char recintof[] = "FORO GNP SEGUROS";
            char lugarf[] = "Puebla, Puebla";

            SetWindowText(GetDlgItem(hwnd, 1013), nombref);
            SetWindowText(GetDlgItem(hwnd, 1014), fechaf);
            SetWindowText(GetDlgItem(hwnd, 1015), horaf);
            SetWindowText(GetDlgItem(hwnd, 1016), recintof);
            SetWindowText(GetDlgItem(hwnd, 1017), lugarf);

            ShowWindow(GetDlgItem(hwnd, 1025), SW_HIDE);
            ShowWindow(GetDlgItem(hwnd, 1026), SW_SHOW);
            ShowWindow(GetDlgItem(hwnd, 1024), SW_HIDE);

            for (int i = 1019; i < 1024; i++)
            {
                //SetWindowText(GetDlgItem(hwnd, i), " ");
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }

            SetWindowText(GetDlgItem(hwnd, 1027), "2");
        }
        if (LOWORD(wParam) == 1026)
        {
            char fechaf[] = "25/11/2023";
            char horaf[] = "20:30";
            char nombref[] = "The Warning";
            char recintof[] = "Teatro Morelos";
            char lugarf[] = "Toluca, Estado de México";

                SetWindowText(GetDlgItem(hwnd, 1013), nombref);
                SetWindowText(GetDlgItem(hwnd, 1014), fechaf);
                SetWindowText(GetDlgItem(hwnd, 1015), horaf);
                SetWindowText(GetDlgItem(hwnd, 1016), recintof);
                SetWindowText(GetDlgItem(hwnd, 1017), lugarf);

                ShowWindow(GetDlgItem(hwnd, 1026), SW_HIDE);
                ShowWindow(GetDlgItem(hwnd, 1025), SW_SHOW);

                for (int i = 1019; i < 1024; i++)
                {
                    ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
                }
                SetWindowText(GetDlgItem(hwnd, 1027), "1");

                ShowWindow(GetDlgItem(hwnd, 1024), SW_SHOW);
        }
        if (LOWORD(wParam) == ID_BOTON_COMPRAR1 )
        {
            cont = 0;
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), FALSE);
            for (int i = 1018; i < 1028; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1059; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            
            for (int i = 1037; i < 1041; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char VIP[150] = "VIP de pie      ADULTOS   $1,040.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)VIP);
            //preciO = 1040;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO);

            char BUTACAS[150] = "Butacas         ADULTOS   $810.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)BUTACAS);
            //preciO1 = 810;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO1);

            char GRAL[150] = "General          ADULTOS   $460.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)GRAL);
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 1, (LPARAM)preciO2);
            res = 0;
            SetDlgItemInt(hwnd, ID_EDIT_CANTIDAD, res, TRUE);

            GetDlgItemText(hwnd, 1013, nombred, sizeof(nombred));
            GetDlgItemText(hwnd, 1014, fechad, sizeof(fechad));
            GetDlgItemText(hwnd, 1015, horad, sizeof(horad));
            GetDlgItemText(hwnd, 1016, recintod, sizeof(recintod));
            GetDlgItemText(hwnd, 1017, lugard, sizeof(lugard));
        }
        if (LOWORD(wParam) == ID_BOTON_COMPRAR2)
        {
            cont = 0;
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), FALSE);
            for (int i = 1018; i < 1028; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1059; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1013; i < 1018; i++)
            {
                SetWindowText(GetDlgItem(hwnd, i), " ");

            }
            
            GetDlgItemText(hwnd, 1019, nombref, sizeof(nombref));
            GetDlgItemText(hwnd, 1020, fechaf, sizeof(fechaf));
            GetDlgItemText(hwnd, 1021, horaf, sizeof(horaf));
            GetDlgItemText(hwnd, 1022, recintof, sizeof(recintof));
            GetDlgItemText(hwnd, 1023, lugarf, sizeof(lugarf));
            SetWindowText(GetDlgItem(hwnd, 1013), nombref);
            SetWindowText(GetDlgItem(hwnd, 1014), fechaf);
            SetWindowText(GetDlgItem(hwnd, 1015), horaf);
            SetWindowText(GetDlgItem(hwnd, 1016), recintof);
            SetWindowText(GetDlgItem(hwnd, 1017), lugarf);

            for (int i = 1037; i < 1041; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char VIP[150] = "VIP de pie      ADULTOS   $1,040.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)VIP);
            //preciO = 1040;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO);

            char BUTACAS[150] = "Butacas         ADULTOS   $810.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)BUTACAS);
            //preciO1 = 810;
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 0, (LPARAM)preciO1);

            char GRAL[150] = "General          ADULTOS   $460.00";
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_ADDSTRING, 0, (LPARAM)GRAL);
            SendMessage(GetDlgItem(hwnd, ID_LIST_EVENTOS), LB_SETITEMDATA, 1, (LPARAM)preciO2);

            res = 0;
            SetDlgItemInt(hwnd, ID_EDIT_CANTIDAD, res, TRUE);

            GetDlgItemText(hwnd, 1013, nombred, sizeof(nombred));
            GetDlgItemText(hwnd, 1014, fechad, sizeof(fechad));
            GetDlgItemText(hwnd, 1015, horad, sizeof(horad));
            GetDlgItemText(hwnd, 1016, recintod, sizeof(recintod));
            GetDlgItemText(hwnd, 1017, lugard, sizeof(lugard));
        }
        if (LOWORD(wParam == ID_REALIZAR_COMPRA))
        {
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAS_PI), TRUE);
            res = GetDlgItemInt(hwnd, ID_EDIT_CANTIDAD, NULL, TRUE);
            boletos = res;
            boletos1 = res;
            if (res == 0) {
                MessageBox(hwnd, "Ingrese la cantidad de boletos", "Advertencia", MB_OK | MB_ICONINFORMATION);
            }
            else
            {
                int idx = SendDlgItemMessage(hwnd, ID_LIST_EVENTOS, LB_GETCURSEL, 0, 0);
                int numc = SendDlgItemMessage(hwnd, ID_LIST_EVENTOS, LB_GETITEMDATA, idx, 0);
                //SetDlgItemInt(hwnd, 1013, numc, TRUE);
                recuperar = numc;
                subtotal = numc * res;
                //SetDlgItemInt(hwnd, 1013, subtotal, TRUE);
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(ID_PROMOCIONES), NULL, Promociones);
            }

            
        }
        if (LOWORD(wParam) == ID_BOTON_EVENTOS_PI)
        {

            EnableWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), FALSE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), TRUE);
            for (int i = 1059; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1028; i < 1042; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            for (int i = 1018; i < 1028; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            char fechaf[] = "25/11/2023";
            char horaf[] = "20:30";
            char nombref[] = "The Warning";
            char recintof[] = "Teatro Morelos";
            char lugarf[] = "Toluca, Estado de México";

            SetWindowText(GetDlgItem(hwnd, 1013), nombref);
            SetWindowText(GetDlgItem(hwnd, 1014), fechaf);
            SetWindowText(GetDlgItem(hwnd, 1015), horaf);
            SetWindowText(GetDlgItem(hwnd, 1016), recintof);
            SetWindowText(GetDlgItem(hwnd, 1017), lugarf);
        }
        if (LOWORD(wParam) == ID_BOTON_COMPRAS_PI)
        {
            if(cont==1||cont==2){
            for (int i = 1018; i < 1042; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_HIDE);
            }
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_EVENTOS_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_VENTA_PI), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BOTON_COMPRAS_PI), FALSE);
            SetWindowText(GetDlgItem(hwnd, 1013), nombred);
            SetWindowText(GetDlgItem(hwnd, 1014), fechad);
            SetWindowText(GetDlgItem(hwnd, 1015), horad);
            SetWindowText(GetDlgItem(hwnd, 1016), recintod);
            SetWindowText(GetDlgItem(hwnd, 1017), lugard);
            

            for (int i = 1059; i < 1064; i++)
            {
                ShowWindow(GetDlgItem(hwnd, i), SW_SHOW);
            }
            SetDlgItemInt(hwnd, ID_EDIT_MISCOMPRAS_BOLETOS,boletos1, TRUE);
            SetDlgItemInt(hwnd, ID_EDIT_MISCOMPRAS_TOTAL,totalfinal, TRUE);
            }
            else if (cont == 0) {
                MessageBox(hwnd, "No ha realizado ninguna compra", "Aviso", MB_OK | MB_ICONINFORMATION);
            }
        }
        if (LOWORD(wParam) == ID_BOTON_SALIR_PI)
        {
            DestroyWindow(hwnd);
            PostQuitMessage(0);
        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}
char numC[16] = { 0 };
LRESULT CALLBACK Promociones(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_INITDIALOG: {
        
        total = subtotal+(subtotal * 0.16);
        sprintf_s(numC, "%.3f", total);
        SetDlgItemText(hwnd, ID_EDIT_TOTAL_COMPRA, numC);
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Ninguno");
        

        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Ticket 2x1");
        int precio3 = 1;
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), CB_SETITEMDATA, -1, (LPARAM)precio3);
        //Ninguno
        int precio1 = 2;
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), CB_SETITEMDATA, 0, (LPARAM)precio1);
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"10%");
        //10%
        int precio2 = 3;
        SendMessage(GetDlgItem(hwnd, ID_COMBO_DESCUENTOS), CB_SETITEMDATA, 0, (LPARAM)precio2);
        SendMessage(GetDlgItem(hwnd, IDC_COMBO2), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Tarjeta de débito");
        SendMessage(GetDlgItem(hwnd, IDC_COMBO2), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Tarjeta de crédito");
        SendMessage(GetDlgItem(hwnd, IDC_COMBO2), (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Paypal");
        res = 0;
        SetDlgItemInt(hwnd, ID_EDIT_TARJETA_COMPRA, res, TRUE);
        SetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, res, TRUE);
        SetDlgItemInt(hwnd, ID_EDIT_USUARIO_COMPRA, res, TRUE);

    }break;
    case WM_COMMAND: {
        if (LOWORD(wParam) == ID_BOTON_DOSPORUNO)
        {
            int idx = SendDlgItemMessage(hwnd, ID_COMBO_DESCUENTOS, CB_GETCURSEL, 0, 0);
            int numc = SendDlgItemMessage(hwnd, ID_COMBO_DESCUENTOS, CB_GETITEMDATA, idx, 0);
            SetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, numc, TRUE);
            if (numc == 1)
            {
                if (boletos % 2 == 0)
                {
                    boletos = boletos / 2;
                    subtotal =boletos * recuperar;
                    total = subtotal + (subtotal * 0.16);
                    sprintf_s(numC, "%.3f", total);
                    SetDlgItemText(hwnd, ID_EDIT_TOTAL_COMPRA, numC);
                }
                
            }
            if (numc == 3)
            {
                total = subtotal - (subtotal * 0.10);
                sprintf_s(numC, "%.3f", total);
                SetDlgItemText(hwnd, ID_EDIT_TOTAL_COMPRA, numC);
            }
        }
        if (LOWORD(wParam) == ID_BOTON_ACEPTAR_COMPRA)
        {
            totalfinal = total;
            cont = 1;
            int res3 = GetDlgItemInt(hwnd, ID_EDIT_TARJETA_COMPRA, NULL, TRUE);
            int res1= GetDlgItemInt(hwnd, ID_EDIT_CLAVE_COMPRA, NULL, TRUE);
            //int res2= GetDlgItemInt(hwnd, ID_EDIT_USUARIO_COMPRA, NULL, TRUE);
            if (res3 == 0||res1==0) {
                MessageBox(hwnd, "Ingrese todos los datos", "Advertencia", MB_OK | MB_ICONINFORMATION);
            }
            else
            {
                EndDialog(hwnd, 0);
                DialogBox(hInstGlob, MAKEINTRESOURCE(ID_PANTALLA_INICIO), NULL, PantallaInicio);
            }
            
        }
    }break;
    case WM_CLOSE: {
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    }break;
    case WM_DESTROY:
        break;
    }
    return 0;
}

void  agregar_evento(eventos* nuevo) {
    if (inicio == NULL) {
        inicio = new eventos;
        aux = inicio;

        aux->sig = NULL;
        aux->ant = NULL;

        strcpy_s(aux->fecha, nuevo->fecha);
        strcpy_s(aux->hora, nuevo->hora);
        strcpy_s(aux->nombre, nuevo->nombre);
        strcpy_s(aux->recinto, nuevo->recinto);
        strcpy_s(aux->lugar, nuevo->lugar);
        aux->numE = nuevo->numE;

    }
    else {
        aux = inicio;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = new eventos;
        aux->sig->sig = NULL;
        aux->sig->ant = aux;
        aux = aux->sig;
        fin = aux;
        strcpy_s(aux->fecha, nuevo->fecha);
        strcpy_s(aux->hora, nuevo->hora);
        strcpy_s(aux->nombre, nuevo->nombre);
        strcpy_s(aux->recinto, nuevo->recinto);
        strcpy_s(aux->lugar, nuevo->lugar);
        aux->numE = nuevo->numE;
    }
}