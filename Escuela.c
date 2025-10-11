#include <stdio.h>
#include <string.h>

int main() {
    int estudiantes = 5;
    int asignaturas = 3;
    float notas[5][3];
    float sumaEstudiante, sumaAsignatura;
    float max, min;
    int aprobados;

    int i = 0;
    while (i < estudiantes) {
        printf("\nEstudiante %d:\n", i + 1);
        for (int j = 0; j < asignaturas; j++) {
            do {
                printf("  Nota en asignatura %d (0-10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10)
                    printf(" ⚠️  Nota inválida. Intenta de nuevo.\n");
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
        i++;
    }

    printf("\nPromedio por estudiante:\n");
    for (int i = 0; i < estudiantes; i++) {
        sumaEstudiante = 0;
        for (int j = 0; j < asignaturas; j++) {
            sumaEstudiante += notas[i][j];
        }
        printf("  Estudiante %d: %.2f\n", i + 1, sumaEstudiante / asignaturas);
    }

    printf("\nPromedio por asignatura:\n");
    for (int j = 0; j < asignaturas; j++) {
        sumaAsignatura = 0;
        for (int i = 0; i < estudiantes; i++) {
            sumaAsignatura += notas[i][j];
        }
        printf("  Asignatura %d: %.2f\n", j + 1, sumaAsignatura / estudiantes);
    }

    printf("\nNota máxima y mínima por estudiante:\n");
    for (int i = 0; i < estudiantes; i++) {
        max = min = notas[i][0];
        for (int j = 1; j < asignaturas; j++) {
            if (notas[i][j] > max) max = notas[i][j];
            if (notas[i][j] < min) min = notas[i][j];
        }
        printf("  Estudiante %d: Máx = %.2f, Mín = %.2f\n", i + 1, max, min);
    }

    printf("\nNota máxima y mínima por asignatura:\n");
    for (int j = 0; j < asignaturas; j++) {
        max = min = notas[0][j];
        for (int i = 1; i < estudiantes; i++) {
            if (notas[i][j] > max) max = notas[i][j];
            if (notas[i][j] < min) min = notas[i][j];
        }
        printf("  Asignatura %d: Máx = %.2f, Mín = %.2f\n", j + 1, max, min);
    }

    printf("\nAprobados por asignatura:\n");
    for (int j = 0; j < asignaturas; j++) {
        aprobados = 0;
        for (int i = 0; i < estudiantes; i++) {
            if (notas[i][j] >= 6) aprobados++;
        }
        printf("  Asignatura %d: %d aprobados, %d reprobados\n", j + 1, aprobados, estudiantes - aprobados);
    }

    return 0;
}