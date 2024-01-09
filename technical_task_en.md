# Technical Task
## Practice work «Tree planer»

You need to write an application to visualize working with several classes of search trees.  
Classes of search trees for implementation:
1) AVL tree
2) RB tree
3) Treap
4) Splay tree

For each class need to implement base operations:
1) Adding an element with a key entered by the user.
2) Adding a certain number of random elements (the number is set by the user).
3) Deleting an element on click.

There are no restrictions on the number of items in the tree. All elements are integers, representable in the int64_t type.
All elements of the search tree are unique. If you enter a duplicate, you do not need to add it to the tree.

## Interface organization

The program interface should contain 4 tabs – one for each class of trees. Each tab should have a main window where the tree is drawn, and buttons/windows for performing insertion operations. The operation of deleting an element must be performed by clicking the mouse on the main screen.  
All nodes of the tree should look the same. It is not allowed to increase the size of the node, due to the fact that it stores too long a number. The numbers should be written in the nodes carefully. Numbers are not allowed to go beyond the boundaries of nodes. Ideally, you should use a monospaced font so that each digit occupies the same place on the screen.  
  
The tree can contain a very different number of keys, so it is necessary to provide scaling (zoom in/out). Vertical and horizontal scrolling is allowed in the close position.  
The user is moody, and wants there to be one among the positions of the tree (closer/ further) that he will be pleased to work with!  
Highlighting nodes or entries in nodes in color is always welcome and in some cases is mandatory (for example, in a red-black tree nodes should have two colors, and in a Cartesian tree it is useful to highlight the key and weight in different colors). Specific colors are a creative design decision (the user is moody, but curious, and agrees to work with both blue-green and purple-yellow wood).
  
## Features of the assessment
Frontend is the main part of the task. Backend without Frontend is not evaluated. The Backend will evaluate the implementation of each class of trees independently of each other.  
Accordingly, partial surrender is possible when not all classes of trees have been implemented yet  