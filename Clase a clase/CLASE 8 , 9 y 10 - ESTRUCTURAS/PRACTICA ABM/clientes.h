typedef struct
{
    int dia;
    int mes;
    int anio;
} sDate;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    sDate fechaIngreso;
    int isEmpty;
} sCustomer;

int menuCustomer();
void show_Customer(sCustomer x);
void show_Customers(sCustomer vec[], int tam);
void initialize_Customers(sCustomer vec[], int tam);

int search_FreePosition(sCustomer vec[], int tam);
int search_Customer(int legajo, sCustomer vec[], int tam);

int highCustomer(sCustomer vec[], int tam);
sCustomer newCustomer(int legajo, char nombre[], int edad, char sexo, int nota1, int nota2, sDate fecha);

int downCustomer(sCustomer vec[], int tam);
int modifyCustomer(sCustomer vec[], int tam);
