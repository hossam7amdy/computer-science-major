# Functional Dependency Theory

## Functional Dependencies

### Definition

A functional dependency is a constraint between two sets of attributes in a relation from a database.

Given a relation R, a set of attributes X in R is said to functionally determine another set of attributes Y, also in R, (written X → Y) if, and only if, each X value is associated with precisely one Y value; R is then said to satisfy the functional dependency X → Y.

### Example

Consider the following relation R:

| A   | B   | C   |
| --- | --- | --- |
| 1   | 2   | 3   |
| 1   | 2   | 4   |
| 1   | 3   | 3   |
| 1   | 3   | 4   |
| 2   | 2   | 3   |
| 2   | 2   | 4   |
| 2   | 3   | 3   |
| 2   | 3   | 4   |

We can see that the following functional dependencies hold:

- A → B
- A → C
- B → C

## Rules of Inference

### Reflexivity Rule

If Y is a subset of X, then X → Y.

### Augmentation Rule

If X → Y, then XZ → YZ.

### Transitivity Rule

If X → Y and Y → Z, then X → Z.

### Union Rule

If X → Y and X → Z, then X → YZ.

### Decomposition Rule

If X → YZ, then X → Y and X → Z.

### Pseudotransitivity Rule

If X → Y and WY → Z, then WX → Z.

## Computation Closure of F

### Armstrong's Axioms

- Reflexivity: If Y is a subset of X, then X → Y.
- Augmentation: If X → Y, then XZ → YZ.
- Transitivity: If X → Y and Y → Z, then X → Z.

### Algorithm

1. Start with F.

```pseudo
F+ = F
repeat
  for each functional dependency f in F+
    apply reflexivity and augmentation rules to f
    add resulting functional dependencies to F+
  for each pair of functional dependencies f1 , f2 in F+
    if f1 and f2 can be combined using transitivity
      add resulting functional dependency to F+
until F+ stops changing
```

## Attribute-Set Closure

### Algorithm

```pseudo
X+ = X
repeat
  for each functional dependency f in F+
    if f can be applied to X+
      add resulting attribute to X+
until X+ stops changing
```

### Example

Relation schema R(A, B, C, G, H, I):
Dependencies: A -> B, A -> C, CG -> H, CG -> I, B -> H

Is AG a candidate key of R?

```pseudo
AG+ = AG
repeat
  for each functional dependency f in F+
    if f can be applied to AG+
      add resulting attribute to AG+
until AG+ stops changing
```

AG+ = AG

## BCNF Revisited

### How do we tell if Ri is in BCNF?

- Can use attribute-set closure under F to find if there is a dependency in F+ that affects Ri
- For each proper subset a ⊆ Ri , compute a+ under F
- If a+ doesn’t contain Ri , but a+ does contain any attributes in Ri – a, then Ri is not in BCNF

## Database Constraints

- Enforcing database constraints can easily become very expensive
- Best to define database schema such that constraint enforcement is efficient
- Ideally, enforcing a functional dependency involves only one relation
  - Then, can specify a key constraint instead of a multi table CHECK constraint!

## Preserving Dependencies

- In general, BCNF decompositions are not dependency-preserving
- 3NF decompositions are dependency-preserving
- SOLUTION: Decompose into 3NF, then into BCNF

## Third Normal Form

### Definition

A relation R is in third normal form (3NF) if, and only if, for every one of its functional dependencies X → A, at least one of the following conditions holds:

### R is in 3NF with respect to F if:

- For all functional dependencies α -> β in F+, where a ⊆ R and b ⊆ R, at least one of the following holds:
  - α -> β is a trivial functional dependency (i.e., β ⊆ α)
  - α is a superkey for schema R
  - Each attribute in β - α is contained in a candidate key for schema R
