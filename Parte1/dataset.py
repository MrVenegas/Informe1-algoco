import random

def guardar_dataset(nombre_archivo, data):
    with open(nombre_archivo, 'w') as f:
        f.write(" ".join(map(str, data)))

n = 10**6  # Tamaño del dataset reducido para pruebas

# Generar dataset aleatorio único
dataset_aleatorio = random.sample(range(10**8), n)  # Asegura que los elementos sean únicos

# Guardar el dataset aleatorio
guardar_dataset("dataset_aleatorio.txt", dataset_aleatorio)

# Dataset Ordenado Ascendentemente
dataset_ascendente = sorted(dataset_aleatorio)
guardar_dataset("dataset_ascendente.txt", dataset_ascendente)

# Dataset Ordenado Descendentemente
dataset_descendente = sorted(dataset_aleatorio, reverse=True)
guardar_dataset("dataset_descendente.txt", dataset_descendente)

# Dataset Casi Ordenado
dataset_casi_ordenado = sorted(dataset_aleatorio)

# Dataset ligeramente desordenado
for _ in range(int(0.05 * n)):
    i = random.randint(0, n-1)
    j = random.randint(0, n-1)
    dataset_casi_ordenado[i], dataset_casi_ordenado[j] = dataset_casi_ordenado[j], dataset_casi_ordenado[i]
guardar_dataset("dataset_casi_ordenado.txt", dataset_casi_ordenado)
