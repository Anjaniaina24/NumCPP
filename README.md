#### Classe NumCpp<T> (namespace NumCPP)   ######

###  **Attributs privés**

* data → contient les données du tableau sous forme linéaire (std::vector<T>).
* shape → contient les dimensions du tableau.
* ndim → nombre de dimensions.
* size → nombre total d’éléments.
* Fonctions internes :

  * calculateShapeAndSize() → calcule ndim et size à partir de shape.
  * index(indices) → calcule la position linéaire dans data depuis des indices multidimensionnels.
  * setShape(sizes) → définit la forme du tableau.

---

###  **Constructeurs**

1. NumCpp(T a)
   → crée un tableau contenant une seule valeur (scalaire).
   Python : np.array(a)

2. NumCpp(std::initializer_list<T> init)
   → crée un tableau 1D à partir d’une liste de valeurs.
   Python : np.array([1, 2, 3])

3. NumCpp(std::initializer_list<NumCpp<T>> init)
   → crée un tableau 2D (ou plus) à partir de sous-tableaux.
   Python : np.array([[1, 2], [3, 4]])

4. NumCpp(const std::vector<size_t>& taille)
   → crée un tableau vide d’une forme donnée.
   Python : np.empty(shape)

---

###  **Accès et informations**

* operator[](indices)
  → accède à un élément via des indices multidimensionnels.
  Python : a[i, j]

* getData()
  → renvoie les données internes sous forme linéaire (vector).
  Python : a.ravel()

* getShape()
  → renvoie la forme du tableau.
  Python : a.shape

* getNdim()
  → renvoie le nombre de dimensions.
  Python : a.ndim

* getSize()
  → renvoie le nombre total d’éléments.
  Python : a.size

* print()
  → affiche le contenu du tableau.
  Python : print(a)

---

###  **Création de tableaux**

* array(T a) → crée un tableau scalaire.
  Python : np.array(a)

* array({1,2,3}) → crée un tableau à partir d’une liste.
  Python : np.array([1, 2, 3])

* array({{1,2},{3,4}}) → crée un tableau 2D.
  Python : np.array([[1, 2], [3, 4]])

---

###  **Opérateurs arithmétiques**

* operator=(m) → assigne un autre tableau.
  Python : a = b

* operator+(m), operator-(m), operator*(m), operator/(m), operator%(m)
  → opérations élément par élément entre deux tableaux.
  Python : a + b, a - b, a * b, a / b, a % b

* Même opérateurs avec un scalaire T m.
  Python : a + 2, a * 3, etc.

---

###  **Comparaisons entre tableaux**

* ==, !=, <, <=, >, >=
  → comparaison élément par élément, retourne un tableau de booléens (NumCpp<bool>).
  Python : a == b, a > b, etc.

###  **Comparaisons avec scalaire**

* ==, !=, <, <=, >, >=
  → compare chaque élément à une valeur scalaire.
  Python : a == 5, a < 2, etc.

---

###  **Tableaux de base**

* zeros(shape) → tableau rempli de zéros.
  Python : np.zeros(shape)

* ones(shape) → tableau rempli de uns.
  Python : np.ones(shape)

* full(shape, value) → tableau rempli avec une valeur donnée.
  Python : np.full(shape, value)

* empty(shape) → tableau non initialisé (valeurs indéfinies).
  Python : np.empty(shape)

* random(shape, start, stop) → tableau avec des valeurs aléatoires entre start et stop.
  Python : np.random.randint(start, stop, shape)

---

###  **Manipulation de formes**

* reshape(sizes) → change la forme sans modifier les données.
  Python : a.reshape(new_shape)

* resize(sizes) → redimensionne le tableau (réalloue si besoin).
  Python : a.resize(new_shape)

* slice(start, stop, step) → extrait une sous-partie.
  Python : a[start:stop:step]

* where(condition, x, y) → retourne x si condition vraie, sinon y.
  Python : np.where(condition, x, y)

* cumsum() → somme cumulative des éléments.
  Python : np.cumsum(a)

* cumprod() → produit cumulatif des éléments.
  Python : np.cumprod(a)

---

###  **Tableaux 1D**

* linspace(start, stop, num) → crée un vecteur de valeurs également espacées.
  Python : np.linspace(start, stop, num)

* arange(sizes) → génère une suite de nombres.
  Python : np.arange(start, stop, step)

* flatten() → aplatit le tableau en 1D.
  Python : a.flatten()

* unique() → retourne les valeurs uniques.
  Python : np.unique(a)

---

###  **Tableaux 2D**

* eye(row, col=0) → matrice identité (ou diagonale).
  Python : np.eye(row, col)

* diag(elem) → crée une matrice diagonale.
  Python : np.diag(elem)

* vander(elem, col) → crée une matrice de Vandermonde.
  Python : np.vander(elem, col)

---

###  **Calculs et statistiques**

* sum() → somme des éléments.
  Python : a.sum()

* prod() → produit des éléments.
  Python : a.prod()

* min() / max() → valeur minimale / maximale.
  Python : a.min(), a.max()

* mean() → moyenne.
  Python : a.mean()

* var() → variance.
  Python : a.var()

* std() → écart-type.
  Python : a.std()

* argmin() / argmax() → indice du min / max.
  Python : a.argmin(), a.argmax()

---

###  **Manipulation et tri**

* sort() → trie les éléments du tableau.
  Python : np.sort(a)

* transpose() → transpose le tableau (échange les axes).
  Python : a.T

---

###  **Fonctions mathématiques**

* apply(func) → applique une fonction à chaque élément.
  Python : np.vectorize(func)(a)

* exp() → exponentielle.
  Python : np.exp(a)

* log() → logarithme naturel.
  Python : np.log(a)

* sqrt() → racine carrée.
  Python : np.sqrt(a)

* sin(), cos(), tan() → fonctions trigonométriques.
  Python : np.sin(a), np.cos(a), np.tan(a)

* asin(), acos(), atan() → fonctions trigonométriques inverses.
  Python : np.arcsin(a), np.arccos(a), np.arctan(a)

* sinh(), cosh(), tanh() → fonctions hyperboliques.
  Python : np.sinh(a), np.cosh(a), np.tanh(a)

* fabs() → valeur absolue.
  Python : np.fabs(a)

* ceil() → arrondi supérieur.
  Python : np.ceil(a)

* floor() → arrondi inférieur.
  Python : np.floor(a)
