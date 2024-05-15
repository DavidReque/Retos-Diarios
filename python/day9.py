#esta clase define la estructura de un nodo de la lista enlazada con dos 
#atributos: val (valor del nodo) y next (puntero al siguiente nodo).
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        #nodo temporal que actua como la cabeza de la lista fusionada
        prehead = ListNode(-1)

        # Apuntador puntador que se usa para construir la lista fusionada
        prev = prehead

        # Mientras ambas listas tengan nodos    
        while list1 and list2:
            #Adjuntamos el nodo con el menor valor a la lista fusionada y avanzamos al siguiente nodo en esa lista
            if list1.val <= list2.val:
                prev.next = list1
                list1 = list1.next
            else:
                prev.next = list2
                list2 = list2.next
            prev = prev.next

        # Al final de las listas, uno de ellos puede tener nodos restantes
        prev.next = list1 if list1 is not None else list2

        # La cabeza real de la lista fusionada está después del nodo temporal
        return prehead.next

#iteraciones del bucle:

#list1: [1, 2, 4]
#list2: [1, 3, 4]

#Comparamos 1 (list1) y 1 (list2). Adjuntamos el nodo con 1 (list1).
#Comparamos 2 (list1) y 1 (list2). Adjuntamos el nodo con 1 (list2).
#Comparamos 2 (list1) y 3 (list2). Adjuntamos el nodo con 2 (list1).
#Comparamos 4 (list1) y 3 (list2). Adjuntamos el nodo con 3 (list2).
#Comparamos 4 (list1) y 4 (list2). Adjuntamos el nodo con 4 (list1).
#list1 está vacío. Adjuntamos el nodo restante con 4 (list2).
#Resultado: [1, 1, 2, 3, 4, 4]