"""import pickle

# Ejemplo de diccionario
diccionario = {"nombre": "Juan", "edad": 30, "ciudad": "Bogotá"}

# Guardar el diccionario en un archivo de texto
with open("archivo.txt", "wb") as archivo:
    pickle.dump(diccionario, archivo)

# Leer el archivo y deserializar el objeto
with open("archivo.txt", "rb") as archivo:
    diccionario_leido = pickle.load(archivo)

# Imprimir el diccionario leído
print(diccionario_leido)"""
"""
import json

# Ejemplo de diccionario
diccionario = {"nombre": "Juan", "edad": 30, "ciudad": "Bogotá"}

# Guardar el diccionario en un archivo JSON con formato legible
with open("archivo.json", "w") as archivo:
    json.dump(diccionario, archivo, indent=4)

# Leer el archivo JSON y convertirlo a un diccionario
with open("archivo.json", "r") as archivo:
    diccionario_leido = json.load(archivo)

# Imprimir el diccionario leído
print(diccionario_leido)

"""
import json

# Ejemplo de diccionario grande
diccionario_grande = {i: i**2 for i in range(100)}

# Convertir el diccionario a una cadena de texto JSON
cadena_json = json.dumps(diccionario_grande)

# Guardar la cadena de texto JSON en un archivo de texto
with open("archivo.txt", "w") as archivo:
    archivo.write(cadena_json)

# Leer el archivo de texto y convertir la cadena de texto JSON a un diccionario
with open("archivo.txt", "r") as archivo:
    cadena_leida = archivo.read()
    diccionario_leido = json.loads(cadena_leida)

# Imprimir el diccionario leído
print(diccionario_leido)