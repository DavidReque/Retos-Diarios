# Definition for a binary tree node.
#Te dan el root de a árbol binario completo con las siguientes propiedades:

#Nodos de hoja tener el valor 0 o 1, donde 0 representa False y 1 representa True.
#Nodos sin hoja tener el valor 2 o 3, donde 2 representa al booleano OR y 3 representa al booleano AND.
#El evaluación de un nodo es el siguiente:

#Si el nodo es un nodo hoja, la evaluación es el valor del nodo, i.e. True o False.
#De lo contrario, evaluar los dos hijos del nodo y aplicar la operación booleana de su valor con las evaluaciones infantiles.
#Devolución el resultado booleano de evaluación el root nodo.

#A árbol binario completo es un árbol binario donde cada nodo tiene cualquiera 0 o 2 niños.

#A nodo de hoja es un nodo que tiene cero hijos.

#Ejemplo 1:

#Entrada: raíz = [2,1,3,null,null,0,1]
#Salida: cierto
#Explicación: El diagrama anterior ilustra el proceso de evaluación.
#El nodo AND se evalúa como Falso Y Verdadero = Falso.
#El nodo OR se evalúa como Verdadero O Falso = Verdadero.
#El nodo raíz se evalúa como True, por lo que devolvemos true.
#Ejemplo 2:

#Entrada: raíz = [0]
#Salida: falso
#Explicación: El nodo raíz es un nodo hoja y se evalúa como falso, por lo que devolvemos falso.
 
#Define la estructura básica de un nodo del árbol binario.
class TreeNode:
      def __init__(self, val=0, left=None, right=None):
        #Inicializa un nodo del árbol con el valor val y opcionalmente con hijos izquierdo y derecho
          self.val = val
          self.left = left
          self.right = right

class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        # Inicializa un nodo del árbol con el valor val y opcionalmente con hijos izquierdo y derecho
        #Si el nodo es una hoja, devuelve True si su valor es 1, y False si su valor es 0.
        if not root.left and not root.right:
             return root.val == 1
        
        #Evaluamos recursivamente el subárbol izquierdo
        left_val = self.evaluateTree(root.left)
        #Evaluamos recursivamente el subárbol derecho
        right_val = self.evaluateTree(root.right)

        # Si el nodo es una operación OR (valor 2), devolvemos el resultado de left_val OR right_val
        if root.val == 2:
             return left_val or right_val
        #Si el nodo es una operación AND (valor 3), devolvemos el resultado de left_val AND right_val
        elif root.val == 3:
             return left_val and right_val
        

## Ejemplo 1:
# Representación del árbol: [2,1,3,null,null,0,1]
# El árbol se ve así:
#        2
#       / \
#      1   3
#         / \
#        0   1
root1 = TreeNode(2)
root1.left = TreeNode(1)
root1.right = TreeNode(3)
root1.right.left = TreeNode(0)
root1.right.right = TreeNode(1)

# Ejemplo 2:
# Representación del árbol: [0]
# El árbol se ve así:
#      0
root2 = TreeNode(0)

# Evaluamos el árbol y mostramos el resultado
print(evaluateTree(root1))  #imprime True por el or (true or false) = true
print(evaluateTree(root2))  #imprime False porque 0 es false