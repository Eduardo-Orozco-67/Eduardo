#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#ifdef __linux__
    #include <termios.h>
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
    int _getch ();
    #define _lfind lfind
    #define _strdup strdup
#else
    #include <conio.h>
    #define CLEAR_SCREEN "cls"
    #if defined(__MSDOS__) || defined(__BORLANDC__)
        #define _getch getch
        #define _lfind lfind
        #define _strdup strdup
    #endif
#endif

typedef struct ADTEquipo {
    char* codigo;
    char* nombre;
    char* ciudad;
    char* estadio;
    char* entrenador;
} Equipo;

void* array_insert  (void *array_var, size_t *length, size_t size, const void *datum);
void* array_remove  (void *array_var, size_t *length, size_t size, const void *datum);
void  array_foreach (void *array_var, size_t length, size_t size, void *params, void (*func)(void*,void*));
void  pause_screen (const char *message);
char* read_string_line (const char *message);
char* read_str (const char *message, char *string_var);
int   read_integer (const char *message);
int   read_field (FILE *file_stream, char *field);
int   compare_equipo (const Equipo *equipo1, const Equipo *equipo2);
void  print_equipo (Equipo *datum, int *counter);
void  print_on_file (Equipo *datum, FILE *file_stream);

const char *path = "equipos.tsv";

int main (void)
{
    Equipo *equipos = NULL;
    size_t length=0;
    Equipo *datum = NULL, equipo;
    int counter=0, main_option, suboption;
    char field[255];
    FILE *file_stream = fopen (path, "r");
    if (file_stream!=NULL)
    {
        while (read_field (file_stream, field))
        {
            equipo.codigo = _strdup (field);
            read_field (file_stream, field);
            equipo.nombre = _strdup (field);
            read_field (file_stream, field);
            equipo.ciudad = _strdup (field);
            read_field (file_stream, field);
            equipo.estadio = _strdup (field);
            read_field (file_stream, field);
            equipo.entrenador = _strdup (field);
            equipos = (Equipo*) array_insert (equipos, &length, sizeof (Equipo), &equipo);
        }
        fclose (file_stream);
    }
    do {
        putchar ('\n');
        system (CLEAR_SCREEN);
        printf ("MEN\351\n");
        printf ("1.- Altas\n");
        printf ("2.- Consultas\n");
        printf ("3.- Actualizaciones\n");
        printf ("4.- Bajas\n");
        printf ("5.- Ordenar registros\n");
        printf ("6.- Listar registros\n");
        printf ("7.- Salir\n");
        printf ("Seleccione una opci\242n: ");
        fflush (stdout);
        do
            main_option = _getch ();
        while (main_option<'1' || main_option>'7');
        printf ("%c\n\n", main_option);
        if (length==0 && main_option!='1' && main_option!='7')
        {
            pause_screen ("No hay registros.\n");
            continue;
        }
        if (main_option<'5')
        {
            equipo.codigo = read_str ("Ingrese el codigo del equipo", field);
            datum = (Equipo*) _lfind (&equipo, equipos, &length, sizeof (Equipo), (int(*)(const void*,const void*))compare_equipo);
            if (datum!=NULL)
            {
                putchar ('\n');
                print_equipo (datum, &counter);
            }
        }
        if (main_option=='1' && datum!=NULL)
            printf ("El registro ya existe.\n");
        else if (main_option>='2' && main_option<='4' && datum==NULL)
            printf ("\nRegistro no encontrado.\n");
        else switch (main_option)
        {
            case '1':
                equipo.codigo = _strdup (field);
                equipo.nombre = read_string_line ("Ingrese el nombre");
                equipo.ciudad = read_string_line ("Ingrese el ciudad");
                equipo.estadio = read_string_line ("Ingrese el estadio");
                equipo.entrenador = read_string_line ("Ingrese el entrenador");
                equipos = (Equipo*) array_insert (equipos, &length, sizeof (Equipo), &equipo);
                printf ("\nRegistro agregado correctamente.\n");
                break;
            case '3':
                printf ("Men\243 de actualizaci\242n de campos\n");
                printf ("1.- nombre\n");
                printf ("2.- ciudad\n");
                printf ("3.- estadio\n");
                printf ("4.- entrenador\n");
                do {
                    suboption = read_integer ("Seleccione el n\243mero de campo a modificar");
                    if (suboption<1 || suboption>4)
                        printf ("Opci\242n incorrecta\n");
                } while (suboption<1 || suboption>4);
                switch (suboption)
                {
                    case 1:
                        free (datum->nombre);
                        datum->nombre = read_string_line ("Ingrese el nuevo nombre");
                        break;
                    case 2:
                        free (datum->ciudad);
                        datum->ciudad = read_string_line ("Ingrese el nuevo ciudad");
                        break;
                    case 3:
                        free (datum->estadio);
                        datum->estadio = read_string_line ("Ingrese el nuevo estadio");
                        break;
                    case 4:
                        free (datum->entrenador);
                        datum->entrenador = read_string_line ("Ingrese el nuevo entrenador");
                        break;
                }
                printf ("\nRegistro actualizado correctamente.\n");
                break;
            case '4':
                memcpy (&equipo, datum, sizeof (Equipo));
                equipos = (Equipo*) array_remove ((void**)equipos, &length, sizeof (Equipo), datum);
                free (equipo.codigo);
                free (equipo.nombre);
                free (equipo.ciudad);
                free (equipo.estadio);
                free (equipo.entrenador);
                printf ("Registro eliminado correctamente.\n");
                break;
            case '5':
                qsort (equipos, length, sizeof (Equipo), (int(*)(const void*,const void*))compare_equipo);
                printf ("Registros ordenados correctamente.\n");
                break;
            case '6':
                counter = 0;
                array_foreacjson_decodeh (equipos, length, sizeof (Equipo), &counter, (void(*)(void*,void*))print_equipo);
                printf ("Total de registros: %d.\n", counter);
                break;
        }
        if (main_option!='7')
            pause_screen ("");
    } while (main_option!='7');
    file_stream = fopen (path, "w");
    if (file_stream!=NULL)
    {
        array_foreach (equipos, length, sizeof (Equipo), file_stream, (void(*)(void*,void*))print_on_file);
        fclose (file_stream);
    }
    return EXIT_SUCCESS;
}

void* array_insert (void *array_var, size_t *length, size_t size, const void *datum)
{
    char *record_var;
    array_var = realloc (array_var, size * (*length+1));
    record_var = (char*)array_var + *length * size;
    memcpy (record_var, datum, size);
    (*length)++;
    return array_var;
}

void* array_remove (void *array_var, size_t *length, size_t size, const void *datum)
{
    size_t i;
    char *record_var = (char*)array_var;
    for (i=0; i<*length && datum!=record_var; i++, record_var+=size);
    if (i<*length)
    {
        for (i++; i<*length; i++)
        {
            record_var+=size;
            memcpy (record_var-size, record_var, size);
        }
        (*length)--;
        array_var = realloc (array_var, size * (*length));
    }
    return array_var;
}

void array_foreach (void *array_var, size_t length, size_t size, void *params, void (*func)(void*,void*))
{
    char *record_var = (char*)array_var;
    if (length>0)
    {
        func (record_var, params);
        array_foreach (record_var+size, length-1, size, params, func);
    }
}

int compare_equipo (const Equipo *equipo1, const Equipo *equipo2)
{
    return equipo1==equipo2 ? 0 : strcmp (equipo1->codigo, equipo2->codigo);
}

void print_equipo (Equipo *datum, int *counter)
{
    printf ("codigo    : %s\n", datum->codigo);
    printf ("nombre    : %s\n", datum->nombre);
    printf ("ciudad    : %s\n", datum->ciudad);
    printf ("estadio   : %s\n", datum->estadio);
    printf ("entrenador: %s\n", datum->entrenador);
    putchar ('\n');
    (*counter)++;
}

void print_on_file (Equipo *datum, FILE *file_stream)
{
    fprintf (file_stream, "%s\t", datum->codigo);
    fprintf (file_stream, "%s\t", datum->nombre);
    fprintf (file_stream, "%s\t", datum->ciudad);
    fprintf (file_stream, "%s\t", datum->estadio);
    fprintf (file_stream, "%s\n", datum->entrenador);
}

char* read_string_line (const char *message)
{
    char string_line[255];
    (void) read_str (message, string_line);
    return _strdup (string_line);
}

char* read_str (const char *message, char *string_var)
{
    printf ("%s: ", message);
    scanf ("%[^\r\n]", string_var);
    (void) getchar ();
    return string_var;
}

int read_integer (const char *message)
{
    int integer_var;
    printf ("%s: ", message);
    scanf ("%d", &integer_var);
    (void) getchar();
    return integer_var;
}

int read_field (FILE *file_stream, char *field)
{
    fscanf (file_stream, "%[^\t\n\r]", field);
    fgetc (file_stream);
    return feof (file_stream) == 0;
}

void pause_screen (const char *message)
{
    printf ("%s\nPresione una tecla para continuar . . . ", message);
    fflush (stdout);
    _getch ();
}

#ifdef __linux__

int _getch ()
{
    int ch;
    struct termios oldt, newt;
    tcgetattr (STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr (STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
