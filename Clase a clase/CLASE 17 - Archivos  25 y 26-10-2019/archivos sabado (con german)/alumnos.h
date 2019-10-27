typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float nota;

}eAlumno;

eAlumno* newAlumno();//CONSTRUCTOR PODEFECTO. SOLAMENTE CREA ESPACIO EN MEMORIA.

eAlumno* newAlumnoParametros(int id,char* nombre, char* apellido, int nota);

int getId(eAlumno* unAlumno);

void setId(eAlumno*,int);
