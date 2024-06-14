class Pila:
    def __init__(self):
        self.top = None  # Inicialmente, la pila está vacía

    def apilar(self, dato):
        nuevo_nodo = Nodo(dato)  # Creamos un nuevo nodo con el dato
        if self.top is None:
            self.top = nuevo_nodo
        else:
            nuevo_nodo.siguiente = self.top
            self.top = nuevo_nodo

    def desapilar(self):
        if self.top is None:
            print("La pila está vacía")
        else:
            valor = self.top.dato
            self.top = self.top.siguiente
            print(f"Elemento desapilado: {valor}")
    def imprimir(self):
        actual = self.top
        while actual:
            print(actual.dato)
            actual = actual.siguiente

class Nodo:
    def __init__(self, dato):
        self.dato = dato
        self.siguiente = None

# Ejemplo de uso
mi_pila = Pila()
mi_pila.apilar("Manzana")
mi_pila.apilar("Plátano")
mi_pila.apilar("Naranja")
mi_pila.imprimir()
mi_pila.desapilar()
