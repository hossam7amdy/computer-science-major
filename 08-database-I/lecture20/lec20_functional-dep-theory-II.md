# Functional Dependency Theory II

## Canonical Cover

### Definition

The canonical cover of a set of functional dependencies F is a set of dependencies Fc such that:

- Fc is equivalent to F
- Fc is in canonical form
- Fc is minimal

### Algorithm

1. Compute the closure of each dependency in F
2. Remove redundant dependencies from F

### Redundant Dependencies

A dependency X → Y is redundant in F if:

- X → Y is in F
- X → Y is not in Fc

### Example

Consider the following set of functional dependencies F:

- A → B
- A → C
- B → C
- C → D

We can compute the closure of each dependency in F:

- A → B: A+ = ABCD
- A → C: A+ = ABCD
- B → C: B+ = BCD
- C → D: C+ = CD

We can see that the following dependencies are redundant:

- A → B
- A → C

Therefore, the canonical cover of F is:

- A → B
- B → C
- C → D

## Extraneous Attributes

An attribute in a functional dependency is extraneous if it can be removed from F without changing F+.

- Attribute A in a -> b
- If A Î a (i.e. A is on left side of the dependency), then let g = a – {A}
  1. See if y -> b can be inferred from F
  2. Compute y+ under F
  3. If b ⊆ y+ then A is extraneous in a
- e.g. if AB -> C and you want to see if B is extraneous, can see if you can infer A -> C from F.

---

- Attribute A in a -> b
- If A Î b (on right side of the dependency), then try the altered set F'
  1. F' = (F – {a ® b}) ∪ {a ® (b – A)}
  2. See if a -> A can be inferred from F'
  3. Compute a+ under F'
  4. If a+ includes A then A is extraneous in b
- e.g. if A ® BC and you want to see if B is extraneous, you can already infer A ® B from this dependency
  - Must generate F' with only A ® C, and if you can infer A -> B from F', then B was indeed extraneous

## Lossless Decompositions

The decomposition is lossless if, for all legal instances of r:
P1(r) NATURAL JOIN P2(r) = r

## BCNF Decompositions

- BCNF decomposition is lossless
  1. R1 ∩ R2 = a
  2. a is a superkey of R1
  3. a also appears in R2

## Dependency Preservation

Some schema decompositions are not dependency-preserving

- Functional dependencies that span multiple relation schemas are hard to enforce
- e.g. BCNF may require decomposition of a schema for one dependency, and make it hard to enforce another dependency

## The 3NF Schema

- Can generate a 3NF schema from a set of functional dependencies F
- Called the 3NF _synthesis algorithm_
  - Instead of decomposing an initial schema, generates schemas from a set of dependencies
- Given a set F of functional dependencies
  1. Uses the canonical cover Fc
  2. Ensures that resulting schemas are dependency-preserving

## 3NF vs. BCNF

### Boyce-Codd Normal Form:

- Eliminates more redundant information than 3NF
- Some functional dependencies become expensive to enforce
  - The conditions to enforce involve multiple relations
- Overall, a very desirable normal form!

### Third Normal Form:

- All [more] dependencies are [probably] easy to enforce…
- Allows more redundant information, which must be kept synchronized by the database application!
- Personal banker example:
  - works_in(emp_id, branch_name)
  - cust_banker_branch(cust_id, branch_name, emp_id, type)
  - Branch names must be kept synchronized between these relations!

## BCNF and 3NF vs. SQL

- SQL constraints:
  - Only _key_ constraints are fast and easy to enforce!
  - Only easy to enforce functional dependencies a -> b if a is
  - key on some table!
  - Other functional dependencies (even “easy” ones in 3NF) may require more expensive constraints, e.g. _CHECK_
- For SQL databases with materialized views:
  - Can decompose a schema into BCNF
  - For dependencies a -> b not preserved in decomposition, create materialized view joining all relations in dependency
  - Enforce unique(a) constraint on materialized view
- Impacts both space and performance, but it works…

## Multi-valued Attributes

- Question is trickier when a schema stores several independent multivalued attributes
- Proposed combined schema:
  `employee(emp_id, emp_name)`
  `emp_info(emp_id, dependent, phone_num)`
- What tuples must appear in emp_info ?
  - emp_info is a relation
  - If an employee has M dependents and N phone numbers, emp_info must contain M \* N tuples
    - Exactly what we get if we natural-join emp_deps and emp_nums
  - Every combination of the employee’s dependents and their phone numbers

## Fourth Normal Form

- Given:
  - Relation schema R
  - Set of functional and multivalued dependencies D
- R is in 4NF with respect to D if:
  - For all multivalued dependencies a ->> b in D+, where
    a ⊆ R and b ⊆ R, at least one of the following holds:
    - a ->> b is a trivial multivalued dependency
    - a is a superkey for R
  - Note: If a -> b then a ->> b
- A database design is in 4NF if all schemas in the design are in 4NF

## 4NF vs. BCNF

- Main difference between 4NF and BCNF is use of
  multivalued dependencies instead of functional
  dependencies
- Every schema in 4NF is also in BCNF
  - If a schema is not in BCNF then there is a nontrivial
    functional dependency a -> b such that a is not a superkey
    for R
  - If a -> b then a ->> b

## 4NF Decompositions

- Decomposition rule is very similar to BCNF
- If schema R is not in 4NF with respect to a set of
  multivalued dependencies D:
  - There is some nontrivial dependency a ->> b in D+
    where a ⊆ R and b ⊆ R, and a is not a superkey of R
  - Also constrain that a ∩ b = ∅
  - Replace R with two new schemas:
  - R1 = (a ∪ b)
  - R2 = (R – b)

### Example

- Combined schema:
  employee(emp_id, emp_name)
  emp_info(emp_id, dependent, phone_num)
- Also have these dependencies:
  - emp_id -> emp_name
  - emp_id ->> dependent
  - emp_id ->> phone_num
- emp_info is not in 4NF
- Following the rules for 4NF decomposition produces:
  (emp_id, dependent)
  (emp_id, phone_num)
  - Note: Each relation’s candidate key is the entire relation.
    The multivalued dependencies are trivial.

### Lossless Decompositions

- Can also define lossless decomposition with
  multivalued dependencies
  - R1 and R2 form a lossless decomposition of R if at least
    one of these dependencies is in D+:
    R1 ∩ R2 R1
    R1 ∩ R2 R2
