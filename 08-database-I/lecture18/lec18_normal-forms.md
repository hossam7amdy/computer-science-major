# Normal Forms

**Normal Form:** A relation is in a particular normal form if it satisfies a certain set of constraints.

**Functional Dependency:** A functional dependency is a constraint between two sets of attributes in a relation from a database.

```sql
  loan_id -> loan_amount
```

## First Normal Form (1NF)

1. No repeating groups
2. Each attribute value is atomic
3. Each row is unique

**Trivial Dependencies:** A functional dependency is trivial if the dependent attribute is a subset of the determinant.

### Example:

In a relation representing employees, let X be the set of attributes {EmployeeID, Name} and Y be the attribute {EmployeeID}.
Here, Y is a subset of X, and the functional dependency EmployeeID, Name → EmployeeID is trivial.
It's self-evident that if you know an employee's EmployeeID and Name, you automatically know their EmployeeID.

**Closure:** The closure of a set of attributes is the set of all attributes that are functionally dependent on the original set.

### Example:

1. Start with X
2. Apply all functional dependencies to X
3. Keep adding attributes until no more can be added

```sql
  A,B -> C
  C -> D
  E -> F
```

1. Start with X = {A,B}.
2. From A,B -> C, we can add C to X. Now X = {A,B,C}.
3. From C -> D, we can add D to X. Now X = {A,B,C,D}.
4. No more attributes can be added, so the closure of {A,B} is {A,B,C,D}.

## Boyce-Codd Normal Form (BCNF)

Every determinant is a candidate key

### Example:

Consider a relation `R` with attributes {StudentID, CourseID, InstructorName} representing the courses students take and their respective instructors.

### Functional Dependencies:

1. `StudentID, CourseID` → `InstructorName`
2. `CourseID` → `InstructorName`

In this example, the first functional dependency, `StudentID, CourseID` → `InstructorName`, means that the combination of StudentID and CourseID uniquely determines the InstructorName. However, `CourseID` → `InstructorName` violates BCNF because CourseID is not a super key; it does not uniquely identify instructors.

To bring the relation into BCNF, we decompose it into two relations:

### New Relations:

#### Relation 1:

- **Attributes:** {StudentID, CourseID, InstructorName}
- **Functional dependency:** `StudentID, CourseID` → `InstructorName` (This is a super key.)

#### Relation 2:

- **Attributes:** {CourseID, InstructorName}
- **Functional dependency:** `CourseID` → `InstructorName` (This is a super key.)

By decomposing the original relation based on the functional dependencies, we have ensured that each relation satisfies the conditions of BCNF.
