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

typedef struct ADTContacto {
    char* alias;
    char* telefono_fijo;
    char* telefono_movil;
    char* correo_electronico;
} Contacto;

void* array_insert  (void *array_var, size_t *length, size_t size, const void *datum);
void* array_remove  (void *array_var, size_t *length, size_t size, const void *datum);
void  array_foreach (void *array_var, size_t length, size_t size, void *params, void (*func)(void*,void*));
void  pause_screen (const char *message);
char* read_string_line (const char *message);
char* read_str (const char *message, char *string_var);
int   read_integer (const char *message);
int   read_field (FILE *file_stream, char *field);
int   compare_contacto (const Contacto *contacto1, const Contacto *contacto2);
void  print_contacto (Contacto *datum, int *counter);
void  print_on_file (Contacto *datum, FILE *file_stream);

const char *path = "contactos.tsv";

int main (void)
{
    Contacto *contactos = NULL;
    size_t length=0;
    Contacto *datum = NULL, contacto;
    int counter=0, main_option, suboption;
    char field[255];
    FILE *file_stream = fopen (path, "r");
    if (file_stream!=NULL)
    {
        while (read_field (file_stream, field))
        {
            contacto.alias = _strdup (field);
            read_field (file_stream, field);
            contacto.telefono_fijo = _strdup (field);
            read_field (file_stream, field);
            contacto.telefono_movil = _strdup (field);
            read_field (file_stream, field);
            contacto.correo_electronico = _strdup (field);
            contactos = (Contacto*) array_insert (contactos, &length, sizeof (Contacto), &contacto);
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
        printf ("Selecciona una opci\242n: ");
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
            contacto.alias = read_str ("Ingresa el alias del contacto", field);
            datum = (Contacto*) _lfind (&contacto, contactos, &length, sizeof (Contacto), (int(*)(const void*,const void*))compare_contacto);
            if (datum!=NULL)
            {
                putchar ('\n');
                print_contacto (datum, &counter);
            }
        }
        if (main_option=='1' && datum!=NULL)
            printf ("El registro ya existe.\n");
        else if (main_option>='2' && main_option<='4' && datum==NULL)
            printf ("\nRegistro no encontrado.\n");
        else switch (main_option)
        {
            case '1':
                contacto.alias = _strdup (field);
                contacto.telefono_fijo = read_string_line ("Ingresa el telefono fijo");
                contacto.telefono_movil = read_string_line ("Ingresa el telefono movil");
                contacto.correo_electronico = read_string_line ("Ingresa el correo electronico");
                contactos = (Contacto*) array_insert (contactos, &length, sizeof (Contacto), &contacto);
                printf ("\nRegistro agregado correctamente.\n");
                break;
            case '3':
                printf ("Men\243 de actualizaci\242n de campos\n");
                printf ("1.- telefono fijo\n");
                printf ("2.- telefono movil\n");
                printf ("3.- correo electronico\n");
                do {
                    suboption = read_integer ("Selecciona el n\243mero de campo a modificar");
                    if (suboption<1 || suboption>3)
                        printf ("Opci\242n incorrecta\n");
                } while (suboption<1 || suboption>3);
                switch (suboption)
                {
                    case 1:
                        free (datum->telefono_fijo);
                        datum->telefono_fijo = read_string_line ("Ingresa el nuevo telefono fijo");
                        break;
                    case 2:
                        free (datum->telefono_movil);
                        datum->telefono_movil = read_string_line ("Ingresa el nuevo telefono movil");
                        break;
                    case 3:
                        free (datum->correo_electronico);
                        datum->correo_electronico = read_string_line ("Ingresa el nuevo correo electronico");
                        break;
                }
                printf ("\nRegistro actualizado correctamente.\n");
                break;
            case '4':
                memcpy (&contacto, datum, sizeof (Contacto));
                contactos = (Contacto*) array_remove ((void**)contactos, &length, sizeof (Contacto), datum);
                free (contacto.alias);
                free (contacto.telefono_fijo);
                free (contacto.telefono_movil);
                free (contacto.correo_electronico);
                printf ("Registro eliminado correctamente.\n");
                break;
            case '5':
                qsort (contactos, length, sizeof (Contacto), (int(*)(const void*,const void*))compare_contacto);
                printf ("Registros ordenados correctamente.\n");
                break;
            case '6':
                counter = 0;
                array_foreacjson_decodeh (contactos, length, sizeof (Contacto), &counter, (void(*)(void*,void*))print_contacto);
                printf ("Total de registros: %d.\n", counter);
                break;
        }
        if (main_option!='7')
            pause_screen ("");
    } while (main_option!='7');
    file_stream = fopen (path, "w");
    if (file_stream!=NULL)
    {
        array_foreach (contactos, length, sizeof (Contacto), file_stream, (void(*)(void*,void*))print_on_file);
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

int compare_contacto (const Contacto *contacto1, const Contacto *contacto2)
{
    return contacto1==contacto2 ? 0 : strcmp (contacto1->alias, contacto2->alias);
}

void print_contacto (Contacto *datum, int *counter)
{
    printf ("alias             : %s\n", datum->alias);
    printf ("telefono fijo     : %s\n", datum->telefono_fijo);
    printf ("telefono movil    : %s\n", datum->telefono_movil);
    printf ("correo electronico: %s\n", datum->correo_electronico);
    putchar ('\n');
    (*counter)++;
}

void print_on_file (Contacto *datum, FILE *file_stream)
{
    fprintf (file_stream, "%s\t", datum->alias);
    fprintf (file_stream, "%s\t", datum->telefono_fijo);
    fprintf (file_stream, "%s\t", datum->telefono_movil);
    fprintf (file_stream, "%s\n", datum->correo_electronico);
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
    printf ("%s\nPresiona una tecla para continuar . . . ", message);
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

#endif
