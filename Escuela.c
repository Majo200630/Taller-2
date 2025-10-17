#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int estudiantes = 5;
    int asignaturas = 3;
    float notas[5][3];
    float sumaEstudiante, sumaAsignatura;
    float max[5], min[5];
    int aprobados;

    for (int i = 0; i < estudiantes; i++)
    {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < asignaturas; j++)
        {
            float nota;
            char entrada[100];
            int valido;

            do
            {
                printf("  Nota en asignatura %d (0-10): ", j + 1);
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = '\0'; // eliminar salto de línea

                valido = sscanf(entrada, "%f", &nota);

                if (valido != 1)
                {
                    printf(" ⚠️  Entrada inválida. Solo se deben ingresar números, no caracteres.\n");
                    continue;
                }

                if (nota < 0 || nota > 10)
                {
                    printf(" ⚠️  Nota fuera de rango. Intenta de nuevo.\n");
                    valido = 0;
                }

            } while (valido != 1 || nota < 0 || nota > 10);

            notas[i][j] = nota;
        }
    }

    printf("\nPromedio por estudiante:\n");
    for (int i = 0; i < estudiantes; i++)
    {
        sumaEstudiante = 0;
        for (int j = 0; j < asignaturas; j++)
        {
            sumaEstudiante += notas[i][j];
        }
        printf("  Estudiante %d: %.2f\n", i + 1, sumaEstudiante / asignaturas);
    }

    printf("\nPromedio por asignatura:\n");
    for (int j = 0; j < asignaturas; j++)
    {
        sumaAsignatura = 0;
        for (int i = 0; i < estudiantes; i++)
        {
            sumaAsignatura += notas[i][j];
        }
        printf("  Asignatura %d: %.2f\n", j + 1, sumaAsignatura / estudiantes);
    }

    printf("\nNota máxima y mínima por estudiante:\n");

    for (int i = 0; i < estudiantes; i++)
    {
        max[i] = notas[i][0];
        min[i] = notas[i][0];

        for (int j = 1; j < asignaturas; j++)
        {
            if (notas[i][j] > max[i])
                max[i] = notas[i][j];
            if (notas[i][j] < min[i])
                min[i] = notas[i][j];
        }

        printf("  Estudiante %d: Máx = %.2f, Mín = %.2f\n", i + 1, max[i], min[i]);
    }

    printf("\nNota máxima y mínima por asignatura:\n");

    for (int j = 0; j < asignaturas; j++)
    {
        float max = notas[0][j]; // Inicializar con la primera nota de la asignatura
        float min = notas[0][j];

        for (int i = 1; i < estudiantes; i++)
        {
            if (notas[i][j] > max)
                max = notas[i][j];
            if (notas[i][j] < min)
                min = notas[i][j];
        }

        printf("  Asignatura %d: Máx = %.2f, Mín = %.2f\n", j + 1, max, min);
    }

    printf("\nAprobados por asignatura:\n");
    for (int j = 0; j < asignaturas; j++)
    {
        aprobados = 0;
        for (int i = 0; i < estudiantes; i++)
        {
            if (notas[i][j] >= 6)
                aprobados++;
        }
        printf("  Asignatura %d: %d aprobados, %d reprobados\n", j + 1, aprobados, estudiantes - aprobados);
    }

    return 0;
}
