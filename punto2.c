#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;


typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;
int idAleatorio = 1000;
Nodo *crearlista()
{
    return NULL;    
}
Nodo *crearNodo(Tarea t){
    Nodo *nodo=(Nodo*)malloc(sizeof(Nodo));
    nodo->T=t;
    nodo->Siguiente=NULL;
    return nodo;
}
void agregartarea(Nodo **star,Nodo *nodo){
    nodo->Siguiente= *star;
    *star=nodo;
}
void listarTareas(Nodo *nodo){
    
    while (nodo!=NULL)
    {
        
        printf("El ID de la tarea es %d cuya descripcion es %s y su duracion es de %d dias \n",nodo->T.TareaID,nodo->T.Descripcion,nodo->T.Duracion);
        nodo=nodo->Siguiente;
    }
    
}
void moverTarea(Nodo **tareaRealizada,Nodo **tareaPendiente,int id){
    Nodo *actual=*tareaPendiente;
    Nodo *anterior=NULL;
    while (actual!=NULL && actual->T.TareaID !=id)
    {
        anterior=actual;
        actual=actual->Siguiente;
    }
    if (actual==NULL)
        {
            printf("No se encuentra el id ");
            return ;
        }
    if (anterior==NULL)
    {
        *tareaPendiente=actual->Siguiente;
    }else{
        anterior->Siguiente=actual->Siguiente;
    }
    actual->Siguiente=*tareaRealizada;
    *tareaRealizada=actual;
    
    printf("Cambio realiazdo con exito\n");
        
    
}
void listarTareasRealizadas(Nodo *nodo){
    printf("Tareas Realizadas:\n");
    while (nodo!=NULL)
    {
       
        printf("El ID de la tarea es %d cuya descripcion es %s y su duracion es de %d dias \n",nodo->T.TareaID,nodo->T.Descripcion,nodo->T.Duracion);
        nodo=nodo->Siguiente;
    }
}
void liberarmemoria(Nodo *lista){
    Nodo *Temp;
    while (lista!=NULL)
    {
        Temp=lista;
        lista=lista->Siguiente;
        free(Temp->T.Descripcion);
        free(Temp);
    }
    
}
int main()
{
    srand(time(NULL));
    Nodo *tareaPendiente = crearlista();
    Nodo *tareaRealizada = crearlista();
    int opcion;
    char *buff;
    int continuar;
    Tarea T;
    

    buff= (char *) malloc(100*sizeof(char));
    do
    {

      
        T.TareaID = idAleatorio++;
        
        
        printf("Ingrese Una breve descripcion de la tarea\n");
        fflush(stdin);
        gets(buff);
        T.Descripcion=(char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(T.Descripcion,buff);
        do
        {
            printf("Ingrese la duracion de la tarea\n");
            scanf("%d", &T.Duracion);
            if (T.Duracion > 100 || T.Duracion < 10)
            {
                printf("La duracion no puede ser menor a 10 o mayor a 100\n ");
            }

             
        } while (T.Duracion < 10 || T.Duracion > 100);
        Nodo *nodo=crearNodo(T);   
        printf("Desea agregar otra tarea Si=1 No=0 \n");
        getchar();
        scanf("%d", &opcion);
        
        agregartarea(&tareaPendiente,nodo);
        
    } while (opcion == 1);
    do
    {
        printf("¿Desea pasar una tarea a la lista de tareas realizadas?\n");
        printf("1 =Si\n");
        printf("0=No\n");
        listarTareas(tareaPendiente);
        scanf("%d",&continuar);
        if (continuar==1)
        {
            int id;
            printf("Ingrese el id de la tarea que quiera cambiar: ");
            scanf("%d",&id);
            getchar();
            moverTarea(&tareaRealizada,&tareaPendiente,id);
        }
        
    } while (continuar==1);

    listarTareas(tareaPendiente);
   
    listarTareasRealizadas(tareaRealizada);
    int seguir;
    do
    {
        printf("Quiere buscar alguna tarea?\n");
        printf("SI=1\n");
        printf("NO=2\n");
        printf("%d",&seguir);
        printf("Como desea buscar su tarea\n ");
        printf("ID=1\n");
        printf("Palabra clave=2\n");
        int forma;
        scanf("%d",&forma);
        if (forma==1)
        {
            
        }else if (forma==2)
        {
            
        }else
        if (seguir!=1)
        {
            printf("Fin programa\n");
        }
        
        
        
        
    } while (seguir==1);
    


    free(buff);
    liberarmemoria(tareaPendiente);
    liberarmemoria(tareaRealizada);
    return 0;
}