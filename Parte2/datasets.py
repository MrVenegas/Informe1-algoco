import random

#Tamaños:
m = 2**11
n = 2**11
p = 2**11

# Función para guardar la matriz en un archivo de texto
def guardar_matriz(nombre_archivo, matriz):
    with open(nombre_archivo, 'w') as f:
        for fila in matriz:
            f.write(" ".join(map(str, fila)) + "\n")

# Función para generar una matriz aleatoria
def generar_matriz_aleatoria(filas, columnas, rango=(0, 10)):
    return [[random.randint(rango[0], rango[1]) for _ in range(columnas)] for _ in range(filas)]


# Función principal para generar las matrices A y B en diferentes formatos
def generar_matrices_y_guardar(m, n, p):
    # Generar Matrices A y B (compatibles para la multiplicación)
    # A es de tamaño m x n, y B es de tamaño n x p

    # 1. Aleatorias
    matriz_A_aleatoria = generar_matriz_aleatoria(m, n)
    matriz_B_aleatoria = generar_matriz_aleatoria(n, p)
    guardar_matriz("matriz_A.txt", matriz_A_aleatoria)
    guardar_matriz("matriz_B.txt", matriz_B_aleatoria)



generar_matrices_y_guardar(m, n, p)